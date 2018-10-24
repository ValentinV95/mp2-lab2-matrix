// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <cstdlib>
//---------------------------------------------------------------------------

void main()
{
  int i, j;
  int n, k;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  cout << "Введите размер матриц "
	  << endl;
  cin >> n;
  TMatrix<int> a(n), b(n), c(n);
  cout << "Как заполнить матрицу : 1 - вручную 2 - рандомно 3 - из исходного примера"
	  << endl;
  cin >> k;
  if ((k != 1) && (k != 2) && (k != 3)) {
	  cout << "Вы не выбрали как заполнить матрицу"
		  << endl;
  }
  else {
	  if (k == 1) {
		  cout << "Введите матрицу а"
			  << endl;
		  for (i = 0; i < n; i++)
			  for (j = i; j < n; j++)
			  {
				  cin >> a[i][j];
			  }
		  cout << "Введите матрицу b"
			  << endl;
		  for (i = 0; i < n; i++)
			  for (j = i; j < n; j++)
			  {
				  cin >> b[i][j];
			  }
	  }
	  if (k == 2) {
		  for (i = 0; i < n; i++)
			  for (j = i; j < n; j++)
			  {
				  a[i][j] = rand() % 1000;
				  b[i][j] = rand() % 1000;
			  }
	  }
	  if (k == 3) {
		  for (i = 0; i < n; i++)
			  for (j = i; j < n; j++)
			  {
				  a[i][j] = i * 10 + j;
				  b[i][j] = (i * 10 + j) * 100;
			  }
	  }

	  cout << "Какую операцию выполнить 1 - сложение 2 - вычитание 3 - присваивание 4 - сранение "
		  << endl;
	  cin >> k;
	  if ((k != 1) && (k != 2) && (k != 3) && (k != 4)) {
		  cout << "Matrix a = " << endl << a << endl;
		  cout << "Matrix b = " << endl << b << endl;
	  }
	  else {
		  if (k == 1) {
			  c = a + b;
			  cout << "Matrix a = " << endl << a << endl;
			  cout << "Matrix b = " << endl << b << endl;
			  cout << "Matrix c = " << endl << c << endl;
		  }
		  if (k == 2) {
			  c = a - b;
			  cout << "Matrix a = " << endl << a << endl;
			  cout << "Matrix b = " << endl << b << endl;
			  cout << "Matrix c = " << endl << c << endl;
		  }
		  if (k == 3) {
			  c = a;
			  cout << "Matrix a = " << endl << a << endl;
			  cout << "Matrix c = " << endl << c << endl;
		  }
		  if (k == 4) {
			  if (a == b) {
				  cout << "Матрицы равны" << endl;
				  cout << "Matrix a = " << endl << a << endl;
				  cout << "Matrix b = " << endl << b << endl;
			  }
			  else {
				  cout << "Матрицы не равны" << endl;
				  cout << "Matrix a = " << endl << a << endl;
				  cout << "Matrix b = " << endl << b << endl;
			  }
		  }
	  }
  }
}
//---------------------------------------------------------------------------
