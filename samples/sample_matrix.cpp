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
  int i, j;
  int val;
  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
        cout << "Input a value [" << i << ']' << '[' << j << "] for matrix a"<<endl;
        cin >> val;
        a[i][j] =  val;
    }
  for (i = 0; i < 5; i++)
      for (j = i; j < 5; j++)
      {
          cout << "Input a value [" << i << ']' << '[' << j << "] for matrix b" << endl;
          cin >> val;
          b[i][j] = val;
      }
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << a + b << endl;
  cout << "Matrix c = a - b" << endl << a - b << endl;
}
//---------------------------------------------------------------------------
