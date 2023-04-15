#include "ros/ros.h"
#include <dirent.h>
#include <cstring>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <opencv4/opencv2/dnn/dnn.hpp>
#include <opencv4/opencv2/core/eigen.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include "car_msgs/YoloDetect.h"
#include "car_msgs/LidarDetect.h"
#include "car_msgs/DetectFinal.h"
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

using namespace cv;
using namespace std;
using namespace message_filters;
typedef message_filters::sync_policies::ApproximateTime<car_msgs::YoloDetect,
                                                        car_msgs::LidarDetect>
    SyncPolicy;

class Detect_barrel
{
public:
    struct Barrel
    {
        cv::Rect self_rect;
        int color;              
        cv::Point3f XYZ_camera; 
        cv::Point3f XYZ_body;   
        cv::Point3f XYZ_lidar;  

        Barrel()
        {
            color = 0;
            XYZ_camera = {0.0, 0.0, 0.0};
            XYZ_lidar = {0.0, 0.0, 0.0};
            XYZ_body = {0.0, 0.0, 0.0};
        }
    };
    Detect_barrel(ros::NodeHandle &_nh)
    {
        extrinsic_cvs_cam_ <<   1.0000, 0.0000, 0.0000, 0.0000,
                                0.0000, 1.0000, 0.0000, 0.0000,
                                0.0000, 0.0000, 1.0000, 0.0000,
                                0.0000, 0.0000, 0.0000, 1.0000;
        extrinsic_cvs_lidar_ << 1.0000, 0.0000, 0.0000, 0.0000,
                                0.0000, 1.0000, 0.0000, -0.1000,
                                0.0000, 0.0000, 1.0000, 0.0950,
                                0.0000, 0.0000, 0.0000, 1.0000;
        intrinsic_cvs_ = (cv::Mat_<double>(3, 3) <<   411.00201416, 0.000000,   332.47589312,
                                                        0.000000, 409.29006958, 231.51753257,
                                                        0.000000,   0.000000,     1.000000);
        //??
         _distances1 = {2.5, 2.35, 2, 1.7, 1.35, 1.2, 1.05, 0.85, 0.72, 0.54, 0.4, 0.35};
        _heights1 = {107, 118, 133, 150, 190, 207, 245, 296, 349, 372, 410, 445};
        // ??
        _distances2 = {2.5, 2.35, 2, 1.7, 1.35, 1.2, 1.05, 0.85, 0.72, 0.54, 0.4, 0.35};
        _heights2 = {102, 112, 128, 140, 182, 211, 235, 305, 343, 389, 445, 450};
        //_x2 = {140, 138, 137, 137, 137, 140, 135, 131, 137, 150}
        
        
        Homography_matrix_ = (cv::Mat_<double>(3, 3) << 0.0007,-0.000,  0.000,
        						  0.0002,-0.0004,-0.0040,
        						 -0.2804, 0.3923, 1.0000);

        detect_nh_ = _nh;
        lidar_sub_ = new message_filters::Subscriber<car_msgs::LidarDetect>(detect_nh_, "/cones", 1);
        yolo_sub_ = new message_filters::Subscriber<car_msgs::YoloDetect>(detect_nh_, "/detect/yolo_detect", 1);
	cout<<"--------init success------------------"<<endl;
        typedef message_filters::sync_policies::ApproximateTime<car_msgs::YoloDetect, car_msgs::LidarDetect> mysync;
        Synchronizer<mysync> *sync = new Synchronizer<mysync>(mysync(100), *yolo_sub_, *lidar_sub_);
        sync->registerCallback(boost::bind(&Detect_barrel::DetectCallback, this, _1, _2));
        ros::spin();
    };
    ~Detect_barrel(){};
    bool init();
    void Projection(const Vec3d yolo_tf_, Vec3d &lidar_tf_);
    void DetectCallback(const car_msgs::YoloDetect::ConstPtr &cam_msg,
                        const car_msgs::LidarDetect::ConstPtr &lidar_msg);
    void location_estimation();
    void match_barrel(int method);
    void load_camera_params(const std::vector<double> intrinsics,
                            const std::vector<double> extrinsics,
                            const std::vector<double> distances,
                            const std::vector<double> heights);
    void show_around();
    // void find_next_point();

private:
    ros::NodeHandle detect_nh_;
    Mat Homography_matrix_;
    vector<Barrel> barrels_camera_;
    vector<Barrel> barrels_lidar_;
    cv::Mat intrinsic_cvs_;
    Eigen::Matrix4d extrinsic_cvs_cam_;
    Eigen::Matrix4d extrinsic_cvs_lidar_;
    cv::Mat discoff_cvs_;
    std::vector<double> _distances1;
    std::vector<double> _heights1;
    std::vector<double> _distances2;
    std::vector<double> _heights2;
    message_filters::Subscriber<car_msgs::YoloDetect> *yolo_sub_;   // topic1 
    message_filters::Subscriber<car_msgs::LidarDetect> *lidar_sub_; // topic2 
    ros::Publisher detect_pub_ = detect_nh_.advertise<car_msgs::DetectFinal>("/detect/final", 1000);; // topic
};

