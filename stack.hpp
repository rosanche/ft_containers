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
        container_type container;

    public:
        explicit stack(
            const container_type &container = container_type())
            : container(container)
        {
        }

        ~stack()
        {
        }

        bool empty() const
        {
            return (container.empty());
        }

        size_type size() const
        {
            return (container.size());
        }

        value_type &top()
        {
            return (container.back());
        }

        const value_type &top() const
        {
            return (container.back());
        }

        void push(const value_type &val)
        {
            container.push_back(val);
        }

        void pop()
        {
            container.pop_back();
        }

        template <class T_, class Container_>
        friend bool operator==(const stack<T_, Container_> &lhs, const stack<T_, Container_> &rhs);

        template <class T_, class Container_>
        friend bool operator<(const stack<T_, Container_> &lhs, const stack<T_, Container_> &rhs);
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return (lhs.container == rhs.container);
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