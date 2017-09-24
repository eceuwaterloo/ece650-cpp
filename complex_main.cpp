// compile: c++ -o complex_main complex_main.cpp
#include <iostream>
#include "complex.hpp"

int main() {
    Complex cx(10, 4);

    std::cout << "Absolute value of " << cx.real() << "+" << cx.imag() << "i"
              << " is " << cx.abs() << "\n";
    return 0;
}
