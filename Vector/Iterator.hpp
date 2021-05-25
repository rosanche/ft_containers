#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>

class Iterator
{
    public:
        // member types 
        typedef T value_type;
        typedef std::ptrdiff_t various_type;
        typedef T *pointer;

        Iterator(void);
        ~Iterator();
        Iterator(T *ptr);
        Iterator &operator=(const Iterator &ptr);

        Iterator &operator++();
        Iterator operator++(int nothing);
        Iterator &operator--();
        Iterator operator--(int nothing) const;

        Iterator &operator+=(various_type add);
        Iterator operator+(various_type add) const;
        Iterator &operator-=(various_type sou);
        Iterator operator-(various_type sou) const;

        bool operator==(const Iterator &ptr) const;
        bool operator!=(const Iterator &ptr) const;

        pointer ptr;

};

template <typename T>
Iterator<T>::Iterator() {
    this->ptr = NULL;
}

template <typename T>
Iterator<T>::Iterator(T *ptr) {
    this->ptr = ptr
}

template <typename T>
Iterator<T>::~Iterator() {
}

template <typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator &ptr)
{
    if (this != &ptr)
    {
        this->ptr = ptr.ptr;
    }
    return (*this);
};

template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    this->ptr++;
    return (*this);
};

template <typename T>
Iterator<T> Iterator<T>::operator++(int nothing)
{
    (void)nothing;
    Iterator<T> copy;
    copy = *this;
    this->ptr++;
    return (copy);
};

template <typename T>
Iterator<T> &Iterator<T>::operator--()
{
    this->ptr--;
    return (*this);
};

template <typename T>
Iterator<T> Iterator<T>::operator--(int nothing) const
{
    (void)nothing;
    Iterator<T> copy;
    copy = *this;
    this->ptr--;
    return (copy);
};

template <typename T>
Iterator<T> &Iterator<T>::operator+=(various_type add)
{
    this->ptr += add;
    return (*this);
};

template <typename T>
Iterator<T> Iterator<T>::operator+(various_type add) const
{
    Iterator copy(*this);

    copy.ptr += add;

    return (copy);
};

template <typename T>
Iterator<T> &Iterator<T>::operator-=(various_type sou)
{
    this->ptr -= sou;
    return (*this);
};

template <typename T>
Iterator<T> Iterator<T>::operator-(various_type sou) const
{
    Iterator copy(*this);

    copy.ptr -= sou;

    return (copy);
};

template <typename T>
bool Iterator<T>::operator==(const Iterator &ptr) const
{
    return this->ptr == ptr;
};

template <typename T>
bool Iterator<T>::operator!=(const Iterator &ptr) const
{
    return this->ptr != ptr;
};

#endif