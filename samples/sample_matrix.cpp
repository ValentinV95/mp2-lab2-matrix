// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include "locale.h"
//---------------------------------------------------------------------------

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int k, t;
	int a1, b1;
	cout << " Triangular matrix" << endl;
	cout << "Vvod matrix" << endl;
	cout << "Vvedite kolichestvo strok matrix:";
	cin >> t;
	TMatrix<int> a(t), b(t);
	cout << "Vvedite matrix A" << endl;
	for (int i = 0; i < t; i++)
		cin >> a[i];
	cout << "Matrix A = " << endl << a << endl;
	cout << "Vvedite matrix B" << endl;
	for (int i = 0; i < t; i++)
		cin >> b[i];
	cout << "Matrix В = " << endl << b << endl;
	cout << " MENU:" << endl;
	do {
		cout << "1.Sum A and B" << endl;
		cout << "2.Sub matrix (A-B) " << endl;
		cout << "3.Sub matrix (B-A)" << endl;
		cout << "4.Exit" << endl;
		cout << "Vibrat punkt:";
		cin >> k;
		switch (k) {
		case 1:
			cout << "Sum A and B" << endl;
			cout << a + b;
			break;
		case 2:
			cout << "Sub matrix (A-B)" << endl;
			cout << a - b;
			break;
		case 3:
			cout << "Sub matrix (B-A)" << endl;
			cout << b - a;
			break;
		case 4: break;
		}
	} while (k < 4);
}

/* TMatrix<int> a(5), b(5), c(5);
int i, j;

setlocale(LC_ALL, "Russian");
cout << "Тестирование программ поддержки представления треугольных матриц"
<< endl;
for (i = 0; i < 5; i++)
for (j = i; j < 5; j++ )
{
a[i][j] =  i * 10 + j;
b[i][j] = (i * 10 + j) * 100;
}
c = a + b;
cout << "Matrix a = " << endl << a << endl;
cout << "Matrix b = " << endl << b << endl;
cout << "Matrix c = a + b" << endl << c << endl;
}*/
//---------------------------------------------------------------------------
