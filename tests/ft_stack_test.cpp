

#include "../stack.hpp"
#include <iostream> // std::cout
#include <vector>   // std::vector
#include <deque>    // std::deque

int main()
{
    std::deque<int> mydeque(3, 100);   // deque with 3 elements
    std::vector<int> myvector(2, 200); // vector with 2 elements
    ft::stack<int> first;              // empty stack
    ft::stack<int> second(mydeque);    // stack initialized to copy of deque

    ft::stack<int, std::vector<int> > third; // empty stack using vector
    ft::stack<int, std::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    // EMPTY
    ft::stack<int> empty_test;
    int sum(0);

    for (int i = 1; i <= 10; i++)
        empty_test.push(i);

    while (!empty_test.empty())
    {
        sum += empty_test.top();
        empty_test.pop();
    }

    std::cout << "total: " << sum << '\n';

    // SIZE
    ft::stack<int> size_test;
    std::cout << "0. size: " << size_test.size() << '\n';

    for (int i = 0; i < 5; i++)
        size_test.push(i);
    std::cout << "1. size: " << size_test.size() << '\n';

    size_test.pop();
    std::cout << "2. size: " << size_test.size() << '\n';

    // TOP
    ft::stack<int> top_test;

    top_test.push(10);
    top_test.push(20);

    top_test.top() -= 5;

    std::cout << "top_test.top() is now " << top_test.top() << '\n';

    // PUSH AND POP
    ft::stack<int> push_pop;

    for (int i = 0; i < 5; ++i)
        push_pop.push(i);

    std::cout << "Popping out elements...";
    while (!push_pop.empty())
    {
        std::cout << ' ' << push_pop.top();
        push_pop.pop();
    }
    std::cout << '\n';
}