#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Eigen/Eigen"

struct SimParams
{
    float dt = .001f;
    float duration = 30.0f;
    Eigen::Vector3f state_init;
    Eigen::Vector3f input_init;

} ;

struct ModelParams
{
    float mass;
    float I_xx, I_yy, I_zz;
    float K_lift;
    float K_drag;
    float L_arm;
    float b_const;
} ;

class Simulator
{

private:

    int num_steps;

    SimParams sim_;
    ModelParams model_;

    float m, g, k_d, k_l, L, B, k;

    Eigen::MatrixXd states_trajectory;
    Eigen::MatrixXd output_trajectory;
    Eigen::MatrixXd input_trajectory;

    Eigen::Matrix<float, 13, 1> states_;            // states = [u, v, w, p, q, r, q_0, q_1, q_2, q_3, x, y, z]
    Eigen::Matrix<float, 13, 1> dt_states_;
    Eigen::Matrix<float, 4, 1> inputs_;
    Eigen::Quaternionf q_rot;

    Eigen::Vector3f F_gravity;
    Eigen::Vector3f F_drag;
    Eigen::Vector3f F_thrust;



    Eigen::Matrix<float, 13, 1>& updateStateDerivatives(Eigen::Matrix<float, 13, 1>& states, Eigen::Matrix<float, 4, 1> inputs_)
    {
        Eigen::Quaternionf quaternion;

        quaternion.toRotationMatrix()
        Eigen::Vector3d euler = quaternion.toRotationMatrix().eulerAngles(2, 1, 0);
        yaw = euler[0]; pitch = euler[1]; roll = euler[2];

        Eigen::Matrix3f R(q_rot);
        F_gravity = R*
        // Use Quaternion to Rotate F_grav vectory into body frame



        Eigen::Vector3f forces_ext;


        // Use Governing Equations of Motion to update state derivatives
        return dt_states_;
    }
    Eigen::Matrix<float, 13, 1>& updateStates(Eigen::Matrix<float, 13, 1>& states,Eigen::Matrix<float, 13, 1>& dt_states)
    {
        // Use Current states and state derivatives to numerically compute state update law.
        // Be sure that the quaternion is normalized every step after being updated.
        return states_;
    }
    Eigen::Matrix<float, 4, 1>& computeInputs(Eigen::Matrix<float, 13, 1>& states, Eigen::Matrix<float, 13, 1>& ref_states )
    {
        // Given the current state of the system and desired state of the system
        // Use PID control to compute input values
        return inputs_;
    }

public:
    Simulator()
    {
        Eigen::Vector3f F_gravity (0.0f, 0.0f, -m*g);
        Eigen::Vector3f F_drag(0.0f, 0.0f, 0.0f);
        Eigen::Vector3f F_thrust(0.0f, 0.0f, k_l*(inputs_(0)));
    }
    void run()
    {
        for(int step =0; step<num_steps; step++)
        {



        }
    }
};