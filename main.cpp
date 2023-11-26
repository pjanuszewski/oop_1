#include <cmath>
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
        double get_x() const {
        return x;
    }

    double get_y() const 
    {
        return y;
    }
    Wektor2D(const std::string& dMsg) : destructorMessage(dMsg)
    {
        std::cout << "Constructor activated";
    }
    Wektor2D() : x(0.0), y(0.0) {}
    Wektor2D(double a, double b) : x(a), y(b) {}
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

Wektor2D operator+(const Wektor2D& w1, const Wektor2D& w2)
{
    double x1 = w1.get_x() + w2.get_x();
    double y1 = w1.get_y() + w2.get_y();
    return Wektor2D(x1,y1);
}
Wektor2D operator*(const Wektor2D& w1, const Wektor2D& w2)
{
    double x1 = w1.get_x() * w2.get_x();
    double y1 = w1.get_y() * w2.get_y();
    return Wektor2D(x1, y1);
}
std::ostream& operator<<(std::ostream& os, const Wektor2D& vector) {
    os << "x: " << vector.get_x() << ", y: " << vector.get_y();
    return os;
}

int main()
{
    Wektor2D first(4, 2);
    Wektor2D second(3, 9);
    Wektor2D sum = first + second;
    Wektor2D il = first*second;
    first.print();
    second.print();
    std::cout << '\n' << sum << '\n';
    std::cout << '\n' << il << '\n';
}