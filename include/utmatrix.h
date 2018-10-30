﻿// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v);                // конструктор копирования
  ~TVector();
  int GetSize()      { return Size;       } // размер вектора
  int GetStartIndex(){ return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  TVector& operator=(const TVector &v);     // присваивание

  // скалярные операции
  TVector  operator+(const ValType &val);   // прибавить скаляр
  TVector  operator-(const ValType &val);   // вычесть скаляр
  TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
  TVector  operator+(const TVector &v);     // сложение
  TVector  operator-(const TVector &v);     // вычитание
  ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s < 1 ||  s >= MAX_VECTOR_SIZE || si < 0)
	{
		throw "1 <= s < MAX_VECTOR_SIZE or si < 0";
	}
	Size = s;
	StartIndex = si;
	pVector = new ValType[Size];
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos >= Size + StartIndex || pos - StartIndex < 0)
	{
		throw "Ind >= Size or Ind < 0";
	}
	return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (Size == v.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (pVector[i] != v.pVector[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if (Size == v.Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (pVector[i] != v.pVector[i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (this != &v)
	{
		if (Size == v.Size)
		{
			StartIndex = v.StartIndex;
			for (int i = 0; i < Size; i++)
			{
				pVector[i] = v.pVector[i];
			}
			return *this;
		}
		else
		{
			Size = v.Size;
			StartIndex = v.StartIndex;
			delete[] pVector;
			pVector = new ValType[Size];
			for (int i = 0; i < Size; i++)
			{
				pVector[i] = v.pVector[i];
			}
			return *this;
		}
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	if (!val)
	{
		TVector<ValType> temp(*this);
		return temp;
	}
	else
	{
		TVector<ValType> temp(Size + StartIndex, 0);
		for (int i = 0; i < temp.Size; i++)
		{
			temp.pVector[i] = val;
		}
		for (int i = StartIndex; i < temp.Size; i++)
		{
			temp.pVector[i] = temp.pVector[i] + pVector[i - StartIndex];
		}
		return temp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	if (val == 0)
	{
		TVector<ValType> temp(*this);
		return temp;
	}
	else
	{
		TVector<ValType> temp(Size + StartIndex, 0);
	    for (int i = 0; i < temp.Size; i++)
		{
			temp.pVector[i] = (-1) * val;
		}
		for (int i = StartIndex; i < temp.Size; i++)
		{
			temp.pVector[i] += pVector[i - StartIndex];
		}
		return temp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
	{
		temp[i] = pVector[i] * val;
	}
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size + StartIndex != v.Size + v.StartIndex)
	{
		throw "dim_vectors_not_equal";
	}
	else
	{
		if (StartIndex < v.StartIndex)
		{
			TVector<ValType> temp(*this);
			for (int i = 0; i < v.Size; i++)
			{
				temp.pVector[i + v.StartIndex - StartIndex] = temp.pVector[i + v.StartIndex - StartIndex] + v.pVector[i];
			}
			return temp;
		}
		else
		{
			TVector<ValType> temp(v);
			for (int i = 0; i < Size; i++)
			{
				temp.pVector[i + StartIndex - v.StartIndex] = temp.pVector[i + StartIndex - v.StartIndex] + pVector[i];
			}
			return temp;
		}
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size + StartIndex != v.Size + v.StartIndex)
	{
		throw "dim_vectors_not_equal";
	}
	else
	{
		if (StartIndex < v.StartIndex)
		{
			TVector<ValType> temp(*this);
			for (int i = 0; i < v.Size; i++)
			{
				temp.pVector[i + v.StartIndex - StartIndex] = temp.pVector[i + v.StartIndex - StartIndex] - v.pVector[i];
			}
			return temp;
		}
		if (StartIndex > v.StartIndex)
		{
			TVector<ValType> temp(v);
			for (int i = 0; i < Size; i++)
			{
				temp.pVector[i + StartIndex - v.StartIndex] = pVector[i] - temp.pVector[i + StartIndex - v.StartIndex];
			}
			for (int i = 0; i < StartIndex - v.StartIndex; i++)
			{
				temp.pVector[i] = temp.pVector[i] - temp.pVector[i] - temp.pVector[i];
			}
			return temp;
		}
		if (Size == v.Size)
		{
			TVector<ValType> temp(Size, StartIndex);
			for (int i = 0; i < Size; i++)
			{
				temp.pVector[i] = pVector[i] - v.pVector[i];
			}
			return temp;
		}
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if (Size + StartIndex != v.Size + v.StartIndex)
	{
		throw "dim_vectors_not_equal";
	}
	else
	{
		ValType temp = 0;
		if (StartIndex < v.StartIndex)
		{
			for (int i = 0; i < v.Size; i++)
			{
				temp = temp + pVector[v.StartIndex - StartIndex + i] * v.pVector[i];
			}
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				temp = temp + pVector[i] * v.pVector[StartIndex - v.StartIndex + i];
			}
		}
		return temp;
    }
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator= (const TMatrix &mt);        // присваивание
  TMatrix  operator+ (const TMatrix &mt);        // сложение
  TMatrix  operator- (const TMatrix &mt);        // вычитание

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
	if (s < 1 || s >= MAX_MATRIX_SIZE)
	{
		throw "1 <= s < MAX_MATRIX_SIZE";
 	}
	Size = s;
	StartIndex = 0;
	for (int i = 0; i < s; i++)
	{
		pVector[i] = TVector<ValType>(s - i, i);
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>>::operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>>::operator!=(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	TVector<TVector<ValType>>::operator=(mt);
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif