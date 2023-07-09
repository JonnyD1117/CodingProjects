#pragma once

#include<iostream>
#include <opencv2/opencv.hpp>
//#include "include/zncc.h"
#include <iterator>


#include "zncc_new.h"
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

        disparity_image = image_L;

        run();

        cv::imshow("Stereo Block Matching Algorithm", disparity_image);
        cv::waitKey(0);
    }
private:

    void run()
    {
        int lr_margin = (width_ /2) ;
        int tb_margin = (height_/2);

        // Zero Pad Stereo Pair
        copyMakeBorder( image_L_, image_L_, tb_margin, tb_margin, lr_margin, lr_margin, BORDER_CONSTANT, 0 );
        copyMakeBorder( image_R_, image_R_, tb_margin, tb_margin, lr_margin, lr_margin, BORDER_CONSTANT, 0 );

        std::vector<double> test_list (image_L_.cols, 0);

        for(int row=0; row <= image_L_.rows - height_; row++){

            std::cout << "Row = " << row << std::endl;

            for( int col =0; col <= image_L_.cols - width_; col++)
            {
                reference_window = image_L_(Range(row, row + height_), Range(col, col + width_ ));

                for( int c =0; c < image_L_.cols- width_; c++)
                {
                    test_list[c] = zncc(image_R_, reference_window, row, c);
                }
                
                int index = std::distance(test_list.begin(), max_element(test_list.begin(), test_list.end())) ;
                disparity_image.at<double>(row,col) = col - index;
            }
        }
    }
};
