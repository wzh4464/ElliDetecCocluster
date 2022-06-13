/**
 * @Author: WU Zihan
 * @Date:   2022-05-24 15:50:45
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-05-24 19:42:48
 */
#include "arc.hpp"

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

void Arc::genMat()
{
    cv::Mat val(sourceSize, CV_8UC1, Scalar(0));
    std::cout << "mat.size: " << val.size << std::endl;
    for (int i = 0; i < points.size(); i++)
    {
        val.at<uchar>(points[i].y,points[i].x) = (uchar) 255;
    }
    cv::imwrite("pics/arc"+to_string(flag)+".jpg", val);
    mat = std::move(val);
}

void Arc::genMatonSrc(const cv::Mat & src)
{
    cv::Mat val=src.clone();
    std::cout << "mat.size: " << val.size << std::endl;
    for (int i = 0; i < points.size(); i++)
    {
        val.at<uchar>(points[i]) = (uchar) 255;
    }
    cv::imwrite("pics/arc"+to_string(flag)+".jpg", val);
    mat = std::move(val);
}

void Arc::estimateArg()
{
    box = cv::fitEllipseAMS(points);
    // box.
    cv::ellipse(mat, box, cv::Scalar(0), 5);
    imwrite("pics/elli"+to_string(flag)+".jpg", mat);
    // cv::Mat F(points.size(), 5, CV_32F );
    // cv::Mat G(points.size(), 1, CV_32F , cv::Scalar(-1));
    // for (int i = 0; i < points.size(); i++)
    // {
    //     F.at<float>(i, 0) = points[i].x * points[i].x;
    //     F.at<float>(i, 1) = points[i].x * points[i].y;
    //     F.at<float>(i, 2) = points[i].y * points[i].y;
    //     F.at<float>(i, 3) = points[i].x;
    //     F.at<float>(i, 4) = points[i].y;
    // }
    // cv::Mat ans;
    // cv::solve(F,G,ans,cv::DECOMP_SVD);
    // std::cout << flag << std::endl << ans << std::endl;
    
}