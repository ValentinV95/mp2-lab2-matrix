// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include <random>
#include "utmatrix.h"


void main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);
	int n;
	cout << "Enter the matrix order (Max Size of Matrix should be less than 10000: ";
	cin >> n;
	cout << "\n";
	TMatrix<int> a(n), b(n);
	cout << "Choose how you want to enter the matrix: \n";
	cout << "1) User's input \n";
	cout << "2) Random \n";
	int k;
	cin >> k;
	if (k == 1)
	{
		cout << "Enter the Matrix a\n";
		cin >> a;
		cout << "Enter the Matrix b\n";
		cin >> b;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				a[i][j] = dis(gen);
				b[i][j] = dis(gen);
			}
		}
	}
	cout << "Choose opperation with matrix \n";
	cout << "1) a + b\n";
	cout << "2) a - b\n";
	cout << "3) a * b\n";
	int r;
	cin >> r;
	switch (r)
	{
	case 1:
		cout << a + b << "\n";
	case 2:
		cout << a - b << "\n";
	case 3:
		cout << a * b << "\n";
	default:
		break;
	}
}
//---------------------------------------------------------------------------
