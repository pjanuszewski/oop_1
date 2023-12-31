#include <algorithm>
#include <concepts>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <new>
#include <random>
#include <variant>
#include <vector>
#include <numeric>

/////////////////////////////////////////////////////
// Przeklej kawalek kodu ponizej. Wymagany C++20!
namespace detail {
template <typename T>
requires std::floating_point<T> || std::integral<T>
struct rand_dist {};

template <std::integral T>
struct rand_dist<T> {
    using type = std::uniform_int_distribution<T>;
};

template <std::floating_point T>
struct rand_dist<T> {
    using type = std::uniform_real_distribution<T>;
};
}  // namespace detail

template <typename T>
requires std::floating_point<T> || std::integral<T>
using rand_dist_t = typename detail::rand_dist<T>::type;

//
template <typename T>
requires std::floating_point<T> || std::integral<T>
auto makeRandomVector(std::size_t size, T min, T max) {
    static std::mt19937 prng{std::random_device{}()};
    rand_dist_t<T> random_dist{min, max};

    std::vector<T> result;
    result.reserve(size);
    std::generate_n(std::back_inserter(result), size,
                    [&] { return random_dist(prng); });
    return result;
}
//////////////////////////////////////////////////////

// Przyklad uzycia
#include <iostream>

class Foo
{
public:
    Foo(int a) : a(a) {}
    int getA() const { return a; }
    void setA(int a) { this->a = a; }
    int operator()(int a)
    {
        return this->a;
    }
private:
    int a;
};

template < typename ConstIt, typename Comp >
std::vector< size_t > sorted_indices(ConstIt first, ConstIt last, Comp compare) {
    std::vector<size_t> indices(std::distance(first, last));
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(),
        [&](size_t a, size_t b) { return compare(*(first + a), *(first + b)); });

    return indices;
}

int main() 
{
    int size;
    std::cin >> size;
    try
    {
        makeRandomVector(size,0,0);
    }
    catch(const std::bad_alloc& e)
    {
        std::cout << "Bad allocation: " << e.what() << '\n';
    }
    catch(const std::bad_variant_access e)
    {
        std::cout << "Bad variant access: " << e.what() << '\n';
    }
    catch(...)
    {
        std::cout << "Error";
    }
}