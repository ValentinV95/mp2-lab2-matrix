// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include "utmatrix.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

void menu()
{
	cout << "Выберите действие:" << endl;
	cout << "1.Ввод матрицы." << endl;
	cout << "2.Сложение матриц." << endl;
	cout << "3.Вычитание матриц." << endl;
	cout << "4.Умножение матрицы на число." << endl;
	cout << "5.Умножение двух матриц." << endl;
	cout << "6.Вывод исходной матрицы на экран." << endl << endl;
	cout << "0-конец" << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int num = 0;
	int size, choose;
	cout << "Введите размер матрицы." << endl;
	cin >> size;
	TMatrix<int> needed(size);
	TMatrix<int> main(size);
	cout << "введите матрицу 1";
	cin >> main;
	cout << main;
	cout << "введите матрицу 2";
	cin >> needed;
	cout << needed;
	menu();
	cin >> choose;
	do {
		menu();
		cin >> choose;
		switch (choose) {
		case 0:
			system("стоп");
			break;
		case 1:
			cout << main;
			break;
		case 2:
			main = main + needed;
			cout << main;
			break;
		case 3:
			main = main - needed;
			cout << main;
			break;
		case 4:
			cout << " введите число : ";
			cin >> num;
			cout << endl << endl;
			main = main * num;
			cout << main;
			break;
		case 5:
			main = main * needed;
			cout << endl << main;
			break;
		case 6:
			cout << main;
			break;
		}
	} while (choose);
	return 0;
}