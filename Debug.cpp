// /**
//  * @Author: Your name
//  * @Date:   2022-04-18 18:50:41
//  * @Last Modified by:   WU Zihan
//  * @Last Modified time: 2022-06-14 10:09:39
//  */
#include "Debug.hpp"

Debug::Debug(/* args */)
{
    // cout << "construct" << endl;
    // file.open("../data/debug.log");
}

Debug::~Debug()
{
    // cout << "destruct" << endl;
    file.close();
}

void Debug::printshort(Mat &src, int m, int n){
    for(int i=m; i<n; i++){
        for( int j=m; j<n; j++){
            cout << (double)src.at<short>(i,j) << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return;
}