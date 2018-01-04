//
// Created by jiguangshen on 1/3/18.
//

#ifndef TINY_NN_BIAS_NODE_H
#define TINY_NN_BIAS_NODE_H


#include "input_neuron.h"

// bias neuron is a processing neuron which act as constants, takes 1.0 output some constant

class Bias_Neuron : public Input_Neuron {
public:
    explicit Bias_Neuron(double bias) : Input_Neuron(1) {
        values[0] = bias;
    }

    void set_values(double value, int id) override {}

    double get_value(int id) override;

    std::string get_name() override;
};


#endif //TINY_CNN_BIAS_NODE_H
