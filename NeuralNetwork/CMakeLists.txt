cmake_minimum_required(VERSION 3.5)

set(SOURCE_FILES neuron.cpp neuron.cpp neuron.h link.cpp link.h feed_forward_neuron.cpp feed_forward_neuron.h network.cpp network.h input_neuron.cpp input_neuron.h bias_neuron.cpp bias_neuron.h pattern.cpp pattern.h)
add_library(NeuronNetwork SHARED ${SOURCE_FILES})