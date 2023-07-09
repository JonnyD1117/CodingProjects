#pragma once

#include <iostream>

template <typename T, size_t rows, size_t cols>
class MultidimensionalArray
{
private:

    size_t row_ = rows;
    size_t col_ = cols;

    T table[rows][cols]{0};


public:
    T at(size_t row, size_t col)
    {
        return table[row][col];
    }

    void at(T& value, size_t row, size_t col)
    {
        table[row][col] = value;
    }

    template <typename U, size_t r, size_t c>
    friend std::ostream& operator<<(std::ostream& os, const MultidimensionalArray<U, r, c>& md);

};

template <typename T, size_t rows, size_t cols>

std::ostream& operator<<(std::ostream& os, const MultidimensionalArray<T, rows, cols>& table)
{
    for(int r = 0; r < rows; r++){
        for(int c =0 ; c<cols; c++) {

            os << table.table[r][c] << "\t";


        }

        os << "\n";
    }
    return os;
}