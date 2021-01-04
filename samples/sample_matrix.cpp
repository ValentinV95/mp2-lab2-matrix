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
  int n, k;
  setlocale(LC_ALL, "Russian");
  std::cout << "Тестирование программ поддержки представления треугольных матриц"
	  << endl;
  std::cout << "Введите порядок матриц: " << endl;
  std::cin >> n;
  TMatrix<int> a(n), b(n);
  std::cout << "Введите 1-ю матрицу" << endl;
  std::cin >> a;
  std::cout << "Введите 2-ю матрицу" << endl;
  std::cin >> b;
  std::cout << "1) 1 + 2" << endl;
  std::cout << "2) 1 - 2" << endl;
  std::cin >> k;
  if (k == 1)
	  std::cout << a + b << endl;
  else

	  if (k == 2)
		  std::cout << a - b << endl;
	  else
		  std::cout << "Операции под таким номером не существует" << endl;
}
//---------------------------------------------------------------------------
