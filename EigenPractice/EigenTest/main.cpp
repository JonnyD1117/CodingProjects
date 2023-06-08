#include <iostream>
#include <Eigen/Eigen>

using namespace Eigen;
using namespace std;
int main() {

    MatrixXd mat;
    mat = mat.Identity(2,3);
//
    std::cout << mat << std::endl;

    std::cout << "#############################" << std::endl;
    std::cout << "#############################" << std::endl;

    std::cout << mat.transpose() << std::endl;

//    Matrix <float, 3, 3> matrixA;
//    matrixA.setZero();
//    cout << matrixA <<endl;
    return 0;
}
