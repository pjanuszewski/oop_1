#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <math.h>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 100; ++i)
    {
        v.emplace_back(rand() % 100);
        std::cout << v[i] << std::endl;
        std::cout << v.capacity() << std::endl;
        std::cout << v.size() << '\n' << std::endl;
        std::cout << &v[0] << std::endl;
    }
    std::size_t non_empty_vectors = 0;
    for (const auto& vec : v)
    {
        if (vec != 0)
        {
            ++non_empty_vectors;
        }
    }
    return 0;
}