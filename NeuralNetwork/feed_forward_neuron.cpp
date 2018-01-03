//
// Created by jiguangshen on 1/2/18.
//

#include "feed_forward_neuron.h"
#include "link.h"

Feed_Forward_Neuron::Feed_Forward_Neuron(int v_size, int e_size) : Neuron(v_size, e_size)
{}

double Feed_Forward_Neuron::transfer_function(double value) {
    return value;
}

//here mode means position of value
void Feed_Forward_Neuron::run(int mode) {
    double total = 0.0;
    for (auto lk : in_links) {
        total += lk.weighted_in_value(0);   //each link to this node has a weight and it needs to multiply the value from the in node
    }
    values[mode] = transfer_function(total);   //this is the activation step, values is updated for a given mode
}

std::string Feed_Forward_Neuron::name()
{
    static std::string name = "Feed_Forward_Neuron";
    return name;
}
