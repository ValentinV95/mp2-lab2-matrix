// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include "locale.h"
#include "cstdlib"


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
	int GetSize()   const { return Size; } // размер вектора
	int GetStartIndex() { return StartIndex; } // индекс первого элемента
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
	if (s + si> MAX_VECTOR_SIZE)
		throw "create_too_large_vector";
	if (s <= 0)
		throw "create_vector_with_negative_length";

	if (si <0)
		throw "create_vector_with_negative_startindex";
	pVector = new ValType[s];
	Size = s;
	StartIndex = si;
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	pVector = new ValType[v.Size];
	Size = v.Size; StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];

} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos - StartIndex < 0) || (pos - StartIndex >= Size))
		throw "set_element_with_negative_index";
	return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	bool k = true;
	if (Size != v.Size)
		return false;
	else
	{
		for (int i = 0; i < Size; i++)
			if (pVector[i] != v.pVector[i])
			{
				k = false;
				break;
			}
		return k;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if (*this == v)
		return false;
	else return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (this != &v)
	{
		if (Size != v.Size)
		{
			delete[] pVector;
			pVector = new ValType[v.Size];
		}
		Size = v.Size; StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{

	TVector <ValType>temp(Size + StartIndex, 0);
	for (int i = 0; i < temp.Size; i++)
		temp.pVector[i] = val;

	for (int i = StartIndex; i < temp.Size; i++)
	{
		temp.pVector[i] += pVector[i - StartIndex];
	}
	return temp;

} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	return (this->operator+(-val));
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector <ValType>Temp(*this);
	for (int i = 0; i < Temp.Size; i++)
		Temp.pVector[i] *= val;
	return Temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (Size+StartIndex == v.Size +v.StartIndex)
	{ 
		//TVector <ValType>Temp((StartIndex <= v.StartIndex) ? *this : v);
		if (StartIndex <= v.StartIndex)
		{
			TVector<ValType> Temp(Size, StartIndex);
			for (int i = 0; i < v.StartIndex - StartIndex; i++)
				Temp.pVector[i] = pVector[i];
			for (int i = v.StartIndex - StartIndex; i < Size; i++)
				Temp.pVector[i] = pVector[i] + v.pVector[i - v.StartIndex + StartIndex];
			return Temp;
		}
		else
		{
			TVector<ValType> Temp(Size, v.StartIndex);
			for (int i = 0; i < StartIndex - v.StartIndex; i++)
				Temp.pVector[i] = v.pVector[i];
			for (int i = StartIndex - v.StartIndex; i < v.Size; i++)
				Temp.pVector[i] = pVector[i - StartIndex + v.StartIndex] + v.pVector[i];
			return Temp;
		}
	}
	else throw("add_vectors_of_different_size");
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (Size + StartIndex != v.Size+ v.StartIndex)
		throw("subtract_vectors_of_different_size");
	if (StartIndex < v.StartIndex)
	{
		TVector <ValType> Temp(*this);
		for (int i = v.Size - 1; i >= 0; i--)
			Temp.pVector[i + v.StartIndex - StartIndex] = Temp.pVector[i + v.StartIndex - StartIndex] - v.pVector[i];
		return Temp;
	}
	else
	{
		TVector <ValType> Temp(v);
		for (int i = Size - 1; i >= 0; i--)
			Temp.pVector[i + StartIndex - v.StartIndex] = pVector[i] - Temp.pVector[i + StartIndex - v.StartIndex];
		for (int i = 0; i < v.Size - Size; i++)
			Temp.pVector[i] = Temp.pVector[i] - Temp.pVector[i] - Temp.pVector[i];
		return Temp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	int S = 0;
	if (Size + StartIndex == v.Size + v.StartIndex)
	{
		for (int i = 0; i < Size; i++)
			S += pVector[i] * v.pVector[i];
		return S;
	}
	else throw("mult_vectors_of_different_size");
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
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if (s > MAX_MATRIX_SIZE)
		throw "create_too_large_matrix";
	Size = s;
	StartIndex = 0;
	for (int i = 0, j = s; i < Size; i++, j--)
	{
		TVector <ValType> temp(j, i);
		pVector[i] = temp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) :
	TVector<TVector<ValType> >(mt)
{
	Size = mt.GetSize();
	StartIndex = 0;
}/*-------------------------------------------------------------------------*/

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt) :
	TVector<TVector<ValType> >(mt)
{
	Size = mt.GetSize();
	StartIndex = 0;
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector <TVector<ValType>>::operator ==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return !(mt == (*this));
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	TVector <TVector<ValType>>::operator =(mt);
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return TVector <TVector<ValType>>::operator +(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return TVector <TVector<ValType>>::operator -(mt);
}
// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
