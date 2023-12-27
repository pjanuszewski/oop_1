# include "Human.hpp"
# include <list>
# include <iostream>

int main()
{
    std::list<int> list;
    list.push_front(10); // error: no match for ‘operator[]’ (operand types are ‘std::list<int>’ and ‘int’)
    list.emplace_back(20);
    list.emplace_front(30);
    list.emplace_front(23);
    list.emplace_back(54);
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    std::cout << &list.front() << std::endl;
    std::cout << &list.back() << std::endl;
    return 0;
}