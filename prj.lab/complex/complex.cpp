﻿#include <complex/complex.hpp>


Complex& Complex::operator=(const Complex& ri){
    re = ri.re;
    im = ri.im;
    return *this;
}
bool Complex:: operator==(const Complex& ri) const{
    double e=0.00001;
    if (abs(re-ri.re)<e and im-ri.im<e){
        return true;
    }
    else{
        return false;
    }
}
bool Complex:: operator!=(const Complex& ri) const{
    return !(*this == ri);
}


Complex& Complex::operator-(){
	re=-re;
    im=-im;
    return *this;
}



Complex& Complex::operator*=(const Complex& ri) {
    double temp= re * ri.re - im * ri.im;
    im = re * ri.im + im * ri.re; re = temp;
    return *this;
}
Complex& Complex::operator*=(const double ri) {
    Complex t = {ri, 0.0};
    Complex temp = {re, im};
    temp *= t;
    return *this;
}

Complex operator*(const Complex& l, const Complex& ri) {
    return Complex(l.re * ri.re - l.im*ri.im, l.re*ri.im + l.im*ri.re);
}
Complex operator*(const Complex& l, const  double r){
    Complex t={r, 0.0};
    return t*l;
}
Complex operator*(const double l, const Complex& r){
    Complex t={l, 0.0};
    return t*r;
}


Complex& Complex::operator/=(const Complex& ri) {
    Complex ans = {1.0, -1.0};
    Complex temp = {re, im};
    Complex a = ans * ri;
    double zn = a.re * a.re + a.im * a.im;
    Complex ch = temp * a;
    re = ch.re/zn;
    im = ch.im/zn;
    return *this;
}
Complex& Complex::operator/=(const double ri) {
    Complex t = {ri, 0.0};
    Complex temp = {re, im};
    temp /= t;
    return *this;
}
Complex  operator/(const Complex& l, const Complex& ri) {
    double temp = ri.re * ri.re + ri.im * ri.im;
    if (temp == 0) {
        std::cout << "Error /0";
        return Complex();
    }
    return Complex((l.re * ri.re + l.im * ri.im) / temp, (l.im * ri.re - l.re * ri.im) / temp);
}
Complex operator/(const Complex& l, const  double r){
    Complex t={r, 0.0};
    return l/t;
}
Complex operator/(const double l, const Complex& r){
    Complex t={l, 0.0};
    return t/r;
}




Complex& Complex::operator+=(const Complex& ri){
    re+=ri.re;
    im+=ri.im; 
    return *this;
}
Complex& Complex::operator+=(const double ri) {
    Complex t = {ri, 0.0};
    Complex temp = {re, im};
    temp += t;
    return *this;
}
Complex operator+(const Complex& l, const  Complex& r){
    Complex sum(l); 
    sum+=r; 
    return sum;
}
Complex operator+(const Complex& l, const  double r){
    Complex t={r, 0.0};
    return t+l;
}
Complex operator+(const double l, const Complex& r){
    Complex t={l, 0.0};
    return t+r;
}



Complex& Complex::operator-=(const Complex& ri){
    re-=ri.re;
    im-=ri.im; 
    return *this;
}
Complex& Complex::operator-=(const double ri) {
    Complex t = {ri, 0.0};
    Complex temp = {re, im};
    temp -= t;
    return *this;
}
Complex operator-(const Complex& l, const Complex& r){
    Complex vch(l); 
    vch-=r; 
    return vch;
}
Complex operator-(const Complex& l, const  double r){
    Complex t={r, 0.0};
    return l-t;
}
Complex operator-(const double l, const Complex& r){
    Complex t={l, 0.0};
    return t-r;
}


//ВВОД
bool CHECK (const std::string& s){
    std::istringstream istr(s);
    Complex z;
    istr >> z;
    if (istr.good()){
        std::cout << "correct" << s << " " << z;
        return true;
    }
    else{
        std::cout << "error vvod" << s << " " << z; 
        return false;
    }
}
std::istream& Complex:: read(std::istream& istr){
    char lBort;
    char rBort;
    char cent;
    double re;
    double im;
    istr >> lBort >> re >> cent >> im >> rBort;
    if (lBort == Complex::lBort && cent == Complex::cent && rBort == Complex::rBort){
        Complex::re = re;
        Complex::im = im;
    }
    else{
        istr.setstate(std::ios_base::failbit);
    }
    return istr;
}

std::ostream& Complex:: write(std::ostream& ostr){
    ostr << lBort << re << cent << im << rBort;
    return ostr;
}
Complex :: Complex(const double real, const double imaginary){ re = real; im=imaginary; }
Complex :: Complex(const double real): Complex(real, 0.0) {}

std::istream& operator>>(std::istream& istr, Complex& ri){
    return ri.read(istr);
}
std::ostream& operator<<(std::ostream& ostr, Complex& ri){
    return ri.write(ostr);
}