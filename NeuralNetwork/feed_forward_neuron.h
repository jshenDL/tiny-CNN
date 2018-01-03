//
// Created by jiguangshen on 1/2/18.
//

#ifndef TINY_CNN_FEED_FORWARD_NEURON_H
#define TINY_CNN_FEED_FORWARD_NEURON_H

#include "neuron.h"


class Feed_Forward_Neuron : public Neuron {
protected:
    virtual double transfer_function(double value);

public:
    Feed_Forward_Neuron(int v_size, int e_size);

    virtual void run(int mode);

    virtual std::string name();
};

#endif //TINY_CNN_FEED_FORWARD_NEURON_H
