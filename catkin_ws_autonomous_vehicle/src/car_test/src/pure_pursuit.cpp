#include "ros/ros.h"
#include "car_msgs/car_location.h"
#include "car_msgs/YoloDetect.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Point.h"
#include "nav_msgs/Path.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"
#include <cmath>
#include <iostream>

#define M 30
#define SPEED 1700

using namespace geometry_msgs;
using namespace std;
const double dist_wheels = 0.33;
double speed = 1650;
double base_speed = 1650, max_speed = 150;
const double pi_m = acos(0)*2.0;
ros::Publisher angle_pub;
int num_points, point_now, goal_num = 0, reg = 0;
bool able = 0, started = 0;
double K_z = 1.2, pre_time = 0.01;

vector<double> x;
vector<double> y;




double attain_dist(Point const& p1, Point const& p2)
{

	return sqrt((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
}


void PathReceive(nav_msgs::Path path)
{
	if (started == 1) return;
	for(int i = 0; i < path.poses.size(); i++)
	{
		x.push_back(path.poses[i].pose.position.x);
		y.push_back(path.poses[i].pose.position.y);
		num_points++;
	}
	started = 1;
	cout << "reveive success!" << endl;
	cout<< x.size() <<endl;
	cout << y.size() << endl;
	cout << "num_points =" << num_points << endl;
	able = 1;
	
	return;
}


void DetectReceive(car_msgs::YoloDetect msg)
{
	if (msg.width[0]*msg.height[0] > 20000 || reg != 0) reg++;
	if (reg >= 3) able = 0;
	return;
	
}

Point get_goal_points(double goal_distance, Point p_now)
{
	Point output, point_temp;
	//cout << "In get_goal_points" << endl;
	//????????????
	point_temp.x = x[point_now];
	point_temp.y = y[point_now];
	output = point_temp;
	int j=0;
	for (int i = point_now + 1; i < num_points && j <= 5; i++)
	{
		point_temp.x = x[i];
		point_temp.y = y[i];
		if(attain_dist(p_now, point_temp) <= attain_dist(p_now, output))
		{
			point_now = i;
			output = point_temp;
		}
		else j++;
	}

	double distan = 0;
	
	Point point_temp_2;
	point_temp_2.x = x[point_now];
	point_temp_2.y = y[point_now];
	if(point_now >= num_points - 1) return output;
	int i;j=0;
	for (i = point_now + 1; i < num_points && j <= 5; i++ )
	{
		point_temp.x = x[i];
		point_temp.y = y[i];
		if((attain_dist(point_temp_2, point_temp) - goal_distance ) * (attain_dist(point_temp_2, point_temp) - goal_distance )<= (distan - goal_distance) * (distan - goal_distance))
		{
			output = point_temp;
			distan = attain_dist(point_temp_2, point_temp);
		}
		else j++;
	}
	cout << "goal_point = is:" << i << endl ;
	return output;
}

double get_result_angle(double current_x, double current_y, double current_angle, Point goal_point)
{
	Point pos_now;
	pos_now.x = current_x;
	pos_now.y = current_y;
	double dist_m = attain_dist(pos_now, goal_point);
	double angle_line, angle_between, output = pi_m / 2;
	
	angle_line = atan2(goal_point.y - current_y, goal_point.x - current_x);

	if (angle_line - current_angle >= pi_m)
	{
		angle_line -= 2 * pi_m;
	}
	else if (current_angle - angle_line >= pi_m)
	{
		angle_line += 2 * pi_m;
	}

	angle_between = angle_line - current_angle;
	
	//cout << "angle_between is:" << angle_between << endl;
	//speed = (speed * double(goal_num) + base_speed + 50.0 + max_speed * (1.0 - 0.5 * sqrt(angle_between * angle_between) / pi_m) )/ double(goal_num + 1);
	//cout << "speed is:" << speed - base_speed << endl;
	goal_num++;
	
	if(angle_between > pi_m / 2) output = 180;
	else if (angle_between <= -pi_m / 2) output = 0;
	else output = 90.0 + 180.0 * atan(2.0 * dist_wheels * sin(angle_between) / dist_m) / pi_m; 

	
	return output;
}

void MsgCallback(car_msgs::car_location msg)
{
	if (started == 0) return;
	
	
	
	msg.x = msg.x + pre_time * cos(msg.z) * 1.5 * (speed - base_speed) / (max_speed + 50.0) ;
	msg.y = msg.y + pre_time * sin(msg.z) * 1.5 * (speed - base_speed) / (max_speed + 50.0) ;
	
	
	double result_angle;
	double goal_distance_1 = 0.7;
	double goal_distance_2 = 1.3;
	ros::param::get("/first_pathplanning/goal_distance_1",goal_distance_1);
	ros::param::get("/first_pathplanning/goal_distance_2",goal_distance_2);
	
	speed = 0;
	goal_num = 0;
	
	Point point_msg, point_n;
	Twist twist;
	if(msg.x >= 100 || able == 0 || (point_now >= num_points - 1 && point_now != 0))
    	{
    		twist.linear.x = 1500;
    		twist.angular.z = 90;
    		cout << "stopped!  " << able << endl; 
    		able = 0;
    		
    		angle_pub.publish(twist);
    		return;
    	}
    	
	
	
	
	goal_num = 0;
	
	point_msg.x = msg.x;
	point_msg.y = msg.y;
	Point goal_point_1 = get_goal_points(goal_distance_1, point_msg);
	Point goal_point_2 = get_goal_points(goal_distance_2, point_msg);
	
	double result_angle_1 = get_result_angle(msg.x, msg.y, msg.z, goal_point_1);
	double result_angle_2 = get_result_angle(msg.x, msg.y, msg.z, goal_point_2);
	
	point_n.x = x[point_now];
	point_n.y = y[point_now];
	
	
		
	if ((result_angle_1 - 90.0) * (result_angle_1 - 90.0) < (result_angle_2 - 90.0) * (result_angle_2 - 90.0)) result_angle_2 = result_angle_1;
	
	//speed = base_speed + max_speed*abs((1.0-1.0*abs(atan(90-result_angle_2)) / pi_m));
	speed = base_speed + max_speed;
	twist.linear.x = speed;
	
    	twist.angular.z = 90 - (K_z * (90.0 - result_angle_2));

		if(twist.angular.z > 180){twist.angular.z = 180; twist.linear.x = base_speed + max_speed*abs((1.0-1.0*abs(atan((result_angle_2 - 180.0) / 2.0)) / pi_m));}
		if(twist.angular.z < 0) {twist.angular.z = 0; twist.linear.x = base_speed + max_speed*abs((1.0-1.0*abs(atan(result_angle_2 / 2.0)) / pi_m));}

		
    	
    	cout << "point_now = is:" << point_now << "  " << point_msg << endl ;
    	cout << "result_angle is:" << twist.angular.z << endl << endl;
    	
    	angle_pub.publish(twist);
    	return;
}

int main(int argc, char **argv)
{
	
	
	speed = SPEED;
	ros::init(argc, argv, "pure_pursuit");
	ros::NodeHandle n;
	num_points = 0;
	ros::param::get("/first_pathplanning/K_z",K_z);
	ros::param::get("/first_pathplanning/pre_time", pre_time);
        point_now = 0;
        ros::param::get("/first_pathplanning/speed_m",max_speed);
	
        
	ROS_INFO("ROS GETS STARTED\n");
	ros::Subscriber pose_subscriber = n.subscribe("/location", 10, MsgCallback);
	ros::Subscriber path_subscriber = n.subscribe("/trajopt/init_traj", 10, PathReceive);
	ros::Subscriber yolo_subscriber = n.subscribe("/detect/yolo_detect", 10, DetectReceive);
	
	angle_pub = n.advertise<Twist>("car/cmd_vel", 50);
	ros::spin();

    
    return 0;
}
