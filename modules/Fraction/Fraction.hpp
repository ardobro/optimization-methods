#pragma once

#include <iostream>
#include <string>
#include "../FractionException.hpp"

class Fraction {
    private:
        int numerator, denominator;

        int gcd(int, int) const;
        int lcm(int, int) const;

    public:
        Fraction() {}
        Fraction(const int&);
        Fraction(const int&, const int&);
        ~Fraction() {}

        void reduce();

        bool operator==(const Fraction&) const;
        Fraction operator+(const Fraction&) const;
        Fraction operator-(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        Fraction operator/(const Fraction&) const;

        friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
};
