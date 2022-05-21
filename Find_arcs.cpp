/**
 * @Author: Your name
 * @Date:   2021-11-22 14:55:36
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-05-20 19:07:14
 */
#include "Find_arcs.hpp"



Arc::Arc(int _flag)
{
    this->flag = _flag;
}

int Arc::getFlag()
{
    return flag;
}

void Arc::setFlag( int _flag )
{
    this->flag = _flag;
}

int Arc::size()
{
    return points.size();
}

void Arc_set::append(Arc&& arc)
{
    data.insert(data.end(),arc);
}

int Arc_set::size()
{
    return data.size();
}


void Arc_set::generateArcSet(cv::Mat &src /*source file image*/)
{
    ArcGen arcGenerater;
    auto output = arcGenerater.getGroups(src);
    int n = 0;
    for (int i = 0; i < output->group.size(); i++)
    {
        append(Arc(i));
        for (int j = 0; j < output->group[i].size(); j++)
        {
            data[i].points.push_back(output->arcpoints[output->group[i][j]]);
            // cout << output->group[i][j] << endl;
        }
        // cout << endl;
    }
    // cout << "变了" << endl;
}