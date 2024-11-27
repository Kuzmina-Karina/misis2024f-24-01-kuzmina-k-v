#ifndef RATIONAL_H_20191010
#define RATIONAL_H_20191010

#include <iosfwd>
#include <iostream>
#include <sstream>

struct Rational {
    Rational() = default;
    explicit Rational (const double chislitel);
    Rational (const double chislitel, const double znamenatel);
    double chis{ 0.0 };
    double znam{ 0.0 };   
    const char cent = '/';
    bool operator==(const Rational& r);
    bool operator!=(const Rational& r);
    Rational& operator+=(const Rational& r);
    Rational& operator+=(const double r);
    Rational& operator*=(const Rational& r);
    Rational& operator-=(const Rational& r);
    Rational& operator-=(const double r);
    Rational& operator/=(const Rational& r);
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr);
};

bool testVvod (const std::string& s);

std::istream& operator>>(std::istream& istr, Rational& r);
std::ostream& operator<<(std::ostream& ostr, Rational& r);

Rational& operator+(const Rational& l, const  Rational& r);
Rational& operator-(const Rational& l, const Rational& r);
Rational& operator*(const Rational& l, const Rational& r);
Rational& operator/(const Rational& l, const Rational& r);

#endif
