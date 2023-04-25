#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

using namespace cv;

int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "camera_capture");
    ros::NodeHandle nh;

    // 创建图像传输对象
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("camera/image", 1);

    // 打开摄像头
    VideoCapture cap(0);

    // 检查摄像头是否打开成功
    if (!cap.isOpened())
    {
        ROS_ERROR("Failed to open camera.");
        return -1;
    }

    // 循环读取并发布摄像头捕获的图像
    Mat frame;
    sensor_msgs::ImagePtr msg;
    ros::Rate loop_rate(30); // 30Hz的发布频率
    int index = 1;
    while (nh.ok())
    {
        // 读取摄像头捕获的图像
        cap >> frame;

        // 将OpenCV图像格式转换为ROS图像格式
        msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

        // 发布ROS图像消息
        pub.publish(msg);

        // 显示图像
        imshow("Capture_Paizhao", frame);

        // 如果按下s键，保存当前帧的图像
        if (waitKey(1) == 's')
        {
            imwrite("/home/szf/Autonomous-Vehicle/catkin_ws_autonomous_vehicle/datasets/book_yolo/images/" + std::to_string(index) + ".jpg", frame);
            ROS_INFO_STREAM("Save image " << index << " successfully!");
            index++;
        }

        // 控制发布频率
        loop_rate.sleep();
    }

    // 释放摄像头
    cap.release();

    // 关闭窗口
    destroyAllWindows();

    return 0;
}
