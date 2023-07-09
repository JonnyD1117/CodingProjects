#pragma once

#include <iostream>
#include <stdint.h>
#include <opencv2/opencv.hpp>
#include <numeric>
#include <cmath>
#include <algorithm>

// https://isas.iar.kit.edu/pdf/SPIE01_BriechleHanebeck_CrossCorr.pdf
//https://www.ipb.uni-bonn.de/html/teaching/photo12-2021/2021-pho1-09-matching-cc.pptx.pdf

using namespace cv;

class ZNCC
{

    ZNCC() = default;

private:

    Mat template_image_, image_, zncc_image;

    double temp_mean, image_mean;

    double templateMean()

};



double zncc (Mat& image, Mat& temp_image, int u, int v)
{
    double image_mean, template_mean, image_dev, template_dev, correlation_dev;

    double num_elemnts = temp_image.rows*temp_image.cols;
    // Compute Means
    for(int p = 0; p < temp_image.rows; p++) {

        uchar* temp_row_ptr = temp_image.ptr<uchar>(p);
        uchar* image_row_ptr = image.ptr<uchar>(p+u);
        for(int q = 0; q < temp_image.cols; q++) {
            template_mean += (int)temp_row_ptr[q];
            image_mean += (int)image_row_ptr[q+v];
        }

        image_mean /= (num_elemnts);
        template_mean /= (num_elemnts);
    }

    // Computer Standard Deviations

    for(int p = 0; p < temp_image.rows; p++) {

        uchar* temp_row_ptr = temp_image.ptr<uchar>(p);
        uchar* image_row_ptr = image.ptr<uchar>(p+u);
        for(int q = 0; q < temp_image.cols; q++) {
            template_dev += (int)((temp_row_ptr[q] - template_mean)*(temp_row_ptr[q] - template_mean));
            image_dev += (int)((image_row_ptr[q+v] - image_mean)*(image_row_ptr[q+v] - image_mean));
            correlation_dev += ((int)temp_row_ptr[q] - template_mean)*((int)image_row_ptr[q+v] - image_mean);
        }
    }

    template_dev = std::sqrt(template_dev/ (num_elemnts - 1));
    image_dev = std::sqrt(image_dev/ (num_elemnts - 1));
    correlation_dev = correlation_dev/ (num_elemnts - 1);

    return correlation_dev/((template_dev)*(image_dev));
}