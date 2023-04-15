#include <iostream>
#include <vector>
#include <string>
#include <std_msgs/Bool.h>
#include "second_circle_pathplanning/Astar.h"
#include "second_circle_pathplanning/map.h"
#include "second_circle_pathplanning/display.h"
#include "second_circle_pathplanning/My_txt.h"
#include "second_circle_pathplanning/SecondStart.h"
#include <ros/ros.h>

int xStart = 50;
int yStart = 40;                       //起点
int xStop = 50;
int yStop = 35;                        //终点
string imagePath;	  //图片路径
string mapPath ;      //地图路径
string framePath ;    //规划路径坐标路径
float weightA = 0.1;                  //权重a
float weightB = 1;                  //权重b
int Astar_count = 0 ;


void Second_planning(std_msgs::Bool Secondstart){

	if(Secondstart.data == true && Astar_count == 0)
	{
		ROS_INFO("Begin Second_planning");
		// 把图片转换成为txt文本然后读取地图信息
		Img2txt(imagePath,mapPath);
		vector<vector<int>> mapData(MapData_My(mapPath,xStart,yStart,xStop,yStop));
		
		//A星算法路径寻找函数
		ASTAR::CAstar astar(mapData, xStart, yStart, xStop, yStop, weightA, weightB,ASTAR::CAstar::PathType::NOFINDPATHPOINT,ASTAR::CAstar::DistanceType::EUCLIDEAN);	
		std::vector<std::pair<int, int> >astarPath = astar.PathPoint();

		if (astar.m_noPathFlag == ASTAR::CAstar::PathType::NOFINDPATHPOINT)
		{
			std::cout << "A星算法没能找到路径!!!" << std::endl;
		}
		else
		{
			//把路径坐标转换成为txt文本信息输出
			PathFrametxt(astarPath,framePath);
			// for (int i = 0; i < astarPath.size(); i++)
			// {
			// 	std::cout << astarPath[i].first << "," << astarPath[i].second << std::endl;
			// }
			Display(astarPath, mapData, xStart, yStart, xStop, yStop, "Astar", true);
		}
		Astar_count = Astar_count+1;
	}
	return ;
}

int main(int argc, char *argv[])
{
	ros::init(argc,argv,"second_circle_pathplanning");
	ros::NodeHandle nh;

	ros::param::get("/second_pathplanning/xStart",xStart);
	ros::param::get("/second_pathplanning/yStart",yStart);
	ros::param::get("/second_pathplanning/xStop",xStop);
	ros::param::get("/second_pathplanning/yStop",yStop);
	ros::param::get("/second_pathplanning/imagePath",imagePath);
	ros::param::get("/second_pathplanning/mapPath",mapPath);
	ros::param::get("/second_pathplanning/AstarframePath",framePath);
	ros::param::get("/second_pathplanning/weightA",weightA);
	ros::param::get("/second_pathplanning/weightB",weightB);

	// ros::Subscriber sub = nh.subscribe("Second_Start",1,Second_planning);
	
	ros::Subscriber sub = nh.subscribe("map_finished",1,Second_planning);

	ros::spin();
	return 0 ;
}