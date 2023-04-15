#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Path.h"
#include "second_circle_pathplanning/SecondStart.h"
#include "second_circle_pathplanning/My_txt.h"

using namespace std;
ros::Publisher optimiaztion_pub;

void Record_Path(nav_msgs::Path Record_Path)
{
    ofstream outfile;
    string Recordframepath;
    string Astarframepath;
    string Saveframepath;

    ros::param::get("/second_pathplanning/AstarframePath",Astarframepath);
    ros::param::get("/record_pathplanning/RecordframePath",Recordframepath);
    ros::param::get("/record_pathplanning/SaveframePath",Saveframepath);

    outfile.open(Recordframepath);
    double x,y;
    for(uint i=0; i<Record_Path.poses.size(); i++)
    {
        x = Record_Path.poses[i].pose.position.x;
        y = Record_Path.poses[i].pose.position.y;
        outfile<<x<<" "<<y<<endl;
    }
    outfile.close();
    ROS_INFO("------------FINISH RECORD_PATH2TXT!---------------");

    CombinePath(Astarframepath,Recordframepath,Saveframepath);
    
    second_circle_pathplanning::SecondStart Optimization_Flag;
    Optimization_Flag.optimization_flag = true;
    Optimization_Flag.second_flag = false;
    optimiaztion_pub.publish(Optimization_Flag);
    return;
}
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"record_path");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("Second_Path",50,Record_Path);
    optimiaztion_pub = nh.advertise<second_circle_pathplanning::SecondStart>("Optimization_Start",1);
    ros::spin();
}