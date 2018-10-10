// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы
#include "utmatrix.h"
#include <stdlib.h>   
#include <time.h> 
//---------------------------------------------------------------------------
#define USE_INT //закомментировать, чтобы использовать double

#ifdef USE_INT
#define mType int
#else
#define mType double
#endif

void main()
{
  
  int i, k, j, f, n, t = 1;
  setlocale(LC_ALL, "Russian");
  cout << "Вас приветствует тестовое приложение!" << endl;
  while(t)
  {
	  do
	  {
		cout << "Введите размеры матриц (не больше, чем MAX_MATRIX_SIZE = 10000)" << endl;
		cin >> n;
		if(n > MAX_MATRIX_SIZE)
		{
			cout << "Размер больше, чем MAX_MATRIX_SIZE" << endl;
		}
	  }
	  while(n > MAX_MATRIX_SIZE);
	TMatrix<mType> a(n), b(n);
	cout << "1) Пользовательский ввод" << endl;
	cout << "2) Случайные матрицы" << endl;
	cin >> k;
	do
	{
		if(k == 1)
		{
			cout << "Введите матрицу a" << endl;
			cin >> a;
			cout << "Введите матрицу b" << endl;
			cin >> b;
		}
		else if (k == 2)
		{
			srand (time(NULL));
			for (i = 0; i < n; i++)
			{
				for (j = i; j < n; j++)
				{
					a[i][j] =  ((double) rand()/ (double) RAND_MAX) * 99 + 1; 
					b[i][j] = ((double) rand()/(double)  RAND_MAX) * 99 + 1; 
				}
			}
			cout << "a =" << endl;
			cout << a << endl;
			cout << "b =" << endl;
			cout << b << endl;
		}
		else
		{
			cout << "Введите 1 или 2" << endl;
			k = 0;
		}
	}
	while(k == 0);
	cout << "1) a + b" << endl;
	cout << "2) a - b" << endl;
	cout << "3) b - a" << endl;
	cout << "Завершить - любая другая клавиша" << endl;
	do
	{
		cin >> f;
		switch(f)
		{
		case 1:
			{
				cout << "a + b =" << endl;
				cout << a + b << endl;
			}
			break;
		case 2:
			{
				cout << "a - b =" << endl;
				cout << a - b << endl;
			}
			break;
		case 3:
			{
				cout << "b - a =" << endl;
				cout << b - a << endl;
			}
			break;
		default:
			f = 0;
		}
	}
	while(f != 0);
	cout << "1) Продолжить с новыми матрицами" << endl;
	cout << "2) Завершить тестирование" << endl;
	int r;
	cin >> r;
	if(r != 1)
	{
		t = 0;
	}
  }
}
//---------------------------------------------------------------------------
