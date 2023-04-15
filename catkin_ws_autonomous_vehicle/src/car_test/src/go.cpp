#include "ros/ros.h"

#include "geometry_msgs/Point.h"
#include "geometry_msgs/PoseStamped.h"
#include <cmath>
#include <iostream>
#include "nav_msgs/Path.h"

#define M 30
#define SPEED 1700

using namespace std;



int main(int argc, char **argv)
{
	ros::init(argc, argv, "go");
	ros::NodeHandle n;
	ros::Publisher path_pub = n.advertise<nav_msgs::Path>("trajopt/init_traj", 5,true);
	vector<double> x;
	vector<double> y;
	nav_msgs::Path path;
	geometry_msgs::PoseStamped pose;
	path.header.frame_id = "lidar_link";
	path.header.stamp = ros::Time::now();
	int num;
	ros::param::get("/points/x", x);
	ros::param::get("/points/y", y);
	ros::param::get("/points/num", num);
	for(int i; i<num; i++)
	{
		
		pose.header.stamp = ros::Time::now();
    		pose.header.frame_id = "lidar_link";
		pose.pose.position.x = x[i];
		pose.pose.position.y = y[i];
		pose.pose.position.z = 0;
		
		path.poses.push_back(pose);
	}
    
	ROS_INFO("ROS GETS STARTED\n");
	
	cout << path << endl;
	while (ros::ok()){path_pub.publish(path);}
	
	
    
    return 0;
}
