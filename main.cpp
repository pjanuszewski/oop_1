#include <cmath>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include "Wektor2D.h"
#include "Informer.h"

class Wektor
{
    public:
        double *wektor;
        Wektor(const int& n) : wektor(new double[n]), vector_size(n)
        {
            for(int i=0; i < n; i++)
            {
                wektor[i] = 0.0;
            }
        }
        ~Wektor()
        {
            delete[] wektor;
        }
    private:
        double number;
        const unsigned int vector_size;

};

int main()
{
    
}