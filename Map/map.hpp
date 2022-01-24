#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "RandomIterator.hpp"

namespace ft
{
    template <typename T>

    class map
    {
    public:
        // member types
        template <class Key,
                  class T,
                  class Compare = less<Key>,
                  class Alloc = allocator<pair<const Key, T> > >
        class map;
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;

        typedef RandomIterator<T> iterator;
        typedef RandomIterator<const T> const_iterator;
        typedef RandomIterator<iterator> reverse_iterator;
        typedef RandomIterator<const_iterator> const_reverse_iterator;

    private:
        T *arrays;
        int v_size;
        int v_capicity;

    public:
        explicit vector(const allocator_type &alloc = allocator_type())
        {
        }

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            // this->
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
        vector(const vector &x);
        // vector(void);
        // ~vector();
        // vector(T *ptr);
        // vector &operator=(const vector &ptr);

        // ITERATORS

        iterator begin()
        {
            return (iterator(this->arrays));
        }
        reverse_iterator rbegin(){
            return (reverse_iterator(this->arrays))}

        iterator end()
        {
            return (iterator(this->arrays[v_size]));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(this->arrays[v_size]))
        }

        // CAPACITY
        int size()
        {
            return (v_size);
        }
        void resize(size_type n, value_type val = value_type())
        {
            return ();
        }
    };
};

#endif