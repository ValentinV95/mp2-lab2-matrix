// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
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
	ValType * pVector;
	int Size;       // размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);                // конструктор копирования
	~TVector();
	int GetSize() { return Size; } // размер вектора
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

											  // ввод - вывод
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
	if (s + si > MAX_VECTOR_SIZE)
	{
		throw ("s > MAX_VECTOR_SIZE");
	}
	else {
		if (s > 0) {
			pVector = new ValType[s];
			if (si >= 0)
				StartIndex = si;
			else
				throw ("StartIndex<0 in a created vector");
			Size = s;
			/*for (int i = 0; i < s + si; i++)
			pVector[i] = 0;*/
		}
		else
			throw ("Size<=0 in a created vector");
	}

} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	pVector = new ValType[v.Size];
	Size = v.Size;
	StartIndex = v.StartIndex;
	for (int i = 0; i <Size; i++)
		pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[]pVector;
	pVector = NULL;
	Size = 0;
	StartIndex = 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos < 0 || pos >= Size+StartIndex) {
		throw("pos <0 or pos>=(StartIndex+Size) in operator[]");
	}
	return pVector[pos-StartIndex];

} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	//bool res = true;//равны
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		return false;
	else {
		for (int i = 0; i < Size; i++)
			if (pVector[i] != v.pVector[i])
				return false;
	}
	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return (!(*this == v));//0-равны, 1-не равны//?????????????????????????????????
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (*this != v) {
		delete[]pVector;
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVector = new ValType[Size];
		if (v.pVector != 0) {
			for (int i = 0; i <Size; i++)
				pVector[i] = v.pVector[i];

		}
		else throw ("v.pVector =NULL in assignment");
	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector<ValType> temp(Size + StartIndex, 0);
	for (int i = 0; i < StartIndex + Size; i++)
		temp.pVector[i] = val;
	for (int i = StartIndex; i < StartIndex + Size; i++)
		temp.pVector[i] = val + pVector[i];
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	ValType a = -val;
	return ((*this) + a);
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> temp(Size);
	for (int i = 0; i <Size; i++)
		temp.pVector[i] = pVector[i] * val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("Cant add vectors with different Size+StartIndex");
	}
	int s, si;
	if (Size > v.Size) {
		TVector<ValType> sum(Size, StartIndex);
		for (int i = 0; i < v.StartIndex - StartIndex; i++)
			sum.pVector[i] = pVector[i];
		for (int i = v.StartIndex - StartIndex; i < Size; i++)
			sum.pVector[i] = pVector[i] + v.pVector[i];
		return sum;
	}
	else {
		/*s = v.Size;
		si = v.StartIndex;*/
		TVector<ValType> sum(v.Size, v.StartIndex);
		for (int i = 0; i < StartIndex - v.StartIndex; i++)
			sum.pVector[i] = v.pVector[i];
		for (int i = StartIndex - v.StartIndex; i < v.Size; i++)
			sum.pVector[i] = pVector[i] + v.pVector[i];
		return sum;
	}

}
/*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	{
		if (Size + StartIndex == v.Size + v.StartIndex)
		{
			if (StartIndex < v.StartIndex)
			{
				TVector<ValType> sub(Size,StartIndex);
				sub = *this;
				for (int i = v.Size - 1; i >= 0; i--)
					sub.pVector[i + v.StartIndex - StartIndex] =sub.pVector[i + v.StartIndex - StartIndex] - v.pVector[i];
				return sub;
			}
			else
			{
				TVector<ValType> sub(v.Size,v.StartIndex);
				sub = v;
				for (int i = Size - 1; i >= 0; i--)
					sub.pVector[i + StartIndex - v.StartIndex] = pVector[i] - sub.pVector[i + StartIndex - v.StartIndex];
				for (int i = 0; i < v.Size - Size; i++)
					sub.pVector[i] = sub.pVector[i] - sub.pVector[i] -sub.pVector[i];
				return sub;
			}
		}
		else throw ("Non equal vectors");
	} /*-------------------------------------------------------------------------*/




} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("Cant multiply vectors with different Size+StartIndex");
	}
	ValType mul = 0;
	if (Size > v.Size) {
		for (int i = v.StartIndex - StartIndex; i < Size; i++)
			mul += pVector[i] * v.pVector[i];
	}
	else {
		for (int i = StartIndex - v.StartIndex; i < v.Size; i++)
			mul += pVector[i] * v.pVector[i];
	}
	return mul;
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
	{
		throw ("s > MAX_MATRIX_SIZE");
	}
	for (int i = 0; i < s; i++) {
		TVector<ValType>temp(s - i, i);
		pVector[i] = temp;
	}

} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return  TVector<TVector<ValType> >::operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return  TVector<TVector<ValType> >::operator!=(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (*this != mt) {
		delete[]pVector;
		Size = mt.Size;
		StartIndex = mt.StartIndex;
		pVector = new TVector<ValType>[StartIndex + Size];
		if (mt.pVector != NULL) {
			for (int i = 0; i < Size; i++)
				pVector[i] = mt.pVector[i];
		}
		else
			throw("mt.pVector=NULL in assigment");

	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return  TVector<TVector<ValType> >::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return  TVector<TVector<ValType> >::operator-(mt);
} /*-------------------------------------------------------------------------*/

  // TVector О3 Л2 П4 С6
  // TMatrix О2 Л2 П3 С3
#endif