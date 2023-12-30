#include <algorithm>
#include <concepts>
#include <iterator>
#include <random>
#include <vector>

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

int main() 
{
    constexpr auto print_vector = [](const auto& vec) {
        for (const auto& el : vec) std::cout << el << ' ';
        std::cout << '\n';
    };
    auto v1 = makeRandomVector<int>(12, 0, 10);
    print_vector(v1);
/*    std::sort(v1.begin(), v1.end());
    print_vector(v1);
    std::cout << '\n' << std::count(v1.begin(), v1.end(), 7) << '\n';
    std::sort(v1.begin(), v1.end(), std::greater<>{});
    print_vector(v1);
    std::cout << '\n' << std::count_if(v1.begin(), v1.end(), [](auto el) { return el > 7;}) << '\n';
    Foo obiekt([]()
    {
        int temp;
        std::cin >> temp;
        return temp;
    }
    ());
    std::cout << std::count_if(v1.begin(), v1.end(), [obiekt](auto el) { return el > obiekt.getA();}) << '\n'; */
    auto val = [](){int v; std::cin >> v; return v;}();
    std::cout << std::count_if(v1.begin(), v1.end(), [&](auto el){return el > val;}) << '\n';
}