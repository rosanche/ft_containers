#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <iostream>

template <typename T>

struct chain_t {
    T datas;
    chain_t *prev;
    chain_t *next; 
};

#endif