#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

template<class C>
class Complex {
public:
	C real, img;

	Complex<C>(C r, C i) : real(r), img(i) {}
	~Complex<C>() {}

	friend std::ostream &operator<< (std::ostream& os, const Complex<C>& z) {
		os << z.real << " + " << z.img << "i";
		return os;
	}
};

#endif // COMPLEX_H