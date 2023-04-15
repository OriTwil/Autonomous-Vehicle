#include "second_circle_pathplanning/map.h"

#include<fstream>
#include<sstream>
#include <vector>


vector<vector<int> >MapData_My(std::string _mapPath,
            int _xStart,                               //起始点X值
			int _yStart,                               //起始点Y值
			int _xStop,                                //目标点X值
			int _yStop                                //目标点Y值
            )
{
	ifstream f;
	f.open(_mapPath);
	string str;
	vector<vector<int> > num;
	while (getline(f, str))      //读取1行并将它赋值给字符串str
	{
		istringstream input(str);   // c++风格的串流的输入操作
		vector<int> tmp;
		int a;
		while (input >> a)          //通过input将第一行的数据一个一个的输入给a
			tmp.push_back(a);
		num.push_back(tmp);
	}
    int m = num.size(),n = num[0].size();
    int xaverage = (_xStart+_xStop)/2;
    int yaverage = (_xStart+_yStop)/2;
    int xdistance = abs(_xStart-_xStop);
    int ydistance = abs(_yStart-_yStop);
    int kernel = 5;
    int lower = _xStart-kernel;
    int upper = _xStart+kernel;
    if(_yStart>_yStop)
    {   
        for(int i = _yStart-1; i>_yStop+1; i--)
        {
            
            for(int j = lower+1; j<upper ; j++)
            {
                if(j<m)
                {
                    num[j][i] = 1; 
                }
            }
        }
    }else
    {   
        for(int i = _yStop-1; i>_yStart+1; i--)
        {
            for(int j = lower+1; j<upper; j++)
            {
                if(j<m)
                {  
                    num[j][i] = 1; 
                }
            }
        }
    }
    // for(int i = 0; i < m; i++)
	// {
    //     for(int j = 0; j < n; j++)
	// 	{
    //         cout<<num[i][j]<<" ";
    // 	}
	// 	cout<<endl;
	// }
	return num;
}
