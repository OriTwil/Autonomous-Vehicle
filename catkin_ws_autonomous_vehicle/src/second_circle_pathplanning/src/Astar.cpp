#include "second_circle_pathplanning/Astar.h"
#include <functional>
#include <math.h>

std::function<float(int,int,int,int)> Distance;

//欧式距离值：根号√((x2-x1)^2+(y2-y1)^2)
float EuclideanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget)
{
	float d = sqrt(pow(_xNode - _xTarget, 2) + pow(_yNode - _yTarget, 2));
	return d;
}

//曼哈顿距离：|(x2-x1)+(y2-y1)|
float ManhattanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget)
{
	float d = std::abs(_xNode - _xTarget) + std::abs(_yNode - _yTarget);
	return d;
}

ASTAR::CAstar::CAstar(std::vector<std::vector<int>>_mapData,  //地图数据，以二维数据存储
			          int _xStart,                               //起始点X值
			          int _yStart,                               //起始点Y值
			          int _xStop,                                //目标点X值
			          int _yStop,                                //目标点Y值
			          float _weightA,                            //权重a值
			          float _weightB,                            //权重b值
			          PathType _noPathFlag,                      //路径是否生成标志)
			          DistanceType _distanceType                //距离类型
		) :m_mapData(_mapData), m_xStart(_xStart), m_yStart(_yStart), m_xStop(_xStop), m_yStop(_yStop), m_noPathFlag(_noPathFlag), m_weightA(_weightA), m_weightB(_weightB)
{
    switch (_distanceType)
    {
    case ASTAR::CAstar::EUCLIDEAN:
        {
            // std::cout << "使用欧式距离！！！" << std::endl;
            Distance = EuclideanDistance;
            break;
        }
    case ASTAR::CAstar::MANHANTTAN:
        {
            // std::cout << "使用曼哈顿距离！！！" << std::endl;
            Distance = ManhattanDistance;
            break;
        }
    default:
        break;
    }
}


//向openlist插入新的节点
ASTAR::Node ASTAR::CAstar::InsertOpen(int _xVal, int _yVal, int _parentXval, int _parentYval, float _hn, float _gn, float _fn)
{
    Node node;
    node.SnodeX   = _xVal;
    node.SnodeY   = _yVal;
    node.SparentX = _parentXval;
    node.SparentY = _parentYval;
    node.Shn      = _hn;
    node.Sgn      = _gn;
    node.Sfn      = _fn;
    return node;
}

std::vector<ASTAR::Node> ASTAR::CAstar::ExpandArray(int _xNodeExpanded, int _yNodeExpanded, float _gNodeExpanded, int _xTarget, int _yTarget,
                                                    std::vector<std::vector<int>> _mapData, std::vector<Node>_closeList)
{
    int mapHeight = _mapData.size();
    int mapWidth  = _mapData[1].size();
    Node node;
    std::vector<Node> nodeList;
    bool expandFlag = false;
    for(int k = 1; k >= -1; k--)
    {
        for(int j = 1; j >= -1; j--)
        {
            if(k != j || j != 0)
            {
                int sx = _xNodeExpanded + k;
				int sy = _yNodeExpanded + j;
				if ((sx >= 0 && sx < mapHeight) && (sy >= 0 && sy < mapWidth) && _mapData[sx][sy] != 1)
				{
					expandFlag = true;
					for (int i = 0; i < _closeList.size(); i++)
					{
						if (sx == _closeList[i].SnodeX && sy == _closeList[i].SnodeY)
						{
							expandFlag = false;
							break;
						}
					}
					if (expandFlag == true)
					{
						node.SnodeX = sx;
						node.SnodeY = sy;
						node.SparentX = _xNodeExpanded;     
						node.SparentY = _yNodeExpanded;     
						node.Sgn = (_gNodeExpanded + EuclideanDistance(_xNodeExpanded, _yNodeExpanded, sx, sy));
						node.Shn = (Distance(_xTarget, _yTarget, sx, sy));
						node.Sfn = m_weightA*node.Sgn + m_weightB*node.Shn;
						nodeList.emplace_back(node);//直接在容器的尾部创建对象
					}
				}
            }
        }
    }
    return nodeList;
}

//用于查询在openlist里面有没有这个节点，有的话就输出key -1.0表示没找到
float ASTAR::CAstar::NodeIndex(std::multimap<float, Node> _openList, int _xNode, int _yNode)
{
	for (std::multimap<float, Node>::iterator it = _openList.begin(); it != _openList.end(); it++)
	{
		if (it->second.SnodeX == _xNode && it->second.SnodeY == _yNode)
		{
			return it->first;
		}
	}
	return -1.0;
}
//用于查询在closelist里节点的下标查找，-1表示没找到
int ASTAR::CAstar::CloseNodeIndex(std::vector<Node> _closeList, int _xNode, int _yNode)
{
	for (int i = 0; i < _closeList.size(); i++)
	{
		if (_closeList[i].SnodeX == _xNode &&  _closeList[i].SnodeY == _yNode)
		{
			return i;
		}
	}
	return -1;
}

