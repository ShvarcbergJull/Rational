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

	Rational& operator /(const Rational& r);

	Rational operator -() const;

	Rational& operator -(const Rational& r);

	Rational& operator ++();//префикс
	Rational operator ++(int);//постфикс

	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;

	operator int() const;
	operator double() const;

};

#endif // !_RATIONAL_H
