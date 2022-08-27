#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
	double real;
	double img;
public:
	Complex(double r, double i);
	~Complex();

	friend std::ostream &operator<< (std::ostream &, const Complex &);
};

#endif // COMPLEX_H