//
// Created by jiguangshen on 11/25/17.
//

#include <iomanip>
#include "neuron.h"

Neuron::Neuron(int w_size, int e_size) {
    values.resize(static_cast<unsigned int>(w_size));
    errors.resize(static_cast<unsigned int>(e_size));
    id = ++ticket;
}

int Neuron::get_id() {
    return id;
}

std::shared_ptr<std::list<Link>> Neuron::get_in_links() {
    return std::make_shared<std::list<Link> >(in_links);
}

std::shared_ptr<std::list<Link>> Neuron::get_out_links() {
    return std::make_shared<std::list<Link> >(out_links);
}

void Neuron::load_from_file(std::ifstream &infile) {
    //TODO
}

void Neuron::save_to_file(std::ofstream &outfile) {
    outfile << std::setw(4) << id << std::endl;
    outfile << values.size();
    for (auto val : values) {
        outfile << " " << std::setprecision(18) << val;
    }
    outfile << std::endl;
    outfile << errors.size();
    for (auto err : errors) {
        outfile << " " << std::setprecision(18) << err;
    }

}

double Neuron::get_value(int index) {
    return values[index];
}

std::vector<double> Neuron::fetch_values() {
    return values;
}

void Neuron::set_values(double new_val, int index) {
    if (index >= static_cast<int>(values.size())) {
        throw std::runtime_error("Index out of bound!");
    }
    values[index] = new_val;
}

double Neuron::get_error(int index) {
    return errors[index];
}

std::vector<double> Neuron::fetch_errors() {
    return errors;
}

void Neuron::set_error(double new_err, int index) {
    if (index >= static_cast<int>(errors.size())) {
        throw std::runtime_error("Index out of bound!");
    }
    errors[index] = new_err;
}

std::string Neuron::get_name() {
    return "Neuron_base";
}

void Neuron::create_link_to(Neuron &to_node, const std::shared_ptr<Link> &link) {
    out_links.push_back(*link.get());                //modify current node out links
    to_node.get_in_links()->push_back(*link.get());  //modify to node in links
}

void connect(Neuron &from_node, Neuron &to_node, Link &link) {
    std::shared_ptr<Link> tmp(&link);
    from_node.create_link_to(to_node, tmp);
}

void connect(Neuron &from_node, Neuron &to_node, const std::shared_ptr<Link> &link) {
    from_node.create_link_to(to_node, link);
}

void connect(const std::shared_ptr<Neuron> &from_node, const std::shared_ptr<Neuron> &to_node,
             const std::shared_ptr<Link> &link) {
    from_node->create_link_to(*to_node.get(), link);
}


int disconnect(const std::shared_ptr<Neuron> &from_node, const std::shared_ptr<Neuron> &to_node) {
    auto out_links = from_node->get_out_links();  //auto deduced type
    int flag = 0;
    for (auto iter = out_links->begin(); iter != out_links->end(); ++iter) {
        if (iter->get_out_node() == to_node) {
            flag = 1; // if link is found
            iter->get_out_node()->get_in_links()->erase(iter);
            break;
        }
    }
    // break to see the link to delete
    return flag;
}

int Neuron::ticket = -1;
