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
  int i, j;
  random_device rd;    
  mt19937 gen(rd());  
  uniform_int_distribution<> dis1(10, 20);
  uniform_int_distribution<> dis2(21, 40);
  setlocale(LC_ALL, "Russian");
  cout << "Triangle Matrix Testing Program" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "Enter matrix size: ";
  int x;
  cin >> x;
  TMatrix<int> a(x), b(x), c(x);
  cout << "How you want to fill matrix? " << endl << "1. Random " << endl << "2. By yourself on keyboard " << endl;
  int p;
  cin >> p;
  if (p) {
	  for (i = 0; i < x; i++)
		  for (j = i; j < x; j++) {
			  a[i][j] = dis1(gen);
			  b[i][j] = dis2(gen);
		  }
  }
  if (p == 2) {
	  cin >> a;
	  cin >> b;
  }
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;

  cout << "What do you want to do with matrix?" << endl << "1. a + b " << endl;
  cout << "2. b - a" << endl;
  cout << "3. a - b" << endl;

	int todo;
	cin >> todo;
	
	switch (todo) {
  case 1:
	  c = a + b;
	  cout << "Matrix c = a + b " << endl << c << endl;
	  break;
  case 2:
	  c = b - a;
	  cout << "Matrix c = b - a " << endl << c << endl;
	  break;
  case 3:
	  c = a - b;
	  cout << "Matrix c = a - b " << endl << c << endl;
	  break;
  }
}
//---------------------------------------------------------------------------
