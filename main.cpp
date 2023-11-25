#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>

struct Informer
{
    Informer()
    {
        std::cout << "Informer constructor" << '\n';
    }
    ~Informer()
    {
        std::cout << '\n' << "Informer destructor" << '\n';
    }
};

struct Wektor2D
{   
public:
    Informer informer;
    std::string destructorMessage;
    void set_x(double a)
    {
        x = a;
    }
    void set_y(double a)
    {
        y = a;
    }
    Wektor2D(const std::string& dMsg) : destructorMessage(dMsg)
    {
        std::cout << "Constructor activated";
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
    double get_x(){return x;}
    double get_y(){return y;}

    private:
        double x;
        double y;
};

int main()
{
    Wektor2D first_vector{"First"};
    first_vector.set_x(4);
    first_vector.set_y(6);
    first_vector.norm();
    first_vector.print();
}