#include "Complex.h"

Complex::Complex(double r, double i) : real(r), img(i) {}

Complex::~Complex() {}

std::ostream &operator<<(std::ostream &os, const Complex &z) {
	os << z.real << " + " << z.img << "i";
	return os;
}