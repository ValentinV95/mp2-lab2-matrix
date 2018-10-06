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
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Порядок матрицы: ";
	cin >> n;

	TMatrix<int> a(n), b(n);

	cout << "Введите первую матрицу:" << endl;
	cin >> a;

	cout << "Введите вторую матрицу:" << endl;
	cin >> b;

	int key = 0;
	do
	{
		cout << "Выберите операцию над матрицами:" << endl;
		cout << "1) a + b" << endl;
		cout << "2) a - b" << endl;
		cout << "3) b - a" << endl;
		int input;
		cin >> input;

		switch (input)
		{
		case 1:
			cout << a + b;
			key++;
			break;
		case 2:
			cout << a - b;
			key++;
			break;
		case 3:
			cout << b - a;
			key++;
			break;
		default:
			cout << "Вы допустили ошибку. Можно использовать только 1, 2, 3" << endl;
		}

		int key1 = 0;
		do
		{
			cout << "Хотите ли вы выбрать другую операцию? (1 - да, 2 - нет)" << endl;
			int input1;
			cin >> input1;

			switch (input1)
			{
			case 1:
				key = 0;
				key1++;
				break;
			case 2:
				key1++;
				break;
			default:
				cout << "Вы допустили ошибку. Можно использовать только 1, 2" << endl;
			}
		} 
		while (!key1);
	} 
	while (!key);
}
//---------------------------------------------------------------------------
