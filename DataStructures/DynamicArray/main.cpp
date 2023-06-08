#include <iostream>

#include "DynamicArray.h"

int main() {

    DynamicArray<int> dyn_arr;

    dyn_arr.push_back(5);
    dyn_arr.push_back(7);
    dyn_arr.push_back(8);
    dyn_arr.push_back(9);
    dyn_arr.push_back(10);
    dyn_arr.push_back(11);
    dyn_arr.push_back(12);
    dyn_arr.push_back(13);
    dyn_arr.push_back(14);
    dyn_arr.Print();

    std::cout << "############################" << std::endl;

    dyn_arr.shrink_to_fit();
    dyn_arr.Print();

    std::cout << "############################" << std::endl;

    dyn_arr.pop_back();
    dyn_arr.Print();
    std::cout << "############################" << std::endl;
    std::cout << "############################" << std::endl;

    std::cout<< dyn_arr.at(0) << std::endl;
    std::cout<< dyn_arr.at(3) << std::endl;
//    std::cout<< dyn_arr.at(55) << std::endl;

    std::cout << "############################" << std::endl;
    std::cout << "############################" << std::endl;

    std::cout<< dyn_arr.front() << std::endl;
    std::cout<< dyn_arr.back() << std::endl;

    std::cout << "############################" << std::endl;
    std::cout << "############################" << std::endl;
//
//    dyn_arr.resize(3);
//    dyn_arr.resize(20, 69);
//    dyn_arr.Print();

    std::cout << "############################" << std::endl;
    std::cout << "############################" << std::endl;
    std::cout << "############################" << std::endl;
    std::cout << "############################" << std::endl;

//    for(DynamicArray<int>::iterator it = dyn_arr.begin(); it != dyn_arr.end(); ++it)
//    {
//        std::cout << *it << std::endl;
//    }

    for(DynamicArray<int>::reverse_iterator it = dyn_arr.rbegin(); it != dyn_arr.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
