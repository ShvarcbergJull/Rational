#include <iostream>
#include <locale.h>
#include "Rational.h"

using namespace std;

istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}

ostream& operator<<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//Test 1
	/*
	Rational a(1, 2), b(-1, 6);

	cout << "a = " << a << " b = " << b << " a + b = " << a + b << endl;

	cout << "a(" << a << ") *= b(" << b << ")" << endl;
	a *= b;
	cout << a << endl;

	cout << "a =" << a << " b = " << b << " a - b = " << a - b << endl;
	Rational c = 3;

	cout << "b = " << b << " c = " << c << " b/c = " << b / c << endl;*/

	//Test 2
	/*
	Rational e(7, 8), f(5, 12);
	cout << "e=" << e << " f=" << f << " e+f=?" << endl;
	cout << "Введите результат g=m/n в формате: m n" << endl;
	Rational g;
	cin >> g;
	if (e + f != g)
		cout << "Неправильно! e+f=" << e + f << endl;
	else
		cout << "Правильно!" << endl;
	*/

	//Equation
	Rational a, b, c, x1, x2, d;

	cout << "Введите a, b и c для квадратного уравнения через пробел:" << endl;
	cout << "a = ";
	cin >> a;
	cout << endl << "b = ";
	cin >> b;
	cout << endl << "c = ";
	cin >> c;

	cout << "Уравнение: " << a << "x^2 + (" << b << ")x + (" << c << ") = 0" << endl;

	Rational cs(4);

	d = b * b - cs * a * c;

	cs.numer = 0;
	cs.denom = 1;
	cout << endl << d << endl;
	if (d < cs)
	{
		cout << "Ответ: Дискриминант меньше 0" << endl;
	}	
	else
	{
 		Rational s;
		s = d.srt();

		cs.numer = 2;
		x1 = (-b + s) / cs / a;
		x2 = (-b - s) / cs / a;
		if (x1 != x2)
			cout << "Ответ: x1=" << x1 << ", x2=" << x2 << endl;
		else
			cout << "Ответ: x1 = x2 =" << x1 << endl;
	}

	system("pause");
	return 0;
}
