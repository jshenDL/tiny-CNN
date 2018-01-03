//
// Created by jiguangshen on 11/25/17.
//

#ifndef TINY_NN_NEURON_H
#define TINY_NN_NEURON_H

#include "link.h"

#include <vector>
#include <list>
#include <fstream>
#include <bits/unique_ptr.h>
#include <boost/asio/detail/shared_ptr.hpp>

class Neuron {
private:
    static int ticket;

protected:
    int id;                              // neuron id number
    std::vector<double> values;         // values stored in this node
    std::vector<double> errors;           // errors stored in this node

    std::list<Link> in_links;            // input links to current neuron
    std::list<Link> out_links;           // output links to the current neuron

public:
    Neuron(int w_size, int e_size);

    virtual ~Neuron() = default;

    std::shared_ptr<std::list<Link>> get_in_links();

    std::shared_ptr<std::list<Link>> get_out_links();

    virtual void run(int mode = 0) {};

    virtual void learn(int mode = 0) {};

    virtual void epoch(int code = 0) {};

    virtual void load_from_file(std::ifstream &infile);

    virtual void save_to_file(std::ofstream &outfile);

    virtual double get_value(int index);   //each neuron will have a value, v = phi(weights * prev_vals)
    virtual std::vector<double> fetch_values();

    virtual void set_values(double new_val, int id);

    virtual double get_error(int id);

    virtual std::vector<double> fetch_errors();

    virtual void set_error(double new_err, int id);

    int get_id();

    virtual std::string get_name();

    void create_link_to(Neuron &to_node, const std::shared_ptr<Link> &link);

    friend void connect(Neuron &from_node, Neuron &to_node, Link &link);

    friend void connect(Neuron &from_node, Neuron &to_node, const std::shared_ptr<Link> &link);

    friend void connect(const std::shared_ptr<Neuron> &from_node, const std::shared_ptr<Neuron> &to_node,
                        const std::shared_ptr<Link> &link);

    friend int disconnect(const std::shared_ptr<Neuron> &from_node, const std::shared_ptr<Neuron> &to_node);
};


#endif //TINY_NN_NEURON_H
