#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>

class Iterator
{
    public:
        // member types 
        // typedef T value_type;
        // typedef T &reference;
        // const typedef T &const_reference;
        // typedef T *pointer;
        // const typedef T *const_pointer;

        Iterator(void);
        ~Iterator();
        Iterator(T);

};

template <typename T>
Iterator<T>::Iterator() {

}

template <typename T>
Iterator<T>::Iterator(T) {
    
}

#endif