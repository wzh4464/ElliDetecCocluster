#pragma once
#include <math.h>
#include <vector>
// #include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "Debug.hpp"
#include "generateEllipseCandidate.h"

using namespace cv;
// using namespace std;
class Arc {
    // private:
    public:
    // memeber
    int flag; // other words, name. If not assigned, flag == -1.
    cv::Size2i sourceSize; // Size of source image.
    cv::Mat mat;
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
    cv::Mat genMat() const noexcept;
    // visualize the arc
    void view();
};

class Arc_set {
    private:

    public:
    Arc_set() {};
    Arc_set(Mat& image)
    {
        generateArcSet(image);
    }
    void append(Arc&&);
    int size();
    std::vector <Arc> data;
    
    /**
     * @brief generate all arcs from source image
     * 1. Guass blur 
     * 2. gray
     * 3. caluculate gradient
     * 4. get rotated gradient map
     * 
     */
    void generateArcSet(const cv::Mat &src);

    void arcGroupView(int n);
};

// class 