#include "Fraction.hpp"

int Fraction::gcd(int a, int b) const {
    if (a == b) {
        return a;
    }

    a = std::abs(a);
    if (a < b) {
        std::swap(a, b);
    }
    
    int mod = a % b;
    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

int Fraction::lcm(int a, int b) const {
    return a * b / gcd(a, b);
}

void Fraction::reduce() {
    int gcd = this->gcd(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

Fraction::Fraction(const int& value) {
    this->numerator = value;
    this->denominator = 1;
}

Fraction::Fraction(const int& numerator, const int& denominator) {
    if (!denominator) {
        throw FractionException("The denominator of the fraction is equal to zero.");
    }

    this->numerator = numerator;
    this->denominator = denominator;
    this->reduce();
}

bool Fraction::operator==(const Fraction& fraction) const {
    return (this->numerator == fraction.numerator) && (this->denominator == fraction.denominator);
}

Fraction Fraction::operator+(const Fraction& fraction) const {
    int numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
    int denominator = this->lcm(this->denominator, fraction.denominator);

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator-(const Fraction& fraction) const {
    int numerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
    int denominator = this->lcm(this->denominator, fraction.denominator);

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator*(const Fraction& fraction) const {
    int numerator = this->numerator * fraction.numerator;
    int denominator = this->denominator * fraction.denominator;

    return Fraction(numerator, denominator);
}

Fraction Fraction::operator/(const Fraction& fraction) const {
    int numerator = this->numerator * fraction.denominator;
    int denominator = this->denominator * fraction.numerator;

    return Fraction(numerator, denominator);
}

std::ostream& operator<<(std::ostream &out, const Fraction& fraction) {
    out << fraction.numerator;

    if (fraction.denominator != 1) {
        out << "/" << fraction.denominator;
    }

    return out;
}
