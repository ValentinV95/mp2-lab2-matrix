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
	int i, j, n, k, t, t1;
	int f;
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц" << endl;
	char *M[] = { "1 - Ввести матрицу вручную","2 - Сформировать матрицу из случайных чисел","3 - Выход из программы" };
	do
	{
		cout << "Введите размеры матриц n=" << endl;
		cin >> n;

		TMatrix<int> A(n), B(n), C(n);
		TMatrix<int> ADD(n), SUB(n);
		cout << "Выберите способ формирования матриц А и В:" << endl << endl;
		for (i = 0; i < 3; i++)
			cout << M[i] << endl;
		cin >> t;
		if (t > 3)
			cout << "Такого пункта меню не существует, повторите ввод!" << endl;
		if (t == 1)
		{
			cout << "Введите матрицу А=" << endl;
			cin >> A;
			cout << "Введите матрицу В=" << endl;
			cin >> B;
		}
		if (t == 2)
		{
			for (i = 0; i < n; i++)
				for (j = i; j < n; j++)
				{
					A[i][j] = rand();
					B[i][j] = rand();
				}
		}

		if (t != 3)
		{
			cout << "Матрица А=" << endl << A << endl;
			cout << "Матрица B=" << endl << B << endl;

			ADD = A + B;
			cout << "A+B=" << endl << ADD << endl;

			SUB = A - B;
			cout << "A-B=" << endl << SUB << endl;

			if (A == B)
				cout << "A=B";
			else cout << "A!=B";
			cout << endl << endl;
		}

	} while (t < 3);

	system("pause");
}