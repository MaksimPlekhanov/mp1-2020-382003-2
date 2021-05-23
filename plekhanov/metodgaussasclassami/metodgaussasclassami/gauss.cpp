#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define EPS 10e-8

using namespace std;

class matrixx
{
	friend int main();
public:
	void InputMatrix()
	{
		cout << "Введите количество векторов матрицы " << endl;
		cin >> x;
		cout << "Введите количество переменных " << endl;
		cin >> y;
		cout << "Введите коэффициенты перед неизвестными переменными матрицы " << endl;
		for (int j = 0; j < x; j++)
		{
			vector<float> nvector;
			cout << "    " << j + 1 << " строка" << endl;
			for (int i = 0; i < y; i++)
			{
				int temp = 0;
				cin >> temp;
				nvector.push_back(temp);
			}
			matrix.push_back(nvector);
		}
		cout << "Введите свободные коэффиценты " << endl;
		for (int i = 0; i < x; i++)
		{
			float temp;
			cin >> temp;
			solve.push_back(temp);
		}
	}

	bool Check1(float number)
	{
		if (abs(number) < EPS)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	vector<float> Minus(vector<float> a, vector<float> b)
	{
		for (int i = 0; i < y; i++)
		{
			if (Check1(a[i]))
			a[i] = a[i] - b[i];
		}
		return a;
	}

	vector<float> SortMatrix(vector<float> a, float number)
	{
		for (int i = 0; i < y; i++)
		{
			if(Check1(a[i]))
			a[i] = a[i] / number;
		}
		return a;
	}

	void OutputMatrix()
	{
		cout << "Конечная матрица " << endl;
		for (int j = 0; j < x; j++)
		{
			for (int i = 0; i < y; i++)
			{
				cout << matrix[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int j = 0; j < x; j++)
		{
			cout << solve[j] << " ";
		}
		cout << endl;
	}
private:
	vector<vector<float>> matrix;
	vector<float> solve;
	int x;
	int y;
};

int main()
{
	float buff;
	setlocale(LC_ALL, "ru");
	matrixx matrix1;
	matrix1.InputMatrix();
	for (int i = 0; i < matrix1.y; i++)
	{
		for (int j = i; j < matrix1.y; j++)
		{
			buff = matrix1.matrix[i][j];
			matrix1.matrix[j] = matrix1.SortMatrix(matrix1.matrix[j], matrix1.matrix[j][i]);
			matrix1.solve[j] = matrix1.solve[j] / buff;
		}
		matrix1.OutputMatrix();
		for (int j = i + 1; j < matrix1.y ; j++)
		{
			matrix1.matrix[j] = matrix1.Minus(matrix1.matrix[j], matrix1.matrix[i]);
			matrix1.solve[j] = matrix1.solve[j] - matrix1.solve[i];
		}
		matrix1.OutputMatrix();
	}
	for (int i = matrix1.y - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			while (matrix1.Check1(matrix1.matrix[j][i]))
			{
				matrix1.matrix[j] = matrix1.Minus(matrix1.matrix[j], matrix1.matrix[i]);
				matrix1.solve[j] = matrix1.solve[j] - matrix1.solve[i];
			}
		}
		matrix1.OutputMatrix();
	}
	matrix1.OutputMatrix();
	return 0;
}