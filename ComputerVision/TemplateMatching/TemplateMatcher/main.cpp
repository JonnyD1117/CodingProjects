#include <iostream>
#include <opencv2/opencv.hpp>
#include "TemplateMatcher.h"

using namespace cv;

int main() {

    TemplateMatcher matcher;

//    Mat image = imread("/home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/NormalizedCrossCorrelation/images/test.png", IMREAD_GRAYSCALE);
//    Mat temp_img = imread("/home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/NormalizedCrossCorrelation/images/test_template.png", IMREAD_GRAYSCALE);
    Mat image = imread("/home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/TemplateMatcher/images/image.png", IMREAD_GRAYSCALE);
    Mat temp_img = imread("/home/indy/repos/CodingProjects/ComputerVision/TemplateMatching/TemplateMatcher/images/template.png", IMREAD_GRAYSCALE);

    auto offsets =  matcher(image,temp_img);

    std::cout << "Template Offsets: U=" << offsets.first << "  V=" << offsets.second << std::endl;
    return 0;
}
