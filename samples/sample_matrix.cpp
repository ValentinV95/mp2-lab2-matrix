// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ������������� ����������� ������"
		<< endl << endl;

	bool z = true;

	do {

		int s, k, d, f;
		bool x = false;
		cout << "������� ������ ������" << endl;
		cin >> s;
		cout << endl;

		TMatrix<int> a(s), b(s), c(s);

		do {

			cout << "�������� ������ ����������" << endl;
			cout << "1) ��������� �����" << endl;
			cout << "2) ������ ����" << endl;
			cin >> k;

			switch (k)
			{
			case 1:

				for (int i = 0; i < s; i++)
					for (int j = i; j < s; j++)
					{
						a[i][j] = rand();
						b[i][j] = rand();
					}

				x = true;

				break;
			case 2:

				cout << "������� ������� a" << endl;

				for (int i = 0; i < s; i++)
					for (int j = i; j < s; j++)
					{
						cout << "a[" << i << "][" << j << "]=";
						cin >> a[i][j];
					}
				cout << endl;

				cout << "������� ������� b" << endl;

				for (int i = 0; i < s; i++)
					for (int j = i; j < s; j++)
					{
						cout << "b[" << i << "][" << j << "]=";
						cin >> b[i][j];
					}
				cout << endl;

				x = true;

				break;
			default:

				cout << "������������ ����, ��������� �������" << endl << endl;

				break;
			}
		} while (!x);

		x = false;
		cout << "������� a = " << endl << a << endl;
		cout << "������� b = " << endl << b << endl << endl;

		do {

			cout << "�������� �������� ��� ���������" << endl;
			cout << "1) ��������" << endl;
			cout << "2) ���������" << endl;
			cout << "3) ���������" << endl;
			cin >> d;

			switch (d)
			{
			case 1:

				c = a + b;
				cout << "������� � = a + b" << endl;
				cout << c;

				x = true;

				break;
			case 2:

				c = a - b;
				cout << "������� � = a - b" << endl;
				cout << c;

				x = true;

				break;
			case 3:

				if (a == b)
					cout << "������� a � b �����" << endl;
				else
					cout << "������� a � b �� �����" << endl;

				x = true;

				break;
			default:

				cout << "������������ ����, ��������� �������" << endl << endl;

				break;
			}

		} while (!x);

		x = false;

		do {
			cout << endl;
			cout << "��������� ���������?" << endl;
			cout << "1) ��" << endl;
			cout << "2) ���" << endl;
			cin >> f;

			switch (f)
			{
			case 1:

				x = true;
				z = false;

				break;
			case 2:

				x = true;

				break;
			default:

				cout << "������������ ����, ��������� �������" << endl << endl;

				break;
			}

		} while (!x);


	}while (z);

}    
//---------------------------------------------------------------------------
