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
	int n, t;
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;

	cout << "Введите размер матриц" << endl;
	cin >> n;

	TMatrix<int> a(n), b(n), c(n);

	cout << "Введите матрицe a" << endl;
	cin >> a;

	cout << "Введите матрицe b" << endl;
	cin >> b;

	cout << "Выберите операцию:" << endl << "1)+" << endl<< "2)-" << endl;
	cin >> t;
	if(t == 1) {
		c = a + b;

		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a + b" << endl << c << endl;
	} else  {
		c = a - b;
		
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a - b" << endl << c << endl;
	}   
}
//---------------------------------------------------------------------------
