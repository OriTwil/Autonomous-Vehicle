#pragma once
#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#define My_Size 20
#define Menu My_Size/2
#define Width 1600
#define Height 1200

using namespace std;
void Display(vector<pair<int,int>> _pathPoint, vector<vector<int>> _mapData, int _xStart, int _yStart, int _xStop, int _yStop,string _pictureName,bool _saveFlag);

#endif