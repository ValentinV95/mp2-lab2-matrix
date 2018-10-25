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
	cout << "Тестирование программ поддержки представления треугольных матриц"
		<< endl;


	int k, n,x=0;
	cout << "Input a size of matrices: ";
	cin >> n;
	TMatrix <int> a(n), b(n),c(n);


	cout << "Menu:" << endl;
	cout << "1.Set matrices" << endl;
	cout << "2.Matrix operations" << endl;
	cout << "3.Exit" << endl;

	while (x == 0) {
	cout << "Input a menu number:"<<endl;
	cin >> k;
		switch (k) {
		case 1: {
			for (int i = 0; i < n; i++)
			{
				for (int j = i; j < n; j++)
				{
					a[i][j] = rand();
					b[i][j] = rand();
				}
			}
			cout << "Matrix a = " << endl << a << endl;
			cout << "Matrix b = " << endl << b << endl;

			break;
		}
		case 2: {
			c = a + b;
			cout << "Matrix c = a + b" << endl << c << endl;
			c = a - b;
			cout << "Matrix c = a - b" << endl << c << endl;
			c = b - a;
			cout << "Matrix  c = b - a" << endl << c << endl;
			break;
		}
		case 3: {
			x = 1;
			break;
		}
		default:
		{
			cout << "Wrong operation" << endl;

		}
		}
	}
}
//---------------------------------------------------------------------------
