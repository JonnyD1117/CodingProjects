#include <iostream>
#include <opencv2/opencv.hpp>
#include "zncc.h"

#include "StereoBlockMatcher.h"

using namespace cv;

int main() {

    Mat L_image;
    Mat R_image;

    StereoBlockMatcher sbm;

    L_image = imread("/home/indy/Coding/ComputerVision/StereoMatching/data/pendulum2/im0.png", IMREAD_GRAYSCALE);
    R_image = imread("/home/indy/Coding/ComputerVision/StereoMatching/data/pendulum2/im1.png", IMREAD_GRAYSCALE);

    sbm(L_image, R_image, 24, 24);

//    copyMakeBorder( image, image, 10, 10, 20, 100, BORDER_CONSTANT, 0 );
////    temp_img = imread("/home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/NormalizedCrossCorrelation/images/test_template.png", IMREAD_GRAYSCALE);
////
////    zncc_img = Mat::zeros(image.rows, image.cols, CV_64F);
////
////    int max_u = image.rows - temp_img.rows;
////    int max_v = image.cols - temp_img.cols;
////
////    for(int u=0; u < max_u; u++)
////    {
////        for( int v =0; v < max_v; v++)
////        {
////            sub_image = image(Range(u, u + temp_img.rows), Range(v, v + temp_img.cols));
////            zncc_img.at<double>(u,v) = zncc(sub_image, temp_img);
////        }
////    }
//
//    cv::imshow("ZNCC", image);
//    cv::waitKey(0);

    return 0;
}
