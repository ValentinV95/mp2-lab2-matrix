// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include "utmatrix.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

void menu()
{
	cout << "�������� ��������:" << endl;
	cout << "1.���� �������." << endl;
	cout << "2.�������� ������." << endl;
	cout << "3.��������� ������." << endl;
	cout << "4.��������� ������� �� �����." << endl;
	cout << "5.��������� ���� ������." << endl;
	cout << "6.����� �������� ������� �� �����." << endl << endl;
	cout << "0-�����" << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int num = 0;
	int size, choose;
	cout << "������� ������ �������." << endl;
	cin >> size;
	TMatrix<int> needed(size);
	TMatrix<int> main(size);
	cout << "������� ������� 1";
	cin >> main;
	cout << main;
	cout << "������� ������� 2";
	cin >> needed;
	cout << needed;
	menu();
	cin >> choose;
	do {
		menu();
		cin >> choose;
		switch (choose) {
		case 0:
			system("����");
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
			cout << " ������� ����� : ";
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