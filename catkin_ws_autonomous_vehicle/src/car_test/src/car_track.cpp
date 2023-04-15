#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

#define WIDTH 1200.0
#define HEIGHT 600.0

const double start_x = WIDTH / 2.0;
const double start_y = HEIGHT / 12.0;
const double zoom = WIDTH / 20.0;

ros::Subscriber pose_subscriber;




using namespace cv;
using namespace std;

Mat IMG(HEIGHT, WIDTH, CV_8UC1, Scalar(255));
int count;
geometry_msgs::Vector3 msg_rev;

geometry_msgs::Vector3 msg_past;

void MsgCallback(const geometry_msgs::Vector3::ConstPtr& msg)
{
    if (msg->x <= -WIDTH / ( 2.0 * zoom )) msg_rev.x = 0;
    else if (msg->x >= WIDTH / ( 2.0 * zoom )) msg_rev.x = WIDTH;
    else msg_rev.x = zoom * msg->x + WIDTH / 2.0;
    
    if(count % 5 != 0) count++;
    else{count++;cout<< "counted " << count/5 << endl;}
    if(count > 100) count=0;

    if (HEIGHT / 2 - start_y - zoom * msg->y <= 0 ) msg_rev.y = 0;
    else if (HEIGHT / 2 - start_y - zoom * msg->y >= HEIGHT) msg_rev.y = HEIGHT;
    else msg_rev.y = HEIGHT / 2.0 - start_y - zoom * msg->y ;
   
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
    ros::init(argc, argv, "receiver");
    ros::NodeHandle n;
    msg_rev.x = start_x;
    msg_rev.y = start_y;
    msg_rev.z = 0;
    msg_past.x = start_x;
    msg_past.y = HEIGHT - start_y;
    msg_past.z = 0;
    count=0;
    
        vector<double> a, b;
	ros::param::get("/points/x", a);
	ros::param::get("/points/y", b);
	ros::param::get("/points/num", num_points);
	for(int i = 0; i < num_points - 1; i++)
		line(IMG, cv::Point((int)(zoom * a[i] + WIDTH / 2.0), (int)(HEIGHT - start_y - zoom * b[i])), cv::Point((int)(zoom * a[i+1] + WIDTH / 2.0), (int)(HEIGHT - start_y - zoom * b[i+1])), Scalar(0, 0, 255), 2, 8, 0);
    
	ROS_INFO("ROS GETS STARTED\n");
	pose_subscriber = n.subscribe("/location", 50, MsgCallback);
	
	waitKey(5);
	ros::spin();

    
    return 0;
}
