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

    try {
        Fraction d(5, 0);
    }
    catch(FractionException exception) {
        std::cout << exception.getError() << std::endl;

        exit(1);
    }

    return 0;
}
