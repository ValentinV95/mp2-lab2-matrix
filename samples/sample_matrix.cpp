#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{

    setlocale(LC_ALL, "Russian");
    int size;
    cout << "������� ������ ������" << endl;
    cin >> size;
    TMatrix<int> a(size), b(size), c(2), d(2);
    int i, j;

    for (i = 0; i < size; i++)
        for (j = i; j < size; j++)
        {
            int q, w;
            cout << "������� " << j + 1 << " ������� " << i + 1 << " ������ ������ �������." << endl;
            cin >> q;
            cout << "������� " << j + 1 << " ������� " << i + 1 << " ������ ������ �������." << endl;
            cin >> w;
            a[i][j] = q;
            b[i][j] = w;
        }
    c = a + b;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a + b" << endl << c << endl;
    d = a - b;
    cout << "Matrix d = a - b" << endl << d << endl;
    if (a == b)
    {
        cout << "������� a � b �����." << endl;
    }
    if (a != b)
    {
        cout << "������� a � b �� �����." << endl;
    }
}