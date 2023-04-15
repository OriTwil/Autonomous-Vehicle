#include "ros/ros.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "MapHandler.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "map_handler");
    ros::NodeHandle node;
    
    // parameters
    node.setParam("save_map", false);
    int map_width;
    int map_height;

    // get parameters from ros::NodeHandle
    node.param<int>("get_map/map_height", map_height, 500);
    node.param<int>("get_map/map_width", map_width, 700);

    MapHandler map(map_height, map_width);
    ROS_INFO("Start Map!");
    while(node.ok())
    {
        ros::spinOnce();
        cv::waitKey(50);
    }
    return 0;
}
