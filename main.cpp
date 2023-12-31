#include <algorithm>
#include <concepts>
#include <cstdio>
#include <iterator>
#include <random>
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

int main() 
{
   /* constexpr auto print_vector = [](const auto& vec) {
        for (const auto& el : vec) std::cout << el << ' ';
        std::cout << '\n';
    };
    auto v1 = makeRandomVector<int>(12, 0, 10);
    print_vector(v1);
    std::sort(v1.begin(), v1.end());
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
    std::cout << std::count_if(v1.begin(), v1.end(), [obiekt](auto el) { return el > obiekt.getA();}) << '\n'; 
    auto val = [](){int v; std::cin >> v; return v;}();
    std::cout << std::count_if(v1.begin(), v1.end(), [&](auto el){return el > val;}) << '\n';*/

/*     std::string string_1;
    std::getline(std::cin, string_1);
    auto it = std::adjacent_find(string_1.begin(), string_1.end());
    if (it == string_1.end())
    {
        std::cout << 0 << '\n';
    }
    else
    {
        std::cout << 1 << '\n';
    }
    
    std::string string_2 = "abc";
    auto it_2 = std::search(string_1.begin(), string_1.end(), string_2.begin(), string_2.end());
    if (it_2 != string_1.end()) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not Found\n";
    }
    std::reverse(string_1.begin(), string_1.end());
    std::cout << string_1 << '\n';
     */
    auto print_vector = [](const auto& vec) {
        for (const auto& el : vec) std::cout << el << ' ';
        std::cout << '\n';
    };

    auto v1 = makeRandomVector<double>(10, 0, 10);
    print_vector(v1);
    std::cout << std::inner_product(v1.begin(), v1.end(), v1.begin(), 0.0) << '\n';

    auto v2 = makeRandomVector<int>(10, 0, 10);
    print_vector(v2);
    auto a = std::find(v2.begin(), v2.end(), 7);
    std::sort(v2.begin(), a);
    print_vector(v2);

    auto v3 = makeRandomVector<int>(10, 0, 10);
    print_vector(v3);
    v3.erase(std::remove(v3.begin(), v3.end(), 7), v3.end());
    print_vector(v3);
    std::cout << size(v3) << '\n';

    auto v4 = makeRandomVector<int>(10, 0, 10);
    print_vector(v4);
    std::rotate(v4.begin(), std::find(v4.begin(), v4.end(), 7), v4.end());
    print_vector(v4);

    auto v5 = makeRandomVector<double>(10, -1, 1);
    print_vector(v5);
    std::any_of(v5.begin(), v5.end(), [](auto el) { return el > 0.9; }) ? std::cout << "Tak\n" : std::cout << "Nie\n";

    std::transform(v5.begin(), v5.end(), v5.begin(), [](auto el) { return sin(el); });
    print_vector(v5);

    auto v6 = makeRandomVector<int>(10, 0, 10);
    print_vector(v6);
    auto pivot = std::partition(v6.begin(), v6.end(), [](auto el) { return el > 6; });
    std::sort(v6.begin(), pivot);
    print_vector(v6);
    std::sort(pivot, v6.end());
    print_vector(v6);
    return 0;
}