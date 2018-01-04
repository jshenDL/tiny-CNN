//
// Created by jiguangshen on 1/3/18.
//

#include "bias_neuron.h"

double Bias_Neuron::get_value(int id) {
    return values[0];
}

std::string Bias_Neuron::get_name() {
    static std::string name = "Bias node";
    return name;
}
