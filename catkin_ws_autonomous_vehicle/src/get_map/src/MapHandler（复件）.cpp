#include "MapHandler.h"
// using namespace message_filters;
Car::Car() : pos_x(0), pos_y(0), vel_x(0), vel_y(0), angle(0){};

MapHandler::MapHandler(int map_h, int map_w) : map_height(map_h), map_width(map_w)
{
    // publisher and subscribers
    std::string topic_name_cone;
    std::string topic_name_move;
    std::string topic_name_cone_color;
    nh.param<std::string>("get_map/topic_name_cone", topic_name_cone, "cones");
    nh.param<std::string>("get_map/topic_name_move", topic_name_move, "location");
    nh.param<std::string>("get_map/topic_name_cone_color", topic_name_cone_color, "/detect/final");
    // sub_cone = nh.subscribe(topic_name_cone, 10, &MapHandler::callback_cone_zzx, this);
    // sub_move = nh.subscribe(topic_name_move, 10, &MapHandler::callback_move, this);
    sub_cone_color = nh.subscribe(topic_name_cone_color, 10, &MapHandler::callback_cone, this);
    // map_metadata
    map_meta = std::vector<std::vector<std::vector<uint8_t>>>(map_height, std::vector<std::vector<uint8_t>>(map_width, std::vector<uint8_t>(3, 0)));
    map_meta_zzx = std::vector<std::vector<std::vector<uint8_t>>>(map_height, std::vector<std::vector<uint8_t>>(map_width, std::vector<uint8_t>(3, 0)));
    map_track = cv::Mat(map_height, map_width, CV_8UC1);
    // generate a car
    car = Car();
    car_past = Car();
    nh.param<float>("get_map/car_start_y", car.start_y, map_height / 2);
    nh.param<float>("get_map/car_start_x", car.start_x, map_width / 2);
    nh.param<float>("get_map/car_start_angle", car.start_angle, 0);
    /////
    car_last = Car();
    car_last.pos_x = car.start_x;
    car_last.pos_y = car.start_y;
    car_last.angle = car.start_angle;
    pub_finish = nh.advertise<std_msgs::Bool>("finish_first_round", 10);
    finish_msg.data = false;
    /////
    car.pos_x = car.start_x;
    car.pos_y = car.start_y;
    car.angle = car.start_angle;
    car_past.pos_x = car.start_x;
    car_past.pos_y = car.start_y;
    car_past.angle = car.start_angle;
    // get ratio
    nh.param<float>("get_map/ratio", ratio, 0.01);
    sub_cone = new message_filters::Subscriber<car_msgs::LidarDetect>(nh, "/cones", 1);
    sub_move = new message_filters::Subscriber<car_msgs::car_location>(nh, "/location", 1);
    typedef message_filters::sync_policies::ApproximateTime<car_msgs::LidarDetect,car_msgs::car_location> mysync;
    Synchronizer<mysync> *sync = new Synchronizer<mysync>(mysync(100), *sub_cone, *sub_move);
    sync->registerCallback(boost::bind(&MapHandler::DetectCallback, this, _1, _2));

}

// void MapHandler::callback_cone_zzx(const car_msgs::LidarDetect::ConstPtr& msg)
// {
//     ROS_INFO("callback_cone_zzx");
//     //ROS_INFO_STREAM(""<<"lidar"<<msg.header.stamp<<"|car"<<msg_temp.header.stamp);
//     // data process
//     get_cone_zzx(msg);

//     // convert vector to cv::Mat
//     vector_to_mat_zzx();

//     //////////////////////
//     check_if_finished_first_round();

//     // check and save map
//     check_and_save_map_zzx();
    
//     // add car to map
//     add_car_to_map_zzx();

//     // show map
//     show_map_zzx();
// }

void MapHandler::callback_cone(const car_msgs::DetectFinal::ConstPtr &msg)
{
    ROS_INFO("callback_cone");
    // data process
    get_cone(msg);

    // convert vector to cv::Mat
    vector_to_mat();

    // check and save map
    check_and_save_map();
    
    // add car to map
    add_car_to_map();

    // show map
    show_map();
}

