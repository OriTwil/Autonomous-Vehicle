#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"

#include <vector>
#include "car_msgs/LidarDetect.h"
#include "car_msgs/car_location.h"
// #include "first_pathplanning/DetectFinal.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Path.h"
#include <math.h>
#include <iostream>

// #define Erose_distance 1.25

double const pi_m = acos(0)*2.0;

ros::Publisher path_pub;
float k_angular = 3.5;
float angle_z = 140;
float speed_x = 150;
double half_distance = 0.55;
double distance_ahead = 1.3;
double dist_wheels = 0.33;
double angle_last = 90, angle_last_last = 90;
double distance_ahead_r = 0.1, half_distance_r = 0.6;
double width = 1.33;
bool able = 1,stopped = 0;

using namespace std;

/*
    angle = 2500.0 - twist.angular.z * 2000.0 / 180.0;
    //ROS_INFO("angle= %d",uint16_t(angle));
    send_cmd(uint16_t(twist.linear.x),uint16_t(angle));
    --------------------------------------------
    angular.z 90中值 左转（逆时针）大于90 右转小于90
    angular.x 1500中值 前进大于1500
*/

void PathReceive(nav_msgs::Path path)
{
	
	stopped = 1;
	
	return;
}

double getDistance(double delta_x, double delta_y)
{
    // ROS_INFO("res:"sqrt(delta_x * delta_x + delta_y * delta_y));
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}
//点跟踪函数
double get_result_angle(double goal_x, double goal_y)
{
	double dist_m = getDistance(goal_x, goal_y);
	double angle_between, output = 90, temp;
	
	angle_between = atan2(goal_y, goal_x);
	
	cout << "angle_between is:" << angle_between << endl;
	//speed = (speed * double(goal_num) + base_speed + 50.0 + max_speed * (1.0 - 2.0 * sqrt(angle_between * angle_between) / pi_m) )/ double(goal_num + 1);
	//cout << "speed is:" << speed - base_speed << endl;
	//goal_num++;
	
	if(angle_between > pi_m) output = 180;
	else if (angle_between <= 0) output = 0;
	else output = 90.0 - k_angular * 180.0 * atan(2.0 * dist_wheels * sin(pi_m / 2.0 - angle_between) / dist_m) / pi_m;

    	if (output >= 180) output = 180;
    	else if (output <= 0) output = 0; 
    	
    	cout << "output is:" << output << endl;
    	temp = output;
    	//output = 0.7 * output + 0.2 * angle_last + 0.1 * angle_last_last;
        
        angle_last_last = angle_last;
        angle_last = temp;
	return output;
}

