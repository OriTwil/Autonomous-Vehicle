#pragma once
#ifndef __MAP__
#define __MAP
#include <vector>
#include<iostream>
using namespace std;
vector<vector<int> > MapData(std::string _mapPath);
vector<vector<int> > MapData_My(std::string _mapPath,
            int _xStart,                               //起始点X值
			int _yStart,                               //起始点Y值
			int _xStop,                                //目标点X值
			int _yStop                                 //目标点Y值
            );

#endif