void MapHandler::DetectCallback(const car_msgs::LidarDetect::ConstPtr& msg_cone, const car_msgs::car_location::ConstPtr &msg_move)
{
    ROS_INFO("callback_cone_zzx");
    //ROS_INFO_STREAM(""<<"lidar"<<msg.header.stamp<<"|car"<<msg_temp.header.stamp);
    // data process
    get_cone_zzx(msg_cone);

    // convert vector to cv::Mat
    vector_to_mat_zzx();

    //////////////////////
    check_if_finished_first_round();

    // check and save map
    check_and_save_map_zzx();
    
    // add car to map
    add_car_to_map_zzx();

    // show map
    show_map_zzx();



    ROS_INFO("callback_move");
    // if positive direction of y-aixs is forward
    car.pos_x = car.start_x + (1.0 / ratio) * msg_move->x;
    car.pos_y = car.start_y + (1.0 / ratio) * msg_move->y;
    car.angle = car.start_angle + (-msg_move->z);
    // draw line
    cv::line(map_track, cv::Point(car_past.pos_x, map_height-car_past.pos_y), cv::Point(car.pos_x, map_height-car.pos_y), cv::Scalar(255));
    // update car_past
    car_past.pos_x = car.pos_x;
    car_past.pos_y = car.pos_y;
    car_past.angle = car.angle;
    // show map
    cv::imshow("Track", map_track);
    cv::waitKey(1);

}

void MapHandler::callback_move(const car_msgs::car_location::ConstPtr &msg)
{
    ROS_INFO("callback_move");
    //msg_temp = msg;
    // if positive direction of y-aixs is forward
    car.pos_x = car.start_x + (1.0 / ratio) * msg->x;
    car.pos_y = car.start_y + (1.0 / ratio) * msg->y;
    car.angle = car.start_angle + (-msg->z);
    // draw line
    cv::line(map_track, cv::Point(car_past.pos_x, map_height-car_past.pos_y), cv::Point(car.pos_x, map_height-car.pos_y), cv::Scalar(255));
    // update car_past
    car_past.pos_x = car.pos_x;
    car_past.pos_y = car.pos_y;
    car_past.angle = car.angle;
    // show map
    cv::imshow("Track", map_track);
    cv::waitKey(1);
}

