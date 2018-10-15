#ifndef _RATIONAL_H
#define _RATIONAL_H
#include <iostream>

class Rational
{
public:

	int numer, denom;
	void simplify();
	Rational();
	Rational(int number);
	Rational(int n, int d);

	Rational& operator +=(const Rational& r);

	Rational& operator *=(const Rational& r);

	Rational operator +(const Rational& r) const;

	Rational operator +(const int& x) const;

    Rational operator *(const Rational& r);

	Rational operator *(const int& n);

	Rational operator *(const double& n);

	Rational& operator /(const Rational& r);

	Rational& operator /(const int& n);

	Rational operator -() const;

	Rational& operator -(const Rational& r);

	Rational& operator ++();//префикс
	Rational operator ++(int);//постфикс

	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;
	bool operator ==(const int& r) const;
	bool operator !=(const int& r) const;
	bool operator <(Rational& r);
	

	operator int() const;
	operator double() const;

	Rational srt();
};

#endif // !_RATIONAL_H
