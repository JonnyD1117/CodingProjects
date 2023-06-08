#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>


namespace py = pybind11;


float add(int i, int j)
{
	return i + j + 0.69f;
}



std::vector<int> test_vector()
{
	std::vector<int> myVect {7,6,5,4,3,2,1};
	return myVect;
}



PYBIND11_MODULE(example_cpp_module, m)
{
	m.doc() = "Test of Pybind11 example plugin"; // Optional module docstring
	m.def("add_cpp", &add, "A function that adds two numbers in C++");
	m.def("my_vector", &test_vector, "A vector that I like");
	
}


int main()
{
	std::cout << "Hello CMake World" << std::endl;
	return 0; 
}
