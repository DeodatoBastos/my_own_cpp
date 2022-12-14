#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <iostream>

namespace my_lib {
const double EPSILON = 0.000001;
template <class C>
class Complex {
   public:
    // Complex values (real part and imaginary part)
    C real, img;

    // Default constructor for gcc
    Complex<C>() : real(0), img(0) {}

    /**
     * @brief Default constructor for complex number
     *
     * @param r real part
     * @param i imaginary part
     */
    Complex<C>(C r, C i) : real(r), img(i) {}

    /**
     * @brief Angle Constructor
     *
     * @param theta argment of z
     **/
    Complex<C>(C theta) : real(std::abs(std::cos(theta)) > EPSILON ? std::cos(theta) : 0), img(std::abs(std::sin(theta)) > EPSILON ? std::sin(theta) : 0) {}

    /**
     * @brief Copy constructor
     *
     * @param w The other complex number that is assigned to this one
     */
    Complex<C>(const Complex<C>& w) {
        *this = w;
    }

    /**
     * @brief Default Destructor
     */
    ~Complex<C>() {}

    /**
     * @brief Assignment operator
     *
     * @param w The other complex number that is assigned to this one
     * @return Complex<C>&
     */
    Complex<C>& operator=(const Complex<C>& w) {
        this->real = w.real;
        this->img = w.img;

        return *this;
    }

    /**
     * @brief Addition Assignment operator
     *
     * @param w The other complex number that is add to this one
     * @return Complex<C>&
     */
    Complex<C>& operator+=(const Complex<C>& w) {
        this->real += w.real;
        this->img += w.img;

        return *this;
    }

    /**
     * @brief Addition Assignment operator
     *
     * @param alpha Real number that is add to this one
     * @return Complex<C>&
     */
    Complex<C>& operator+=(const C& alpha) {
        this->real += alpha;

        return *this;
    }

    /**
     * @brief Subtraction Assignment operator
     *
     * @param w The other complex number that is subtracted to this one
     * @return Complex<C>&
     */
    Complex<C>& operator-=(const Complex<C>& w) {
        this->real -= w.real;
        this->img -= w.img;

        return *this;
    }

    /**
     * @brief Subtraction Assignment operator
     *
     * @param alpha Real number that is subtracted to this one
     * @return Complex<C>&
     */
    Complex<C>& operator-=(const C& alpha) {
        this->real -= alpha;

        return *this;
    }

    /**
     * @brief Multiplication Assignment operator
     *
     * @param w The other complex number that is multiplied to this one
     * @return Complex<C>&
     */
    Complex<C>& operator*=(const Complex<C>& w) {
        C new_real = this->real * w.real - this->img * w.img;
        C new_img = this->real * w.img + this->img * w.real;

        this->real = new_real;
        this->img = new_img;

        return *this;
    }

    /**
     * @brief Multiplication Assignment operator with a real number
     *
     * @param alpha real number
     * @return Complex<C>&
     */
    Complex<C>& operator*=(const C& alpha) {
        this->real *= alpha;
        this->img *= alpha;

        return *this;
    }

    /**
     * @brief Division Assignment operator
     *
     * @param w The other complex number that is divided to this one
     * @return Complex<C>&
     */
    Complex<C>& operator/=(const Complex<C>& w) {
        C new_real = this->real * w.real + this->img * w.img;
        C new_img = this->img * w.real - this->real * w.img;
        C denominator = w.real * w.real + w.img * w.img;

        if (denominator < EPSILON)
            throw std::runtime_error("Math error: Attempted to divide by Zero\n");

        this->real = new_real / denominator;
        this->img = new_img / denominator;

        return *this;
    }

    /**
     * @brief Division Assignment operator by a real number
     *
     * @param alpha real number
     * @return Complex<C>&
     */
    Complex<C>& operator/=(const C& alpha) {
        if (alpha < EPSILON)
            throw std::runtime_error("Math error: Attempted to divide by Zero\n");

        this->real /= alpha;
        this->img /= alpha;

        return *this;
    }

    /**
     * @brief Addition operator
     *
     * @param w The other complex number that is add to this one
     * @return Complex<C>
     */
    Complex<C> operator+(const Complex<C>& w) const {
        return Complex<C>(*this) += w;
    }

    /**
     * @brief Addition operator
     *
     * @param alpha Real number that is add to this one
     * @return Complex<C>
     */
    Complex<C> operator+(const C& alpha) const {
        return Complex<C>(*this) += alpha;
    }

    /**
     * @brief Subtraction operator
     *
     * @param w The other complex number that is subtracted to this one
     * @return Complex<C>
     */
    Complex<C> operator-(const Complex<C>& w) const {
        return Complex<C>(*this) -= w;
    }

    /**
     * @brief Subtraction operator
     *
     * @param alpha C number that is subtracted to this one
     * @return Complex<C>
     */
    Complex<C> operator-(const C& alpha) const {
        return Complex<C>(*this) -= alpha;
    }

    /**
     * @brief Opposite operator
     *
     * @return Complex<C>
     */
    Complex<C> operator-() const {
        return Complex<C>() - *this;
    }

    /**
     * @brief Multiplication operator
     *
     * @param w The other complex number that is multiplied to this one
     * @return Complex<C>
     */
    Complex<C> operator*(const Complex<C>& w) const {
        return Complex<C>(*this) *= w;
    }

    /**
     * @brief Multiplication operator with a real number
     *
     * @param alpha real number
     * @return Complex<C>
     */
    Complex<C> operator*(const C& alpha) const {
        return Complex<C>(*this) *= alpha;
    }

    /**
     * @brief Division operator
     *
     * @param w The other complex number that is divided to this one
     * @return Complex<C>
     */
    Complex<C> operator/(const Complex<C>& w) const {
        return Complex<C>(*this) /= w;
    }

    /**
     * @brief Division operator by a real number
     *
     * @param alpha real number
     * @return Complex<C>
     */
    Complex<C> operator/(const C& alpha) const {
        return Complex<C>(*this) /= alpha;
    }

    /**
     * @brief Verify if two complex numbers are equal
     *
     * @param w The other complex number to compare
     */
    bool operator==(const Complex<C>& w) const {
        return (this->real == w.real && this->img == w.img);
    }

    /**
     * @brief Verify fi two complex numbers are different
     *
     * @param w the other complex number to compare
     */
    bool operator!=(const Complex<C>& w) const {
        return !(*this == w);
    }

    /**
     * @brief returns the magnitude of the complex number
     *
     * @return C
     */
    C abs() const {
        return (C)std::sqrt((this->real * this->real) + (this->img * this->img));
    }

    /**
     * @brief returns the squared magnitude of the complex number
     *
     * @return C
     */
    C norm() const {
        return (this->real * this->real) + (this->img * this->img);
    }

    /**
     * @brief returns the argument, angle, of the complex number
     *
     * @return C
     */
    C arg() const {
        return (C)std::atan2(this->img, this->real);
    }

    /**
     * @brief returns the conjugate of the complex number
     *
     * @return Complex<C>
     */
    Complex<C> conj() {
        return Complex<C>(this->real, -this->img);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex<C>& z) {
        char operation = z.img >= 0 ? '+' : '-';
        os << z.real << " " << operation << " " << std::abs(z.img) << "i";
        return os;
    }
};

template <class C>
Complex<C> polar(const C& r, const C& theta) {
    return Complex<C>(theta) * r;
}

}  // namespace my_lib
#endif  // COMPLEX_H