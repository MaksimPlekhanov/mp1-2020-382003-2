#include <iostream>
#include <math.h>
#include <vector>
#define EPS 0.001

using namespace std;

class FunctionVariable
{
public:
	virtual double Function1(double x) = 0;

	virtual double Function2(double x) = 0;

	virtual double Derivative1(double x) = 0;
	
	virtual double Derivative2(double x) = 0;
};

class FindVariables : public FunctionVariable
{
public:
	virtual double Newton(double con) = 0;

	virtual double preobr(double x) = 0;
	
	virtual double Secant(double nach, double con) = 0;
};

class Solver :  public FindVariables, public FunctionVariable
{
public:
	void otr()
	{
		cout << "������� ������������ �������� a ��� ������ ������� " << endl;
		cin >> a;
		cout << "������� ������������ �������� b ��� ������ ������� " << endl;
		cin >> b;
	}

	double Function1(double x)
	{
		return x * x - 2 * x - 15;
	}

	double Function2(double x)
	{
		return x * x - 2 * x - 15;
	}

	double Derivative1(double x)
	{
		return 2 * x + 2;
	}

	double Derivative2(double x)
	{
		return 2 * x + 2;
	}

	double Newton(double con)
	{
		double nach = con - Function1(con) / Derivative1(con);
		while (fabs(nach - con) > EPS)
		{
			con = nach;
			nach = con - Function1(con) / Derivative1(con);
		}
		return nach;
	}

	double preobr(double x)
	{
		return sqrt(fabs(Function1(x))) - x;
	}

	double Secant(double a, double b)
	{
		while (fabs(b - a) > EPS) {
			a = b - (b - a) * preobr(b) / (preobr(b) - preobr(a));
			b = a - (a - b) * preobr(a) / (preobr(a) - preobr(b));
		}
		return b;
	}

	double ChooseFunction()
	{
		if (choosefunction <= 0)
		{
			cout << "������� ����� �������" << endl;
			cin >> choosefunction;
			if (choosefunction == 1)
			{
				return Function1(b);
			}
			else
			{
				return Function2(b);
			}
		}
	}

	double ChooseDerivative()
	{
		if (choosefunction == 1)
		{
			return Derivative1(b);
		}
		else
		{
			return Derivative2(b);
		}
	}

	double ChooseMethod()
	{
		cout << "������� ����� �������: 1 - ������, 2 - �������" << endl;
		cin >> choose;
		if (choose == 1)
		{
			return Newton(b);
		}
		else
		{
			return Secant(a, b);
		}
	}

	void Solve()
	{
		b = ChooseMethod();
		cout << "������ ��������� = " << b << endl;
	}
private:
	double a;
	double b;
	int choosefunction = 0;
	int choose;
	/*double(*Function1)(double);
	double(*Function2)(double);
	double(*Deritive1)(double);
	double(*Deritive2)(double);
	double(*Newton)(double);
	double(*Secant)(double);*/
};

int main()
{
	setlocale(LC_ALL, "ru");
	Solver obj;
	obj.otr();
	obj.Solve();

	return 0;
}