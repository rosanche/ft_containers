

#include <iostream>
#include <stack>
#include <vector>
#include <deque>

int main()
{
    std::deque<int> mydeque(3, 100);   // deque with 3 elements
    std::vector<int> myvector(2, 200); // vector with 2 elements
    std::stack<int> first;             // empty stack
    std::stack<int> second(mydeque);   // stack initialized to copy of deque

    std::stack<int, std::vector<int> > third; // empty stack using vector
    std::stack<int, std::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    // EMPTY
    std::stack<int> empty_test;
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
    std::stack<int> size_test;
    std::cout << "0. size: " << size_test.size() << '\n';

    for (int i = 0; i < 5; i++)
        size_test.push(i);
    std::cout << "1. size: " << size_test.size() << '\n';

    size_test.pop();
    std::cout << "2. size: " << size_test.size() << '\n';

    // TOP
    std::stack<int> top_test;

    top_test.push(10);
    top_test.push(20);

    top_test.top() -= 5;

    std::cout << "top_test.top() is now " << top_test.top() << '\n';

    // PUSH AND POP
    std::stack<int> push_pop;

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