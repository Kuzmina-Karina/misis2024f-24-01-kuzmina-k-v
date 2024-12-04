#ifndef RATIONAL_H_20191010
#define RATIONAL_H_20191010

#include <iosfwd>
#include <iostream>
#include <sstream>

struct Rational {
    Rational() = default;
    explicit Rational (const int32_t chislitel);
    Rational (const int32_t chislitel, const int32_t znamenatel);
    int32_t chis{0};
    int32_t znam{1};   
    const char cent = '/';
    bool operator==(const Rational& r);
    bool operator!=(const Rational& r);
    Rational& operator=(const Rational& r);
    Rational& operator+=(const Rational& r);
    Rational& operator+=(const int32_t r);
    Rational& operator*=(const Rational& r);
    Rational& operator*=(const int32_t r);
    Rational& operator-=(const Rational& r);
    Rational& operator-=(const int32_t r);
    Rational& operator/=(const int32_t r);
    Rational& operator/=(const Rational& r);
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr);

    void norm();
};

bool testVvod (const std::string& s);

std::istream& operator>>(std::istream& istr, Rational& r);
std::ostream& operator<<(std::ostream& ostr, Rational& r);

Rational operator+(const Rational& l, const Rational& r);
Rational operator-(const Rational& l, const Rational& r);
Rational operator*(const Rational& l, const Rational& r);
Rational operator/(const Rational& l, const Rational& r);

Rational operator+(const Rational& l, const  int32_t r);
Rational operator-(const Rational& l, const  int32_t r);
Rational operator*(const Rational& l, const  int32_t r);
Rational operator/(const Rational& l, const  int32_t r);

Rational operator+(const int32_t l, const Rational& r);
Rational operator-(const int32_t l, const Rational& r);
Rational operator*(const int32_t l, const Rational& r);
Rational operator/(const int32_t l, const Rational& r);


#endif
