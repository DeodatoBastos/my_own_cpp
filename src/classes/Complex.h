#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

template<class C>
class Complex {
public:
	C real, img;

	Complex<C> () : real(0), img(0) {}
	Complex<C> (C r, C i) : real(r), img(i) {}
	Complex<C> (C theta) : real(cos(theta)), img(sin(theta)) {}
	Complex<C> (C multiplier, const Complex<C>& w): real(multiplier * w.real), img(multiplier * w.img) {}

	Complex<C>& operator= (const Complex<C>& w) {
		this-> real = w.real;
		this->img = w.img;

		return *this;
	}

	~Complex<C> () {}

	friend std::ostream &operator<< (std::ostream& os, const Complex<C>& z) {
		os << z.real << " + " << z.img << "i";
		return os;
	}
};

#endif // COMPLEX_H