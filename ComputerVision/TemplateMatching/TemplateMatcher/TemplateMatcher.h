#pragma once

#include <opencv2/opencv.hpp>
#include "zncc_new.h"
#include <utility>

using namespace cv;


class TemplateMatcher
{
    Mat image_;
    Mat template_image_;
    std::pair<size_t, size_t> offset_coords;


public:

    std::pair<size_t, size_t> operator () (Mat& image, Mat& template_image)  {

        image_ = image;
        template_image_ = template_image;

        return run();
    }

    std::pair<size_t, size_t> run()
    {
        Mat sub_image;
        Mat zncc_image;

        zncc_image = image_;

        int max_u = image_.rows - template_image_.rows;
        int max_v = image_.cols - template_image_.cols;

        int offset_u = -1;
        int offset_v = -1;
        double max_value = -1;
        double value;

        for(int u=0; u < max_u; u++) {
            for( int v =0; v < max_v; v++) {

                value = zncc(image_, template_image_, u, v);
                zncc_image.at<double>(u,v) = value;

                if(value > max_value) {
                    max_value = value;
                    offset_u = u;
                    offset_v = v;
                }
            }
        }

//    cv::imshow("ZNCC", zncc_image);
//    cv::waitKey(0);

        offset_coords.first = offset_u;
        offset_coords.second = offset_v;

        return offset_coords;
    }

};