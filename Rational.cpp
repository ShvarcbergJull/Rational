#include <iostream>
#include <fstream>
#include <math.h>
#include "Rational.h"

using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}	

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
}

void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2;i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational& Rational::operator *=(const Rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator +(const Rational& r) const
{
	Rational res(*this);

	return res += r;
}

Rational Rational::operator *(const Rational& r) const
{
	Rational res(*this);

	return res *= r;
}

Rational& Rational::operator /(const Rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}

Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

Rational& Rational::operator -(const Rational& r)
{
	return (*this += (-r));
}

Rational& Rational::operator ++()
{
	numer += denom;
	return(*this);
}

Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

bool Rational::operator ==(const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}

bool Rational::operator <(Rational& r) 
{
	if (denom != r.denom)
	{
		numer *= r.denom;
		r.numer *= denom;
		Rational s = r.denom * denom;
		r.denom = s;
		denom = s;
	}

	return (numer < r.numer);
}

Rational::operator int() const
{
	return numer / denom;
}

Rational::operator double() const
{
	return ((double)numer / denom);
}

Rational Rational::srt()
{
	Rational res(*this);
	double f;
	f = sqrt(res.numer);
	Rational n, d;
	int p = f, k = 1;
	f -= p;
	while (f > 0 && k < 1000)
	{
		f *= 10;
		int i = f;
		n.numer = n.numer * 10 + i;
		f -= i;
		k *= 10;
	}
	
	n.denom = k;
	n.numer += p * k;

	f = sqrt(res.denom);
	p = f;
	f -= p;
	k = 1;
	while (f > 0 && k < 1000)
	{
		f *= 10;
		int i = f;
		d.numer = d.numer * 10 + i;
		f -= i;
		k++;
	}

	d.denom = k;
	d.numer += p * k;

	res = n / d;
	res.simplify();

	return res;
}
