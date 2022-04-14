

#include "../map.hpp"
#include <iostream> // std::cout
#include <vector>   // std::vector
#include <deque>    // std::deque

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

int main()
{
    // INITIALIZATION / CONSTRUCTOR
    ft::map<char, int> first;

    first['a'] = 30;
    first['b'] = 40;
    first['c'] = 60;
    first['d'] = 70;

    ft::map<char, int> second(first.begin(), first.end());

    ft::map<char, int> third(second);

    ft::map<char, int, classcomp> fourth;

    // OPERATORS
    ft::map<char, int> one;
    ft::map<char, int> two;

    one['x'] = 8;
    one['y'] = 16;
    one['z'] = 32;

    two = one;                  // two now contains 3 ints
    one = ft::map<char, int>(); // and one is now empty

    std::cout << "Size of one: " << one.size() << '\n';
    std::cout << "Size of two: " << two.size() << '\n';

    // ITERATORS
    ft::map<char, int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    ft::map<char, int>::reverse_iterator rit;
    for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';

    // CAPACITY
    ft::map<char, int> cap_test;
    std::cout << "map size is " << cap_test.size() << '\n';

    cap_test['a'] = 10;
    cap_test['b'] = 20;
    cap_test['c'] = 30;

    std::cout << "after adding 3 elements map size is " << cap_test.size() << '\n';
    cap_test.insert(ft::pair<char, int>('d', 40));
    std::cout << "after inserting 1 elements map size is " << cap_test.size() << '\n';
    cap_test.erase('d');
    std::cout << "after erasing 1 elements map size is " << cap_test.size() << '\n';

    std::cout << "printing map while it's not empty \n";
    while (!cap_test.empty())
    {
        std::cout << cap_test.begin()->first << " => " << cap_test.begin()->second << '\n';
        cap_test.erase(cap_test.begin());
    }

    // MAX SIZE
    int i;
    ft::map<int, int> max_test;

    if (max_test.max_size() > 1000)
    {
        for (i = 0; i < 1000; i++)
            max_test[i] = 0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else
        std::cout << "The map could not hold 1000 elements.\n";

    // ACCESS OPERATOR
    ft::map<char, std::string> op_test;

    op_test['a'] = "an element";
    op_test['b'] = "another element";
    op_test['c'] = op_test['b'];

    std::cout << "op_test['a'] is " << op_test['a'] << '\n';
    std::cout << "op_test['b'] is " << op_test['b'] << '\n';
    std::cout << "op_test['c'] is " << op_test['c'] << '\n';
    std::cout << "op_test['d'] is " << op_test['d'] << '\n';

    std::cout << "op_test now contains " << op_test.size() << " elements.\n";

    // INSERT/ERASE
    ft::map<char, int> ins_test;

    // first insert function version (single parameter):
    ins_test.insert(ft::pair<char, int>('a', 100));
    ins_test.insert(ft::pair<char, int>('z', 200));

    ft::pair<ft::map<char, int>::iterator, bool> ins_pair;
    ins_pair = ins_test.insert(ft::pair<char, int>('z', 500));
    if (ins_pair.second == false)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ins_pair.first->second << '\n';
    }

    // second insert function version (with hint position):
    ft::map<char, int>::iterator ins_it = ins_test.begin();
    ins_test.insert(ins_it, ft::pair<char, int>('b', 300)); // max efficiency inserting
    ins_test.insert(ins_it, ft::pair<char, int>('c', 400)); // no max efficiency inserting

    // third insert function version (range insertion):
    ft::map<char, int> anothermap;
    anothermap.insert(ins_test.begin(), ins_test.find('c'));

    // showing contents:
    std::cout << "ins_test contains:\n";
    for (ins_it = ins_test.begin(); ins_it != ins_test.end(); ++ins_it)
        std::cout << ins_it->first << " => " << ins_it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (ins_it = anothermap.begin(); ins_it != anothermap.end(); ++ins_it)
        std::cout << ins_it->first << " => " << ins_it->second << '\n';

    ins_test['d'] = 40;
    ins_test['e'] = 50;

    std::cout << "ins_test contains:\n";
    for (ins_it = ins_test.begin(); ins_it != ins_test.end(); ++ins_it)
        std::cout << ins_it->first << " => " << ins_it->second << '\n';

    ins_it = ins_test.find('b');
    ins_test.erase(ins_it); // erasing by ins_iterator

    ins_test.erase('c'); // erasing by key

    ins_it = ins_test.find('e');
    ins_test.erase(ins_it, ins_test.end()); // erasing by range

    // show content:
    std::cout << "ins_test contains:\n";
    for (ins_it = ins_test.begin(); ins_it != ins_test.end(); ++ins_it)
        std::cout << ins_it->first << " => " << ins_it->second << '\n';

    // OTHERS MODIFIERS
    ft::map<char, int> foo, bar;

    foo['x'] = 100;
    foo['y'] = 200;

    bar['a'] = 11;
    bar['b'] = 22;
    bar['c'] = 33;

    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    ft::map<char, int> mod_test;

    mod_test['x'] = 100;
    mod_test['y'] = 200;
    mod_test['z'] = 300;

    std::cout << "mod_test contains:\n";
    for (ft::map<char, int>::iterator it = mod_test.begin(); it != mod_test.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    mod_test.clear();
    mod_test['a'] = 1101;
    mod_test['b'] = 2202;

    std::cout << "mod_test contains:\n";
    for (ft::map<char, int>::iterator it = mod_test.begin(); it != mod_test.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    // KEY COMPARISON
    ft::map<char, int> key_test;

    ft::map<char, int>::key_compare mycomp = key_test.key_comp();

    key_test['a'] = 100;
    key_test['b'] = 200;
    key_test['c'] = 300;

    std::cout << "key_test contains:\n";

    char key_char = key_test.rbegin()->first; // key value of last element

    ft::map<char, int>::iterator key_it = key_test.begin();
    do
    {
        std::cout << key_it->first << " => " << key_it->second << '\n';
    } while (mycomp((*key_it++).first, key_char));

    std::cout << '\n';

    // VALUE COMPARISON
    ft::map<char, int> comp_test;

    comp_test['x'] = 1001;
    comp_test['y'] = 2002;
    comp_test['z'] = 3003;

    std::cout << "comp_test contains:\n";

    ft::pair<char, int> highest = *comp_test.rbegin(); // last element

    ft::map<char, int>::iterator comp_it = comp_test.begin();
    do
    {
        std::cout << comp_it->first << " => " << comp_it->second << '\n';
    } while (comp_test.value_comp()(*comp_it++, highest));

    // FIND / COUNT
    ft::map<char, int> find_test;
    ft::map<char, int>::iterator find_it;

    find_test['a'] = 50;
    find_test['b'] = 100;
    find_test['c'] = 150;
    find_test['d'] = 200;

    find_it = find_test.find('b');
    if (find_it != find_test.end())
        find_test.erase(find_it);

    // print content:
    std::cout << "elements in find_test:" << '\n';
    std::cout << "a => " << find_test.find('a')->second << '\n';
    std::cout << "c => " << find_test.find('c')->second << '\n';
    std::cout << "d => " << find_test.find('d')->second << '\n';

    ft::map<char, int> count_test;
    char c;

    count_test['a'] = 101;
    count_test['c'] = 202;
    count_test['f'] = 303;

    for (c = 'a'; c < 'h'; c++)
    {
        std::cout << c;
        if (count_test.count(c) > 0)
            std::cout << " is an element of count_test.\n";
        else
            std::cout << " is not an element of count_test.\n";
    }

    // LOWER / UPPER
    ft::map<char, int> low_up;
    ft::map<char, int>::iterator itlow, itup;

    low_up['a'] = 20;
    low_up['b'] = 40;
    low_up['c'] = 60;
    low_up['d'] = 80;
    low_up['e'] = 100;

    itlow = low_up.lower_bound('b'); // itlow points to b
    itup = low_up.upper_bound('d');  // itup points to e (not d!)

    low_up.erase(itlow, itup); // erases [itlow,itup)

    // print content:
    for (ft::map<char, int>::iterator it = low_up.begin(); it != low_up.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    // EQUAL
    ft::map<char, int> equal_test;

    equal_test['a'] = 10;
    equal_test['b'] = 20;
    equal_test['c'] = 30;

    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    ret = equal_test.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';

    // MAP ALLOCATOR
    int psize;
    ft::map<char, int> alloc_test;
    ft::pair<const char, int> *p;

    // allocate an array of 5 elements using alloc_test's allocator:
    p = alloc_test.get_allocator().allocate(5);

    // assign some values to array
    psize = sizeof(ft::map<char, int>::value_type) * 5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    alloc_test.get_allocator().deallocate(p, 5);

    // NON MEMBERS OPERATORS
    ft::map<char, int> foo2, bar2;
    foo2['a'] = 100;
    foo2['b'] = 200;
    bar2['a'] = 10;
    bar2['z'] = 1000;

    // foo2 ({{a,100},{b,200}}) vs bar2 ({a,10},{z,1000}}):
    if (foo2 == bar2)
        std::cout << "foo2 and bar2 are equal\n";
    if (foo2 != bar2)
        std::cout << "foo2 and bar2 are not equal\n";
    if (foo2 < bar2)
        std::cout << "foo2 is less than bar2\n";
    if (foo2 > bar2)
        std::cout << "foo2 is greater than bar2\n";
    if (foo2 <= bar2)
        std::cout << "foo2 is less than or equal to bar2\n";
    if (foo2 >= bar2)
        std::cout << "foo2 is greater than or equal to bar2\n";
}
