#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <math.h>
#include <string>
#include <vector>
#include "Human.hpp"
#include <list>

int main()
{
    std::vector<Human> v;
    std::string name;
    std::vector<Human>::iterator it = v.begin();
    std::list<int> l(4);
    auto it2 = l.begin();
    std::vector<Human>::const_reverse_iterator rit;
    std::list<int>::reverse_iterator rit2;
    l = {1, 2, 3, 4};
    while (true)
    {
        std::cin >> name;
        if (name == "q")
        {
            break;
        }
        else if (name == "pop")
        {
            if (!v.empty())
            {
                v.pop_back();
            }
        }
        else
        {
            Human h(name, 0, true, true);
            v.push_back(std::move(h));
            std::cout << '\n' << v.back().getName() << '\n';
        }
    }
    for (rit = v.crbegin(); rit != v.crend(); ++rit)
    {
        std::cout << rit->getName() << '\n';
    }
    for (rit2 = l.rbegin(); rit2 != l.rend(); ++rit2)
    {
        (*rit2)++;
        std::cout << *rit2 << '\n';
    }
    for(const int& e : l)
    {
        std::cout << e << '\n';
    }
    return 0;
}