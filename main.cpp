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
        Wektor(const int& n, const int& length) : capacity(n), wektor(new double[n]), vector_size(length)
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
        int get_vector_size() const
        {
            return vector_size;
        }
        void print() const 
        {
            for (int i = 0; i < vector_size; i++) 
            {
                std::cout << '\n' << wektor[i];
            }
            std::cout <<'\n';
        }
        int get_capacity() const
        {
            return capacity;
        }
        void change_size(const int &new_size) 
        {
            if (new_size <= capacity) 
            {
                if (new_size <= vector_size) 
                {
                    vector_size = new_size;
                } 
                else 
                {
                    for (int i = vector_size; i <=new_size; i++) 
                    {
                        wektor[i] = 0.0;
                    }
                    vector_size = new_size;
                }
            } 
            else 
            {
                double *new_wektor = new double[new_size];
                for (int i = 0; i < vector_size; i++)
                {
                    new_wektor[i] = wektor[i];
                }
                for (int i = vector_size; i <= new_size; i++) 
                {
                    new_wektor[i] = 0.0;
                }
                delete [] wektor;
                wektor = new_wektor;
                capacity = new_size;
                vector_size = new_size;
            }
        }

        double &operator[](int index)
        {
            return wektor[index];
        }
    private:
        unsigned int vector_size;
        unsigned int capacity;
};


int main()
{
    double A[5]{13.32, 54.78, 34.01, 81.5, 5.12};
    Wektor my_vector(10,5);
    my_vector.print();

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        my_vector[i] = A[i];
    }
    my_vector.print();
    my_vector.change_size(8);
    my_vector.print();

    my_vector.change_size(14);
    my_vector.print();

    std::cout << "Vector size: " << my_vector.get_vector_size() << std::endl;
    std::cout << "Vector capacity: " << my_vector.get_capacity() << std::endl;

    return 0;
}