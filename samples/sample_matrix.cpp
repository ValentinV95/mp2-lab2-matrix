// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
#include <time.h>
//---------------------------------------------------------------------------

void main()
{ int n , Key, f;
setlocale(LC_ALL, "Russian");
cout << "������������ �������� ��������� ������������� ����������� ������"
	<< endl;
L:
cout << "������� ������ ������ � � b";
cout << endl;
cin >> n;
if (n < MAX_MATRIX_SIZE)
{
	TMatrix<int > a(n);
	TMatrix<int > b(n);

	cout << "������� 1 , ���� ������ �������� ������� ��������������, 2, ���� ������ ������ ������������ �����: ";
	cout << endl;

	cin >> Key;
	switch (Key)
	{
	case 1:
		{ 
			cout << "   a:"<<endl;
			for ( int i = 0; i < n; i++)
				for (int j = i; j< n; j++)
					cin >> a[i][j];

			cout << "   b:" << endl;
			for ( int i = 0; i < n; i++)
				for (int j = i; j< n; j++)
					cin >> b[i][j];
			break;
		}
	case 2:
		{
			srand(time(NULL));
			for ( int i = 0; i < n; i++)
				for (int j = i; j< n; j++)
				{
					a[i][j] = (int) rand()%245;
					b[i][j] = (int) rand()%137;
				}
				break;
		}
	default :
		{  Key = 0;
		cout << "���-�� �� �� ��� ������ � ����������!";
		cout << endl;
		}
	}
	if (Key != 0)
	{
	cout << "a = " << endl;
	cout << a << endl;
	cout << "b = " << endl;
	cout << b << endl;

	cout << "��� ��������� �������?";
	cout << endl;
	cout << "1: a + b";
	cout << endl;
	cout << "2: a - b";
	cout << endl;
	cout << "3 : b - a";
	cout << endl;
	cin >> Key;
	switch (Key)
	{
	case 1:
		{
			cout << " a + b = " << endl ;
			cout << a+b<< endl;
			break;
		}
	case 2:
		{
			cout << " a + b = " << endl ;
			cout << a-b<< endl;
			break;
		}
	case 3:
		{
			cout << " b - a = " << endl ;
			cout << b - a << endl;
			break;
		}
	default:
		{
			Key = 0;
			cout << "������� �� ������!";
			cout << endl;
		}
	}
	}
	cout << "������� 1, ����� ����������� ����� , ��� ������� 2, ����� ����: " ;
	cin >> f;
	if (f == 1)
		goto L;
	else cout << "���� ����!";
	cout << endl;
}
}
//---------------------------------------------------------------------------
