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

int main()
{
    std::vector<Human> v;
    std::string name;
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
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i].getName() << '\n';
    }
    return 0;
}