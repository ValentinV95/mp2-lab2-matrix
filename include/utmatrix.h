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
	ValType* pVector;
	int Size;												// размер вектора
	int StartIndex;											// индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector& v);
	~TVector();
	int GetSize() { return Size; }
	int GetStartIndex() { return StartIndex; }
	ValType& operator[](int pos);
	bool operator==(const TVector& v) const;
	bool operator!=(const TVector& v) const;
	TVector& operator=(const TVector& v);

	// скалярные операции
	TVector  operator+(const ValType& val);
	TVector  operator-(const ValType& val);
	TVector  operator*(const ValType& val);

	// векторные операции
	TVector  operator+(const TVector& v);
	TVector  operator-(const TVector& v);
	ValType  operator*(const TVector& v);

	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if ((s < 0) || (si < 0) || (s > MAX_VECTOR_SIZE) || (si > MAX_VECTOR_SIZE))
		throw "Not available Size or StartIndex";
	else
	{
		Size = s;
		pVector = new ValType[s];
		StartIndex = si;
	}
}

template <class ValType>  //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
	Size = 0;
	StartIndex = 0;
}

template <class ValType>  //доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos - StartIndex < 0) || (pos > MAX_VECTOR_SIZE) || (pos > StartIndex + Size))
		throw "Out of bounds of the vector";
	else
		return(pVector[pos - StartIndex]);
}

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector& v) const
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		return(false);
	else
		for (int i = 0; i < Size; i++)
			if (pVector[i] != v.pVector[i])
				return(false);
	return(true);
}

template <class ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
	return !(*this == v);
}

template <class ValType>  //присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (Size != v.Size)
	{
		delete[] pVector;
		Size = v.Size;
		pVector = new ValType[Size];
	}
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
	StartIndex = v.StartIndex;
	return *this;
}

template <class ValType>  //прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector<ValType> res(Size + StartIndex, 0);
	for (int i = 0; i < StartIndex; i++)
		res[i] = val;
	for (int i = StartIndex; i < res.Size; i++)
		res[i] = val + (*this)[i];
	return(res);
}

template <class ValType> //вычестеть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector<ValType> res(Size + StartIndex, 0);
	for (int i = 0; i < StartIndex; i++)
		res[i] = -val;
	for (int i = StartIndex; i < res.Size; i++)
		res[i] = (*this)[i] - val;
	return(res);
}

template <class ValType>  //умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	if (!val)
		throw "can't mult on 0";
	else
	{

		TVector<ValType> res(Size, StartIndex);
		for (int i = StartIndex; i < res.Size; i++)
			res[i] = val * (*this)[i];
		return(res);
	}
}

template <class ValType>  //сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
	//if (Size != v.Size)
	//	throw ("different length of vectors");
	if ((Size + StartIndex) != (v.Size + v.StartIndex)) 
	 throw ("different length of vectors"); 
	else
	{
		if (Size > v.Size)
		{
			TVector<ValType> res(*this);
			for (int i = 0; i < v.Size; i++)
				res.pVector[i + v.StartIndex - StartIndex] = res.pVector[i + v.StartIndex - StartIndex] + v.pVector[i];
			return(res);
		}
		else
		{
			TVector<ValType> res(v);
			for (int i = 0; i < Size; i++)
				res.pVector[i + StartIndex - v.StartIndex] = pVector[i] + v.pVector[i + StartIndex - v.StartIndex];
			return(res);
		}
	}
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	if (StartIndex + Size != v.Size + v.StartIndex)
		throw "Not equal size of vectors";
	else
	{
		if (Size >= v.Size)
		{
			TVector<ValType> res(*this);
			for (int i = 0; i < v.Size; i++)
				res.pVector[i + v.StartIndex - StartIndex] = res.pVector[i + v.StartIndex - StartIndex] - v.pVector[i];
			return(res);
		}
		else
		{
			TVector<ValType> res(v);
			for (int i = 0; i < StartIndex - v.StartIndex; i++)
				res.pVector[i] = v.pVector[i] * (-1);
			for (int i = 0; i < Size; i++)
				res.pVector[i + StartIndex - v.StartIndex] = pVector[i] - v.pVector[i + StartIndex - v.StartIndex];
			return(res);
		}
	}
}

template <class ValType>
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if (StartIndex + Size != v.Size + v.StartIndex)
		throw "Not equal size of vectors";
	else
	{
		ValType res = 0;
		if (StartIndex < v.StartIndex)
		{
			for (int i = 0; i < v.Size; i++)
				res += pVector[i + v.StartIndex - StartIndex] * v.pVector[i];
			return res;
		}
		else
		{
			for (int i = 0; i < Size; i++)
				res += pVector[i] * v.pVector[i + StartIndex - v.StartIndex];
			return res;
		}
	}
}

//Матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);
	TMatrix(const TVector<TVector<ValType> >& mt);
	bool operator==(const TMatrix& mt) const;
	bool operator!=(const TMatrix& mt) const;
	TMatrix& operator= (const TMatrix& mt);
	TMatrix  operator+ (const TMatrix& mt);
	TMatrix  operator- (const TMatrix& mt);

	// ввод / вывод
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		  in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if ((s < 0) || (s > MAX_MATRIX_SIZE))
		throw ("incorrect size");
	else
	{
		Size = s;
		StartIndex = 0;
		for (int i = 0, j = s; i < s; i++, j--)
		{
			TVector<ValType> v(j, i);
			pVector[i] = v;
		}
	}
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt)
{
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{
}

template <class ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
		return TVector<TVector<ValType>>::operator==(mt);
}

template <class ValType>
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return TVector<TVector<ValType>>::operator!=(mt);
}

template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	TVector<TVector<ValType>>::operator=(mt);
   return *this;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType>>::operator+(mt);
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType>>::operator-(mt);
}

#endif
