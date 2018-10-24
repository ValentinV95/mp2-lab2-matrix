// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
using namespace std;

//---------------------------------------------------------------------------

void main()
{
	setlocale(LC_ALL, "Russian");
  int i, j, n;
	cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
	cout << "�������� �������� ��� ������:"
		<< endl;
	cout << "����� ������� �������, ������� �� ������"
		<< endl;
	cin >> n;
	
	
		TMatrix<int> a(n), b(n);

	
	
	cout << "����� ������ ������� ��������������, ������� 1. ����� �������� ��������� �������, ������� ����� ������ �����"
		<< endl;
	int chs;
	cin >> chs;
	if (chs == 1)
	{
		cout << "������� �"
			<< endl;
		cout << a;
		cout << "������� b"
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
	cout << "������� �������� ��������� �������"
		<< endl;
	cout << "����� �"
		<< endl;
	cout << a;
	cout << "����� �"
		<< endl;
	cout << b;
	cout << "�������� ��������\n"<<"1. �+�\n"<<"2. A-�\n"<<"3. �-A"
		<< endl;
	int logp, flag;
	do {
		cin >> logp;
		switch (logp)
		{
		case 1:
			cout << "����� �+�"
				<< endl;
			cout << a + b;
			flag = 1;
			break;
		case 2:
			cout << "����� �-�"
				<< endl;
			cout << a - b;
			flag = 1;
			break;
		case 3:
			cout << "����� �-�"
				<< endl;
			cout << b - a;
			flag = 1;
			break;

		default:
			cout << "�������� �����, ���������� ��� ���"
				<< endl;
			flag = 0;
			break;
		}
	} while (flag != 1);
	
	system("pause");
	

}
//---------------------------------------------------------------------------
