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
  int n, k;
  setlocale(LC_ALL, "Russian");
  std::cout << "������������ �������� ��������� ������������� ����������� ������"
	  << endl;
  std::cout << "������� ������� ������: " << endl;
  std::cin >> n;
  TMatrix<int> a(n), b(n);
  std::cout << "������� 1-� �������" << endl;
  std::cin >> a;
  std::cout << "������� 2-� �������" << endl;
  std::cin >> b;
  std::cout << "1) 1 + 2" << endl;
  std::cout << "2) 1 - 2" << endl;
  std::cin >> k;
  if (k == 1)
	  std::cout << a + b << endl;
  else

	  if (k == 2)
		  std::cout << a - b << endl;
	  else
		  std::cout << "�������� ��� ����� ������� �� ����������" << endl;
}
//---------------------------------------------------------------------------
