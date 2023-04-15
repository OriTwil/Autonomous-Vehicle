#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include "ros/ros.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "car_msgs/DetectFinal.h"
#include "car_msgs/LidarDetect.h"
#include "car_msgs/car_location.h"
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <visualization_msgs/Marker.h>
//////////////////////
#include "std_msgs/Bool.h"

// using namespace message_filters;
// typedef message_filters::sync_policies::ApproximateTime<car_msgs::LidarDetect,car_msgs::car_location> SyncPolicy;

class Car
{
    public:
        Car();
        float start_x;
        float start_y;
        float start_angle;
        float pos_x;
        float pos_y;
        float vel_x;
        float vel_y;
        float angle;
};

class MapHandler
{
    public:
        MapHandler(int map_h, int map_w);
        void callback_cone_zzx(const car_msgs::LidarDetect::ConstPtr& msg);
        void callback_cone(const car_msgs::DetectFinal::ConstPtr& msg);
        void callback_move(const car_msgs::car_location::ConstPtr& msg);
        void get_cone_zzx(const car_msgs::LidarDetect::ConstPtr& msg);
        void get_cone(const car_msgs::DetectFinal::ConstPtr& msg);
        void vector_to_mat_zzx();
        void vector_to_mat();
        void add_car_to_map_zzx();
        void add_car_to_map();
        void show_map_zzx();
        void show_map();
        void check_and_save_map_zzx();
        void check_and_save_map();
        /////////////////////////////
        void check_if_finished_first_round(void);
        void pub_finish_msg(void);
        void save_map(void);
        void visualizeSetPoints(int ,int);
        /////////////////////////////
        //void DetectCallback(const car_msgs::LidarDetect::ConstPtr& msg_cone, const car_msgs::car_location::ConstPtr &msg_move);

    private:
        ros::Subscriber sub_cone;
        ros::Subscriber sub_move;
        // message_filters::Subscriber<car_msgs::LidarDetect> *sub_cone;   // topic1 
        // message_filters::Subscriber<car_msgs::car_location> *sub_move; // topic2 
        ros::Subscriber sub_cone_color;
        ros::NodeHandle nh;
        std::vector<std::vector<std::vector<uint8_t>>> map_meta;
        cv::Mat map_cv;
        std::vector<std::vector<std::vector<uint8_t>>> map_meta_zzx;
        cv::Mat map_cv_zzx;
        cv::Mat map_track;
        int map_height;
        int map_width;
        Car car;
        Car car_past;
        ////////////
        Car car_last;
        ros::Publisher pub_finish;
        std_msgs::Bool finish_msg;
        ros::Publisher setpoint_pub;
        ////////////
        float ratio;
};

#endif // MAP_HANDLER_H
