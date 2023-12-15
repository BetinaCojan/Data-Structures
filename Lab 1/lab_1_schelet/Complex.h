#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <math.h>

class Complex {
private:
	double re;
	double im;

public:
	Complex(double re, double im) {
		this->re = re;
		this->im = im;
	}

	double getRe() {
		return re;
	}

	double getIm() {
		return im;
	}

	double modulus() {
		return sqrt(pow(this->re, 2) + pow(this->im, 2));
	}

	Complex add(Complex c) {
		c.re += this->re;
		c.im += this->im;
		return c;
	}

	Complex multiply(Complex c) {
	    double resultReal = (this->re * c.re) - (this->im * c.im);
        double resultImag = (this->re * c.im) + (this->im * c.re);
        return Complex(resultReal, resultImag);
    }
};

#endif // __COMPLEX_H__
