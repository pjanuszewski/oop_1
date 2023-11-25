#include <cstdio>
#include <iostream>
#include <math.h>

struct Wektor2D
{
    public:
        double x;
        double y;
        std::string destructorMessage;
    Wektor2D(double a, double b, const std::string& dMsg) : destructorMessage(dMsg)
    {
        x = a;
        y = b;
        std::cout << "Constructor activated: " << x << "    " << y << '\n';
    }
    ~Wektor2D()
    {
        std::cout << "\n" << "Destructor activated: " << destructorMessage;
    }
    double norm()
    {
        double n = sqrt(x*x + y*y);
        std::cout << '\n' << n << '\n';
        return n;
    }
    void print()
    {
        std::cout << '\n' << x << '\n' << y << '\n';
    }
};

int main(){
    Wektor2D first_vector{4.028, 6.932, "First"};
    Wektor2D second_vector{2.352, 6.321, "Second"};
    Wektor2D third_vector{9.234, 0.624, "Third"};
    first_vector.norm();
    first_vector.print();
    second_vector.norm();
    second_vector.print();
    third_vector.norm();
    third_vector.print();
}
