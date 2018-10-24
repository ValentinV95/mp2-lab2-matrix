// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
using namespace std;

//---------------------------------------------------------------------------

void main()
{
	setlocale(LC_ALL, "Russian");
  int i, j, n;
	cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
	cout << "Выберете желаемый тип матриц:"
		<< endl;
	cout << "Чтобы создать матрицы, введите их размер"
		<< endl;
	cin >> n;
	
	
		TMatrix<int> a(n), b(n);

	
	
	cout << "Чтобы ввести матрицу самостоятельно, нажмите 1. Чтобы получить случайную матрицу, нажмите любую другую цифру"
		<< endl;
	int chs;
	cin >> chs;
	if (chs == 1)
	{
		cout << "Введите а"
			<< endl;
		cout << a;
		cout << "Введите b"
			<< endl;
		cout << b;
	}
	else
	{
		for (i = 0; i < n; i++)
			for (j = i; j < n; j++)
			{
				a[i][j] = 1 + rand() % 100;
				b[i][j] = 1 + rand() % 100;
			}
	}
	cout << "Матрицы выглядят следующим образом"
		<< endl;
	cout << "Вывод А"
		<< endl;
	cout << a;
	cout << "Вывод Б"
		<< endl;
	cout << b;
	cout << "Выберите операцию\n"<<"1. А+Б\n"<<"2. A-Б\n"<<"3. Б-A"
		<< endl;
	int logp, flag;
	do {
		cin >> logp;
		switch (logp)
		{
		case 1:
			cout << "Вывод А+Б"
				<< endl;
			cout << a + b;
			flag = 1;
			break;
		case 2:
			cout << "Вывод А-Б"
				<< endl;
			cout << a - b;
			flag = 1;
			break;
		case 3:
			cout << "Вывод Б-А"
				<< endl;
			cout << b - a;
			flag = 1;
			break;

		default:
			cout << "Неверный номер, попробуйте ещё раз"
				<< endl;
			flag = 0;
			break;
		}
	} while (flag != 1);
	
	system("pause");
	

}
//---------------------------------------------------------------------------
