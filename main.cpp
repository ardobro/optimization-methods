#include <iostream>
#include "Fraction.hpp"

int main() {
    Fraction a(10, 2);
    Fraction b(3, 4);
    Fraction c(20, 4);

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << a << " = " << c << " is " << (a == c) << std::endl;

    return 0;
}
