// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"

void main()
{
	int n,key,type,op;
	cout << "Enter the size of the matrix :" << endl;
	cin >> n;
	TMatrix <int> a(n), b(n);
	cout << "Enter matrix A, then B";
	cin >> a >> b;
	cout << "Choose the operation :" << endl
		<< "1.A + B" << endl << "2.A - B" << endl << "3. B - A";
	cin >> op;
	switch (op)
	{
		case 1:
		{
			cout << endl << a + b;
			break;
		}
		case 2:
		{
			cout << endl << a - b;
			break;
		}
		case 3:
		{
			cout << endl << b - a;
			break;
		}
		default:
		{
			cout << "Wrong operation, try again";
			cout << "Choose the operation :" << endl
				<< "1.A + B" << endl << "2.A - B" << endl << "3. B - A";
			cin >> op;
		}
	}
}




