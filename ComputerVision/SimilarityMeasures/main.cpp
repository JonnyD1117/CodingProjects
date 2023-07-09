#include <iostream>
#include <opencv2/opencv.hpp>
//#include "zncc.h"
#include "zncc_new.h"
//#include "ncc_new.h"
#include "ssd.h"
#include "sad.h"

using namespace cv;

int main() {

    Mat image;
    Mat temp_img;
    Mat sub_image;
    Mat zncc_img;

//    image = imread("/home/indy/Coding/ComputerVision/data/images/test.png", IMREAD_GRAYSCALE);
//    temp_img = imread("/home/indy/Coding/ComputerVision/data/images/test_template.png", IMREAD_GRAYSCALE);
//
    Mat white = imread("/home/indy/Coding/ComputerVision/data/images/test_white.png", IMREAD_GRAYSCALE);
    Mat black = imread("/home/indy/Coding/ComputerVision/data/images/test_black.png", IMREAD_GRAYSCALE);


    std::cout << zncc(white, black, 0, 0) << std::endl;

//    image = image(Range(0, temp_img.rows), Range(0, temp_img.cols));
//
//    SumSquaredDifferences ssd;
//
//    SumAbsoluteDifferences sad;
//
//    std::cout << ssd(image, temp_img) << std::endl;
//    std::cout << sad(image, temp_img) << std::endl;

//    ZNCC thing;
//    zncc_img = thing(image, temp_img);

//    zncc_img = Mat::zeros(image.rows, image.cols, CV_64F);
//
//    int max_u = image.rows - temp_img.rows;
//    int max_v = image.cols - temp_img.cols;
//
//    for(int u=0; u < max_u; u++)
//    {
//        for( int v =0; v < max_v; v++)
//        {
//            sub_image = image(Range(u, u + temp_img.rows), Range(v, v + temp_img.cols));
//            zncc_img.at<double>(u,v) = zncc(sub_image, temp_img);
//        }
//    }
//
//    cv::imshow("ZNCC", zncc_img);
//    cv::waitKey(0);

    return 0;
}
