//
// Created by jiguangshen on 11/26/17.
//

#include "link.h"
#include "neuron.h"

Link::Link() {
    id = ++ticket;
}

// mode is the value index
double Link::in_value(int mode=0) {
    return in_node->get_value(mode);
}

// mode is the value index
double Link::out_value(int mode=0) {
    return out_node->get_value(mode);
}

double Link::in_error(int mode=0) {
    return in_node->get_error(mode);
}

double Link::out_error(int mode=0) {
    return out_node->get_error(mode);
}

//each link carries value from in node to out node, with weight on the link
double Link::weighted_in_value(int mode=0) {
    return in_node->get_value(mode) * weights[0];
}

//each link carries value from out node to in node, with weight on the link
double Link::weighted_out_value(int mode=0) {
    return out_node->get_value(mode) * weights[0];
}

double Link::weighted_in_error(int mode=0) {
    return in_node->get_error(mode) * weights[0];
}

double Link::weighted_out_error(int mode=0) {
    return out_node->get_error(mode) * weights[0];
}




