#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator it = easyfind(v, 2);
    std::cout << "Found: " << *it << std::endl;

    it = easyfind(v, 5);

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::list<int>::iterator it2 = easyfind(l, 20);
    std::cout << "Found: " << *it2 << std::endl;

    it2 = easyfind(l, 50);

    return 0;
}