/*
void drawStraightLine(cv::Mat *img, cv::Point p1, cv::Point p2, cv::Scalar color)
{
    cv::Point p, q;
    if (p1.x != p2.x)
    {
        p.x = 0;
        q.x = img->cols;
        // Slope equation (y1 - y2) / (x1 - x2)
        float m = (p1.y - p2.y) / (p1.x - p2.x);
        // Line equation:  y = mx + b
        float b = p1.y - (m * p1.x);
        p.y = m * p.x + b;
        q.y = m * q.x + b;
    }
    else{
        p.x = q.x = p2.x;
        p.y = 0;
        q.y = img->rows;
    }
    cv::line(*img, p, q, color, 2);
}
*/
//void show_selected_points()
//{
//    Mat src(800, 600, CV_8UC3, Scalar(255, 255, 255));
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
/*
void Display(float min_left_x,float min_left_y,float second_x,float second_y,double a,double b,double c, double c_p)
{
    // cv::Mat ImgDisplay = cv::Mat::zeros(300,300,cv::CV_8UC3);
    cv::Mat ImgDisplay = cv::Mat::zeros(600,600,CV_8UC3);

    drawStraightLine(&ImgDisplay, cv::Point(300,300), cv::Point(300,400),cv::Scalar(255,255,255));
    drawStraightLine(&ImgDisplay, cv::Point(300,300), cv::Point(200,300),cv::Scalar(255,255,255));

	// cv::line(ImgDisplay, p1, p2, colorLine, thicknessLine);
    //对坐标进行转换，把原点取在（300,300）处,同时把比例放大为十倍
    //OpenCV坐标体系中的零点坐标为图片的左上角，X轴为图像矩形的上面那条水平线；Y轴为图像矩形左边的那条垂直线。
    min_left_x = min_left_x*50+300;
    min_left_y = 600-(min_left_y*50+300);
    second_x   = second_x*50+300;
    second_y   = 600-(second_y*50+300);
    
    cv::circle(ImgDisplay,cv::Point(int(min_left_x),int(min_left_y)), 10,cv::Scalar(255,0,255),-1);
    cv::circle(ImgDisplay,cv::Point(int(second_x),int(second_y)), 10,cv::Scalar(255,0,255),-1);


    std::cout<<min_left_x<<" "<<min_left_y<<" "<<second_x<<" "<<second_y<<std::endl;
    drawStraightLine(&ImgDisplay, cv::Point(int(min_left_x),int(min_left_y)), cv::Point(int(second_x),int(second_y)),cv::Scalar(255,0,0));

    //对 ax+by+c=0 和 ax+by+c_p=0 方程进行绘制;
    double x0,y0,x1,y1;

    x0 = -c/a;   //y=0时候的x0
    x1 = -c_p/a;
    y0 = -c/b;   //x=0时候的y0
    y1 = -c_p/b;

    x0 = x0*50+300;
    x1 = x1*50+300;
    y0 = 600-(y0*50+300);
    y1 = 600-(y1*50+300);
    std::cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<std::endl;

    drawStraightLine(&ImgDisplay, cv::Point(int(x0),300), cv::Point(300,int(y0)),cv::Scalar(0,255,0));
    drawStraightLine(&ImgDisplay, cv::Point(int(x1),300), cv::Point(300,int(y1)),cv::Scalar(0,0,255));

    cv::imshow("Path",ImgDisplay);
    cv::waitKey(5);
}
*/

void MsgCallback(car_msgs::car_location msg)
{
	if(msg.x >= 100)
    	{
    		able = 0;
    	}
    	return;
}


