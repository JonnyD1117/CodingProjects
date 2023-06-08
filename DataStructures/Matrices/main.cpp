#include <iostream>
#include "Matrix.h"
#include <cstring>

int main() {

    int init_A[2][5] = {
            {1,2,3,4,5},
            {6,7,8,9,10}
    };

    int init_B[5][3] = {
            {11, 12, 13},
            {14, 15, 16},
            {17, 18, 19},
            {20, 21, 22},
            {23, 24, 25}
    };

    Matrix<int, 2, 5> mat_A(init_A);
    Matrix<int, 5, 3> mat_B(init_B);
    Matrix<int, 2, 3> mat_C;

    Matrix<double, 3,3> mat_d(
            {{1,0,0},
             {0,2,0},
             {0,0,1}
            });

//    std::memcpy(mat_A._matrix, init_A, sizeof(init_A));
//    std::memcpy(mat_B._matrix, init_B, sizeof(init_B));

    mat_A.PrintMatrix();
    std::cout << "######################################################" << std::endl;
    2*mat_A;

    mat_A.PrintMatrix();


//    mat_B.PrintMatrix();
//
//    mat_C = mat_A * mat_B;
//
    std::cout << "######################################################" << std::endl;

    mat_A.ElementWiseAddition(6);

    mat_A.PrintMatrix();

//    mat_C.PrintMatrix();

    mat_d.PrintMatrix();

    Matrix<int, 4,4> mat_E;

    mat_E.Identity();

//    mat_E.PrintMatrix();

    std::cout << mat_E << std::endl;


    return 0;
}
