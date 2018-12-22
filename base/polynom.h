#ifndef __PROC_H__
#define __PORC_H__

#include "list.h"
#include <iostream>
#include <string>

using namespace std;

struct Monom
{
	int koef;
	int degree;

	Monom& operator+(Monom m)
	{
		Monom res;
		res.koef = m.koef + koef;
		res.degree = degree;
		return res;
	}

	bool operator==(Monom m)
	{
		return koef == m.koef && degree == m.degree;
	}

	bool operator!=(Monom m)
	{
		return !(*this == m);
	}
};

class Polynom
{
	TList<Monom> monoms;
public:
	Polynom() {}
	Polynom(Polynom& p) { monoms = p.monoms; }
	void AddMonom(int, double);
	Polynom operator+(Polynom& p);
	double Calculate();
	double Calculate(int x, int y, int z);
	void GetPolynomFromConsole()
	{
		cout << "f(x,y,z)=sum(k*x^DEG*y^DEG*z^DEG,n)\n";
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int deg = 1;
			int digit;
			cout << "x: ";
			cin >> digit;
			deg = 100 * digit;

			cout << "y: ";
			cin >> digit;
			deg += 10 * digit;

			cout << "z: ";
			cin >> digit;
			deg += digit;
			cout << '\n';

			double k;
			cout << "k: ";
			cin >> k;
			cout << '\n';

			AddMonom(deg, k);
		}
	}

	friend ostream& operator<< (ostream& os, Polynom& pol)
	{
		os << "f(x,y,z)=";
		for (auto m : pol.monoms)
			os << '+' << m.koef << "*x^" << (m.degree / 100) << "*y^" << (m.degree % 100) / 10 << "*z^" << m.degree % 10;
	}
	bool operator==(Polynom& pol)
	{
		return monoms == pol.monoms;
	}
};

#endif