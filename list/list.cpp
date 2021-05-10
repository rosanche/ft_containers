#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T>
class List
{
private:
    T list[];

public:
    List();
    ~List();
};

#endif