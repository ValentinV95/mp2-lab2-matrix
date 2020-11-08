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
	if (si < 0)
	{
		throw ("start indeks less zero");
	}
	if ((s <= 0) || (s > MAX_VECTOR_SIZE))
	{
		throw("value size is incorrect");
	}
	this->Size = s;
	this->StartIndex = si;
	this->pVector = new ValType[s];
	for (int i = 0; i < Size; i++)
		pVector[i] = 0;
}

template <class ValType>  //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	this->Size = v.Size;
	this->StartIndex = v.StartIndex;
    pVector = new ValType[this->Size];
    for (int i = 0; i < Size; i++)
		this->pVector[i] = v.pVector[i];
	
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
}

template <class ValType>  //доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos >= StartIndex) && (pos < Size + StartIndex))
	{
		return pVector[pos - StartIndex];
	}
	else 
	{ 
		throw ("index incorrect"); 
	}
}

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector& v) const
{
	if (this->Size == v.Size)
	{
		bool f = false;
		for (int i = 0; i < Size; i++)
		{
			if (this->pVector[i] != v.pVector[i])
			{
				return f;
			}
		}
		f = true;
		return f;
	}
}

template <class ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
	return !(*this == v);
}

template <class ValType>  //присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	this->Size = Size;
	this->StartIndex = v.StartIndex;
	for (int i = 0; i < this->Size; i++)
	{
		this->pVector[i] = v.pVector[i];
	}
}

template <class ValType>  //прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	if (val == 0)
		return *this;
	TVector <ValType> dop;
	dop = *this;
	for (int i = 0; i < Size; i++)
		dop[i] = dop[i] + val;
	return dop;
}

template <class ValType> //вычестеть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
     if (val == 0)
		return *this;
	 TVector <ValType> dop;
	 dop = *this;
	 for (int i = 0; i < Size; i++)
		 dop[i] = dop[i] - val;
	 return dop;
}

template <class ValType>  //умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector <ValType> dop;
	dop = *this;
	for (int i = 0; i < Size; i++)
		dop[i] = dop[i] * val;
	return dop;
}

template <class ValType>  //сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
	if (Size != v.Size)
		throw ("different length of vectors");
	else
	{
		TVector<ValType> dop;
		dop = *this;
		for (int i = 0; i < Size; i++)
			dop = dop[i] + v.pVector[i];
		return *dop;
	}
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	if (Size != v.Size)
		throw ("different length of vectors");
	else
	{
		TVector<ValType> dop;
		dop = *this;
		for (int i = 0; i < Size; i++)
			dop = dop[i] - v.pVector[i];
		return *dop;
	}
}

template <class ValType>
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if (Size != v.Size)
		throw ("different length of vectors");
	ValType res = 0;
    for (int i = 0; i < this->Size; i++)
	{
		res = res + this->pVector[i] * v.pVector[i];
	}
	return res;
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
	Size = s;
	StartIndex = 0;
	for (int i = 0; i < s; i++)
		pVector[i] = TVector <ValType>(s - i, i);
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt)
{
	this->Size = mt.Size;
	for (int i = 0; i < Size; i++)
		pVector[i] = mt.pVector[i];

}

template <class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{

}

template <class ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	bool f = false;
	if (Size == mt.Size)
	{
		for (int i = 0; i < Size; i++)
			if (pVector[i] != mt.pVector[i])
				return f;
		f = true;
		return f;
	}
}

template <class ValType>
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return !((*this) == mt);
}

template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size)
	{
		Size = mt.Size;
		delete[] pVector;
		pVector =new TVector<ValType>[Size]
	    for (int i = 0; i < this->Size; i++)
		   pVector[i] = mt.pVector[i];
	}
	else
	{
		for (int i = 0; i < Size; i++)
			this->pVector[i] = mt.pVector[i];
	}
   return *this;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size)
	{
		throw ("different sizes!");
		return 0;
	}
	TMatrix<ValType> tmp;
	tmp = *this;
	for (int i = 0; i < Size; i++)
		tmp[i] = tmp[i] + mt.pVector[i];
	return tmp;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size)
	{
		throw ("different sizes!");
		return 0;
	}
    TMatrix<ValType> tmp;
	tmp = *this;
    for (int i = 0; i < Size; i++)
		tmp[i] = tmp[i] - mt.pVector[i];
	return tmp;
}

#endif
