#ifndef __FRACTION_H
#define __FRACTION_H

class Fraction {
public:
	double num;
	double denom;

	Fraction(double n, double d): num(n), denom(d) {};

    // Overload * operator
	Fraction operator*(const Fraction& f) {
		return Fraction(this->num * f.num, this->denom * f.denom);
	}

	// Overload / operator 
	Fraction operator/(const Fraction& f) {
		if (f.num == 0) {
			std::cerr << "Error: Division by zero." << std::endl;
		}
		return Fraction(this->num * f.denom, this->denom * f.num);
	}

	// Get actual value of this fraction
	double getValue() {
		return this->num / this->denom;
	}

	// Overload << operator - Friend function declaration
    //friend std::ofstream &operator<<...*/
	friend std::ostream& operator<<(std::ostream& out, const Fraction f);
};

// Overload << operator - Friend function implementation 
	std::ostream& operator<<(std::ostream& out, const Fraction f) {
		out << f.num << "/" << f.denom << '\n';
		return out;
	}

#endif