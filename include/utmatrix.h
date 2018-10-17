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
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v);                // конструктор копирования
  ~TVector();
  int GetSize()     const { return Size;       } // размер вектора
  int GetStartIndex()const{ return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  TVector& operator=(const TVector &v);     // присваивание

  // скалярные операции
  TVector  operator+(const ValType &val) const;   // прибавить скаляр
  TVector  operator-(const ValType &val) const;   // вычесть скаляр
  TVector  operator*(const ValType &val) const;   // умножить на скаляр

  // векторные операции
  TVector  operator+(const TVector &v) const;     // сложение
  TVector  operator-(const TVector &v) const;     // вычитание
  ValType  operator*(const TVector &v) const;    // скалярное произведение

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
	if(s <= 0)
	{
		throw ("Negative_Size");
	}
	if(si < 0)
	{
		throw ("Negative_StartIndex");
	}
	if((s + si) > MAX_VECTOR_SIZE)
	{
		throw ("Too_large_Size");
	}
	Size = s;
	StartIndex = si;
	pVector = new ValType[s];
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	for(int i = 0; i < Size; i++)
	{
		pVector[i] = v.pVector[i] ;
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
	if(pos - StartIndex < 0 || pos >= Size + StartIndex)
	{
		throw("Incorrect index");
	}
	return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if(Size != v.Size)
	{
		return false;
	}
	for(int i = 0; i < Size; i++)
	{
		if(pVector[i] != v.pVector[i])
		{
			return false;
		}
	}
	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return (!(*this == v));
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if(this != &v)
	{
		if (Size == v.Size)
		{
			for(int i = 0; i < Size; i++)
			{
				pVector[i] = v.pVector[i] ;
			}
			StartIndex = v.StartIndex;
		}
		else
		{
			delete[] pVector;
			Size = v.Size;
			StartIndex = v.StartIndex;
			pVector = new ValType[Size];
			for(int i = 0; i < Size; i++)
			{
				pVector[i] = v.pVector[i];
			}
		}

	}
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)const
{
	if (!val)
	{
		TVector <ValType> p(*this);
		return p;
	}
	else
	{
		TVector <ValType> p(Size + StartIndex,0);
		for(int i = 0; i < p.Size; i++)
		{
			p.pVector[i] = val;
		}
		for(int i = StartIndex; i < p.Size; i++)
		{
			p.pVector[i] += pVector[i - StartIndex];
		}
		return p;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)const
{
	TVector <ValType> p(*this);
	return p + val*(-1);
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)const
{
	if (val == 0)
	{
		TVector <ValType> p(1,Size + StartIndex - 1);
		return p;
	}
	else
	{
		TVector <ValType> p(*this);
		for(int i = 0; i < p.Size; i++)
		{
			p.pVector[i] = p.pVector[i]*val;
		}
		return p;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)const
{
	if((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("cant_add_vectors_with_not_equal_size");
	}
	if(StartIndex < v.StartIndex)
	{
		TVector <ValType> p(*this);
		for(int i = v.Size - 1; i >=0; i--)
		{
			p.pVector[i + v.StartIndex - StartIndex] = p.pVector[i + v.StartIndex - StartIndex] + v.pVector[i];
		}
		return p;
	}
	else
	{
		TVector <ValType> p(v);
		for(int i = Size - 1; i >=0; i--)
		{
			p.pVector[i - v.StartIndex + StartIndex] = p.pVector[i - v.StartIndex + StartIndex] + pVector[i];
		}
		return p;
	}
	
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)const
{
	if((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("cant_subtract_vectors_with_not_equal_size");
	}
	if(StartIndex < v.StartIndex)
	{
		TVector <ValType> p(*this);
		for(int i = v.Size - 1; i >=0; i--)
		{
			p.pVector[i + v.StartIndex - StartIndex] = p.pVector[i + v.StartIndex - StartIndex] - v.pVector[i];
		}
		return p;
	}
	else
	{
		TVector <ValType> p(v);
		for(int i = Size - 1; i >=0; i--)
		{
			p.pVector[i - v.StartIndex + StartIndex] = pVector[i] - p.pVector[i - v.StartIndex + StartIndex] ;
		}
		for(int i = 0; i < StartIndex - v.StartIndex; i++)
		{
			p.pVector[i] = p.pVector[i] - p.pVector[i] - p.pVector[i];
		}
		return p;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)const
{
	if((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("cant_multiply_vectors_with_not_equal_size");
	}
	ValType ans = 0;
	if(StartIndex < v.StartIndex)
	{
		for(int i = v.Size - 1; i >=0; i--)
		{
			ans += pVector[i + v.StartIndex - StartIndex] * v.pVector[i];
		}
	}
	else
	{
		for(int i = Size - 1; i >=0; i--)
		{
			ans += v.pVector[i - v.StartIndex + StartIndex] * pVector[i];
		}
	}
	return ans;
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
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType>>(s)
{
	if(s > MAX_MATRIX_SIZE)
	{
		throw ("Too_Large_Matrix_Size");
	}
	Size = s;
	StartIndex = 0;
	for(int i = 0, k = s; i < s; i++, k--)
	{
		TVector<ValType> tmp(k,i);
		pVector[i] = tmp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) : TVector<TVector<ValType>>(mt) 
  {
	 Size = mt.GetSize();
	 StartIndex = 0;
  }

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt): TVector<TVector<ValType>>(mt)
{
	 StartIndex = 0;
	 Size = mt.GetSize();
}


template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>> :: operator== (mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return (!(*this == mt));
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	TVector<TVector<ValType>> :: operator= (mt);
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>> :: operator+ (mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>> :: operator- (mt);
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
