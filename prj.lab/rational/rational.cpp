#include <rational/rational.hpp>

Rational& operator*(const Rational& l, const Rational& r) {
    return Rational(l.chis * r.chis, l.znam * r.znam);
}

Rational& Rational::operator*=(const Rational& r) {
    chis = chis * r.chis;
    znam = znam * r.znam;
    return *this;
}

Rational& operator/(const Rational& l, const Rational& r) {
    double temp = l.znam * r.chis;
    if (temp == 0) {
        std::cerr << "Error /0";
        return Rational();
    }
    return Rational(l.chis * r.znam, temp);
}
Rational& Rational::operator/=(const Rational& r) {
    chis = chis * r.znam;
    znam = znam * r.chis;
    if (znam == 0) {
        std::cerr << "Error /0";
        return Rational();
    }
    return *this;
}

Rational& Rational::operator+=(const Rational& r){
    chis=chis*r.znam+r.chis*znam;
    znam*=r.znam; 
    return *this;
}

Rational& Rational::operator-=(const Rational& r){
    chis=chis*r.znam-r.chis*znam;
    znam*=r.znam; 
    return *this;
}

Rational& operator+(const Rational& l, const  Rational& r){ const
    return Rational(l.chis * r.znam + r.chis * l.znam, l.znam * r.znam);
}

Rational& operator-(const Rational& l, const Rational& r){
    return Rational(l.chis * r.znam - r.chis * l.znam, l.znam * r.znam);
}

//ВВОД
bool testVvod (const std::string& s){
    std::istringstream istr(s);
    Rational z;
    istr >> z;
    if (istr.good()){
        std::cout << "correct" << s << " " << z;
    }
    else{
        std::cout << "error vvod" << s << " " << z; 
    }
}
std::istream& Rational:: read(std::istream& istr){
    char cent;
    double chis;
    double znam;
    istr >> chis >> cent >> znam;
    if (cent == Rational::cent){
        Rational::chis = chis;
        Rational::znam = znam;
    }
    else{
        istr.setstate(std::ios_base::failbit);
    }
    return istr;
}

std::ostream& Rational:: write(std::ostream& ostr){
    ostr << chis << cent << znam << std::endl;
    return ostr;
}
Rational :: Rational(const double chislitel, const double znamenatel){chis=chislitel; znam=znamenatel;}
Rational :: Rational(const double chislitel): Rational(chislitel, 1) {}

std::istream& operator>>(std::istream& istr, Rational& r){
    return r.read(istr);
}
std::ostream& operator<<(std::ostream& ostr, Rational& r){
    return r.write(ostr);
}