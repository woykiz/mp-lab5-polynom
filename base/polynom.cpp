#include "polynom.h"

void Polynom::AddMonom(int deg, double k)
{
	Monom value;
	value.degree = deg;
	value.koef = k;
	monoms.Add(value);
}

Polynom Polynom::operator+(Polynom& pol)
{
	Polynom res;

	int i = 0;
	int j = 0;

	for (; i < pol.monoms.Size(); i++)
	{
		auto f1 = pol.monoms[i];
		auto f2 = monoms[j];

		if (j < monoms.Size())
			while (f1.degree < f2.degree)
			{
				res.monoms.Add(f2);
				j++;

				if (j >= monoms.Size())
					break;

				f2 = monoms[j];
			}
		if (f1.degree == f2.degree)
		{
			if (f1.koef + f2.koef != 0)
				res.monoms.Add(f1 + f2);
			j++;
		}
		else
			res.monoms.Add(f1);
	}

	for (; j < monoms.Size(); j++)
	{
		auto mon = monoms[j];
		res.monoms.Add(mon);
	}

	return res;
}

double Polynom::Calculate(int x, int y, int z)
{
	double sum = 0;
	for (auto m : monoms)
	{
		auto debug = pow(x, m.degree / 100);
		sum += m.koef * pow(x, m.degree / 100)* pow(y, (m.degree % 100) / 10)* pow(z, m.degree % 10);
	}
	return sum;
}

double Polynom::Calculate()
{
	int x, y, z;
	cout << "x= ";
	cin >> x;
	cout << "y= ";
	cin >> y;
	cout << "y= ";
	cin >> z;
	cout << "\n";

	double res = Calculate(x, y, z);
	cout << "res: " << res;
	return res;
}