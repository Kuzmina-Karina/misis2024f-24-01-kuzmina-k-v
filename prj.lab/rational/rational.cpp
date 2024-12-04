#include<rational/rational.hpp>

/////
int32_t gcd(int32_t a, int32_t b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}
void Rational::norm() {
	if (znam == 0)
		throw std::overflow_error("Divide by zero exception");

	int32_t Gcd = gcd(std::abs(chis), std::abs(znam));
	chis /= Gcd;
	znam /= Gcd;
}


/////
Rational& Rational::operator=(const Rational& r) {
	chis = r.chis;
	znam = r.znam;
	return *this;
}
bool Rational::operator==(const Rational& r) {
	if (chis == r.chis and znam==r.znam)
		return true;
	else
		return false;
}
bool Rational:: operator!=( const Rational& r) {
	if (chis == r.chis and znam==r.znam)
		return false;
	else
		return true;
}


/////
bool Rational::operator<(const Rational& r) const{
    return (chis*r.znam < r.chis*znam);
}
bool Rational::operator<=(const Rational& r) const{
    return (chis*r.znam <= r.chis*znam);
}
bool Rational::operator>(const Rational& r) const{
    return (chis*r.znam > r.chis*znam);
}
bool Rational::operator>=(const Rational& r) const{
    return (chis*r.znam >= r.chis*znam);
}

/////
Rational& Rational::operator+=(const Rational& r) {
	int32_t coef = r.znam / gcd(std::abs(znam), r.znam);
	chis *= coef;
	znam *= coef;
	chis += znam / r.znam * r.chis;
	norm();
	return *this;
}
Rational& Rational::operator+=(const int32_t r) {
    Rational t(r/1);
    Rational temp (chis/znam);
    temp += t;
    return *this;
}
Rational operator+(const Rational& l, const Rational& r) {
    Rational s=l;
	s += r;
	return s;
}
Rational operator+(const Rational& l, const  int32_t r){
    Rational t(r/1);
    return t+l;
}
Rational operator+(const int32_t l, const Rational& r){
    Rational t(l/1);
    return t+r;
}


/////
Rational& Rational::operator-=(const Rational& r) {
	int32_t coef = r.znam / gcd(znam, r.znam);
	chis *= coef;
	znam *= coef;
	chis -= znam / r.znam * r.chis;
	norm();
	return *this;
}
Rational& Rational::operator-=(const int32_t r) {
    Rational t(r/1);
    Rational temp (chis/znam);
    temp -= t;
    return *this;
}
Rational operator-(const Rational& l, const Rational& r) {
    Rational s=l;
	s -= r;
	return s;
}
Rational operator-(const Rational& l, const  int32_t r){
    Rational t(r/1);
    return l-t;
}
Rational operator-(const int32_t l, const Rational& r){
    Rational t(l/1);
    return t-r;
}

/////
Rational& Rational::operator*=(const Rational& r) {
	chis *= r.chis;
	znam *= r.znam;
	norm();
	return *this;
}
Rational& Rational::operator*=(const int32_t r) {
    Rational t(r/1);
    Rational temp (chis/znam);
    temp *= t;
    return *this;
}
Rational operator*(const Rational& l, const Rational& r) {
    Rational s=l;
	s *= r;
	return s;
}
Rational operator*(const Rational& l, const  int32_t r){
    Rational t(r/1);
    return t*l;
}
Rational operator*(const int32_t l, const Rational& r){
    Rational t(l/1);
    return t*r;
}


/////
Rational& Rational::operator/=(const Rational& r) {
	if (r.chis == 0 || r.znam == 0)
		throw std::overflow_error("Divide by zero exception");

	chis *= r.znam;
	znam *= r.chis;
	norm();
	return *this;
}
Rational& Rational::operator/=(const int32_t r) {
    Rational t(r/1);
    Rational temp (chis/znam);
    temp /= t;
    return *this;
}
Rational operator/(const Rational& l, const Rational& r) {
    Rational s=l;
	s /= r;
	return s;
}
Rational operator/(const Rational& l, const  int32_t r){
    Rational t(r/1);
    return l/t;
}
Rational operator/(const int32_t l, const Rational& r){
    Rational t(l/1);
    return t/r;
}


/////
std::ostream& operator<<(std::ostream& ostrm, Rational& r) {
	return r.write(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& r) {
	return r.read(istrm);
}


/////
std::ostream& Rational::write(std::ostream& ostrm) 
{
    ostrm << chis << cent << znam;
	return ostrm;
}
Rational :: Rational(const int32_t chislitel, const int32_t znamenatel){ chis = chislitel; znam=znamenatel; }
Rational :: Rational(const int32_t chislitel): Rational(chislitel, 1) {}

std::istream& Rational::read(std::istream& istrm)
{
	int32_t numInp(0);
	char cent(0);
	int32_t denomInp(0);
	istrm >> numInp >> cent >> denomInp;
	if (istrm.good()) {
		if (Rational::cent == cent) {
			if (denomInp <= 0) {
				throw std::invalid_argument("Expected positive denominator");
			}
			chis = numInp;
			znam = denomInp;
			norm();
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
