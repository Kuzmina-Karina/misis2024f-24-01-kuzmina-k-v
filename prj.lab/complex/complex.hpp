#ifndef COMPLEX_COMPLEX_H_20191010
#define COMPLEX_COMPLEX_H_20191010

#include <iosfwd>
#include <iostream>
#include <sstream>

struct Complex {
    Complex() = default;
    explicit Complex (const double real);
    Complex (const double real, const double imaginary);
    double re{ 0.0 };
    double mn{ 0.0 };   
    const char lBort = '{';
    const char rBort = '}';
    const char cent = ',';
    bool operator==(const Complex& ri);
    bool operator!=(const Complex& ri);

    Complex& operator+=(const Complex& ri);
    Complex& operator+=(const double ri);

    Complex& operator*=(const Complex& ri);
    Complex& operator*=(const double ri);

    Complex& operator-=(const Complex& ri);
    Complex& operator-=(const double ri);

    Complex& operator/=(const Complex& ri);
    Complex& operator/=(const double ri);

    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr);
};

bool CHECK (const std::string& s);

std::istream& operator>>(std::istream& istr, Complex& ri);
std::ostream& operator<<(std::ostream& ostr, Complex& ri);

Complex operator+(const Complex& l, const  Complex& r);
Complex operator-(const Complex& l, const Complex& r);
Complex operator*(const Complex& l, const Complex& r);
Complex operator/(const Complex& l, const Complex& r);

Complex operator+(const Complex& l, const  double r);
Complex operator-(const Complex& l, const  double r);
Complex operator*(const Complex& l, const  double r);
Complex operator/(const Complex& l, const  double r);

Complex operator+(const double l, const Complex& r);
Complex operator-(const double l, const Complex& r);
Complex operator*(const double l, const Complex& r);
Complex operator/(const double l, const Complex& r);

#endif
