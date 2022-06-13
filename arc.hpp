#pragma once
#include <math.h>
#include <vector>
// #include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <generateEllipseCandidate.h>

class Arc {
    // private:
    public:
    // memeber
    int flag; // other words, name. If not assigned, flag == -1.
    cv::Size2i sourceSize; // Size of source image.
    cv::Mat mat;
    // double arg[5];
    cv::RotatedRect box;
    public:
    // member
    std::vector<cv::Point2i> points;


    // function
    Arc (int); // construct with name
    int getFlag() const noexcept;
    void setFlag(int);
    cv::Size2i getSourceSize() const noexcept;
    void setSourceSize(cv::Size2i &&);
    cv::Point2i & operator[](int i){
       return points[i];
    } // [] reference
    // generate Matrix format
    void genMat();
    void genMatonSrc(const cv::Mat &);
    // visualize the arc
    void estimateArg();
};