void ASTAR::CAstar::AstarCoreFunction()
{
    float goalDistance = EuclideanDistance(m_xStart,m_yStart,m_xStop,m_yStop);
    float pathCost = 0.0;
    float f_ = m_weightA * goalDistance + m_weightB * pathCost;
    //把初始点加入list里面
    Node node = InsertOpen(m_xStart , m_yStart, m_xStart, m_yStart, goalDistance, pathCost, f_);
    m_openList.insert(std::make_pair(goalDistance,node));
    while (true)
	{
		//对应伪代码-->if the queue(openList) is empty, return False; break; 
		if (m_openList.size() == 0)
			break;

		//对应伪代码-->Remove the node "n" with the lowest f(n) from the priority queue.
		std::multimap<float, Node>::iterator pos = m_openList.begin();   //multimap键值默认是从小到大排布
		int xNodeExpanded = pos->second.SnodeX;
		int yNodeExpanded = pos->second.SnodeY;
		float gNodeExpanded = pos->second.Sgn;

		// 对应伪代码-->Mark node "n" as expanded
		Node closeNode = pos->second;
		m_closeList.emplace_back(closeNode);
		m_openList.erase(pos);

		//对应伪代码-->if the node "n" is the goal state, return TRUE; break; 
		if (xNodeExpanded == m_xStop && yNodeExpanded == m_yStop)
		{
			m_noPathFlag = FINDPATHPOINT;
			break;
		}
		//获得所有节点n的所有“可用”邻居集合
		std::vector<Node> nodeList = ExpandArray(xNodeExpanded, yNodeExpanded, gNodeExpanded, m_xStop, m_yStop, m_mapData, m_closeList);
		for (int i = 0; i < nodeList.size(); i++)
		{
			int xNode = nodeList[i].SnodeX;
			int yNode = nodeList[i].SnodeY;
			float nodeIndex = NodeIndex(m_openList, xNode, yNode);
			if (nodeIndex == -1.0)
			{
			    //对应伪代码-->If node m is not in openList, push node m into openList 
				float gn = gNodeExpanded + EuclideanDistance(xNode, yNode, xNodeExpanded, yNodeExpanded);
				float hn = Distance(xNode, yNode, m_xStop, m_yStop);
				float fn = m_weightA*gn+ m_weightB*hn;

				Node node_ = InsertOpen(xNode, yNode, xNodeExpanded, yNodeExpanded, hn, gn, fn);
				m_openList.insert(std::make_pair(fn, node_));
			}
			else
			{
				//对应伪代码-->If g(m)>g(n)+Cnm
				//lower_bound返回查找结果第一个迭代器,upper_bound返回最后一个查找结果的下一个位置的迭代器
				std::multimap<float, Node>::iterator indexLow = m_openList.lower_bound(nodeIndex);
				std::multimap<float, Node>::iterator indexUpper = m_openList.upper_bound(nodeIndex);
				indexUpper--;
				if (indexLow == indexUpper)
				{
					//表示没有重复的键值
					if (indexLow->second.Sgn > (gNodeExpanded + EuclideanDistance(xNode, yNode, xNodeExpanded, yNodeExpanded)))
					{
						indexLow->second.SparentX = xNodeExpanded;
						indexLow->second.SparentY = yNodeExpanded;
						indexLow->second.Sgn = gNodeExpanded + EuclideanDistance(xNode, yNode, xNodeExpanded, yNodeExpanded);
						indexLow->second.Sfn =  m_weightA*indexLow->second.Sgn + m_weightB*indexLow->second.Shn;
					}
				}
				else
				{
					//表示有重复的键值
					while (indexLow != indexUpper)
					{
						if (indexLow->second.SnodeX == xNode && indexLow->second.SnodeY == yNode)
							break;
						indexLow++;
					}

					if (indexLow->second.Sfn > (gNodeExpanded + EuclideanDistance(xNode, yNode, xNodeExpanded, yNodeExpanded)))
					{
						indexLow->second.SparentX = xNodeExpanded;
						indexLow->second.SparentY = yNodeExpanded;
						indexLow->second.Sgn = gNodeExpanded + EuclideanDistance(xNode, yNode, xNodeExpanded, yNodeExpanded);
						indexLow->second.Sfn = m_weightA*indexLow->second.Sgn + m_weightB*indexLow->second.Shn;
					}
				}

			}
        }
    }
    
}

std::vector<std::pair<int, int>> ASTAR::CAstar::FindPath(std::vector<Node>_closeList, int _xStart, int _yStart, int _xStop, int _yStop)
{
	std::pair<int, int>path;
	std::vector<std::pair<int, int> >findPath;
	path.first = _xStop;
	path.second = _yStop;
	findPath.emplace_back(path);
	int index = CloseNodeIndex(_closeList, _xStop, _yStop);

	while (true)
	{
		if (_closeList[index].SparentX == _xStart && _closeList[index].SparentY == _yStart)
		{
			break;
		}
		int nodeX = _closeList[index].SparentX;
		int nodeY = _closeList[index].SparentY;

		path.first = nodeX;
		path.second = nodeY;
		findPath.emplace_back(path);

		index = CloseNodeIndex(_closeList, nodeX, nodeY);
	}
	return findPath;
}


/***
 *@函数功能   对外的A星算法的接口
 ------------------------------------------------
 *@参数       无
 ------------------------------------------------
 *@返回值     路径节点 类型[(first,second),(),()...]
 */
std::vector<std::pair<int, int>> ASTAR::CAstar::PathPoint()
{
	// std::cout<<"Begin to find Path!"<<std::endl;
	//AstarCoreFunction完善openList与closeList
	AstarCoreFunction();
	//FindPath通过closeList进行寻找路径点
	std::vector<std::pair<int, int> > pathPoint = FindPath(m_closeList, m_xStart, m_yStart, m_xStop, m_yStop);
	return pathPoint;
}
