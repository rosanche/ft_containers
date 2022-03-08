#ifndef STACK_HPP
#define STACK_HPP

#include "../Vector/Vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T>>
    class stack
    {
    public:
        typedef Container container_type;
        typedef T value_type;
        typedef size_t size_type;

    public:
        explicit Stack(
            const container_type &container = container_type())
            : container_type(container)
        {
        }

        ~Stack()
        {
        }

        template <class T, class Container>
        bool operator==(const Stack<T, Container> &a, const Stack<T, Container> &b)
        {
            return (a.container_type == b.container_type);
        }

        template <class T, class Container>
        bool operator!=(const Stack<T, Container> &a, const Stack<T, Container> &b)
        {
            return (a.container_type != b.container_type);
        }

        template <class T, class Container>
        bool operator<(const Stack<T, Container> &a, const Stack<T, Container> &b)
        {
            return (a.container_type < b.container_type);
        }

        template <class T, class Container>
        bool operator<=(const Stack<T, Container> &a, const Stack<T, Container> &b)
        {
            return (a.container_type <= b.container_type);
        }

        template <class T, class Container>
        bool operator>(const Stack<T, Container> &a, const Stack<T, Container> &b)
        {
            return (a.container_type > b.container_type);
        }

        template <class T, class Container>
        bool operator>=(const Stack<T, Container> &a, const Stack<T, Container> &b)
        {
            return (a.container_type >= b.container_type);
        }

        bool empty() const
        {
            return (container_type.empty());
        }

        size_type size() const
        {
            return (container_type.size());
        }

        value_type &top()
        {
            return (container_type.back());
        }

        const value_type &top() const
        {
            return (container_type.back());
        }

        void push(const value_type &val)
        {
            container_type.push_back(val);
        }

        void pop()
        {
            container_type.pop_back();
        }
    }
};

#endif