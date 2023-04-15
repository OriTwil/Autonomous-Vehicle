#pragma once
#ifndef _ASTAR_H
#define _ASTAR_H
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace ASTAR
{

    struct Node
    {
        int SnodeX;      //节点X值
        int SnodeY;      //节点Y值       
        int SparentX;    //父节点X值
        int SparentY;    //父节点Y值
        float Sgn;       //节点g值
        float Shn;       //节点h值
        float Sfn;       //节点f值
    };
    
    class CAstar
    {
    public:
        //路径类型的枚举类型，NOFINDPATHPOINT表示没找到路径点，FINDPATHPOINT找到路径点
        enum PathType {NOFINDPATHPOINT=0,FINDPATHPOINT=1};
        //距离类型 EUCLIDEAN欧式距离，MANHANTTAN曼哈顿距离
		enum DistanceType {EUCLIDEAN=0,MANHANTTAN=1};
		PathType m_noPathFlag;
        
    public:
        /*初始化函数*/
		CAstar(std::vector<std::vector<int>>_mapData,  //地图数据，以二维数据存储
			int _xStart,                               //起始点X值
			int _yStart,                               //起始点Y值
			int _xStop,                                //目标点X值
			int _yStop,                                //目标点Y值
			float _weightA,                            //权重a值
			float _weightB,                            //权重b值
			PathType _noPathFlag,                      //路径是否生成标志)
			DistanceType _distanceType                 //距离类型
		);

        std::vector<std::pair<int,int>> PathPoint();
    private:
        /*两点之间的欧式距离*/
	    //float EuclideanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget); 

        // 向OpenList插入数据
        Node InsertOpen(int _xVal, int _yVal, int _parentXval, int _parentYval, float _hn, float _gn, float _fn);

        //扩展一个节点的八邻点
        std::vector<Node> ExpandArray(int _xNodeExpanded, int _yNodeExpanded, float _gNodeExpanded, int _xTarget, int _yTarget,
                                      std::vector<std::vector<int>> _mapData, std::vector<Node>_closeList);
        
        //得到openList->multimap中的索引
        float NodeIndex(std::multimap<float,Node>_openList, int _xNode, int _yNode);

        //得到closeList->vector中的索引
        int CloseNodeIndex(std::vector<Node> _closeList, int _xNode, int _yNode);

        //Astar的核心函数
        void AstarCoreFunction();

        std::vector<std::pair<int,int>> FindPath(std::vector<Node>_closeList, int _xStart, int _yStart, int _xStop, int _yStop);
    private:
        std::multimap<float, Node> m_openList;
        std::vector<Node> m_closeList;
        std::vector<std::vector<int>> m_mapData;
        float m_weightA;
        float m_weightB;
        int m_xStart;
        int m_yStart;
        int m_xStop;
        int m_yStop;
    };
    
}

#endif