void MapHandler::get_cone(const car_msgs::DetectFinal::ConstPtr &msg)
{
    int pix_x = 0;
    int pix_y = 0;

    for (int i = 0; i < 8; ++i)
    {
        pix_x = 0;
        pix_y = 0;
        if (msg->barrels_x[i] != 0 && msg->barrels_y[i] != 0)
        {
            pix_x = (int)(car.pos_x + (1.0 / ratio) * (msg->barrels_x[i] * cos(car.angle) + msg->barrels_y[i] * sin(car.angle)));
            pix_y = map_height - (int)(car.pos_y + (1.0 / ratio) * (-msg->barrels_x[i] * sin(car.angle) + msg->barrels_y[i] * cos(car.angle)));
            // draw cones on the map
            if ((pix_x - 1) >= 0 && (pix_x + 1) < map_width && (pix_y - 1) >= 0 && (pix_y + 1) < map_height)
            {
                if (msg->color[i] == 0)
                {
                    map_meta[pix_y][pix_x][0] = (map_meta[pix_y][pix_x][0] < 250) ? (map_meta[pix_y][pix_x][0] + 50) : 250;
                    map_meta[pix_y - 1][pix_x][0] = (map_meta[pix_y - 1][pix_x][0] < 250) ? (map_meta[pix_y - 1][pix_x][0] + 50) : 250;
                    map_meta[pix_y + 1][pix_x][0] = (map_meta[pix_y + 1][pix_x][0] < 250) ? (map_meta[pix_y + 1][pix_x][0] + 50) : 250;
                    map_meta[pix_y][pix_x - 1][0] = (map_meta[pix_y][pix_x - 1][0] < 250) ? (map_meta[pix_y][pix_x - 1][0] + 50) : 250;
                    map_meta[pix_y][pix_x + 1][0] = (map_meta[pix_y][pix_x + 1][0] < 250) ? (map_meta[pix_y][pix_x + 1][0] + 50) : 250;
                    map_meta[pix_y - 1][pix_x - 1][0] = (map_meta[pix_y - 1][pix_x - 1][0] < 250) ? (map_meta[pix_y - 1][pix_x - 1][0] + 50) : 250;
                    map_meta[pix_y - 1][pix_x + 1][0] = (map_meta[pix_y - 1][pix_x + 1][0] < 250) ? (map_meta[pix_y - 1][pix_x + 1][0] + 50) : 250;
                    map_meta[pix_y + 1][pix_x - 1][0] = (map_meta[pix_y + 1][pix_x - 1][0] < 250) ? (map_meta[pix_y + 1][pix_x - 1][0] + 50) : 250;
                    map_meta[pix_y + 1][pix_x + 1][0] = (map_meta[pix_y + 1][pix_x + 1][0] < 250) ? (map_meta[pix_y + 1][pix_x + 1][0] + 50) : 250;
                }
                else if (msg->color[i] == 1)
                {
                    map_meta[pix_y][pix_x][2] = (map_meta[pix_y][pix_x][2] < 250) ? (map_meta[pix_y][pix_x][2] + 50) : 250;
                    map_meta[pix_y - 1][pix_x][2] = (map_meta[pix_y - 1][pix_x][2] < 250) ? (map_meta[pix_y - 1][pix_x][2] + 50) : 250;
                    map_meta[pix_y + 1][pix_x][2] = (map_meta[pix_y + 1][pix_x][2] < 250) ? (map_meta[pix_y + 1][pix_x][2] + 50) : 250;
                    map_meta[pix_y][pix_x - 1][2] = (map_meta[pix_y][pix_x - 1][2] < 250) ? (map_meta[pix_y][pix_x - 1][2] + 50) : 250;
                    map_meta[pix_y][pix_x + 1][2] = (map_meta[pix_y][pix_x + 1][2] < 250) ? (map_meta[pix_y][pix_x + 1][2] + 50) : 250;
                    map_meta[pix_y - 1][pix_x - 1][2] = (map_meta[pix_y - 1][pix_x - 1][2] < 250) ? (map_meta[pix_y - 1][pix_x - 1][2] + 50) : 250;
                    map_meta[pix_y - 1][pix_x + 1][2] = (map_meta[pix_y - 1][pix_x + 1][2] < 250) ? (map_meta[pix_y - 1][pix_x + 1][2] + 50) : 250;
                    map_meta[pix_y + 1][pix_x - 1][2] = (map_meta[pix_y + 1][pix_x - 1][2] < 250) ? (map_meta[pix_y + 1][pix_x - 1][2] + 50) : 250;
                    map_meta[pix_y + 1][pix_x + 1][2] = (map_meta[pix_y + 1][pix_x + 1][2] < 250) ? (map_meta[pix_y + 1][pix_x + 1][2] + 50) : 250;
                }
                else if (msg->color[i] == 2)
                {
                    map_meta[pix_y][pix_x][1] = (map_meta[pix_y][pix_x][1] < 250) ? (map_meta[pix_y][pix_x][1] + 50) : 250;
                    map_meta[pix_y - 1][pix_x][1] = (map_meta[pix_y - 1][pix_x][1] < 250) ? (map_meta[pix_y - 1][pix_x][1] + 50) : 250;
                    map_meta[pix_y + 1][pix_x][1] = (map_meta[pix_y + 1][pix_x][1] < 250) ? (map_meta[pix_y + 1][pix_x][1] + 50) : 250;
                    map_meta[pix_y][pix_x - 1][1] = (map_meta[pix_y][pix_x - 1][1] < 250) ? (map_meta[pix_y][pix_x - 1][1] + 50) : 250;
                    map_meta[pix_y][pix_x + 1][1] = (map_meta[pix_y][pix_x + 1][1] < 250) ? (map_meta[pix_y][pix_x + 1][1] + 50) : 250;
                    map_meta[pix_y - 1][pix_x - 1][1] = (map_meta[pix_y - 1][pix_x - 1][1] < 250) ? (map_meta[pix_y - 1][pix_x - 1][1] + 50) : 250;
                    map_meta[pix_y - 1][pix_x + 1][1] = (map_meta[pix_y - 1][pix_x + 1][1] < 250) ? (map_meta[pix_y - 1][pix_x + 1][1] + 50) : 250;
                    map_meta[pix_y + 1][pix_x - 1][1] = (map_meta[pix_y + 1][pix_x - 1][1] < 250) ? (map_meta[pix_y + 1][pix_x - 1][1] + 50) : 250;
                    map_meta[pix_y + 1][pix_x + 1][1] = (map_meta[pix_y + 1][pix_x + 1][1] < 250) ? (map_meta[pix_y + 1][pix_x + 1][1] + 50) : 250;
                }
            }
        }
    }
}

