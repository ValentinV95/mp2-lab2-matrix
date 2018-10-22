// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include <random>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(5), b(5), c(5), d(5), f(5);
  int i, j;
  random_device rd;    
  mt19937 gen(rd());  
  uniform_int_distribution<> dis1(1, 20);
  uniform_int_distribution<> dis2(21, 40);
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++)
    {
		a[i][j] = dis1(gen);
		b[i][j] = dis2(gen);
    }
  c = a + b;
  d = b - a;
  f = a - b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  cout << "Matrix d = b - a" << endl << d << endl;
  cout << "Matrix f = a - b" << endl << f << endl;
}
//---------------------------------------------------------------------------
