#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include "car_msgs/car_location.h"
#include "nav_msgs/Path.h"
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

#define WIDTH 1200.0
#define HEIGHT 600.0

const double start_x = WIDTH / 2.0;
const double start_y = HEIGHT / 12.0;
const double zoom = WIDTH / 40.0;

ros::Subscriber pose_subscriber;

using namespace cv;
using namespace std;

double num_points;
Mat IMG(HEIGHT, WIDTH, CV_8UC3, Scalar(0, 0, 0));
geometry_msgs::Vector3 msg_rev;
bool received = 0;
vector<double> x, y;
int count_m;
geometry_msgs::Vector3 msg_past;

void PathReceive(nav_msgs::Path path)
{
	if(received == 1) return;
    	num_points = 0;
	for(int i = 0; i < path.poses.size(); i++)
	{
		x.push_back(path.poses[i].pose.position.x);
		y.push_back(path.poses[i].pose.position.y);
		num_points++;
	}
	cout << "reveive success!" << endl;
    for(int i = 0; i < num_points - 1; i++)
		line(IMG, cv::Point((zoom * x[i] + WIDTH / 2.0), (HEIGHT - start_y - zoom * y[i])), cv::Point((zoom * x[i+1] + WIDTH / 2.0), (HEIGHT - start_y - zoom * y[i+1])), Scalar(0, 0, 255), 2, 8, 0);
    imshow("Track",IMG);
	waitKey(1000);
	received = 1;
	return;
}

void MsgCallback(const car_msgs::car_location::ConstPtr& msg)
{
	
    if (msg->x <= -WIDTH / ( 2.0 * zoom )) msg_rev.x = 0;
    else if (msg->x >= WIDTH / ( 2.0 * zoom )) msg_rev.x = WIDTH;
    else msg_rev.x = zoom * msg->x + WIDTH / 2.0;

    //if(count_m % 5 != 0) count_m++;
    //else{count_m++;cout<< "counted " << count_m/5 << endl;}
    //if(count_m > 100) count_m=0;

    if (HEIGHT - start_y - zoom * msg->y <= 0 ) msg_rev.y = 0;
    else if (HEIGHT - start_y - zoom * msg->y >= HEIGHT) msg_rev.y = HEIGHT;
    else msg_rev.y = HEIGHT - start_y - zoom * msg->y ;
   
    if (msg_rev != msg_past)
      {
	   line(IMG, Point((int)msg_rev.x, (int)msg_rev.y), Point((int)msg_past.x, (int)msg_past.y), Scalar(0, 255, 0), 2, 8, 0);
	   msg_past = msg_rev;
	   
	   imshow("Track",IMG);
	   waitKey(100);
 	}
	
    
    return;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "track");
    ros::NodeHandle n;
    msg_rev.x = start_x;
    msg_rev.y = start_y;
    msg_rev.z = 0;
    msg_past.x = start_x;
    msg_past.y = HEIGHT - start_y;
    msg_past.z = 0;
    count_m=0;
    
        
	//ros::param::get("/points/x", a);
	//ros::param::get("/points/y", b);
	//ros::param::get("/points/num", num_points);
	
	ROS_INFO("ROS GETS STARTED\n");
	pose_subscriber = n.subscribe("/location", 50, MsgCallback);
	ros::Subscriber path_subscriber = n.subscribe("/trajopt/init_traj", 10, PathReceive);
	waitKey(5);
	ros::spin();

    
    return 0;
}
