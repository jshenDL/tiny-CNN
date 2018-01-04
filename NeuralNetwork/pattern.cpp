//
// Created by jiguangshen on 1/3/18.
//

#include "pattern.h"

// constructor that takes just sizes of input and output patterns
Pattern::Pattern(int in_size, int out_size) {
    in_set.resize(static_cast<unsigned int>(in_size));
    out_set.resize(static_cast<unsigned int>(out_size));
}

// read data from a file stream
Pattern::Pattern(int in_size, int out_size, std::ifstream &infile) {
    in_set.resize(static_cast<unsigned int>(in_size));
    out_set.resize(static_cast<unsigned int>(out_size));

    load_from_file(infile);
}

// read data from variable list
Pattern::Pattern(int in_size, int out_size, int data_id, ...) {
    in_set.resize(static_cast<unsigned int>(in_size));
    out_set.resize(static_cast<unsigned int>(out_size));

    id = data_id;
    va_list vl;

    va_start(vl, data_id);
    for (auto in : in_set) {
        in = va_arg(vl, double);
    }

    for (auto out : out_set) {
        out = va_arg(vl, double);
    }

    va_end(vl);
}

// finally we can load from vector
Pattern::Pattern(int in_size, int out_size, int data_id, std::vector<double> &input_set,
                 std::vector<double> &output_set) {
    in_set.resize(static_cast<unsigned int>(in_size));
    out_set.resize(static_cast<unsigned int>(out_size));

    id = data_id;

    in_set = input_set;
    out_set = output_set;
}

// utility functions to extract pattern values
double Pattern::in(int id) {
    return in_set[id];
}

double Pattern::out(int id) {
    return out_set[id];
}

void Pattern::set_in(int id, double value) {
    in_set[id] = value;
}

void Pattern::set_out(int id, double value) {
    out_set[id] = value;
}

int Pattern::in_size() {
    return static_cast<int>(in_set.size());
}

int Pattern::out_size() {
    return static_cast<int>(out_set.size());
}

int Pattern::get_id() {
    return id;
}

void Pattern::save_to_file(std::ofstream &outfile) {
    outfile << id << "\t";
    for (const double &pt : in_set) {
        outfile << pt << "\t";
    }

    for (unsigned int i = 0; i < out_set.size(); i++) {
        outfile << out_set[i];
        if (i != out_set.size() - 1) outfile << "\t";
    }

    outfile << std::endl;
}

void Pattern::load_from_file(std::ifstream &infile) {
    //TODO
}

void Pattern::copy(Pattern &in) {
    //TODO
}