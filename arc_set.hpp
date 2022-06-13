#pragma once
#include <math.h>
#include <vector>
// #include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <generateEllipseCandidate.h>
#include "arc.hpp"

class Arc_set {
    private:
    const cv::Mat &src;
    public:
    Arc_set() = delete;
    Arc_set(const Mat& image):
    src(image)
    {
        generateArcSet();
        // src = image;
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
    void generateArcSet();

    void viewAllArcs();
};