#include "detect_barrel.hpp"

using namespace std;
using namespace cv;
#define DISTANCE_THRESHOLD 0.25
bool Detect_barrel::init()
{
    // Homography_matrix_ = homo_mat_;
    return true;
}

void Detect_barrel::Projection(const Vec3d lidar_tf_, Vec3d &yolo_tf_)
{
    Mat lidar_(3, 1, CV_64F);
    Mat camera_(3, 1, CV_64F);
    lidar_.at<double>(0, 0) = lidar_tf_[0];
    lidar_.at<double>(1, 0) = lidar_tf_[1];
    lidar_.at<double>(2, 0) = lidar_tf_[2];
    camera_ = this->Homography_matrix_ * lidar_;
    yolo_tf_[0] = camera_.at<double>(0, 0);
    yolo_tf_[1] = camera_.at<double>(1, 0);
    yolo_tf_[2] = camera_.at<double>(2, 0);
    cout << "yolo_tf_ = " << yolo_tf_ << endl;
}

bool compareDistance(Rect2d p1, Rect2d p2)
{
    return (p1.width < p2.width);
}

void Detect_barrel::load_camera_params(const std::vector<double> intrinsics,
                                       const std::vector<double> extrinsics,
                                       const std::vector<double> distances,
                                       const std::vector<double> heights)
{
}

void Detect_barrel::match_barrel(int method)
{
    std::vector<cv::Rect2d> temp;
    if (method == 1)
    {
        cout << "method1!!!" << endl;
        // location_estimation(barrels_);
        for (int i = 0; i < barrels_camera_.size(); i++)
        {
            for (int j = 0; j < barrels_lidar_.size(); j++)
            {
                double distance_x = pow(barrels_camera_[i].XYZ_body.x - barrels_lidar_[j].XYZ_lidar.x, 2);
                double distance_y = pow(barrels_camera_[i].XYZ_body.y - barrels_lidar_[j].XYZ_lidar.y, 2);
                double color = double(barrels_camera_[i].color);
                // cout << "=====================================" << endl;
                cv::Rect2d bar(i, j, distance_x + distance_y, color);
                if (distance_x + distance_y < DISTANCE_THRESHOLD)
                {
                    temp.push_back(bar);
                }
            }
            // cout << "i:" << i << barrels_camera_[i].XYZ_body << endl;
            // cout << "i:" << i << barrels_lidar_[i].XYZ_lidar << endl;
        }
        std::vector<int> is, js;
        if (temp.size() > 0)
        {
            // cout << "111" << endl;
            sort(temp.begin(), temp.end(), compareDistance);
            for (int p = 0; p < temp.size(); p++)
            {
                // cout << "Sorted:" << temp[p] << endl;
                int i = temp[p].x;
                int j = temp[p].y;
                if (std::count(is.begin(), is.end(), i) || std::count(js.begin(), js.end(), j))
                {
                    continue;
                }
                if (is.size() >= 4 || js.size() >= 4)
                {
                    break;
                }
                is.push_back(i);
                js.push_back(j);
                // barrels_camera_[i].XYZ_body.x = barrels_lidar_[j].XYZ_lidar.x;
                // barrels_camera_[i].XYZ_body.y = barrels_lidar_[j].XYZ_lidar.y;
                barrels_lidar_[j].color = barrels_camera_[i].color;
                // barrels_camera_[i].color = temp[p].height;
            }
        }
        // cout << "112" << endl;
        Mat src(800, 600, CV_8UC3, Scalar(255, 255, 255));
        int car_x = 400;
        int car_y = 300;
        rectangle(src, cv::Point2d(car_x - 17, car_y - 15), cv::Point2d(car_x + 17, car_y + 30), Scalar(0, 255, 0));
        for (int i = 0; i < barrels_lidar_.size(); i++)
        {
            int x_around = barrels_lidar_[i].XYZ_lidar.x * 100 + 400;
            int y_around = -barrels_lidar_[i].XYZ_lidar.y * 100 + 300;

            if (barrels_lidar_[i].color == 0)
            {
                circle(src, cv::Point(x_around, y_around), 10, Scalar(255, 0, 0), -1);
            }
            else if (barrels_lidar_[i].color == 1)
            {
                circle(src, cv::Point(x_around, y_around), 10, Scalar(0, 0, 255), -1);
            }
            else
            {
                circle(src, cv::Point(x_around, y_around), 10, Scalar(0, 0, 0), -1);
            }
        }

        //cv::imshow("around", src);
        //cv::waitKey(1);
        car_msgs::DetectFinal final_result_;
        for (int i = 0; i < 8; i++)
        {
            // cout << "113" << endl;
            final_result_.barrels_x[i] = 0;
            final_result_.barrels_y[i] = 0;
            final_result_.barrels_z[i] = 1;
            final_result_.color[i] = 2;
        }
        for (int i = 0; i < barrels_lidar_.size(); i++)
        {
            // cout << "114" << endl;
            final_result_.barrels_x[i] = barrels_lidar_[i].XYZ_lidar.x;
            final_result_.barrels_y[i] = barrels_lidar_[i].XYZ_lidar.y;
            final_result_.barrels_z[i] = 1;
            final_result_.color[i] = barrels_lidar_[i].color;
        }
        detect_pub_.publish(final_result_);
        is.clear();
        js.clear();
    }
    // else
    // {
    //     vector<Vec3d> lidar_projections;
    //     for (int i = 0; i < barrels_.size(); i++)
    //     {
    //         Vec3d barriel_lidar;
    //         Vec3d barriel_yolo;
    //         barriel_lidar[0] = barrels_[i].XYZ_lidar.x;
    //         barriel_lidar[1] = barrels_[i].XYZ_lidar.y;
    //         barriel_lidar[2] = barrels_[i].XYZ_lidar.z;
    //         Projection(barriel_lidar, barriel_yolo);
    //         lidar_projections.push_back(barriel_yolo);
    //     }
    //     if (lidar_projections.size())
    //     {
    //         for (int p = 0; p < lidar_projections.size(); p++)
    //         {
    //             for (int q = 0; q < barrels_.size(); q++)
    //             {
    //                 cout << "Projection:" << lidar_projections[p] << endl;
    //                 cout << "Detection:" << barrels_[q].XYZ_camera << endl;
    //             }
    //         }
    //     }
    // }
}