void MapHandler::get_cone_zzx(const car_msgs::LidarDetect::ConstPtr &msg)
{
    int pix_x = 0;
    int pix_y = 0;

    for (int i = 0; i < 8; ++i)
    {
        pix_x = 0;
        pix_y = 0;
        if (msg->x[i] != 0 && msg->y[i] != 0)
        {
            pix_x = (int)(car.pos_x + (1.0 / ratio) * (msg->x[i] * cos(car.angle) + msg->y[i] * sin(car.angle)));
            pix_y = map_height - (int)(car.pos_y + (1.0 / ratio) * (-msg->x[i] * sin(car.angle) + msg->y[i] * cos(car.angle)));
            // draw cones on the map
            if (pix_x >= 1 && pix_x+1 < map_width && pix_y >= 1 && pix_y+1 < map_height)
            {
                map_meta_zzx[pix_y][pix_x][1] = (map_meta_zzx[pix_y][pix_x][1] < 250) ? (map_meta_zzx[pix_y][pix_x][1] + 50) : 250;
                map_meta_zzx[pix_y][pix_x-1][1] = (map_meta_zzx[pix_y][pix_x-1][1] < 250) ? (map_meta_zzx[pix_y][pix_x-1][1] + 50) : 250;
                map_meta_zzx[pix_y][pix_x+1][1] = (map_meta_zzx[pix_y][pix_x+1][1] < 250) ? (map_meta_zzx[pix_y][pix_x+1][1] + 50) : 250;
                map_meta_zzx[pix_y+1][pix_x][1] = (map_meta_zzx[pix_y+1][pix_x][1] < 250) ? (map_meta_zzx[pix_y+1][pix_x][1] + 50) : 250;
                map_meta_zzx[pix_y+1][pix_x-1][1] = (map_meta_zzx[pix_y+1][pix_x-1][1] < 250) ? (map_meta_zzx[pix_y+1][pix_x-1][1] + 50) : 250;
                map_meta_zzx[pix_y+1][pix_x+1][1] = (map_meta_zzx[pix_y+1][pix_x+1][1] < 250) ? (map_meta_zzx[pix_y+1][pix_x+1][1] + 50) : 250;
                map_meta_zzx[pix_y-1][pix_x][1] = (map_meta_zzx[pix_y-1][pix_x][1] < 250) ? (map_meta_zzx[pix_y-1][pix_x][1] + 50) : 250;
                map_meta_zzx[pix_y-1][pix_x-1][1] = (map_meta_zzx[pix_y-1][pix_x-1][1] < 250) ? (map_meta_zzx[pix_y-1][pix_x-1][1] + 50) : 250;
                map_meta_zzx[pix_y-1][pix_x+1][1] = (map_meta_zzx[pix_y-1][pix_x+1][1] < 250) ? (map_meta_zzx[pix_y-1][pix_x+1][1] + 50) : 250;
            }
        }
    }
}


void MapHandler::vector_to_mat()
{
    //  convert 3D vector to cv::Mat
    map_cv = cv::Mat(map_height, map_width, CV_8UC3);
    for (unsigned int i = 0; i < map_height; ++i)
    {
        for (unsigned int j = 0; j < map_width; ++j)
        {
            map_cv.at<cv::Vec3b>(i, j)[0] = map_meta[i][j][0];
            map_cv.at<cv::Vec3b>(i, j)[1] = map_meta[i][j][1];
            map_cv.at<cv::Vec3b>(i, j)[2] = map_meta[i][j][2];
        }
    }
}

