// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
	int size,�;
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
	std::cin >> �;

	if (� == 1)
		std::cout << a - b << endl;
	else

		if (� == 2)
			std::cout << a + b << endl;
		else
			std::cout << "wrong action" << endl;
}
//---------------------------------------------------------------------------
