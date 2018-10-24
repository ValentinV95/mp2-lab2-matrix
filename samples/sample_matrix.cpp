// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <stdlib.h>
//---------------------------------------------------------------------------

void main()
{
  
  int i,n, j,t1,t2;

    setlocale(LC_ALL, "Russian");
  cout << "Testing programs to support the submission of triangular matrices" << endl;
   
 cout << "Enter the sizes of matrix(<10000)"<<endl;
 cin >> n;
 TMatrix<int> a(n), b(n), c(n);
 if (n > MAX_MATRIX_SIZE)
 {
	 cout<<"The size of the matrices exceeds the maximum"<<endl;
 }
 cout << "Choose how to fill the matrices:" << endl;
 cout << "1.Filling the matrix with random numbers" << endl;
 cout << "2.The use of a template matrix" << endl;
 cout << "3.Filling in the matrix by the user" << endl;
  cin >> t1;
  if (t1 == 1)
  {
	  for (i = 0; i < n; i++)
	  
		  for (j = i; j < n; j++) {
			  a[i][j] = rand() % 1001;
			  b[i][j] = rand() % 1001;
		  }
		  cout << "a =" << a << endl;
		  cout << "b =" << b << endl;
	  
  }
  if (t1 == 2)
  {
	  for (i = 0; i < n; i++)
		  for (j = i; j < n; j++) {
			  a[i][j] = i * 10 + j;
			  b[i][j] = (i * 10 + j) * 100;
		  }
  }
  if (t1 == 3) 
  {
	  cout << "Enter matrix a" << endl;
	  cin >> a;
	  cout << "Enter matrix b" << endl;
	  cin >> b;
  }
  cout << "Select the actions you want to perform on the matrices" << endl;
  cout << "1.Addition of matrices a+b" << endl;
  cout<< "2.Subtraction of matrices a-b" << endl;
  cin >> t2;
  if (t2 == 1) 
  {
	  c = a + b;
	  cout << "Matrix a = " << endl << a << endl;
	  cout << "Matrix b = " << endl << b << endl;
	  cout << "Matrix c = a + b" << endl << c << endl;
  }
  if (t2 == 2) 
  {
	  c = a - b;
	  cout << "Matrix a = " << endl << a << endl;
	  cout << "Matrix b = " << endl << b << endl;
	  cout << "Matrix c = a - b" << endl << c << endl;
  }
  
}
//---------------------------------------------------------------------------
