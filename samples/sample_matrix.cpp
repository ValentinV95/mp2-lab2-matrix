// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	int n;

    TMatrix<int> a(n), b(n), c(n), d(n);

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование программ поддержки представления треугольных матриц" << endl;

	cout << "Введите размер матриц" << endl;
	cin >> n;
	cout << "Заполните поля матрицы А" << endl;
	cin >> a;
	cout << endl;
	cout << "Заполните поля матрицы В" << endl;
	cin >> b;
	cout << endl;
    
	cout << "1 - сумма матриц, 2 - разность матриц, 3 - присваивание, 4 - сравнение матриц" << endl;
	int temp;
	cin >> temp;
	cout << endl;
	if (temp == 1)
	{
		c = a + b;
		cout << "Matrix c = a + b" << endl << c << endl;
	}
	if (temp == 2)
	{
		d = a - b;
		cout << "Matrix d = a - b" << endl << d << endl;
	}
	if (temp == 3)
	{
		a = b;
		cout << "Matrix a = b" << endl << a << endl;
	}
	if (temp == 4)
	{
		if (a != b)
		{
			cout << "Matrix a != b" << endl << d << endl;
		}
		else
		{
			cout << "Matrix a == b" << endl << d << endl;
		}
	}
}
//---------------------------------------------------------------------------