void Detect_barrel::DetectCallback(const car_msgs::YoloDetect::ConstPtr &yolo_msg, const car_msgs::LidarDetect::ConstPtr &lidar_msg)
{
    cout << "-------data_in--------" << endl;
    double fx = intrinsic_cvs_.at<double>(0, 0);
    for (int i = 0; i < 4; i++)
    {
        if ((yolo_msg->width[i] != 0 || yolo_msg->height[i] != 0))

        {
            Barrel barrel;
            barrel.self_rect.x = yolo_msg->left[i];
            barrel.self_rect.y = yolo_msg->top[i];
            barrel.self_rect.width = yolo_msg->width[i];
            barrel.self_rect.height = yolo_msg->height[i];
            barrel.color = yolo_msg->ID[i];
            barrel.XYZ_lidar.x = 0;
            barrel.XYZ_lidar.y = 0;
            barrel.XYZ_lidar.z = 0;
            barrels_camera_.push_back(barrel);
        }
        else
            break;
    }
    for (int i = 0; i < 8; i++)
    {
        if ((lidar_msg->x[i] != 0 || lidar_msg->y[i] != 0))
        {
            Barrel barrel;
            barrel.self_rect.x = 0;
            barrel.self_rect.y = 0;
            barrel.self_rect.width = 0;
            barrel.self_rect.height = 0;
            barrel.color = 2;
            barrel.XYZ_lidar.x = lidar_msg->x[i];
            barrel.XYZ_lidar.y = lidar_msg->y[i];
            barrel.XYZ_lidar.z = lidar_msg->z[i];
            barrels_lidar_.push_back(barrel);
        }
        else
            break;
    }
    cout << "-------data_in_over--------" << endl;
    location_estimation();
    // cout<<"--------------------"<<endl;
    // cout<<"size:"<<barrels_.size()<<endl;
    // for(int i=0; i<barrels_.size(); i++){
    //     //cout<<"Detection:"<<barrels_[i].XYZ_body<<endl;
    //     cout<<"Detection:"<<barrels_[i].XYZ_camera<<endl;
    //     }
    // cout<<"--------------------"<<endl;
    // barrels_.clear();
    if (barrels_lidar_.size() > 0)
    {
        int method = 1;
        match_barrel(method);
    }
    // show_around();
    barrels_camera_.clear();
    barrels_lidar_.clear();
}

double linear_inter(const std::vector<double> X_Arr, const std::vector<double> Y_Arr, const int length, const double x)
{
    int j;
    double y = 0;
    // cout<<"x:"<<x<<endl;
    if (x <= X_Arr[0])
    {
        y = Y_Arr[0];
        return y;
    }
    else if (x >= X_Arr[length - 1])
    {
        y = Y_Arr[length - 1];
        return y;
    }
    else
    {
        for (j = 1; j < length; j++)
        {
            if (x <= X_Arr[j])
            {
                j--;
                break;
            }
        }
    }

    y = Y_Arr[j] * ((x - X_Arr[j + 1]) / (X_Arr[j] - X_Arr[j + 1])) + Y_Arr[j + 1] * ((x - X_Arr[j]) / (X_Arr[j + 1] - X_Arr[j]));
    // cout<<"y:"<<y<<endl;
    return y;
}

