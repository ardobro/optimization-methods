#include <iostream>
#include "./modules/Fraction/Fraction.hpp"
#include "./modules/Matrix.hpp"

#define N 3
#define M 5

int main() {
    Matrix<Fraction> matrix;

    matrix.readFromFile("input.txt");
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.addRowToRowWithCoeff(0, 1, Fraction(-5));
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.addRowToRowWithCoeff(0, 2, Fraction(4));
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.multiplyRowToCoeff(1, Fraction(-1, 7));
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.addRowToRowWithCoeff(1, 2, Fraction(7));
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.multiplyRowToCoeff(2, Fraction(-1, 25));
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.addRowToRowWithCoeff(2, 1, Fraction(2));
    matrix.printToFile("output.txt");
    matrix.print();

    matrix.addRowToRowWithCoeff(2, 0, Fraction(2));
    matrix.printToFile("output.txt");
    matrix.print();

    return 0;
}
