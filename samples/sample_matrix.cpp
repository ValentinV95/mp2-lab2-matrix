// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
#include "locale.h"
//---------------------------------------------------------------------------

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int k, t;
	int a1, b1;
	cout << " ����������� �������" << endl;
	cout << "���� ������" << endl;
	cout << "������� ���������� ����� ������:";
	cin >> t;
	TMatrix<int> a(t), b(t);
	cout << "������� ������� �" << endl;
	for (int i = 0; i < t; i++)
		cin >> a[i];
	cout << "������� � = " << endl << a << endl;
	cout << "������� ������� �" << endl;
	for (int i = 0; i < t; i++)
		cin >> b[i];
	cout << "������� � = " << endl << b << endl;
	cout << " ����:" << endl;
	do {
		cout << "1.�������� ������ � � �" << endl;
		cout << "2.��������� ������ (�-�)" << endl;
		cout << "3.��������� ������ (�-�)" << endl;
		cout << "4.�����" << endl;
		cout << "������� �����:";
		cin >> k;
		switch (k) {
		case 1:
			cout << "�������� ������ � � �" << endl;
			cout << a + b;
			break;
		case 2:
			cout << "��������� ������ (�-�)" << endl;
			cout << a - b;
			break;
		case 3:
			cout << "��������� ������ (�-A)" << endl;
			cout << b - a;
			break;
		case 4: break;
		}
	} while (k < 4);
}

 /* TMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
}*/
//---------------------------------------------------------------------------
