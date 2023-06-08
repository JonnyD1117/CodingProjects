#pragma once

#include "../Matrices/Matrix.h"


enum class CoordAxes
{
    x = 0,
    y = 1,
    z = 2,
    X = 3,
    Y = 4,
    Z = 5
};


template< size_t row_size, size_t col_size>
class RotationMatrix : public Matrix<double, row_size, col_size>
{

public:

    Matrix<double, row_size, col_size> RotMat_X(double angle)
    {
        Matrix<double, row_size, col_size> mat;

    }
    Matrix<double, row_size, col_size> RotMat_Y(double angle)
    Matrix<double, row_size, col_size> RotMat_Z(double angle)




};

