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

class Shape_visitor_base;

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

    virtual void accept(Shape_visitor_base &visitor) = 0;

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
    Shape_Vector() : vector(new Shape*[1000])
    {
        std::cout << "Shape_Vector constructor" << std::endl;
    };
    virtual ~Shape_Vector()
    {
        for(int i = 0; i < number_of_shapes; i++)
        {
            delete vector[i];
        }
        delete[] vector;
        std::cout << "Shape_Vector destructor" << std::endl;
    };
    void add(Shape* shape)
    {
        vector[number_of_shapes] = shape;
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
            return vector[index];
        }
    };
    void push(Shape* shape)
    {
        add(shape);
    };
    void pop()
    {
        delete vector[number_of_shapes - 1];
        number_of_shapes--;
    };
    void id_all()
    {
        for(int i = 0; i < number_of_shapes; i++)
        {
            vector[i]->id();
        }
    };
protected:
    unsigned int number_of_shapes = 0;
private:
    Shape** vector;
};
class Shape_visitor_base;
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
    void accept(Shape_visitor_base &visitor) override
    {
        visitor.visit(*this);
    };
    ~Circle()
    {
        std::cout << "Circle destructor" << std::endl;
    };
private:
    
    double radius;
};
class Shape_visitor_base;
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
    void accept(Shape_visitor_base &visitor) override
    {
        visitor.visit(*this);
    };
    ~Square()
    {
        std::cout << "Square destructor" << std::endl;
    };
private:
    double side;
};

class Shape_visitor_base
{
public:
    virtual void visit(Square &shape) = 0;
    virtual void visit(Circle &shape) = 0;
    virtual ~Shape_visitor_base() = default;
};

class Shape_Factory
{
public:
    Shape* operator()(const std::string &name, const double &value)
    {
        if(name == "Circle")
        {
            return new Circle{value};
        }
        else if(name == "Square")
        {
            return new Square{value};
        }
        else
        {
            std::cout << "Invalid shape name" << std::endl;
            return nullptr;
        }
    };
private:
};

void id(const Shape &shape)
{
    shape.id();
};

int main()
{
    //Square square_1(5);
    //Circle circle_1(5);

    Geometry shape_1;
    return 0;
}