#include <iostream>
#include "geometry_msgs/Point.h"
#include "car_msgs/car_location.h"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"

using namespace std;
using namespace geometry_msgs;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Test");
	ros::NodeHandle n;
	double x,  y, z;
        car_msgs::car_location location;
	Point point;
	
	int recv;
	Twist twist;
	twist.linear.x = 1500;
	twist.angular.z = 90;
	ROS_INFO("ROS GETS STARTED\n");
	ros::Publisher location_pub = n.advertise<car_msgs::car_location>("location", 50);
	ros::Publisher point_pub = n.advertise<Point>("points_m", 50);
	ros::Publisher twist_pub = n.advertise<Twist>("car/cmd_vel", 50);
	while(1)
	{
		cout << "0:退出 1:输入当前位置 2:输入目标点 3:急停 4:舵机角度调试 5:急停2.0 " << endl;
		cin >> recv ;
		
		if(recv == 1)
		{
			cout << "输入x坐标：" ;
			cin >> x ;
			cout << "输入y坐标：" ;
			cin >> y ;
			cout << "输入z坐标：" ;
			cin >> z ;
			location.x = x;
			location.y = y;
			location.z = z;
			location_pub.publish(location);
			cout << "输入成功！" << endl;
			continue;
		}
		else if (recv == 2)
		{
			cout << "输入x坐标：" ;
			cin >> x ;
			cout << "输入y坐标：" ;
			cin >> y ;
			cout << "输入z坐标：" ;
			cin >> z ;
			point.x = x;
			point.y = y;
			point.z = z;
			point_pub.publish(point);
			cout << "输入成功！" << endl;
			continue;
		}
		else if (recv == 3)
		{
			location.x = 300;
			location.y = 0;
			location.z = 0;
			location_pub.publish(location);
		}
		else if (recv == 4)
		{
			cout << "0:退出 1:加一度 2：减一度 4：加10度 5：减10度" << endl;
			while(1)
			{
				cin >> recv ;
				switch(recv)
				{
					case 1: twist.angular.z += 1;
						break;
					case 2: twist.angular.z -= 1;
						break;
					case 4: twist.angular.z += 10;
						break;
					case 5: twist.angular.z -= 10;
						break;
					default:break;
				}
				cout << "当前角度：" << twist.angular.z << endl;
				twist_pub.publish(twist);
				if (recv == 0) break;
			}
			
			
		}
		else if (recv == 5)
		{
			twist_pub.publish(twist);
			
			
		}
		else if (recv == 0) break;
	}
    return 0;
}

