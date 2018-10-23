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
	TMatrix<int> a(5), b(5), c(5);
	int i, j, tmp, tmp2;

	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ������������� ����������� ������" << endl;
	cout << "���� ������ ���������� ����������-������� 1" << endl << "���� ������ ���������� (����������)-������� 2" << endl << "������ ���� ������-������� 3" << endl;
	cin >> tmp;
	if (tmp == 2)
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++) {
				a[i][j] = i * 10 + j;
				b[i][j] = (i * 10 + j) * 100;
			}
	if (tmp == 3) {
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++)
				cin >> a[i][j];
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++)
				cin >> b[i][j];
	}
	if (tmp == 1)
		for (i = 0; i < 5; i++)
			for (j = i; j < 5; j++) {
				a[i][j] = rand() % 1001;
				b[i][j] = rand() % 1001;
			}

	cout << "�������� ������-������� 1" << endl << "��������� ������-������� 2" << endl;
	cin >> tmp2;
	if (tmp2 == 1) {
		c = a + b;
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a + b" << endl << c << endl;
	}
	if (tmp2 == 2) {
		c = a - b;
		cout << "Matrix a = " << endl << a << endl;
		cout << "Matrix b = " << endl << b << endl;
		cout << "Matrix c = a - b" << endl << c << endl;
	}
}
//---------------------------------------------------------------------------
