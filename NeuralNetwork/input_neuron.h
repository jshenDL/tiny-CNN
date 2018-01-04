//
// Created by jiguangshen on 1/3/18.
//

#ifndef TINY_CNN_INPUT_NEURON_H
#define TINY_CNN_INPUT_NEURON_H

#include "neuron.h"

// create an input neuron,
class Input_Neuron : public Neuron {
public:
    explicit Input_Neuron(int size) : Neuron(size, size) {}

    std::string get_name() override;;
};


#endif //TINY_CNN_INPUT_NEURON_H