void MapHandler::vector_to_mat_zzx()
{
    //  convert 3D vector to cv::Mat
    map_cv_zzx = cv::Mat(map_height, map_width, CV_8UC3);
    for (unsigned int i = 0; i < map_height; ++i)
    {
        for (unsigned int j = 0; j < map_width; ++j)
        {
            map_cv_zzx.at<cv::Vec3b>(i, j)[0] = map_meta_zzx[i][j][0];
            map_cv_zzx.at<cv::Vec3b>(i, j)[1] = map_meta_zzx[i][j][1];
            map_cv_zzx.at<cv::Vec3b>(i, j)[2] = map_meta_zzx[i][j][2];
        }
    }
}

void MapHandler::add_car_to_map()
{
    cv::line(map_cv, cv::Point(car.pos_x, map_height - car.pos_y), cv::Point(car.pos_x + (2.5 / ratio) * sin(-3.14159265 / 4 + car.angle), map_height - (car.pos_y + (2.5 / ratio) * cos(-3.14159265 / 4 + car.angle))), cv::Scalar(0, 255, 255));
    cv::line(map_cv, cv::Point(car.pos_x, map_height - car.pos_y), cv::Point(car.pos_x + (2.5 / ratio) * sin(3.14159265 / 4 + car.angle), map_height - (car.pos_y + (2.5 / ratio) * cos(3.14159265 / 4 + car.angle))), cv::Scalar(0, 255, 255));
    cv::ellipse(map_cv, cv::Point(car.pos_x, map_height - car.pos_y), cv::Size((2.5 / ratio), (2.5 / ratio)), car.angle / 3.14159265 * 180, 225, 315, cv::Scalar(0, 255, 255));
    cv::circle(map_cv, cv::Point(car.pos_x, map_height - car.pos_y), 5, cv::Scalar(255, 255, 255), 5);
}

void MapHandler::add_car_to_map_zzx()
{

    float detect_dist = 1.5;
    float wanted_angle1 = -3.14159265*120/180;
    float wanted_angle2 = 3.14159265*120/180;
    cv::line(map_cv_zzx, cv::Point(car.pos_x, map_height-car.pos_y), cv::Point(car.pos_x+(detect_dist/ratio)*sin(wanted_angle1+car.angle), map_height-(car.pos_y+(detect_dist/ratio)*cos(wanted_angle1+car.angle))), cv::Scalar(0, 255, 255));
    cv::line(map_cv_zzx, cv::Point(car.pos_x, map_height-car.pos_y), cv::Point(car.pos_x+(detect_dist/ratio)*sin(wanted_angle2+car.angle), map_height-(car.pos_y+(detect_dist/ratio)*cos(wanted_angle2+car.angle))), cv::Scalar(0, 255, 255));
    cv::ellipse(map_cv_zzx, cv::Point(car.pos_x, map_height-car.pos_y), cv::Size((detect_dist/ratio), (detect_dist/ratio)), car.angle/3.14159265*180, 150, 360, cv::Scalar(0, 255, 255));
    cv::ellipse(map_cv_zzx, cv::Point(car.pos_x, map_height-car.pos_y), cv::Size((detect_dist/ratio), (detect_dist/ratio)), car.angle/3.14159265*180, 0, 30, cv::Scalar(0, 255, 255));
    cv::circle(map_cv_zzx, cv::Point(car.pos_x, map_height-car.pos_y), 5, cv::Scalar(255, 255, 255), 5);
    /*
    cv::line(map_cv_zzx, cv::Point(car.pos_x, map_height - car.pos_y), cv::Point(car.pos_x + (2.5 / ratio) * sin(-3.14159265 / 4 + car.angle), map_height - (car.pos_y + (2.5 / ratio) * cos(-3.14159265 / 4 + car.angle))), cv::Scalar(0, 255, 255));
    cv::line(map_cv_zzx, cv::Point(car.pos_x, map_height - car.pos_y), cv::Point(car.pos_x + (2.5 / ratio) * sin(3.14159265 / 4 + car.angle), map_height - (car.pos_y + (2.5 / ratio) * cos(3.14159265 / 4 + car.angle))), cv::Scalar(0, 255, 255));
    cv::ellipse(map_cv_zzx, cv::Point(car.pos_x, map_height - car.pos_y), cv::Size((2.5 / ratio), (2.5 / ratio)), car.angle / 3.14159265 * 180, 225, 315, cv::Scalar(0, 255, 255));
    cv::circle(map_cv_zzx, cv::Point(car.pos_x, map_height - car.pos_y), 5, cv::Scalar(255, 255, 255), 5);
    */
}

