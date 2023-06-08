#pragma once

#include <Eigen/Eigen>

struct model_params
{
    double spring_const = 1.0;
    double damper_const = 0.1;
    double mass = 5.0;                 // Kg
};

struct simulation_params
{
    double dt = .001;                    // In Seconds
    double simTime = .5;                // In Seconds
};

class SimpleOscillator {

public:

    SimpleOscillator()
    {
        num_dt = (size_t)(simParams.simTime / simParams.dt);
        states_history.setZero(num_states, num_dt);
        output_history.setZero(num_outputs, num_outputs);


        A << 0.0, 1.0, -modelParams.spring_const / modelParams.mass, -modelParams.damper_const / modelParams.mass;
        B << 0.0, 0.0;
        C << 0.0, 1.0;

        init_state << 0.0, 0.5;
    }

    SimpleOscillator(const model_params& mParams, const simulation_params& sParams)
    : modelParams{mParams}, simParams{sParams}
    {
        SimpleOscillator();
    }

    void runSimulation()
    {
        std::cout << "state_list = [";
        for(int idx = 0; idx < num_dt; idx++)
        {
            states = (A*init_state) + (B *0.0);
            output = C*init_state;
//
//            states_history.col(idx) = init_state;
//            output_history.col(idx) = output;
            init_state = states;
            std::cout<< states[0] << ", ";
        }
        std::cout << "]";

    }

private:

    model_params modelParams;
    simulation_params simParams;
    size_t num_dt;

    int num_states = 2;
    int num_outputs = 1;

    Eigen::Matrix<double, 2,1> init_state;
    Eigen::Matrix<double, 2,1> states;
    Eigen::Matrix<double, 1,1> output;

    Eigen::MatrixXd states_history;
    Eigen::MatrixXd output_history;

    Eigen::Matrix<double, 2,2> A;
    Eigen::Matrix<double, 2,1> B;
    Eigen::Matrix<double, 1,2> C;

};


