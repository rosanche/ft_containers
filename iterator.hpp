
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

/** SRC = https://www.cplusplus.com/reference/iterator/iterator_traits/ **/

namespace ft
{
    template <typename T>
    struct iterator_traits
    {
        typedef typename T::value_type value_type;
        typedef typename T::difference_type difference_type;
        typedef typename T::iterator_category iterator_category;
        typedef typename T::pointer pointer;
        typedef typename T::reference reference;
    };

    template <typename T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
        typedef T *pointer;
        typedef T &reference;
    };

    template <typename T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
        typedef const T *pointer;
        typedef const T &reference;
    };
}
#endif