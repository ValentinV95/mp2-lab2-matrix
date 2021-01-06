// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"

void main()
{
    int value = 0;
    size_t size = 0;
    size_t count = 0;
    cout << "Write size of matixes" << endl;
    cin >> size;
    if (size == 0)
    {
        cout << "U choice size = 0";
    }
    else
    {
        cout << endl << "Size of matrixes is " << size << "x" << size << endl;
    }
    TMatrix<int> a(size), b(size), res(size);
    cout << "Choice elements of matrixes a and b" << endl << "Matrix a:" << endl;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> value;
            a[i][j] = value;
        }
    }
    cout << "Matrix a = " << endl << a << endl;
    cout << endl << "matrix b:" << endl;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            cout << "b[" << i << "][" << j << "] = ";
            cin >> value;
            b[i][j] = value;
        }
    }
    cout << "Matrix b = " << endl << b << endl;
    cout << "Write would you like to do smth with this matrixes?" << endl << "If you want to add tap - 1," << endl << "if you want to sub (a - b) - tap 2," << endl << "if you want to sub (b - a) - tap 3," << endl << "if you woudlnt like to do smth - write 0" << endl;
    cin >> count;
    cout << "You`ve turned - " << count << endl;
    while (count == 1 || count == 2 || count == 3)
    {
        switch (count)
        {
        case 1:
        {
            res = a + b;
            cout << "res = " << endl << res << endl;
            cout << "Write would you like to do smth with this matrixes?" << endl << "If you want to add tap - 1," << endl << "if you want to sub (a - b) - tap 2," << endl << "if you want to sub (b - a) - tap 3," << endl << "if you woudlnt like to do smth - write 0" << endl;
            cin >> count;
            cout << "You`ve turned - " << count << endl;
            break;
        }
        case 2:
        {
            res = a - b;
            cout << "res = " << endl << res << endl;
            cout << "Write would you like to do smth with this matrixes?" << endl << "If you want to add tap - 1," << endl << "if you want to sub (a - b) - tap 2," << endl << "if you want to sub (b - a) - tap 3," << endl << "if you woudlnt like to do smth - write 0" << endl;
            cin >> count;
            cout << "You`ve turned - " << count << endl;
            break;
        }
        case 3:
        {
            res = b - a;
            cout << "res = " << endl << res << endl;
            cout << "Write would you like to do smth with this matrixes?" << endl << "If you want to add tap - 1," << endl << "if you want to sub (a - b) - tap 2," << endl << "if you want to sub (b - a) - tap 3," << endl << "if you woudlnt like to do smth - write 0" << endl;
            cin >> count;
            cout << "You`ve turned - " << count << endl;
            break;
        }
        }
    }
    cout << "You choise count as 0 or incorrect: Program has ended";
}
