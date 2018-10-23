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
	cout << " ТРЕУГОЛЬНЫЕ МАТРИЦЫ" << endl;
	cout << "Ввод матриц" << endl;
	cout << "Введите количество строк матриц:";
	cin >> t;
	TMatrix<int> a(t), b(t);
	cout << "Введите матрицу А" << endl;
	for (int i = 0; i < t; i++)
		cin >> a[i];
	cout << "Матрица А = " << endl << a << endl;
	cout << "Введите матрицу В" << endl;
	for (int i = 0; i < t; i++)
		cin >> b[i];
	cout << "Матрица В = " << endl << b << endl;
	cout << " МЕНЮ:" << endl;
	do {
		cout << "1.Сложение матриц А и В" << endl;
		cout << "2.Вычитание матриц (А-В)" << endl;
		cout << "3.Вычитание матриц (В-А)" << endl;
		cout << "4.Выход" << endl;
		cout << "Выбрать пункт:";
		cin >> k;
		switch (k) {
		case 1:
			cout << "Сложение матриц А и В" << endl;
			cout << a + b;
			break;
		case 2:
			cout << "Вычитание матриц (А-В)" << endl;
			cout << a - b;
			break;
		case 3:
			cout << "Вычитание матриц (В-A)" << endl;
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
