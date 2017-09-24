#pragma once

// An example of a complex number
// See complex_main.cpp for compilation instructions

#include <cmath>
class Complex {
private:
    double re, im;

public:
    Complex( double = 0.0, double = 0.0 );

    /// Accessors

    double real() const;
    double imag() const;
    double abs() const;
    Complex exp() const;

    /// Mutators
    void normalize();
};

// Constructor
inline Complex::Complex( double r, double i ):
    re( r ), im( i ) {/*empty constructor*/}

// return the real component
inline double Complex::real() const {
    return re;
}

// return the imaginary component
inline double Complex::imag() const {
    return im;
}

// return the absolute value
inline double Complex::abs() const {
    return std::sqrt( re*re + im*im );
}

// Return the exponential of the complex value
inline Complex Complex::exp() const {
    double exp_re = std::exp( re );

    return Complex( exp_re*std::cos(im), exp_re*std::sin(im) );
}

// Normalize the complex number (giving it unit absolute value, |z| = 1)
inline void Complex::normalize() {
    if ( re == 0 && im == 0 ) {
        return;
    }

    double absval = abs();
    re /= absval;
    im /= absval;
}
