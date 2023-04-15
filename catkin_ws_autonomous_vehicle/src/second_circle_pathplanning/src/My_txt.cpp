#include "second_circle_pathplanning/My_txt.h"

using namespace std;

void Img2txt(std::string _imagePath ,std::string _mapPath)  //把图片转换为txt文本方便路径规划
{
    cv::Mat img,img_src,imageDst,img_gray;
    img_src = cv::imread(_imagePath);

    float scaleW = 0.1;
    float scaleH = 0.1;
    int dilate_kernel_size = 3;
    ros::param::get("/second_pathplanning/dilate_kernel_size",dilate_kernel_size);


    int width = int(img_src.cols * scaleW);
    //定义想要扩大或者缩小后的宽度，src.cols为原图像的宽度，乘以10%则得到想要的大小，并强制转换成int型
    int height = int(img_src.rows * scaleH);
    //定义想要扩大或者缩小后的高度，src.cols为原图像的高度，乘以10%则得到想要的大小，并强制转换成int型
    cv::resize(img_src, img, cv::Size(width, height));//缩放图像

    int channels = img.channels();
    cv::Mat element = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(dilate_kernel_size, dilate_kernel_size));
    cv::dilate(img, imageDst, element);

    if(channels>=2)
    {
        cv::cvtColor(imageDst,img_gray,cv::COLOR_BGR2GRAY);
    }
    else{
        img_gray = imageDst;
    }

    

    ofstream outfile;
    outfile.open(_mapPath);
    for(int i=0 ; i<height; i++)
    {
        for(int j=0 ; j<width; j++)
        {
            int pixel = int(img_gray.at<u_char>(i,j));
            if(pixel==0)
            {
                outfile<<"0"<<" ";
            }
            else{
                outfile<<"1"<<" ";
            }
        }
        if(i != height-1)
        {
            outfile<<endl;
        }
    }
    outfile.close();
    ROS_INFO("-------------FINISH IMG2TXT!----------------");
    return ;
}

void PathFrametxt(vector<pair<int,int> > _pathPoint,std::string _framePath)   //路径规划的路径写成文本
{
    ofstream outfile;
    outfile.open(_framePath);
    int x_zero = 50;
    int y_zero = 57;
    double ratio = 0.3;  
    double x,y;
    for (auto it = _pathPoint.rbegin(); it !=_pathPoint.rend(); ++it)   //反向迭代器
	{
		y = -(it->first - x_zero)*ratio;
        x = (it->second - y_zero)*ratio;
        outfile<<x<<" "<<y<<endl;
	}
    outfile.close();
    ROS_INFO("------------FINISH PATH2TXT!---------------");
    return;
}

void CombinePath(std::string Astar_framePath,std::string Record_framePath,std::string Save_framePath)   //A*路径和记录路径融合
{
    double Combine_ratio;
    ros::param::get("/record_pathplanning/Combine_ratio",Combine_ratio);
    std::vector<std::pair<double, double> > Astar_frame;
    std::vector<std::pair<double, double> > Record_frame;

    std::pair<double, double> frame;
    ifstream in_a(Astar_framePath);
    string line;
	int count=0;

	while (getline(in_a, line)){//读取Astar坐标
		stringstream ss(line);//初始化 法1
		double x;
		while (ss >> x){//每一行包含不同个数的数字
			count++;
			if(count<2)
			{
			    frame.first = x;
			}
			else
			{
                frame.second = x;
                Astar_frame.emplace_back(frame);
                count = 0;
			}
		}
	}
    ifstream in_r(Record_framePath);
    string line_r;
    count=0;
    while (getline(in_r, line_r)){//读取Record坐标
		stringstream ss(line_r);//初始化 法1
		double x;
		while (ss >> x){//每一行包含不同个数的数字
			count++;
			if(count<2)
			{
			    frame.first = x;
			}
			else
			{
                frame.second = x;
                Record_frame.emplace_back(frame);
                count = 0;
			}
		}
	}   
    ofstream outfile;
    outfile.open(Save_framePath);
    unsigned int i = 0;
    double x,y;
    for (unsigned int j = 0; j < Record_frame.size(); j++)   //反向迭代器
	{
        if(abs(Record_frame[j].first-Astar_frame[i].first)<0.5 && abs(Record_frame[j].second-Astar_frame[i].second)<0.5 && i<Astar_frame.size())
        {
            x = Record_frame[j].first*Combine_ratio+Astar_frame[i].first*(1-Combine_ratio);
            y = Record_frame[j].second*Combine_ratio+Astar_frame[i].second*(1-Combine_ratio);
            i = i+1;
        }else
        {
            x = Record_frame[j].first;
            y = Record_frame[j].second;
        }
        outfile<<x<<" "<<y<<endl;
	}
    outfile.close();
    ROS_INFO("------------FINISH COMBINE_PATH!---------------");
    return;
}

std::vector<std::pair<double, double> >TestReadtxt(std::string _txtPath)
{
    ROS_INFO("------------FINISH TestRead!---------------");
    std::pair<double, double> frame;
    std::vector<std::pair<double, double> > total_frame;
	ifstream in(_txtPath);
	string line;
	int count=0;
	while (getline(in, line)){//获取文件的一行字符串到line中
		stringstream ss(line);//初始化 法1
		double x;
		while (ss >> x){//每一行包含不同个数的数字
			count++;
			if(count<2)
			{
			    frame.first = x;
			}
			else
			{
                frame.second = x;
                total_frame.emplace_back(frame);
                count = 0;
			}
		}
	}
    /* for(int i=0;i<total_frame.size();i++)
    {
        cout<<"x"<<total_frame[i].first<<endl;
        cout<<"y"<<total_frame[i].second<<endl;
    }  */
    return total_frame;
}

