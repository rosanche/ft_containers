#ifndef STACK_HPP
#define STACK_HPP

#include "stack.hpp"
#include <deque>

namespace ft
{
    template <class T, class Container = std::deque<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef T value_type;
        typedef size_t size_type;

    protected:
        container_type c;

    public:
        explicit stack(
            const container_type &c = container_type())
            : c(c)
        {
        }

        ~stack()
        {
        }

        bool empty() const
        {
            return (c.empty());
        }

        size_type size() const
        {
            return (c.size());
        }

        value_type &top()
        {
            return (c.back());
        }

        const value_type &top() const
        {
            return (c.back());
        }

        void push(const value_type &val)
        {
            c.push_back(val);
        }

        void pop()
        {
            c.pop_back();
        }

        template <class T_, class Container_>
        friend bool operator==(const stack<T_, Container_> &lhs, const stack<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool operator<(const stack<T_, Container_> &lhs, const stack<T_, Container_> &rhs);
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.c == rhs.c);
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.container < rhs.container);
    }

    // l >= r == l !< r
    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(lhs < rhs);
    }

    // l > r == l !<= r
    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(lhs <= rhs);
    }

    // l <= r == r !< l
    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return !(rhs < lhs);
    }
}

#endif