#include <cstdio>
#include <iostream>
#include <math.h>

struct Wektor2D
{
    public:
        double x = 4.028;
        double y = 1.947;
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
    Wektor2D a;
    a.norm();
    a.print();
    return 0;
}
