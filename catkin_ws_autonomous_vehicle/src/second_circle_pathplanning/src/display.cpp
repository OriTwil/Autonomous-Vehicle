#include "second_circle_pathplanning/display.h"
#include <ros/ros.h>

void Display(vector<pair<int, int> >_pathPoint, vector<vector<int>>_mapData,int _xStart,int _yStart,int _xStop,int _yStop,string _pictureName,bool _saveFlag)
{
	int ROWS = _mapData.size();
	int COLS = _mapData[1].size();
	cv::Mat img(Height, Width, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::Point left_up, right_bottom;
	cv::Point point_first, point_second;

    //中间路径点--->黄色
	for (int i = 0; i < _pathPoint.size(); i++)
	{
		left_up.x = _pathPoint[i].second * My_Size;
		left_up.y = _pathPoint[i].first * My_Size;
		right_bottom.x = left_up.x + My_Size;
		right_bottom.y = left_up.y + My_Size;
		cv::rectangle(img, left_up, right_bottom, cv::Scalar(0, 255, 255), -1, 8, 0);//path yellow(full)
	}
	//障碍物--->黑色,起点--->蓝色，终点--->红色
	for (int i = 0; i<ROWS; i++)
	{
		for (int j = 0; j<COLS; j++)
		{
			left_up.x = j * My_Size; //存储数组的列(j)对应矩形的x轴
			left_up.y = i * My_Size;
			right_bottom.x = left_up.x + My_Size;
			right_bottom.y = left_up.y + My_Size;
			if (_mapData[i][j])    //mapData里面障碍物是 1
			{
				cv::rectangle(img, left_up, right_bottom, cv::Scalar(0, 0, 0), -1, 8, 0);//obstacles balck
			}
			else
			{
				if (i == _xStart&&j == _yStart)
					cv::rectangle(img, left_up, right_bottom, cv::Scalar(255, 0, 0), -1, 8, 0);//start point blue(full)
				else if (i == _xStop&&j == _yStop)
					cv::rectangle(img, left_up, right_bottom, cv::Scalar(0, 0, 255), -1, 8, 0);//goal point red(full)
			}

		}
	}
	//中间线--->黄色
	for (int i = 1; i < COLS; i++)
	{
		point_first.x = i * My_Size;
		point_first.y = 1 * My_Size;
		point_second.x = i *My_Size;
		point_second.y = (ROWS - 1) * My_Size;
		cv::line(img, point_first, point_second, cv::Scalar(141,238,238), 2, 2);
	}
	for (int i = 1; i < ROWS;i++)
	{
		point_first.x = 1 * My_Size;
		point_first.y = i * My_Size;
		point_second.x = (COLS - 1) * My_Size;
		point_second.y = i * My_Size;
		cv::line(img, point_first, point_second, cv::Scalar(141,238,238), 2, 2);
	}
	//路径线--->黄色
	point_first.x = _yStop * My_Size + Menu;
	point_first.y = _xStop * My_Size + Menu;
	for (int i = 0; i < _pathPoint.size(); i++)
	{
		left_up.x = _pathPoint[i].second * My_Size;
		left_up.y = _pathPoint[i].first * My_Size;
		point_second.x = left_up.x + Menu;
		point_second.y = left_up.y + Menu;
		cv::line(img, point_first, point_second, cv::Scalar(0, 0, 0), 2, 4);
		point_first = point_second;
	}
	if (_saveFlag)
	{
		std::string save_imagePath;
		ros::param::get("/second_pathplanning/save_imagePath",save_imagePath);
		cv::imwrite(save_imagePath, img);
		cout << "save png success" << endl;
	}
	cv::imshow("Astar", img);
	cv::waitKey(0);
}