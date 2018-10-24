// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <cstdio>
#include <cstdlib>



void main()
{

	int k = 0, n, l;
	bool res;
	do {
		cout << "Choose one of the items:" << '\n';
		char*d[3] = { "1. Input Matrices","2. Form matrices randomly","3. Exit" };
		for (int i = 0; i < 3; i++)
			cout << d[i] << '\n';
		cout << "Input a menu number:";
		cin >> k;
		if (k == 3) break;
		if ((k == 1) || (k == 2)) {
			cout << "Input a size of matrices: ";
			cin >> n;
			cout << '\n';
		}
		TMatrix<int> a(n), b(n), c(n);
		if (k == 1) {
			cout << "Input matrix a" << '\n';
			cin >> a;
			cout << "Input matrix b" << '\n';
			cin >> b;
		}
		if (k == 2) {
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n ; j++)
				{
					a[i][j] = rand();
					b[i][j] = rand();
				}
			}
			cout << "a= ";
			cout << a << '\n';
			cout << "b= ";
			cout << b << '\n';
		}
		char*e[3] = { "1. a+b=","2. a-b=","3. a==b" };
		for (int i = 0; i < 3; i++)
			cout << e[i] << '\n';
		cout << "Input a menu number:";
		cin >> l;
		switch (l) {
		case 1: {
			c = a + b;
			cout << c << '\n';
			break;
		}
		case 2: {
			c = a - b;
			cout << c << '\n';
			break;
		}
		case 3: {
			res = (a == b);
			cout << res << '\n';
			break;
		}

		}
	} while (k < 3);
}











