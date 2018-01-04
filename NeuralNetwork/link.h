//
// Created by jiguangshen on 11/26/17.
//

#ifndef TINY_NN_LINK_H
#define TINY_NN_LINK_H

#include <vector>
#include <memory>
class Neuron;

class Link {
private:
    static int ticket;

protected:
    int id;
    std::vector<double> weights;  // the weight on the link betweenn 0 and 1
    std::shared_ptr<Neuron> in_node;
    std::shared_ptr<Neuron> out_node;
public:
    Link();

    ~Link() = default;

    virtual void save(std::ofstream &out_file);

    virtual void load(std::ifstream &in_file);

    virtual double get_weight(int id);

    virtual void set_weight(double new_val, int id);

    virtual void set_in_node(const std::shared_ptr<Neuron> &node, int id);

    virtual void set_out_node(const std::shared_ptr<Neuron> &node, int id);

    virtual std::shared_ptr<Neuron> get_in_node();

    virtual std::shared_ptr<Neuron> get_out_node();

    virtual std::string get_name(int id);

    virtual void update_weight(double new_val);

    int get_id();

    virtual double in_value(int mode);

    virtual double out_value(int mode);

    virtual double in_error(int mode);

    virtual double out_error(int mode);

    virtual double weighted_in_value(int mode);

    virtual double weighted_out_value(int mode);

    virtual double weighted_in_error(int mode);

    virtual double weighted_out_error(int mode);

    virtual int get_size();

    virtual void epoch(int mode);
};

#endif //TINY_NN_LINK_H
