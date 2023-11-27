#pragma once
#include "Informer.h"
#include <cmath>
#include <string>

class Wektor2D 
{
public:
    Informer informer;                                          // Create object of class Informer
    std::string destructorMessage;
    Wektor2D(const std::string& dMsg);
    Wektor2D();
    static Wektor2D polar_coordinates(double r, double theta);
    static Wektor2D cartesian_coordinates(double a, double b);
    double norm();
    void print();
    static double get_num_wek();

    friend Wektor2D operator+(const Wektor2D& w1, const Wektor2D& w2);
    friend Wektor2D operator*(const Wektor2D& w1, const Wektor2D& w2);

    ~Wektor2D();

private:
    double x;
    double y;
    static int num_wek;

    Wektor2D(double a, double b);
};
