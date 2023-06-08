#pragma once

#include <opencv2/opencv.hpp>
#include "include/zncc.h"

using namespace cv;

class StereoBlockMatcher
{
    Mat image_L_;
    Mat image_R_;

    size_t width_;
    size_t height_;

    Mat disparity_image;

    Mat reference_window;
    Mat sliding_window;

public:

    void operator()(Mat& image_L, Mat& image_R, size_t width, size_t height)
    {
        image_L_ = image_L;
        image_R_ = image_R;
        width_ = width;
        height_ = height;

        run();

        cv::imshow("Stereo Block Matching Algorithm", disparity_image);
        cv::waitKey(0);
    }
private:

    void run()
    {
        /* 1) Pad Left & Right Images based on window size.
         * 2) For every row and col in ref image compute reference window correspondence,
         * 3) For every col in sliding image (same ref row e.g. epipolar line) compute correspondence
         * 4) for each row of sliding image select best matching correspondence
         * 5) Back out pixel coords that best match
         * 6) Compute image disparity from ref and sliding pixel values
         * 7) Repeat for every row in Sliding image
         */

        // Zero Pad Stereo Pair

//        double ref_value;

        int max_u = image.rows - temp_img.rows;
        int max_v = image.cols - temp_img.cols;



        for(int u=0; u < max_u; u++)
        {
            for( int v =0; v < max_v; v++)
            {
                for(;;)
                {

                }
                sub_image = image(Range(u, u + temp_img.rows), Range(v, v + temp_img.cols));
                zncc_img.at<double>(u,v) = zncc(sub_image, temp_img);
            }
        }

    }
};
