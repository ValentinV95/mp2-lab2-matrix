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
  TMatrix<int> a(5), b(5), c(5);
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
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
 
  c = a + b;
  cout << "Matrix c = a + b" << endl << c << endl;

  b = a - c;
  cout << "Matrix b = a - c" << endl << b << endl;

  if (b != c - a)
  {
      cout << "Matrix b != c - a" << endl << endl;
  }

  if (b == a - c)
  {
      cout << "Matrix b == -(c - a)" << endl << endl;
  }

  TMatrix<double> a1(2), b1(2), c1(2), d1(2);
  for (i = 0; i < 2; i++)
      for (j = i; j < 2; j++)
      {
          a1[i][j] = 0.3 + 0.1 * i;
          b1[i][j] = 0.3 + 0.1 * i * 0.5;
      }
  cout << "Matrix a1 = " << endl << a1 << endl;
  cout << "Matrix b1 = " << endl << b1 << endl;
  d1 = a1 - b1;
  cout << "Matrix d1 = " << endl << d1 << endl;
  
}