void pathplanning_first(const car_msgs::LidarDetect obstacles){
    geometry_msgs::Twist twist;
    
    if(stopped == 1) return;
    
    if(able == 0)
    {
    	twist.linear.x = 1500;
    	twist.angular.z = 90;
    	path_pub.publish(twist);
    	return;
    }
    ROS_INFO("ROS GETS STARTED\n");
    
    float base_speed = 1650;
    twist.linear.x =  speed_x + base_speed;

    float left_point_x[8],left_point_y[8],left_point_distance[8];
    float delta_x,delta_y,delta_x_p2p,delta_y_p2p;
    int   left_num = 0;
    
    double a,b,c, c_p;
    float min_distance = 0, min_distance_p2p = 0, min_distance_p3p = 2;
    int   min_left_num=0, min_p2p = 0, min_p3p = 0;

    // 遍历所有点并且储存离车最近的左点，并且记录该点对应的下标
    for(int i=0; i<8; i++)
    {
        
        if(obstacles.x[i]<0 && (getDistance(obstacles.x[i],obstacles.y[i])< min_distance || min_distance == 0))
        {
            min_distance = getDistance(obstacles.x[i],obstacles.y[i]);
            min_left_num = i;
        }
    }
    ROS_INFO("101");
    // cout<<
    getDistance(obstacles.x[min_left_num], obstacles.y[min_left_num]);
    ROS_INFO("111");

    if (getDistance(obstacles.x[min_left_num], obstacles.y[min_left_num]) < 0.15)
    {
    	cout << "stop!" << endl;
    	speed_x = -150;
    	twist.linear.x = 1500;
    	twist.angular.z = 90;
    	path_pub.publish(twist);  
        return;
    }
    
    
    //如果找不到最近的左点，就直接旋转
    if (min_distance == 0 || getDistance(obstacles.x[min_left_num], obstacles.y[min_left_num]) > 1.33)
    {
        //twist.angular.z = 0.4 * angle_z + 0.3 * angle_last + 0.3 * angle_last_last;
		ROS_INFO("2222");
        for(int i=0; i<8; i++)
	    {
		if(obstacles.x[i]!=0 )
		{
		    cout << obstacles.x[i] << "  " << obstacles.y[i] << endl;
		}
	    }
        twist.angular.z = angle_z;
        path_pub.publish(twist);
        
        angle_last_last = angle_last;
        angle_last = angle_z;        
        return;
    }
    
    // 遍历所有点，同时计算点间距离，找到二近点，并且记录该点对应的下标
    for(int j=0; j<8; j++)
    {
        ROS_INFO("333");
        if(j != min_left_num && obstacles.y[j] > obstacles.y[min_left_num] && obstacles.y[j] > 0)
        {
            if(getDistance(obstacles.x[j] - obstacles.x[min_left_num], obstacles.y[j] - obstacles.y[min_left_num]) < min_distance_p2p || min_distance_p2p == 0)
            {
                min_p2p = j;
                min_distance_p2p = getDistance(obstacles.x[j] - obstacles.x[min_left_num], obstacles.y[j] - obstacles.y[min_left_num]);
            }
        }
    }
    //未找到次邻点的情况
    if(min_distance_p2p == 0 || min_distance_p2p >= width || atan2(obstacles.y[min_p2p]-obstacles.y[min_left_num],obstacles.y[min_p2p]-obstacles.y[min_left_num]) > pi_m * 0.75)
    {
        cout << "NOT FOUND" << endl;
        if (distance_ahead_r >= obstacles.y[min_left_num] + half_distance_r)
        {
            delta_x = obstacles.x[min_left_num] ;
            twist.angular.z = get_result_angle(delta_x, obstacles.y[min_left_num] + half_distance_r);
        }
        else{
            delta_x = obstacles.x[min_left_num] + sqrt(half_distance * half_distance_r - pow(obstacles.y[min_left_num] - distance_ahead_r, 2));
            twist.angular.z = get_result_angle(delta_x, distance_ahead_r);
        }
        
        path_pub.publish(twist);
        return;
    }

    for(int j=0; j<8; j++)
    {
        if(j != min_left_num && j != min_p2p && obstacles.y[j] > 0 && obstacles.y[j] > obstacles.y[min_p2p] && min_distance_p2p <= width)
        {
            if(getDistance(obstacles.x[j] - obstacles.x[min_p2p], obstacles.y[j] - obstacles.y[min_p2p]) < min_distance_p3p || min_distance_p3p == 0 )
            {
                min_p3p = j;
                min_distance_p3p = getDistance(obstacles.x[j] - obstacles.x[min_p2p], obstacles.y[j] - obstacles.y[min_p2p]);
            }
        }
    }
    
    a = atan2(obstacles.y[min_p3p]-obstacles.y[min_p2p],obstacles.x[min_p3p]-obstacles.x[min_p2p]);
    b = atan2(obstacles.y[min_p2p]-obstacles.y[min_left_num],obstacles.x[min_p2p]-obstacles.x[min_left_num]);
    
    if (a < -pi_m / 2.0) a += 2.0 * pi_m;
    if (b < -pi_m / 2.0) b += 2.0 * pi_m;
    
    if(min_distance_p3p == 0 || min_distance_p3p >= width )
    {
        ;
    }else if(a - b> 7.0 * pi_m/18.0)
    {
        min_left_num = min_p2p;
        if (distance_ahead_r >= obstacles.y[min_left_num] + half_distance_r)
        {
            delta_x = obstacles.x[min_left_num] ;
            twist.angular.z = get_result_angle(delta_x, obstacles.y[min_left_num] + half_distance_r);
        }
        else{
            delta_x = obstacles.x[min_left_num] + sqrt(half_distance * half_distance_r - pow(obstacles.y[min_left_num] - distance_ahead_r, 2));
            twist.angular.z = get_result_angle(delta_x, distance_ahead_r);
        }
        
        path_pub.publish(twist);
        return;
    }else
    {
        cout << "111" << endl;
        //min_left_num = min_p2p;
        //min_p2p = min_p3p;
    }
    
    
    
    
    //cout << obstacles.x[min_left_num] << "  " << obstacles.y[min_left_num] << endl;
    //cout << obstacles.x[min_p2p] << "  " << obstacles.y[min_p2p] << endl;
    
    a = obstacles.y[min_p2p] - obstacles.y[min_left_num];
    b = obstacles.x[min_left_num] - obstacles.x[min_p2p];
    c = (obstacles.x[min_p2p] * obstacles.y[min_left_num] - obstacles.x[min_left_num] * obstacles.y[min_p2p]);
    
    //cout << "xishu: " << a << "  " << b << "  " << c << endl;
    
    c_p = c - half_distance * getDistance(a, b);
    
    //cout << "c_p:" << c_p << endl;
    
    if  (obstacles.x[min_p2p] - obstacles.x[min_left_num] == 0) twist.angular.z = get_result_angle(obstacles.x[min_p2p], obstacles.y[min_p2p]);
    
    if (a * b > 0) delta_x = - distance_ahead / 2.0 - c_p/a;
    else delta_x = distance_ahead / 2.0 - c_p/a;
    
    cout << "delta_xx: " << delta_x  << " "  << a << " " << b << " " << c_p << " " << c << endl;
    
    if (delta_x >  0 && a * b > 0 ) delta_x = -distance_ahead / 2.0;
    if (delta_x <  0 && a * b < 0) delta_x = -distance_ahead / 2.0;
    
    
    delta_y = -( a * delta_x + c_p) / b;
    if (delta_y <0) delta_y = -delta_y;
    
    if (delta_y > distance_ahead) 
    {
        if (a != 0) delta_x =  -( b * distance_ahead + c_p) / a;
        else delta_x = obstacles.x[min_left_num] - obstacles.x[min_p2p];
    
        
    
        twist.angular.z = get_result_angle(delta_x, distance_ahead);
    }
    else twist.angular.z = get_result_angle(delta_x, delta_y);
    std::cout << "delta_x:" << delta_x << std::endl ;
    cout << "delta_y:" << delta_y << endl << endl;
    
        
        
    
    
    //发布速度信息
    path_pub.publish(twist);
    //Display(obstacles.x[min_left_num],obstacles.y[min_left_num],obstacles.x[min_p2p],obstacles.y[min_p2p],a,b,c,c_p);
    return;
}


