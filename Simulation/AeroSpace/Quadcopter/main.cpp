#include <iostream>
#include<string>

#include <Eigen/Geometry>

using namespace Eigen;
int main() {

    Eigen::Vector3f myVect(1,1,1);
    Eigen::Vector3f dummy;

    float x, y, z, w;
//    x = y = z = w = 1.0f;
    x = 1;
    y = 2;
    z = 3;
    w = 5;
    Quaternionf q(w, x, y, z);
    q.normalize();

//    MatrixXf rot = q.toRotationMatrix().eulerAngles(10, 20, 30);

//    std::cout << rot<< std::endl;
//    std::cout << q<< std::endl;
//
//    std::cout << q.inverse() << std::endl;

//    std::cout << q.toRotationMatrix() << std::endl;
//    std::cout << "##################" << std::endl;
//    std::cout << q.inverse().toRotationMatrix() << std::endl;


////    q.normalize();
//    Matrix3f R(q);
//    Matrix4f M;
//    M.setIdentity();
//    M.block<3,3>(0,0) = R;
//
//    dummy = R*myVect;
//
//    Eigen::Vector3f I(1,1,1);
//
//    std::cout << R << std::endl;

//    q.x() +=.69f;
//    q.y() +=.69f;
//    q.z() +=.69f;
//    q.w() +=.69f;
//
//    std::cout << "####################" << std::endl;
//    std::cout << q << std::endl;
//    std::cout << R << std::endl;
//    std::cout <<  dummy << std::endl;
//
//    Matrix3f R_inv(q.conjugate());
//
//    dummy = R_inv*myVect;
//    std::cout << R_inv << std::endl;
//    std::cout <<  dummy << std::endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
