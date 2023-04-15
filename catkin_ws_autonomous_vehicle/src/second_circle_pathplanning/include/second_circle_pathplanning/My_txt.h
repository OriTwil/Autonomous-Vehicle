#pragma once
#ifndef _MY_TXT_
#define _MY_TXT_

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <fstream>
#include <ros/ros.h>

// #define scaleW  0.1 // 定义新图像的大小，宽度缩小到10%
// #define scaleH  0.1  //定义新图像的大小，高度缩小到10%

using namespace std;

void Img2txt(std::string _imagePath, std::string _mapPath);
void PathFrametxt(vector<pair<int,int>> _pathPoint,std::string _framePath);
void CombinePath(std::string Astar_framePath,std::string Record_framePath,std::string Save_framePath); 
std::vector<std::pair<double, double> >TestReadtxt(std::string _txtPath);

#endif
