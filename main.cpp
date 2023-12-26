#include <cmath>
#include <cstdio>
#include <iostream>
#include <istream>
#include <math.h>
#include <string>
#include <tuple>
#include <utility>

template <typename T> class Pair
{
private:
    T first;
    T second;
public:
    Pair() : first(), second() {}
    Pair (const T& first_element,const T& second_element)
    {
        first = first_element;
        second = second_element;
    }
    T sum() const
    {
        return first + second;
    }
    const Pair<T> operator+(const Pair<T>& pair) const
    {
        return Pair<T>(this->first + pair.first, this->second + pair.second);
    }
    void print() const
    {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

template <typename T, unsigned int N> class Array_of_Pairs
{
private:
    Pair<T> array[N];
public:
    Array_of_Pairs() : array() {}
    Pair<T>& operator[](const unsigned int& index)
    {
        return array[index];
    }
    Pair<T> sum() const
    {
        Pair<T> sum = Pair<T>(0,0);
        for (int i = 0; i < N; i++)
        {
            sum = sum + array[i];
        }
        return sum;
    }
};
template <typename T> class Array_of_Pairs<T, 0>
{};

template <typename T, std::size_t N> T multiply(const T (&a)[N])
{
    T result = 1;
    for (int i = 0; i < N; i++)
    {
        result *= a[i];
    }
    return result;
};

template <typename T>
struct S {
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S<double> {
    void print() { puts("Specjalizacja dla double"); }
};

template <typename T> T sum_of_pair(const Pair<T>& pair)
{
    return pair.sum(); 
};

int main()
{
    Pair<int> p1(1, 1);
    Pair<int> p2(2, 2);
    Pair<int> p3(3, 3);
    Pair<double> p4(1.1, 1.1);
    Pair<double> p5(2.2, 2.2);
    Pair<double> p6(3.3, 3.3);
    Array_of_Pairs<int, 3> array_of_pairs1;
    Array_of_Pairs<double, 3> array_of_pairs2;
    array_of_pairs1[0] = p1; array_of_pairs1[1] = p2; array_of_pairs1[2] = p3;
    array_of_pairs2[0] = p4; array_of_pairs2[1] = p5; array_of_pairs2[2] = p6;
    array_of_pairs1.sum().print();
    array_of_pairs2.sum().print();
    S<int> s1;
    S<char> s3;
    S<double> s2;
    s1.print();
    s2.print();
    s3.print();
    int a[3] = {1, 2, 3};
    std::cout << multiply(a) << std::endl;
    std::cout << sum_of_pair(p1) << std::endl;
    return 0;
}