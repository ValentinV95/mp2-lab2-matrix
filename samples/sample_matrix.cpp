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
  TMatrix<int> a(3), b(3), c(3), d(3), l(3);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
 /* for (i = 0; i < 3; i++)
    for (j = i; j < 3; j++ )
    {
      a[i][j] =  2;
      b[i][j] =  3;
    }*/

  cin >> a;
  cin >> b;
  c = a + b;
  d = a-b;
  l= c+d;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  cout << "Matrix d = a - b" << endl << d << endl;
  cout << "Matrix l = c + d" << endl << l << endl;
}
//---------------------------------------------------------------------------
