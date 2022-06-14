/**
 * @Author: WU Zihan
 * @Date:   2022-05-09 20:46:49
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-06-13 23:35:45
 */

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <vector>
// #include <limits.h>
// #include <float.h>
// #include <iostream>
// #include <fstream>
// #include "EllipseDetector.h"
// #include "EdgeDetector.h"
// #include "CurveSimplifier.h"
#include <unordered_map>
#include <numeric>
#include "Find_arcs.hpp"
#include "Debug.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;
// static Debug& debugger = Debug::getInstance();




int main(int argc, char **argv)
{
    
    cout << "Built with OpenCV " << CV_VERSION << endl;
    // CommandLineParser parser(argc, argv, "{@input | /Users/zihanwu/ellipseDetectionplus/coin.jpeg | input image}");
    // string filename;
    // filename = parser.get<String>("@input");
// #ifdef __APPLE__
    Mat src = imread("../pics/hockey.jpg", IMREAD_GRAYSCALE);
//     #else
//     Mat src = imread("/home/wu/codes/dataset/hockey.jpg", IMREAD_GRAYSCALE);
// #endif

    // ArcGen a;
    // cout << a.getGroups(src) << endl;
    // cout << src.rows << endl;
    Arc_set result(src);
    // for (int i = 0; i < result.data.size(); i++)
    // {
    //     result.data[i].genMat();
    // }
    
    // result.data[0].genMat();
    // cout << result.data[0].mat.size << endl;
    return EXIT_SUCCESS;
}