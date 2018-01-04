//
// Created by jiguangshen on 1/2/18.
//

#ifndef TINY_NN_NETWORK_H
#define TINY_NN_NETWORK_H

#include "neuron.h"

class Network : public Neuron {
protected:
    int num_neurons;
    int num_links;
    std::vector<Neuron> neurons;   //all the nodes in the Network
    std::vector<Link> links;       //all the links in the netowrk

    virtual void create_network();

    virtual void load_inputs();

    virtual void save_nodes_and_links(std::ofstream &outfile);

    virtual void load_nodes_and_links(std::ifstream &infile);

public:
    Network();

    ~Network() override = default;

    void epoch(int code) override;

    virtual std::string name();
};


#endif //TINY_NN_NETWORK_H
