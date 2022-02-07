#include "../Vector.hpp"

int main()
{
    // initialization
    ft::vector<int> one;
    ft::vector<int> two(10, 90);
    ft::vector<int> three(two.begin(), two.end());
    ft::vector<int> tour(two);

    for (ft::vector<int>::iterator x = two.begin(); x != two.end(); ++x)
        std::cout << "x value :" << x << std::endl;
    
    // ft::vector<int> myvector;
    // for (int i=1; i<=5; i++) myvector.push_back(i);

    // std::cout << "myvector contains:";
    // for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
}