// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include < conio.h>
//---------------------------------------------------------------------------

int main()
{
    int n;
    cout << " vvedite size matrix" << endl;
    cin >> n;
  TMatrix<int > a(n), b(n), c(n);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  cout << " vvedite matrix a" << endl;
  cin >> a;
  cout << " vvedite b" << endl;
  cin >> b;
 /* for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }*/

  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;

  c = a + b;
  
  cout << "Matrix c = a + b" << endl << c << endl;
  cout << " Нажмите любую клавишу " << endl;

  c = a - b;
  cout << "Matrix c = a - b" << endl << c << endl;
  cout << " Нажмите любую клавишу " << endl;

  if (a == b)
      cout << "a==b" << endl;
  else
      cout << "a!=b" << endl;

  getch();
  return 0;
}
//---------------------------------------------------------------------------
