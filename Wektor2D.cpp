#include "Wektor2D.h"
#include <iostream>

int Wektor2D::num_wek = 0;

Wektor2D::Wektor2D(const std::string& dMsg) : destructorMessage(dMsg) {
    std::cout << "Constructor activated";
    ++num_wek;
}

Wektor2D::Wektor2D() : x(0.0), y(0.0) {
    ++num_wek;
}

Wektor2D Wektor2D::polar_coordinates(double r, double theta) {
    double x = r * cos(theta);
    double y = r * sin(theta);
    return Wektor2D(x, y);
}

Wektor2D Wektor2D::cartesian_coordinates(double a, double b) {
    return Wektor2D(a, b);
}

double Wektor2D::norm() {
    double n = sqrt(x * x + y * y);
    std::cout << '\n' << n << '\n';
    return n;
}

void Wektor2D::print() {
    std::cout << '\n' << x << '\n' << y << '\n';
}

Wektor2D::~Wektor2D() {
    std::cout << "\n" << "Destructor activated: " << destructorMessage;
    --num_wek;
}

Wektor2D operator+(const Wektor2D& w1, const Wektor2D& w2) {
    double x1 = w1.x + w2.x;
    double y1 = w1.y + w2.y;
    return Wektor2D(x1, y1);
}

Wektor2D operator*(const Wektor2D& w1, const Wektor2D& w2) {
    double x1 = w1.x * w2.x;
    double y1 = w1.y * w2.y;
    return Wektor2D(x1, y1);
}
