#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

template<class C>
class Complex {
public:
	// Complex values (real part and imaginary part)
	C real, img;

	// Default constructor for gcc
	Complex<C> () : real(0), img(0) {}

	/**
	 * @brief Default constructor for complex number
	 * 
	 * @param r real part
	 * @param i imaginary part
	 */
	Complex<C> (C r, C i) : real(r), img(i) {}

	/** 
	 * @brief Angle Constructor
	 * 
	 * @param theta argment of z
	**/
	Complex<C> (C theta) : real(cos(theta)), img(sin(theta)) {}

	/**
	 * @brief Default Destructor
	 */
	~Complex<C> () {}

	/**
	 * @brief Assignment operator
	 * 
	 * @param w The other complex number that is assigned to this one
	 * @return Complex<C>&
	 */
	Complex<C>& operator= (const Complex<C>& w) {
		this-> real = w.real;
		this->img = w.img;

		return *this;
	}

	friend std::ostream &operator<< (std::ostream& os, const Complex<C>& z) {
		os << z.real << " + " << z.img << "i";
		return os;
	}
};

#endif // COMPLEX_H