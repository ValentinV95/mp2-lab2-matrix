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
	int size,с;
	std::cout << "Write size of matixes" << endl;
	std::cin >> size;
	if(size == 0)
		cout << "incorrect size";

	TMatrix<int> a(size), b(size);
	std::cout << "enter the first matrix" << endl;
	std::cin >> a;
	std::cout << "enter the second matrix" << endl;
	std::cin >> b;

	std::cout << "if you want to subtract press 1, if you want to add press 2" << endl;
	std::cin >> с;

	if (с == 1)
		std::cout << a - b << endl;
	else

		if (с == 2)
			std::cout << a + b << endl;
		else
			std::cout << "wrong action" << endl;
}
//---------------------------------------------------------------------------
