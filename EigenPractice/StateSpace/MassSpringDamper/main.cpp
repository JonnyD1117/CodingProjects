#include <iostream>
#include <Eigen/Eigen>
#include "SimpleOscillator.h"

int main() {

    SimpleOscillator osc;

    osc.runSimulation();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
