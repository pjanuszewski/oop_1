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

    void id() const
    {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Area: " << area << std::endl;
    };

    ~Shape() 
    {

    };

private:
    double area;
protected:
    std::string name;
};

class Circle : public Shape
{
public:
    Circle(const double &radius) : radius(radius), Shape{M_PI * radius * radius}
    {
        name = "Circle";
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
    Square(const double &side) : side(side), Shape{side * side}
    {
        name = "Square";
    };
    double get_side() const
    {
        return side;
    };

private:
    double side;
};

void id(const Shape &shape)
{
    shape.id();
};

int main()
{
    Square square_1(5);
    Circle circle_1(5);

    square_1.id();
    circle_1.id();
    id(square_1);
    return 0;
}