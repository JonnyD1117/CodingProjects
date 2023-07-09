#include <iostream>
#include "MultidimensionalArray.h"

int main() {

    const size_t num_rows = 5;
    const size_t num_cols = 5;

    MultidimensionalArray<int, num_rows,num_cols> myMdArray;

    int value = 0;
    for(int i =0 ; i < num_rows; i++)
    {
        for(int j =0; j < num_cols; j++)
        {
            myMdArray.at(value, i, j);
            value++;
        }
    }
    std::cout << myMdArray << std::endl;
    return 0;
}
