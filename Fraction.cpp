#include "Fraction.hpp"

int Fraction::gcd(int a, int b) {
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

int Fraction::lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void Fraction::reduce() {
    int numerator, denominator;
    int gcd = this->gcd(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

Fraction::Fraction(int value) {
    this->numerator = value;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    try {
        if (!denominator) {
            throw FractionException("Знаменатель дроби не можен быть равен 0.");
        }

        this->numerator = numerator;
        this->denominator = denominator;
    }
    catch(FractionException &exception) {
        std::cout << exception.getError() << std::endl;
        exit(1);
    }
}

bool Fraction::operator==(Fraction& fraction) {
    this->reduce();
    fraction.reduce();

    return (this->numerator == fraction.numerator) && (this->denominator == fraction.denominator);
}

Fraction Fraction::operator+(Fraction& fraction) {
    this->reduce();
    fraction.reduce();

    int numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
    int denominator = this->lcm(this->denominator, fraction.denominator);
    Fraction sum(numerator, denominator);

    sum.reduce();

    return sum;
}

Fraction Fraction::operator-(Fraction& fraction) {
    this->reduce();
    fraction.reduce();

    int numerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
    int denominator = this->lcm(this->denominator, fraction.denominator);
    Fraction difference(numerator, denominator);

    difference.reduce();

    return difference;
}

Fraction Fraction::operator*(Fraction& fraction) {
    this->reduce();
    fraction.reduce();

    int numerator = this->numerator * fraction.numerator;
    int denominator = this->denominator * fraction.denominator;
    Fraction composition(numerator, denominator);

    composition.reduce();

    return composition;
}

Fraction Fraction::operator/(Fraction& fraction) {
    this->reduce();
    fraction.reduce();

    int numerator = this->numerator * fraction.denominator;
    int denominator = this->denominator * fraction.numerator;
    Fraction quotient(numerator, denominator);

    quotient.reduce();

    return quotient;
}

std::ostream& operator<<(std::ostream &out, const Fraction& fraction) {
    out << fraction.numerator;

    if (fraction.denominator != 1) {
        out << "/" << fraction.denominator;
    }

    return out;
}
