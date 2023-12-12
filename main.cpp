#include <cmath>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>

class Figura
{
public:
    Figura() : pole(0) {};
    Figura(const double &pole) : pole(pole){}; 
    double get_pole() const
    {
        return pole;
    };
    void set_pole(double p)
    {
        pole = p;
    };

    ~Figura() 
    {

    };

private:
    double pole;
};

int main()
{
    return 0;
}