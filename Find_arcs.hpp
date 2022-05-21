#pragma once
#include <math.h>
#include <vector>
// #include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include "Debug.hpp"
#include <generateEllipseCandidate.h>

using namespace cv;
// using namespace std;
class Arc {
    private:
    // memeber
    int flag; // other words, name
    
    public:
    // member
    std::vector<cv::Point2i> points;


    // function
    Arc (int);
    int getFlag();
    void setFlag(int);
    int size();
    cv::Point2i & operator[](int i){
       return points[i];
    } // [] reference
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
    void generateArcSet(cv::Mat &src); // generate all arcs
};

// class 