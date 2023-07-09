#pragma once

#include <iostream>
#include <stdint.h>
#include <opencv2/opencv.hpp>
#include <numeric>
#include <cmath>
#include <algorithm>
#include "MultidimensionalArray.h"


// https://isas.iar.kit.edu/pdf/SPIE01_BriechleHanebeck_CrossCorr.pdf
//https://www.ipb.uni-bonn.de/html/teaching/photo12-2021/2021-pho1-09-matching-cc.pptx.pdf

using namespace cv;

template<typename T, size_t rows, size_t cols>
class FastNormalizedCrossCorrelation
{

private:
    MultidimensionalArray<T,rows, cols> sum_table;
    MultidimensionalArray<T,rows, cols> sq_sum_table;

    T template_mean, template_sq_zero_mean_shift;

    Mat disparity_image_;
    Mat template_image_;
    Mat ref_image_;


    double templateMean()
    {
        T template_std;
        cv::meanStdDev(template_image_, template_mean, template_std);
        return template_mean;
    }

    double templateZeroMeanShift(Mat& template_image)
    {

    }

    void run()
    {

    }


public:

    Mat operator()(Mat& image, Mat& template_image)
    {

        template_image_ = template_image;
        ref_image_ = image;
        disparity_image_ = image;

        run();

        return disparity_image_;
    }
};


double FastNCC(Mat& image, Mat& template_image, int K)
{
    // Computer Max U & V offsets
    int max_u = image.rows - template_image.rows;
    int max_v = image.cols - template_image.cols;

    // Precompute Template Mean and Squared Zero-Mean Shift
    double template_mean, template_sq_zero_mean_shift;

    for(int p =0; p < template_image.rows; p++){
        for(int q =0; template_image.cols; q++){

        }
    }

}



/*
 * ################   Fast NCC Algorithm  ####################
 * 1) Precompute template Mean
 * 2) Precompute Template Zero mean squared shift sum
 * 3) Precompute Image Sum Table
 * 4) Precompute Image Energy Sum Table
 * 5) Approximate Numerator template Summation operation as a summation of "K" bias functions approximations
 * 6) Calculate the Numerator and Denominator Terms
 * 7) Construct the NCC and return
 *
 *
 * ################    CHALLENGES    #######################
 * - Create Sum and Energy Tables (recursively?)
 * - Figure out how to use Template Bias functions
 * -
 */
