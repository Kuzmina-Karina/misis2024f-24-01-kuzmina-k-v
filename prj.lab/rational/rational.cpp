#include<rational/rational.hpp>
#include<numeric>


Rational::Rational(int32_t number) {
	chis = number;
	znam = 1;
}

Rational::Rational(int32_t number, int32_t denomi) {
	
	if (denomi < 0) {
		denomi *= -1;
		number *= -1;
	}
	if (denomi == 0) {
		throw std::invalid_argument("Divide by zero exception");
	}
	chis = number;
	znam = denomi;
	//std::cout << "1111111111111111111111";
	//std:: cout << chis << " " << znam;
	norm();
}

Rational::Rational(const Rational& copy) {
	chis = copy.chis;
	znam = copy.znam;
	norm();
	//std::cout << chis << " " << znam;
}


Rational& Rational::operator-(){
	chis=-chis;
    return *this;
}

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
		throw std::invalid_argument("Zero denumenator in Rational ctor");

	int32_t Gcd = gcd(std::abs(chis), std::abs(znam));
	//std::cout << chis << " " <<znam;
	chis /= Gcd;
	znam /= Gcd;
	
	if (znam<0){
		znam*=(-1);
		chis*=(-1);
	}
	
}

/////
Rational& Rational::operator=(const Rational& r) {
	chis = r.chis;
	znam = r.znam;
	return *this;
}
bool Rational::operator==(const Rational& r) const {
	if (chis == r.chis and znam==r.znam)
		return true;
	else
		return false;
}
bool Rational::operator==(const int32_t& r) const {
	if (chis == r and znam==1)
		return true;
	else
		return false;
}
bool Rational:: operator!=( const Rational& r) const{
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
	Rational rhs=r;
	//std::cout << " " << chis;
	chis*=rhs.znam;
	//std::cout << " " << chis;
	rhs.chis*=znam;
	znam*=rhs.znam;
	chis+=rhs.chis;
	
	norm();
	return *this;
}
//17/3 1/1
Rational& Rational::operator+=(const int32_t r) {
    Rational t=Rational(r,1);
    Rational temp = Rational(chis, znam);
	//std::cout << chis << " " << znam << " " << temp;
    temp += t;
	//std::cout <<" " << temp << " " << chis << " "<< znam <<" ";
	chis=temp.chis;
	znam=temp.znam;
    return *this;
}
Rational operator+(const Rational& l, const Rational& r) {
    Rational s=l;
	s += r;
	return s;
}
Rational operator+(const Rational& l, const  int32_t r){
    Rational t=Rational(r,1);
    return t+l;
}
Rational operator+(const int32_t l, const Rational& r){
    Rational t=Rational(l,1);
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
    Rational t=Rational(r,1);
    Rational temp =Rational(chis,znam);
    temp -= t;
	chis=temp.chis;
	znam=temp.znam;
    return *this;
}
Rational operator-(const Rational& l, const Rational& r) {
    Rational s=l;
	s -= r;
	return s;
}

Rational operator-(const Rational& l, const  int32_t r){
    Rational t=Rational(r,1);
    return l-t;
}
Rational operator-(const int32_t l, const Rational& r){
    Rational t=Rational(l,1);
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
    Rational t=Rational(r,1);
    Rational temp =Rational(chis,znam);
    temp *= t;
	chis=temp.chis;
	znam=temp.znam;
    return *this;
}
Rational operator*(const Rational& l, const Rational& r) {
    Rational s=l;
	s *= r;
	return s;
}
Rational operator*(const Rational& l, const  int32_t r){
    Rational t=Rational(r,1);
    return t*l;
}
Rational operator*(const int32_t l, const Rational& r){
    Rational t=Rational(l,1);
    return t*r;
}


/////
Rational& Rational::operator/=(const Rational& r) {
	if (r.chis == 0 || r.znam == 0)
		throw std::invalid_argument("Zero denumenator in Rational ctor");

	chis *= r.znam;
	znam *= r.chis;
	norm();
	return *this;
}
Rational& Rational::operator/=(const int32_t r) {
    Rational t=Rational(r,1);
    Rational temp =Rational(chis,znam);
    temp /= t;
	chis=temp.chis;
	znam=temp.znam;
    return temp;
}
Rational operator/(const Rational& l, const Rational& r) {
    Rational s=l;
	s /= r;
	return s;
}
Rational operator/(const Rational& l, const  int32_t r){
    Rational t=Rational(r,1);
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
