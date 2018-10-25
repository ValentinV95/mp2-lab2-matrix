// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц"
		<< endl << endl;

	bool z = true;

	do {

		int s, k, d, f;
		bool x = false;
		cout << "Введите размер матриц" << endl;
		cin >> s;
		cout << endl;

		TMatrix<int> a(s), b(s), c(s);

		do {

			cout << "Выберете способ заполнения" << endl;
			cout << "1) Случайные числа" << endl;
			cout << "2) Ручной ввод" << endl;
			cin >> k;

			switch (k)
			{
			case 1:

				for (int i = 0; i < s; i++)
					for (int j = i; j < s; j++)
					{
						a[i][j] = rand();
						b[i][j] = rand();
					}

				x = true;

				break;
			case 2:

				cout << "Введите матрицу a" << endl;

				for (int i = 0; i < s; i++)
					for (int j = i; j < s; j++)
					{
						cout << "a[" << i << "][" << j << "]=";
						cin >> a[i][j];
					}
				cout << endl;

				cout << "Введите матрицу b" << endl;

				for (int i = 0; i < s; i++)
					for (int j = i; j < s; j++)
					{
						cout << "b[" << i << "][" << j << "]=";
						cin >> b[i][j];
					}
				cout << endl;

				x = true;

				break;
			default:

				cout << "Неправильный ввод, повторите попытку" << endl << endl;

				break;
			}
		} while (!x);

		x = false;
		cout << "Матрица a = " << endl << a << endl;
		cout << "Матрица b = " << endl << b << endl << endl;

		do {

			cout << "Выберите операцию над матрицами" << endl;
			cout << "1) Сложение" << endl;
			cout << "2) Вычитание" << endl;
			cout << "3) Сравнение" << endl;
			cin >> d;

			switch (d)
			{
			case 1:

				c = a + b;
				cout << "Матрица с = a + b" << endl;
				cout << c;

				x = true;

				break;
			case 2:

				c = a - b;
				cout << "Матрица с = a - b" << endl;
				cout << c;

				x = true;

				break;
			case 3:

				if (a == b)
					cout << "Матрицы a и b равны" << endl;
				else
					cout << "Матрицы a и b не равны" << endl;

				x = true;

				break;
			default:

				cout << "Неправильный ввод, повторите попытку" << endl << endl;

				break;
			}

		} while (!x);

		x = false;

		do {
			cout << endl;
			cout << "Завершить программу?" << endl;
			cout << "1) Да" << endl;
			cout << "2) Нет" << endl;
			cin >> f;

			switch (f)
			{
			case 1:

				x = true;
				z = false;

				break;
			case 2:

				x = true;

				break;
			default:

				cout << "Неправильный ввод, повторите попытку" << endl << endl;

				break;
			}

		} while (!x);


	}while (z);

}    
//---------------------------------------------------------------------------
