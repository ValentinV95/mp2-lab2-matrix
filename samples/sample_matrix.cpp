// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{

    int size;
    bool check = false;
    while (check == false) {
        cout << "Enter matrix size" << endl;
        cin >> size;
        if (size > 0)
            check = true;
        else
            cout << "Invalid matrix size" << endl;
    }
    TMatrix<int> a(size), b(size), res(size);
    cout << "Enter the value of the matrices" << endl << "Matrix a:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int val;
            cout << "a[" << i << "][" << j << "] = ";
            cin >> val;
            a[i][j] = val;
        }
    }
    cout << "Matrix a = " << endl << a << endl;
    cout << endl << "matrix b:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            int val;
            cout << "b[" << i << "][" << j << "] = ";
            cin >> val;
            b[i][j] = val;
        }
    }

    res = a + b;
    cout << "a + b: " << endl << res << endl;
    res = a - b;
    cout << "a - b: " << endl << res << endl;
}
//---------------------------------------------------------------------------
