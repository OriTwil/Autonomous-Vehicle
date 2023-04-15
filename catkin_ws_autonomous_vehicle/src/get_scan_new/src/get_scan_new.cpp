#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"

class NewScan
{
    public:
        NewScan()
        {
            sub = nh.subscribe("scan", 1000, &NewScan::callback, this);
            pub = nh.advertise<sensor_msgs::LaserScan>("scan_new", 10);
        }
        void callback(const sensor_msgs::LaserScan::ConstPtr &scan)  
        {
            // Get basic information of scan
            unsigned int size = scan->ranges.size();
            std::vector<float> data_r = std::vector<float>(size, 0);
            float angle_now = scan->angle_min;
            // Init scan_new
            scan_new.angle_increment = scan->angle_increment;
            scan_new.header = scan->header;
            scan_new.scan_time = scan->scan_time;
            scan_new.time_increment = scan->time_increment;
            scan_new.range_max = scan->range_max;
            scan_new.range_min = scan->range_min;
            scan_new.ranges.resize(size);
            scan_new.intensities.resize(size);
            // Read raw data
            for(int i=0; i<size; ++i)
            {
                data_r[i] = angle_now;
                angle_now += scan->angle_increment;
            }
            // Change angle x to 2pi-x
            for(int i=0; i<size; ++i)
            {
                data_r[i] = 2*3.14159265 - data_r[i];
            }
            // Change angle range [0, 2pi] to [-pi, pi]
            for(int i=0; i<size; ++i)
            {
                data_r[i] = (data_r[i]>3.14159265)?(data_r[i]-2*3.14159265):data_r[i];
            }
            // Get index of the min element
            unsigned int index_min = min_element(data_r.begin(), data_r.end()) - data_r.begin();
            unsigned int index_max = max_element(data_r.begin(), data_r.end()) - data_r.begin();
            scan_new.angle_min = data_r[index_min];
            scan_new.angle_max = data_r[index_max];
            // Fill data of scan_new
            for(int i=0; i<=index_min; ++i)
            {
                scan_new.ranges[i] = scan->ranges[index_min-i];
                scan_new.intensities[i] = scan->intensities[index_min-i];
            }
            for(int i=index_min+1; i<size; ++i)
            {
                scan_new.ranges[i] = scan->ranges[size+index_min-i];
                scan_new.intensities[i] = scan->intensities[size+index_min-i];
            }
            pub.publish(scan_new);
        }
    private:
        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::Subscriber sub;
        sensor_msgs::LaserScan scan_new;
};


int main(int argc, char** argv)
{
    ros::init(argc, argv, "get_scan_new");
    ros::NodeHandle nh;
    NewScan new_scan;
    ROS_INFO("Start!");
    // ros::Rate rate(10);
    while(nh.ok())
    {
        ros::spinOnce();
        // rate.sleep();
    }
    return 0;
}