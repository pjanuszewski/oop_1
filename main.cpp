#include <cmath>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <string>
#include "Wektor2D.h"
#include "Informer.h"

struct Kokardka
{
    Kokardka()      { dlugosc = 42; }
    Kokardka(int d) { dlugosc = d; }
    
    int dlugosc;
};

struct Prezent
{
    Prezent(int dk)
    {
        std::cout << k.dlugosc << std::endl;
        k.dlugosc = dk;
        std::cout << k.dlugosc << std::endl;
    }
    
    Kokardka k;
    // Inne pola ...
};

struct Liczba
{
    Liczba(int w)           : wartosc{w}         { 
        std::cout << "Konstruktor z argumentem: " << w << std::endl;
    }
    /* Liczba(const Liczba& l) : wartosc{l.wartosc} {
        std::cout << "Konstruktor kopiujacy: " << wartosc << std::endl;
    } */
    
    int wartosc;
};

class Wektor
{
    public:
        //double *wektor;
        Wektor(const int& n, const int& length) : capacity(n), wektor(new double[n]), vector_size(length)
        {
            for(int i=0; i < n; i++)
            {
                wektor[i] = 0.0;
            }
        }
        Wektor(const Wektor& w) : capacity(w.capacity), wektor(new double[w.capacity]), vector_size(w.vector_size)
        {
            for(int i=0; i < w.capacity; i++)
            {
                wektor[i] = w.wektor[i];
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

        double &operator[](const int &index)
        {
            if (index < 0)
            {
                std::cout << "Index can't be negative. Index set to 0." << std::endl;
                return wektor[0];
            }
            if (index < vector_size)
            {
                return wektor[index];
            }
            else 
            {
                std::cerr << "Index out of bound. Size increased to: " << index << std::endl;
                Wektor::change_size(index);
                return wektor[index];
            }
        }
    private:
        double *wektor;
        unsigned int vector_size;
        unsigned int capacity;
};

int main()
{
/*  double A[5]{13.32, 54.78, 34.01, 81.5, 5.12};
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
    my_vector[0] = 42.;
    my_vector.print();
    double a = my_vector[0];
    std::cout << a << '\n';
    a++;
    std::cout << a << '\n';
    double b = my_vector[16];
    my_vector.print();
    try {
        double out_of_bounds = my_vector[-3];  // This should throw an error
    } catch (const std::out_of_range& e) {
        std::cout << "Caught an out-of-range exception: " << e.what() << '\n';
    } */
/*     Prezent prezent(15);
    Liczba a{1};
    Liczba b{a};  // W celu konstrukcji b wołamy konstruktor kopiujący z argumentem 'a'
    Liczba c = a; // Tutaj także wołamy konstruktor kopiujący, vide lab. 1
    std::cout << "b: " << b.wartosc << std::endl;
    std::cout << "c: " << c.wartosc << std::endl; */

    double A[5]{13.32, 54.78, 34.01, 81.5, 5.12};
    Wektor my_vector(10,5);
    my_vector.print();

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        my_vector[i] = A[i];
    }
    my_vector.print();
    Wektor copy_vector(my_vector);
    copy_vector.print();
    return 0;
}