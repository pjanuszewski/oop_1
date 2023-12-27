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
    std::vector<int> v{100, 42};
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    std::cout << v[99] << std::endl;
    return 0;
}