#pragma once

#include <iostream>
#include <stdint.h>
#include <opencv2/opencv.hpp>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace cv;

double ncc (Mat& sub_image, Mat& temp_image)
{
    std::vector<double>img_mean;
    std::vector<double> temp_mean;
    std::vector<double>img_std_dev;
    std::vector<double> temp_std_dev;

    cv::meanStdDev(sub_image, img_mean, img_std_dev);
    cv::meanStdDev(temp_image, temp_mean, temp_std_dev);

//    double sub_image_mean = img_mean[0];
//    double template_mean = temp_mean[0];

    double sub_image_std_dev =  (img_std_dev[0] !=0) ? img_std_dev[0] : 0.0000001;
    double template_std_dev = (temp_std_dev[0] !=0) ? temp_std_dev[0] : 0.0000001;

//        std::cout << "Sub Image Mean: " << sub_image_mean << ","  << sub_image_std_dev << std::endl;
//        std::cout << "Template Image Mean: " << template_mean << ","  << template_std_dev << std::endl;

    std::vector<double> covariance_vec;
    double tmp_;


    for(int i=0; i < sub_image.rows; i++)
    {
        for(int j=0; j < sub_image.cols; j++)
        {
            tmp_ = ((double)sub_image.at<uint8_t>(i, j)) * ((double)temp_image.at<uint8_t>(i, j));
            tmp_ *= (1.0 / (sub_image_std_dev * template_std_dev));
            covariance_vec.push_back(tmp_);
        }
    }

    return std::reduce(covariance_vec.begin(), covariance_vec.end(), 0.0) / (covariance_vec.size()*2.0);

}