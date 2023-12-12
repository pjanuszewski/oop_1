#include <cmath>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>


class Geometry
{
public:
    Geometry()
    {
        std::cout << "Geometry constructor" << std::endl;
    };
    void id()
    {

    };
    virtual ~Geometry()
    {
        std::cout << "Geometry destructor" << std::endl;
    };

};

class Shape : public Geometry
{
public:
    Shape(const double &area) : area(area)
    {
        
    }; 

    double get_area() const
    {
        return area;
    };

    virtual void id() const
    {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Area: " << area << std::endl;
    };

    virtual ~Shape() 
    {
        std::cout << "Shape destructor" << std::endl;
    };

private:
    double area;
protected:
    std::string name;
};

class Shape_Vector
{
public:
    Shape_Vector() : wektor(new Shape*[1000])
    {
        std::cout << "Shape_Vector constructor" << std::endl;
    };
    virtual ~Shape_Vector()
    {
        for(int i = 0; i < number_of_shapes; i++)
        {
            delete wektor[i];
        }
        delete[] wektor;
        std::cout << "Shape_Vector destructor" << std::endl;
    };
    void add(Shape* shape)
    {
        wektor[number_of_shapes] = shape;
        number_of_shapes++;
    };
    Shape* operator[](const unsigned int &index)
    {
        if(index >= number_of_shapes)
        {
            std::cout << "Index out of range" << std::endl;
            return nullptr;
        }
        else
        {
            return wektor[index];
        }
    };
protected:
    unsigned int number_of_shapes = 0;
private:
    Shape** wektor;
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

    void id() const override
    {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Area: " << get_area() << std::endl;
        std::cout << "Radius: " << radius << std::endl;
    };
    ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
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

    void id() const override
    {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Area: " << get_area() << std::endl;
        std::cout << "Side: " << side << std::endl;
    };
    ~Square()
    {
        std::cout << "Square destructor" << std::endl;
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
    //Square square_1(5);
    //Circle circle_1(5);

    Shape* f = new Square{5};
    id(*f);
    delete f;

    Geometry shape_1;
    return 0;
}