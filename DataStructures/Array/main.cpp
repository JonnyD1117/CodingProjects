#include <iostream>
#include "Array.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    Array<int, 5> arr;);

//    for(int i =0 ; i< 5; i++)
//    {
//        arr[i] =i;
//    }

    for(int i =0 ; i< 5; i++)
    {
        std::cout<< arr[i] << std::endl;
    }

    std::cout<<"Array AT() Pos = " << arr.at(5) << std::endl;


    return 0;
}
