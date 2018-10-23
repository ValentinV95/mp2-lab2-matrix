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
	int n;

    TMatrix<int> a(n), b(n), c(n), d(n);

    setlocale(LC_ALL, "Russian");
    cout << "������������ �������� ��������� ������������� ����������� ������" << endl;

	cout << "������� ������ ������" << endl;
	cin >> n;
	cout << "��������� ���� ������� �" << endl;
	cin >> a;
	cout << endl;
	cout << "��������� ���� ������� �" << endl;
	cin >> b;
	cout << endl;
    
	cout << "1 - ����� ������, 2 - �������� ������, 3 - ������������, 4 - ��������� ������" << endl;
	int temp;
	cin >> temp;
	cout << endl;
	if (temp == 1)
	{
		c = a + b;
		cout << "Matrix c = a + b" << endl << c << endl;
	}
	if (temp == 2)
	{
		d = a - b;
		cout << "Matrix d = a - b" << endl << d << endl;
	}
	if (temp == 3)
	{
		a = b;
		cout << "Matrix a = b" << endl << a << endl;
	}
	if (temp == 4)
	{
		if (a != b)
		{
			cout << "Matrix a != b" << endl << d << endl;
		}
		else
		{
			cout << "Matrix a == b" << endl << d << endl;
		}
	}
}
//---------------------------------------------------------------------------
