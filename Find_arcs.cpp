/**
 * @Author: WU Zihan
 * @Date:   2021-11-22 14:55:36
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-06-14 10:12:46
 */
#include "Find_arcs.hpp"

std::fstream Debug::file("../data/debug.log");

Arc::Arc(int _flag)
{
    this->flag = _flag;
}

Arc::Arc(int _flag, Out *elli_out, const cv::Mat &src)
{
    // save in
    this->flag = _flag;
    this->ring = std::move(*elli_out->arc.end());
    elli_out->arc.pop_back();
    setSourceSize(cv::Size2i(src.cols, src.rows));

    // debug
#ifdef DEBUG
    std::cout << ring.cx << '\t' << ring.cy << '\t' << ring.ax << '\t' << ring.bx << '\t' << ring.theta << std::endl;
    Debug::file << ring.cx << '\t' << ring.cy << '\t' << ring.ax << '\t' << ring.bx << '\t' << ring.theta << std::endl; 
#endif // DEBUG

    // calculate

}

int Arc::getFlag() const noexcept
{
    return flag;
}

void Arc::setFlag(int _flag)
{
    this->flag = _flag;
}

cv::Size2i Arc::getSourceSize() const noexcept
{
    return sourceSize;
}

void Arc::setSourceSize(cv::Size2i &&size)
{
    sourceSize = size;
}

// cv::Mat Arc::genMat() const noexcept
// {
//     cv::Mat val(sourceSize, CV_8UC1, Scalar(0));
//     for (int i = 0; i < points.size(); i++)
//     {
//         val.at<uchar>(points[i].x, points[i].y) = (uchar)255;
//     }
//     cv::imwrite("arc" + to_string(flag) + ".jpg", val);
//     //  waitKey(0);
//     return val;
// }

// void Arc::view()
// {
// }

void Arc_set::append(Arc &&arc)
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
    int num;
    cout << "group size: " << (num = output->arc_num) << endl;
    for (int i = 0; i < num; i++)
    {
        append(Arc(i, output, src));
    }
}
 
// void Arc_set::arcGroupView(int n)
// {
// }