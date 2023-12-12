#include <cmath>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>

class Shape
{
public:
    Shape() : area(0) 
    {

    };

    Shape(const double &area) : area(area)
    {

    }; 

    double get_area() const
    {
        return area;
    };

    void set_area(double p)
    {
        area = p;
    };

    ~Shape() 
    {

    };

private:
    double area;
};

class Circle : public Shape
{
public:
    Circle(const double &radius) : radius(radius)
    {
        set_area(M_PI * radius * radius);
    };
    double get_radius() const
    {
        return radius;
    };

private:
    double radius;
};

class Square : public Shape
{
public:
    Square(const double &side) : side(side)
    {
        set_area(side * side);
    };
    double get_side() const
    {
        return side;
    };

private:
    double side;
};

int main()
{
    return 0;
}