#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
public:
    double re;
    double im;
 
    Complex(double real, double imag): re(real), im(imag) {};

    //Overload + operator
    Complex operator+(const Complex& other) {
        return Complex(this->re + other.re, this->im + other.im);
    }

    // Overload - operator
    Complex operator-(const Complex& other) {
        return Complex(this->re - other.re, this->im - other.im);
    }

    // Overload * operator
    Complex operator*(const Complex& other) {
	    return Complex(
            this->re * other.re - this->im * other.im,
            this->re * other.im + this->im * other.re
        );
    }

    // Copy constructor 
    Complex(const Complex& other): re(other.re), im(other.im) {}

    // Copy assignment 
    Complex operator=(const Complex& other) {
        if (this != &other) {
            this->re = other.re;
            this->im = other.im;
        }
        return *this;
    }

    // Destructor 
    ~Complex() {}

    // Overload << operator - Friend function declaration
    friend std::ostream& operator<< (std::ostream &out, const Complex &number);
};

// Overload << operator - Friend function implementation 

    std::ostream& operator<< (std::ostream &out, const Complex& number) {
        out << "Complex nr: Re(" 
            << number.re << ")* Im(" << number.im << ")\n";

        return out;
    }

            
    // std::ofstream& operator<<(std::ofstream &out, const Complex& number) {
    //     out << "Complex nr: " 
    //         << number.re << (number.im >= 0 ? " + " : " - ") 
    //         << std::abs(number.im) << "i";
    //     return out;
    // }

#endif
