#pragma once

#include <iostream>
#include <string>

class Fraction {
    private:
        /* Числитель */
        int numerator;
        /* Знаменатель */
        int denominator;

        /* Получить НОД */
        int gcd(int, int);
        /* Получить НОК */
        int lcm(int, int);

    public:
        Fraction() {}
        Fraction(int);
        Fraction(int, int);
        // Fraction(double);
        // Fraction(float);
        ~Fraction() {}

        /* Сократить дробь */
        void reduce();

        bool operator==(Fraction&);
        Fraction operator+(Fraction&);
        Fraction operator-(Fraction&);
        Fraction operator*(Fraction&);
        Fraction operator/(Fraction&);

        friend std::ostream& operator<<(std::ostream &out, const Fraction &fraction);
};

class FractionException {
    private:
        std::string m_error;

    public:
        FractionException(std::string error) : m_error(error) {}

        const char* getError() {return m_error.c_str();}
};