int main(int argc, char *argv[])
{
    //1.包含头文件;
    ros::init(argc,argv,"pathplanning");
    //2.初始化ROS节点;
    ros::NodeHandle nh;
    
    ROS_INFO("ROS GETS STARTED\n");
    ros::param::get ("/first_pathplanning/k_angular_z",k_angular);
    ros::param::get ("/first_pathplanning/angle_z",angle_z);
    ros::param::get ("/first_pathplanning/speed_x", speed_x);
    ros::param::get ("/first_pathplanning/half_distance", half_distance);
    ros::param::get ("/first_pathplanning/distance_ahead", distance_ahead);
    ros::param::get ("/first_pathplanning/distance_ahead_r", distance_ahead_r);
    ros::param::get ("/first_pathplanning/half_distance_r", half_distance_r);
    ros::param::get ("/first_pathplanning/width", width);
    
    //3.创建节点句柄
    path_pub = nh.advertise<geometry_msgs::Twist>("car/cmd_vel",10);
    ros::Subscriber path_sub = nh.subscribe("cones",10, pathplanning_first);
    ros::Subscriber pose_subscriber = nh.subscribe("/location", 10, MsgCallback);
    ros::Subscriber path_subscriber = nh.subscribe("/trajopt/init_traj", 10, PathReceive);

    
    

    ros::spin();

    return 0;
}
