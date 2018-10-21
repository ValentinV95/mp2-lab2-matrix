// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include <random>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void sample() {
	cout << "enter matrix size" << endl;
	int n;
	cin >> n;
	TMatrix<double> A(n), B(n);
	cout << "select input method matrix" << endl;
	cout << "1 - random" << endl;
	cout << "2 - input from console" << endl;
	while (true) {
		unsigned input_method;
		cin >> input_method;
		if (input_method == 1) {
			random_device rd;
			mt19937 gen(rd());
			uniform_real_distribution<> dis(-100, 100);
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					A[i][j] = dis(gen);
					B[i][j] = dis(gen);
				}
			}
			cout << endl << "A = " << endl << A << endl;
			cout << endl << "B = " << endl << B << endl;
			break;
		} else if (input_method == 2) {
			cout << "enter matrix A" << endl;
			cin >> A;
			cout << endl << "A = " << endl << A << endl;
			cout << "enter matrix B" << endl;
			cin >> B;
			cout << endl << "B = " << endl << B << endl;
			break;
		} else {
			cout << "incorrect input, please usage:" << endl;
			cout << "1 - random" << endl;
			cout << "2 - input from console" << endl;
		}

	}
	cout << "choose matrix operation" << endl;
	cout << "1: A - B" << endl;
	cout << "2: A + B" << endl;
	cout << "3: B - A" << endl;
	while (true) {
		unsigned enter_operation;
		cin >> enter_operation;
		if (enter_operation == 1) {
			cout << " A - B  = " << endl <<  A - B << endl;
		} else if (enter_operation == 2) {
			cout << " A + B  = " << endl << A + B << endl;
		} else if (enter_operation == 3) {
			cout << " B - A  = " << endl << B - A << endl;
		}
		cout << "do you want exit?" << endl;
		cout << "Yes - press any key" << endl;
		cout << "No - enter 1" << endl;
		unsigned ques_exit;
		cin >> ques_exit;
		if (ques_exit != 1) {
			break;
		} else {
			cout << "choose matrix operation" << endl;
			cout << "1: A - B" << endl;
			cout << "2: A + B" << endl;
			cout << "3: B - A" << endl;
		}
	}
}


void main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
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

  sample();
}
//---------------------------------------------------------------------------
