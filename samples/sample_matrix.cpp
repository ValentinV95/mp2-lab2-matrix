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
	TMatrix<int> a(5), b(5), c(5);
	int i, j, tmp, tmp2;

	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц" << endl;
	cout << "Ввод матриц рандомными значениями-введите 1" << endl << "Ввод матриц программой (алгоритмом)-введите 2" << endl << "Ручной ввод матриц-введите 3" << endl;
	cin >> tmp;
	if (tmp == 2)
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++) {
				a[i][j] = i * 10 + j;
				b[i][j] = (i * 10 + j) * 100;
			}
	if (tmp == 3) {
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++)
				cin >> a[i][j];
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++)
				cin >> b[i][j];
	}
	if (tmp == 1)
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++) {
				a[i][j] = rand() % 1001;
				b[i][j] = rand() % 1001;
			}

	cout << "Сложение матриц-введите 1" << endl << "Вычитание матриц-введите 2" << endl;
	cin >> tmp2;
	if (tmp2 == 1) {
		c = a + b;
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a + b" << endl << c << endl;
	}
	if (tmp2 == 2) {
		c = a - b;
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a - b" << endl << c << endl;
	}
}
//---------------------------------------------------------------------------
