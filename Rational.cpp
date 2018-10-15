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

Rational Rational::operator +(const int& x) const
{
	Rational r(x);
	
	return (*this + r);
}

Rational Rational::operator *(const Rational& r)
{
	Rational res(*this);

	return res *= r;
}

Rational Rational::operator *(const int& n)
{
	Rational res(*this);
	res.numer *= n;
	simplify();
	return res;
}
/*
Rational Rational::operator *(const double& n)
{
	Rational res(*this);
	Rational d;
	double f = n;
	int p = f, k = 1;
	f -= p;
	while (f > 0 && k < 1000)
	{
		f *= 10;
		int i = f;
		d.numer = d.numer * 10 + i;
		f -= i;
		k *= 10;
	}
	d.denom = k;
	d.numer += p * k;
	d.simplify();
	d = res * d;
	return d;
}*/

Rational& Rational::operator /(const Rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}

Rational& Rational::operator /(const int& n)
{
	Rational res(*this);
	res.denom *= n;
	simplify();
	return res;
}

Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

Rational& Rational::operator -(const Rational& r)
{
	Rational res(*this);

	return (res += (-r));
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

bool Rational::operator ==(const int& r) const
{
	Rational res(*this), r1(r);
	r1.denom *= res.denom;
	r1.numer *= res.denom;
	return (res == r1);
}

bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}

bool Rational::operator !=(const int& r) const
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
/*
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
}*/

Rational Rational::srt()
{
	Rational res(*this), x1, y1;
	double x = 2, y = 2;

	while (res.numer != (int(x * x * 10000)/10000.0))
	{
		x = ((res.numer / x) + x) * 1 / 2;
	}
	x = int(x * 1000) / 1000.0;

	while (res.denom != (int(y * y * 10000) / 10000.0))
	{
		y = ((res.denom / y) + y) * 1 / 2;
	}
	y = int(y * 1000) / 1000.0;

	
	for (int i = 0; i < 2; i++)// для чисел из которых ровно не извлекается корень
	{
		Rational n;
		double f;
		if (i == 0)
			f = x;
		else
			f = y;

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

		if (i == 0)
			x1 = n;
		else
			y1 = n;
	}

	res = x1 / y1;
	simplify();

	/*res.numer = x;
	res.denom = y;*/

	return res;
}
