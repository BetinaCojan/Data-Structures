#include <iostream>
#ifndef __FRACTION_H__
#define __FRACTION_H__

class Fraction {
private:
	double num;
	double denom;

public:
	Fraction(double num, double denom) {
		this->num = num;
		this->denom = denom;
	}

	double getNum() {
		return num;
	}

	double getDenom() {
		return denom;
	}

	double decimal() {
		if (this->denom == 0) {
			std::cerr << "Error: Division by zero." << std::endl;
			return 0.0;
		}
		return this->num / this->denom;
	}

	Fraction multiply(Fraction f) {
		double resultNum = this->num * f.num;
		double resultDenom = this->denom * f.denom;
		return Fraction(resultNum, resultDenom);
	}

	Fraction divide(Fraction f) {
		if (f.num == 0) {
			std::cerr << "Error: Division by zero." << std::endl;
		}
		return multiply(Fraction(f.denom, f.num));
	}
};

#endif // __FRACTION_H__
