// #include "detect_barrel.hpp"

#include "detect_barrel.cpp"
#include <ros/ros.h>
#include <csignal>
#include <ros/package.h>
#include <cmath>
#include "cv_bridge/cv_bridge.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <std_msgs/Header.h>




using namespace message_filters;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "detect_barrel");
  ros::NodeHandle ros_nh_;
  ros::Subscriber detect_sub_;
  Detect_barrel *detector = new Detect_barrel(ros_nh_);
  // detector->init();
  std::cout << "------Detector init successfully------" << std::endl;
  // 消息时序同步
  // typedef message_filters::sync_policies::ApproximateTime<car_msgs::YoloDetect, car_msgs::LidarDetect> syncpolicy;
  // message_filters::Subscriber<car_msgs::YoloDetect> camera_sub(ros_nh_, "/detect/yolo_detect", 1);
  // message_filters::Subscriber<car_msgs::LidarDetect> lidar_sub(ros_nh_, "camera_info", 1);
  // TimeSynchronizer<syncpolicy> sync(camera_sub, lidar_sub, 10);
  // sync.registerCallback(boost::bind(&Detect_barrel::DetectCallback, detector, _1, _2));
  // detect_sub_ = ros_nh_.subscribe<car_msgs::YoloDetect>("/detect/yolo_detect", 1, 
  // boost::bind(&Detect_barrel::YoloDetectCallback, detector, _1));
  ros::spin();
  return 0;
}
