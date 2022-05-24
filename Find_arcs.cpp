/**
 * @Author: Your name
 * @Date:   2021-11-22 14:55:36
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-05-24 11:38:51
 */
#include "Find_arcs.hpp"



Arc::Arc(int _flag)
{
    this->flag = _flag;
}

int Arc::getFlag() const noexcept
{
    return flag;
}

void Arc::setFlag( int _flag )
{
    this->flag = _flag;
}

cv::Size2i Arc::getSourceSize() const noexcept
{
    return sourceSize;
}

void Arc::setSourceSize(cv::Size2i && size)
{
    sourceSize = size;
}

 cv::Mat Arc::genMat() const noexcept
 {
     cv::Mat val(sourceSize, CV_8UC1);
     for (int i = 0; i < points.size(); i++)
     {
         val.at<uchar>(points[i].x,points[i].y) = (uchar) 255;
     }
     cv::imwrite("arc"+to_string(flag)+".jpg", val);
    //  waitKey(0);
     return val;
 }

void Arc::view()
{
    
}

void Arc_set::append(Arc&& arc)
{
    // data.insert(data.end(),arc);
    data.push_back(arc);
}

int Arc_set::size()
{
    return data.size();
}


void Arc_set::generateArcSet(const cv::Mat &src /*source file image*/)
{
    ArcGen arcGenerater;
    auto output = arcGenerater.getGroups(src);
    cout << "group size: " << output->group.size() << endl;
    // int n = 0;
    for (int i = 0; i < output->group.size(); i++)
    {
        // cout << i << ": " << endl;
        append(Arc(i));
        data[i].setSourceSize(Size2i(src.cols,src.rows));
        for (int j = 0; j < output->group[i].size(); j++)
        {
            for (int k = 0; k < output->arcpoints[output->group[i][j]].size(); k++)
            {
                data[i].points.push_back(output->arcpoints[output->group[i][j]][k]);
            }
            
            // data[i].points.push_back(output->arcpoints[output->group[i][j]]);
            // cout << output->arcpoints[output->group[i][j]] << endl;
        }
        // cout << endl;
    }
    // cout << "变了" << endl;
}

void Arc_set::arcGroupView(int n)
{

}