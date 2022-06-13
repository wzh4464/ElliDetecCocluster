/**
 * @Author: WU Zihan
 * @Date:   2022-05-24 15:52:19
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-05-24 19:38:34
 */
#include "arc_set.hpp"


void Arc_set::append(Arc&& arc)
{
    // data.insert(data.end(),arc);
    data.push_back(arc);
}

int Arc_set::size()
{
    return data.size();
}


void Arc_set::generateArcSet()
{
    ArcGen arcGenerater;
    auto output = arcGenerater.getGroups(src);
    // ofstream dataset("data.txt");
    // dataset << "outer size: " << output->arcpoints.size();
    // for (int i = 0; i < output->arcpoints.size(); i++)
    // {
    //     append(Arc(i));
    //     data[i].setSourceSize(Size2i(src.cols,src.rows));
    //     data[i].points = output->arcpoints[i];
    //     // dataset << data[i].points << endl;
    // }
    // dataset.close();
    
    cout << "group size: " << output->group.size() << endl;
    // int n = 0;
    for (int i = 0; i < output->group.size(); i++)
    {
        // cout << i << ": " << endl;
        append(Arc(i));
        data[i].setSourceSize(cv::Size2i(src.cols,src.rows));
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

void Arc_set::viewAllArcs()
{
    cv::Mat val = src.clone();
    for (int i = 0; i < size(); i++)
    {
        for (int j = 0; j < data[i].points.size(); j++)
        {
            val.at<uchar>(data[i].points[j]) = (uchar) 255;
        }
        
    }
    cv::imshow("all arc on src", val);
    while (char x=waitKey() != 'q')
    {
        std::cout << x << std::endl;
    }
    
}