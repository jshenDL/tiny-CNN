//
// Created by jiguangshen on 1/2/18.
//

#include "network.h"

void Network::create_network() {}

void Network::load_inputs() {}

void Network::save_nodes_and_links(std::ofstream &outfile) {
    outfile << "Number of neurons:" << num_neurons << std::endl;
    outfile << "Number of links:" << num_links << std::endl;

    for (Neuron &it : neurons) {
        it.save_to_file(outfile);
    }
}

void Network::load_nodes_and_links(std::ifstream &infile) {
    //TODO
}

Network::Network() : Neuron(0, 0) {
    num_neurons = 0;
    num_links = 0;
}

std::string Network::name() {
    static std::string name = "basic network";
    return name;
}

void Network::epoch(int code) {
    for (Neuron &node : neurons) {
        node.epoch(code);
    }
    for (Link &link : links) {
        link.epoch(code);
    }
}