void Detect_barrel::location_estimation()
{

    double fx = intrinsic_cvs_.at<double>(0, 0);
    double fy = intrinsic_cvs_.at<double>(1, 1);
    double cx = intrinsic_cvs_.at<double>(0, 2);
    double cy = intrinsic_cvs_.at<double>(1, 2);
    ROS_INFO_STREAM("Location estimation");
    for (int i = 0; i < barrels_camera_.size(); ++i)
    {
        double center_u = barrels_camera_[i].self_rect.x + barrels_camera_[i].self_rect.width / 2;
        double center_v = barrels_camera_[i].self_rect.y + barrels_camera_[i].self_rect.height / 2;
        // cout << "x:" << center_u << endl;
        // cout << "y:" << center_v - 0.15 * barrels_[i].self_rect.height << endl;
        if (center_u < 220 || center_u > 420)
        {
            barrels_camera_[i].XYZ_camera.z = linear_inter(_heights2, _distances2, _heights2.size(), barrels_camera_[i].self_rect.height);
        }
        else{
            barrels_camera_[i].XYZ_camera.z = linear_inter(_heights1, _distances1, _heights1.size(), barrels_camera_[i].self_rect.height);
        }
        barrels_camera_[i].XYZ_camera.x = (center_u - cx) * barrels_camera_[i].XYZ_camera.z / fx;
        barrels_camera_[i].XYZ_camera.y = (center_v - cy) * barrels_camera_[i].XYZ_camera.z / fy;

        Eigen::Vector3d P_camera;
        P_camera << barrels_camera_[i].XYZ_camera.x, barrels_camera_[i].XYZ_camera.y, barrels_camera_[i].XYZ_camera.z;
        Eigen::Matrix3d Rbc_cam = extrinsic_cvs_cam_.topLeftCorner(3, 3).inverse();
        Eigen::Vector3d tbc_cam = extrinsic_cvs_cam_.topRightCorner(3, 1);
        Eigen::Vector3d P_body = Rbc_cam * P_camera - tbc_cam;
        barrels_camera_[i].XYZ_body.x = P_body[0];
        barrels_camera_[i].XYZ_body.y = P_body[2];
        barrels_camera_[i].XYZ_body.z = 0;

        Eigen::Vector3d P_lidar;
        P_lidar << barrels_lidar_[i].XYZ_lidar.x, barrels_lidar_[i].XYZ_lidar.y, barrels_lidar_[i].XYZ_lidar.z;
        Eigen::Matrix3d Rbc_lidar = extrinsic_cvs_lidar_.topLeftCorner(3, 3).inverse();
        Eigen::Vector3d tbc_lidar = extrinsic_cvs_lidar_.topRightCorner(3, 1);
        Eigen::Vector3d P_lidar_ = Rbc_lidar * P_lidar - tbc_lidar;
        barrels_lidar_[i].XYZ_lidar.x = P_lidar_[0];
        barrels_lidar_[i].XYZ_lidar.y = P_lidar_[1];
        barrels_lidar_[i].XYZ_lidar.z = 0;
        cout << "lidar:" << barrels_lidar_[i].XYZ_lidar << endl;
    }
    ROS_INFO_STREAM("Location estimation finished!");
}

// void Detect_barrel::show_around()
// {
//     Mat src(800, 600, CV_8UC3, Scalar(255, 255, 255));
//     int car_x = 400;
//     int car_y = 300;
//     rectangle(src, cv::Point2d(car_x - 17, car_y - 15), cv::Point2d(car_x + 17, car_y + 30), Scalar(0, 255, 0));

//     for (int i = 0; i < barrels_.size(); i++)
//     {
//         int x_around = barrels_[i].XYZ_body.x * 100 + 400;
//         int y_around = -barrels_[i].XYZ_body.y * 100 + 300;

//         if (barrels_[i].color == 0)
//         {
//             circle(src, cv::Point(x_around, y_around), 10, Scalar(255, 0, 0), -1);
//         }
//         else if (barrels_[i].color == 1)
//         {
//             circle(src, cv::Point(x_around, y_around), 10, Scalar(0, 0, 255), -1);
//         }
//     }
//     cv::imshow("around", src);
//     cv::waitKey(1);
// }

