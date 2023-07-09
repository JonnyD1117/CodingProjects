#pragma once

#include<iostream>
#include<cmath>

#include <opencv2/opencv.hpp>

using namespace cv;

class SumAbsoluteDifferences
{
    double abs_sum = 0.0;
    double diff;

public:
    int operator()(Mat& img1, Mat& img2 ) {

//        if(img1.size != img2.size) { throw DimensionMismatch; }

        for(int i = 0; i < img1.rows; i++) {

            uchar* img1_row = img1.ptr<uchar>(i);
            uchar* img2_row = img2.ptr<uchar>(i);

            for(int j = 0; j < img1.cols; j++) {

                diff = img2_row[j] - img1_row[j];
                abs_sum += std::abs(diff);
            }
        }
        return (int)abs_sum;
    }
};