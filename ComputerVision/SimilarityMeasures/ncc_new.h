#pragma once

#include <iostream>
#include <stdint.h>
#include <opencv2/opencv.hpp>
#include <numeric>
#include <cmath>
#include <algorithm>

//https://www.ipb.uni-bonn.de/html/teaching/photo12-2021/2021-pho1-09-matching-cc.pptx.pdf

using namespace cv;

double ncc (Mat& sub_image, Mat& temp_image, int u, int v)
{
    std::vector<double> image_std (temp_image.rows* temp_image.cols);
    std::vector<double> temp_std(temp_image.rows* temp_image.cols);
    std::vector<double> covariance_std(temp_image.rows* temp_image.cols);

    for(int p = 0; p < temp_image.rows; p++) {

        double* temp_row_ptr = temp_image.ptr<double>(p);
        double* image_row_ptr = sub_image.ptr<double>(p);
        for(int q = 0; q < temp_image.cols; q++) {
            temp_std[(p*q)+q] = std::pow(temp_row_ptr[q],2.0);
            image_std[(p*q)+q] = std::pow(image_row_ptr[q],2.0);
            covariance_std[(p*q)+q] = image_row_ptr[q] * temp_row_ptr[q];
        }
    }
   double template_dev =  std::reduce(temp_std.begin(), temp_std.end(), 0.0);
   double image_dev = std::reduce(image_std.begin(), image_std.end(), 0.0) ;
   double covar_dev =  std::reduce(covariance_std.begin(), covariance_std.end(), 0.0);

   return covar_dev / std::sqrt(image_dev * template_dev);
}