void MapHandler::show_map()
{
    cv::imshow("Global Map", map_cv);
}

void MapHandler::show_map_zzx()
{
    cv::imshow("Global Map ZZX", map_cv_zzx);
}

void MapHandler::check_and_save_map()
{
    bool need_save = false;
    bool got_param = ros::param::get("save_map", need_save);
    std::string map_path;
    std::string map_name;
    if (need_save && got_param && !map_cv.empty())
    {
        // ros::param::set("save_map", false);
        bool got_path = ros::param::get("get_map/map_path", map_path);
        bool got_name = ros::param::get("get_map/map_name", map_name);
        if (got_path && got_name)
        {
            std::stringstream ss;
            ss << map_path << map_name;

            bool saved = false;
            saved = cv::imwrite(ss.str(), map_cv);

            ROS_INFO_STREAM("saved:" << saved << "\n"
                                     << "path:" << ss.str());
        }
        else
        {
            ROS_INFO("Did not get parameters");
        }
    }
}

void MapHandler::check_and_save_map_zzx()
{
    bool need_save = false;
    bool got_param = ros::param::get("save_map", need_save);
    std::string map_path;
    std::string map_name;
    if (need_save && got_param && !map_cv_zzx.empty())
    {
        ros::param::set("save_map", false);
        bool got_path = ros::param::get("get_map/map_path", map_path);
        bool got_name = ros::param::get("get_map/map_name_zzx", map_name);
        if (got_path && got_name)
        {
            std::stringstream ss;
            std::stringstream ss_track;
            ss << map_path << map_name;
            ss_track << map_path << "track.png";
            bool saved = false;
            saved = cv::imwrite(ss.str(), map_cv_zzx);
            saved &= cv::imwrite(ss_track.str(), map_track);

            ROS_INFO_STREAM("saved:" << saved << "\n"
                                     << "path:" << ss.str());
        }
        else
        {
            ROS_INFO("Did not get parameters");
        }
    }
}


///////////////////
void MapHandler::check_if_finished_first_round(void)
{
    if(finish_msg.data == false)
    {
        if(car_last.pos_x<car.start_x && car.pos_x>car.start_x && abs(car.pos_y-car.start_y)<50)
        {
            finish_msg.data = true;
            save_map();
        }
    }
    car_last.pos_x = car.pos_x;
    car_last.pos_y = car.pos_y;
    car_last.angle = car.angle;
    pub_finish_msg();
}

void MapHandler::pub_finish_msg(void)
{
    pub_finish.publish(finish_msg);
}

void MapHandler::save_map(void)
{
    std::string map_path;
    std::string map_name;
    if(map_cv.empty() == false)
    {
        bool got_path = ros::param::get("get_map/map_path", map_path);
        bool got_name = ros::param::get("get_map/map_name", map_name);
        if(got_path && got_name)
        {
            std::stringstream ss;
            std::stringstream ss_track;
            ss << map_path << map_name;
            ss_track << map_path << "track.png";
            bool saved = false;
            saved = cv::imwrite(ss.str(), map_cv_zzx);
            saved &= cv::imwrite(ss_track.str(), map_track);

            ROS_INFO_STREAM("saved:" << saved << "\n"
                                     << "path:" << ss.str());
        }
        else
        {
            ROS_INFO("Did not get parameters");
        }
    }
}
////////////////////

