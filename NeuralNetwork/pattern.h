//
// Created by jiguangshen on 1/3/18.
//

#ifndef TINY_NN_PATTERN_H
#define TINY_NN_PATTERN_H

#include <vector>
#include <stdarg.h>
#include <fstream>


// Pattern class describes the input data and the output data
// used for training and testing
// it offers various way to access the data

class Pattern {
private:
    std::vector<double> in_set;
    std::vector<double> out_set;
    int id;

public:
    Pattern(int in_size, int out_size);

    Pattern(int in_size, int out_size, int data_id, ...);

    Pattern(int in_size, int out_size, int data_id, std::vector<double> &in_set, std::vector<double> &out_set);

    Pattern(int in_size, int out_size, std::ifstream &infile);

    ~Pattern() {}

    virtual double in(int id);

    virtual double out(int id);

    virtual void set_in(int id, double value);

    virtual void set_out(int id, double value);

    virtual int in_size();

    virtual int out_size();

    virtual void save_to_file(std::ofstream &outfile);

    virtual void load_from_file(std::ifstream &infile);

    virtual int get_id();

    virtual void copy(Pattern &in);
};


#endif //TINY_CNN_PATTERN_H
