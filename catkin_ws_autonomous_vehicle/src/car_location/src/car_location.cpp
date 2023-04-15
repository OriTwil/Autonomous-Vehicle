#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/Path.h"
#include "tf/transform_datatypes.h"
#include "std_msgs/Int8.h"
#include "nav_msgs/Odometry.h"
#include "car_msgs/car_location.h"

ros::Publisher rpy_publisher;
ros::Publisher flag_publisher;
ros::Publisher path_publisher;
ros::Subscriber quat_subscriber;


nav_msgs::Path path_m;

int pos = 0, count_m = 0;
std_msgs::Int8 able;
bool star;

void MsgCallback(const geometry_msgs::PoseWithCovarianceStamped msg)
{
    tf::Quaternion q;
    double roll, pitch, yaw;
    tf::quaternionMsgToTF(msg.pose.pose.orientation, q);
    tf::Matrix3x3(q).getRPY(roll, pitch, yaw);
    
    geometry_msgs::PoseStamped posed;

    car_msgs::car_location rpy;
    rpy.x = msg.pose.pose.position.x;
    rpy.y = msg.pose.pose.position.y;
    rpy.z = yaw;
    
    switch(pos)
    {
    	case 0: if(rpy.x >= 0.5) pos++;
    		break;
    	case 1: if(rpy.x <= -0.5) pos++;
    		break;
    	case 2: if(rpy.x <= -10.5) pos++;
    		break;
    	case 3: if(rpy.x >= -10) {pos++;
            for (int i=-10; i<=0; i++){
            posed.pose.position.x=-(double(i) - 10.0) * rpy.x / 20.0;
            posed.pose.position.y=-(double(i) - 10.0) * rpy.y / 20.0;
            posed.pose.position.z=0;
            path_m.poses.push_back(posed);
        }
    		path_publisher.publish(path_m);}
    		break;
    	case 4:if(rpy.x >= 0.5) pos++;
    		break;
    	case 5: if(rpy.y >= 1) pos++;
    		break;
      case 6: if(rpy.x <= -5) pos++;
    		break;
    }
    
    if(rpy.x > 0.1 || rpy.x < -0.1 || rpy.y > 0.1 || rpy.y < -0.1){
    if(star == 0) { star=1; 
    for (int i=-10; i<=0; i++){
            posed.pose.position.x=(double(i) ) * 10.0 / 20.0;
            posed.pose.position.y= -(double(i) ) * 0.0 / 20.0;;
            posed.pose.position.z=0;
            path_m.poses.push_back(posed);
            }}
    if(count_m < 2) count_m++;
    else{
    	count_m=0;
    	posed.pose.position.x=rpy.x;
    	posed.pose.position.y=rpy.y;
    	posed.pose.position.z=rpy.z;
    	path_m.poses.push_back(posed);
    }
    }
    
    able.data = pos;
    flag_publisher.publish(able);
    
    rpy.header.stamp = ros::Time::now();
    rpy.header.frame_id = "lidar_link";
    //ROS_INFO("published pose location:x = %f y = %f orientation :yaw = %f",rpy.x, rpy.y, yaw);
    rpy_publisher.publish(rpy);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    able.data = 0;
    star = 0;
    rpy_publisher = n.advertise<car_msgs::car_location>("location", 50);
    flag_publisher = n.advertise<std_msgs::Int8>("flag", 50);
    quat_subscriber = n.subscribe("/robot_pose_ekf/odom_combined", 50, MsgCallback);
    path_publisher = n.advertise<nav_msgs::Path>("Second_Path", 50);
    
    
    ros::spin();
    return 0;
}
