#pragma once
#include <iostream>
#include <string>
#include <optional>

#include "MatrixExceptions.h"


template<typename T, size_t row_size, size_t col_size>
class Matrix
{
private:
    size_t _num_rows = row_size;
    size_t _num_cols = col_size;

public:

    T _matrix[row_size][col_size] = { 0 };

    /*
     * Matrix Constructor
     */

    Matrix(){}

    Matrix(const T (&val)[row_size][col_size])
    {
        for(int i =0; i< row_size; i++)
        {
            for(int j=0; j<col_size; j++)
            {
                _matrix[i][j] = val[i][j];
            }
        }
    }



    class ProxyMatrix
    {
    public:
        ProxyMatrix(T* mat) : _matrix_ptr(mat) { }

        T& operator[](int j) { return _matrix_ptr[j]; }

    private:
        T* _matrix_ptr;
    };

    /*
     * Operator Overloading
     */
    // Scalar Multiplication
    void operator* (T value)
    {
        for(int i=0 ; i < row_size; i++)
        {
            for(int j=0; j < col_size; j++)
            {
                (*this)[i][j] *= value;
            }
        }
    }

    /*
     * Matrix Addition
     */
    template<size_t row, size_t col>
    Matrix<T, row_size, col_size>& operator+ (const Matrix<T, row, col>& mat)
    {
        if( row != row_size || col != col_size) { throw MatrixImcompatible; }

        Matrix<T, row_size, col_size> tmp_mat;
        for(int i=0 ; i < row_size; i++)
        {
            for(int j=0; j < col_size; j++)
            {
                tmp_mat[i][j] = (*this)[i][j] + mat[i][j];
            }
        }

        return std::optional<Matrix<T, row_size, col_size>>{ tmp_mat };
    }



    // Matrix Multiplication
    ProxyMatrix operator[](int i) { return ProxyMatrix(_matrix[i]); }

    const size_t NumRows() { return row_size; }
    const size_t NumCols() { return col_size; }
    Matrix& GetMatrix() { return _matrix; }

    template<size_t c2>
    friend inline Matrix<T, row_size, c2> operator* (Matrix<T, row_size, col_size> & lhs, Matrix<T,col_size, c2> & mat)
    {
        Matrix<T,row_size ,c2> output_mat;
        for(int i=0; i < row_size; i++)
        {
            for(int j=0; j < c2; j++)
            {
                T sum { 0 } ;
                for(int k=0; k < col_size; k++)
                {
                    sum += lhs[i][k] * mat[k][j];
                }
                output_mat[i][j] = sum;
            }
        }
        return output_mat;
    };

    /*
     * Public API
     */

    void PrintMatrix()
    {

        std::string mat_string;

        for(int i=0; i<_num_rows; i++)
        {
            for(int j=0; j<_num_cols; j++) {

                mat_string += std::to_string(_matrix[i][j]);
                mat_string += "\t";
            }
            mat_string += "\n";
        }

        std::cout<< mat_string << std::endl;
    }

//    bool IsSquare();
//    Identity();

    // ElementWise Addition

    void ElementWiseAddition(T value)
    {
        for(int i=0 ; i < row_size; i++)
        {
            for(int j=0; j < col_size; j++)
            {
                (*this)[i][j] += value;
            }
        }
    }

//    Matrix<T, row_size, col_size>& ElementWiseAddition(T value, T idx=0)
//    {
//        Matrix<T, row_size, col_size> tmp_mat;
//        for(int i=0 ; i < row_size; i++)
//        {
//            for(int j=0; j < col_size; j++)
//            {
//                tmp_mat[i][j] = (*this)[i][j] + value;
//            }
//        }
//        return tmp_mat;
//    }


    // ElementWise Subtraction

    Matrix<T, row_size, col_size>& Identity()
    {
        if(row_size != col_size)
        {
            throw NonSquareInversion;
        }

        for(int i =0; i<row_size; i++)
        {
            for(int j =0 ; j< col_size; j++)
            {
                if (i == j)
                {
                    _matrix[i][j] = 1.0;
                }
            }
        }


    }



};


/*
 * Globally Define Pre-Multiplication
 */
template<typename T, size_t  row, size_t  col>
Matrix<T, row, col> operator*(T value, Matrix<T, row, col>& mat)
{

    for(int i=0 ; i < row; i++)
    {
        for(int j=0; j < col; j++)
        {
            mat[i][j] *= value;
        }
    }

}
template<typename T, size_t  row, size_t  col>
std::ostream& operator << (std::ostream& os, Matrix<T,row, col>& mat)
{
    for(int i=0 ; i < row; i++)
    {
        for(int j=0; j < col; j++)
        {
            os << std::to_string(mat[i][j]) << " ";
            if ( j == col-1)
            {
                os<< "\n";
            }
        }
    }

    return os;
}
