#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft {
    template <typename T>

    class Vector
    {
        public:
            // member types
            
            typedef T value_type;
            typedef T &reference;
            const typedef T &const_reference;
            typedef T *pointer;
            const typedef T *const_pointer;
    };
};

#endif