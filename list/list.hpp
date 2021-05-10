#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T>

namespace ft {
    class List
    {
    private:
        T list[];

    public:
        List();
        ~List();
    };
}

#endif