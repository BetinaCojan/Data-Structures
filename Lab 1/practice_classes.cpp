#include <iostream>
#include <stdio.h>
 
class Complex {
    double re;
    double im;
 
public:
    void initialize(double re, double im) {
        this->re = re;
        this->im = im;
    }
 
    Complex conjugate() {
        Complex conj;
        conj.initialize(re, -im);
 
        return conj;
    }
 
    void show() {
        if (im > 0) {
            std::cout << re << "+" << im << "i" << std::endl;
        } else {
            std::cout << re << im << "i" << std::endl;
        }
    }
};

int main() {
    Complex number;    
    number.initialize(2, 3);
    number.show();
    Complex conj;
    conj = number.conjugate();
    conj.show();
    return 0;
}