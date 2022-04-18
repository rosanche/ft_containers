#include "../vector.hpp"

int main()
{
    // INITIALIZATION
    ft::vector<int> one;
    ft::vector<int> two(10, 90);
    ft::vector<int> three(two.begin(), two.end());
    ft::vector<int> tour(two);

    for (ft::vector<int>::iterator x = two.begin(); x != two.end(); ++x)
        std::cout << "x value :" << *x << std::endl;

    // SIZE AND CAPACITY
    ft::vector<int> test_size;
    std::cout << "\nsize: empty container : " << test_size.size() << '\n';

    for (int i = 0; i < 7; i++)
        test_size.push_back(i);
    std::cout << "size after 7 push back : " << test_size.size() << '\n';

    test_size.insert(test_size.end(), 15, 100);
    std::cout << "size after inserting 15 : " << test_size.size() << '\n';

    test_size.pop_back();
    std::cout << "size after a pop back : " << test_size.size() << '\n';

    test_size.resize(19);
    std::cout << "resize at 19 : " << test_size.size() << '\n';

    if (!test_size.empty())
        std::cout << "container isn't empty" << '\n';

    test_size.clear();
    std::cout << "size after clear: " << test_size.size() << '\n';

    if (test_size.empty())
        std::cout << "container is empty\n"
                  << '\n';

    ft::vector<int> capacity_test;

    // set some content in the vector:
    for (int i = 0; i < 100; i++)
        capacity_test.push_back(i);

    std::cout << "size: " << (int)capacity_test.size() << '\n';
    std::cout << "capacity: " << (int)capacity_test.capacity() << '\n';
    std::cout << "max_size: " << (int)capacity_test.max_size() << '\n';

    for (int i = 0; i < 50; i++)
        capacity_test.push_back(i);
    std::cout << "\nafter 50 push_back : \n";
    std::cout << "size: " << capacity_test.size() << "\n";
    std::cout << "capacity: " << capacity_test.capacity() << "\n";
    std::cout << "max_size: " << capacity_test.max_size() << "\n";

    std::cout << "\nafter reserve 250 : \n";

    capacity_test.reserve(250);
    std::cout << "size: " << capacity_test.size() << "\n";
    std::cout << "capacity: " << capacity_test.capacity() << "\n";
    std::cout << "max_size: " << capacity_test.max_size() << "\n";

    // PUSH BACK AND POP BACK
    ft::vector<int> vector;
    for (int i = 1; i <= 5; i++)
        vector.push_back(i);

    std::cout << "vector contains:";
    for (ft::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    for (int i = 0; i <= 3; i++)
        vector.pop_back();
    vector.push_back(8);
    std::cout
        << "vector now only contains 3 in disorder with new element:";
    ft::vector<int>::iterator it;
    for (it = vector.end(); it != vector.begin(); --it)
        std::cout
            << ' ' << *it;
    std::cout << ' ' << *it;
    std::cout << '\n';

    // MODIFIERS ASSIGN
    std::cout << "\nassigning in differents way\n\n";
    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign(7, 100); // 7 ints with a value of 100

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';

    std::cout << "\nMy vector " << '\n';
    for (ft::vector<int>::iterator one = first.begin(); one != first.end(); ++one)
        std::cout << ' ' << *one;

    first.push_back(15);

    std::cout << "\nAfter push back 15" << '\n';
    for (ft::vector<int>::iterator one = first.begin(); one != first.end(); ++one)
        std::cout << ' ' << *one;

    std::cout << "\nAfter pop back" << '\n';
    first.pop_back();
    for (ft::vector<int>::iterator one = first.begin(); one != first.end(); ++one)
        std::cout << ' ' << *one;

    // INSERT
    ft::vector<int> insert_test(3, 100);
    ft::vector<int>::iterator insert_it;

    insert_it = insert_test.begin();
    insert_it = insert_test.insert(insert_it, 200);

    insert_test.insert(insert_it, 2, 300);

    // "it" no longer valid, get a new one:
    insert_it = insert_test.begin();

    ft::vector<int> newvector(2, 400);
    insert_test.insert(insert_it + 2, newvector.begin(), newvector.end());

    int stdarray[] = {501, 502, 503};
    insert_test.insert(insert_test.begin(), stdarray, stdarray + 3);

    std::cout << "\ninsert_test contains:";
    for (insert_it = insert_test.begin(); insert_it < insert_test.end(); insert_it++)
        std::cout << ' ' << *insert_it;
    std::cout << '\n';

    // ERASE AND CLEAR
    ft::vector<int> erase_test;
    for (int i = 1; i <= 10; i++)
        erase_test.push_back(i);
    std::cout << "\n\n erase_test contains:";
    for (unsigned i = 0; i < erase_test.size(); ++i)
        std::cout << ' ' << erase_test[i];
    erase_test.erase(erase_test.begin() + 5);
    erase_test.erase(erase_test.begin(), erase_test.begin() + 3);

    std::cout << "\n erase_test contains after erase:";
    for (unsigned i = 0; i < erase_test.size(); ++i)
        std::cout << ' ' << erase_test[i];
    std::cout << '\n';

    ft::vector<int> foo(3, 100); // three ints with a value of 100
    ft::vector<int> bar(5, 200); // five ints with a value of 200

    std::cout << "\noriginal std foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "original std bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';

    foo.swap(bar);

    std::cout << "after swap std foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "after swap std bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';

    foo.clear();
    std::cout << "\nstd foo size after clear = " << foo.size();

    // SWAP
    ft::vector<int> a(3, 100); // three ints with a value of 100
    ft::vector<int> b(5, 200); // five ints with a value of 200

    a.swap(b);

    std::cout << "a contains:";
    for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "b contains:";
    for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    // OPERATORS AT
    ft::vector<int> at_test(10);

    for (unsigned i = 0; i < at_test.size(); i++)
        at_test.at(i) = i;

    std::cout << "at_test contains:";
    for (unsigned i = 0; i < at_test.size(); i++)
        std::cout << ' ' << at_test.at(i);
    std::cout << '\n';

    // OPERATORS FRONT AND BACK
    ft::vector<int> front_back;

    front_back.push_back(50);
    front_back.push_back(10);

    front_back.front() -= front_back.back();

    // the result should be 40
    std::cout << "front_back.front() is now " << front_back.front() << '\n';
}