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
	if ((s < 0) || (si < 0) || (s > MAX_VECTOR_SIZE))
		throw "Incorrect Size or StartIndex";
	else 
	{
		this->Size = s;
		this-> = si;
		this-> = new ValType[s];

		for (int i = 0; i < Size; i++)
		{
			this->pVector[i] = 0;
		}
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	this->Size = v.Size;
	this-> = v.StartIndex;
	this->pVector = new ValType[this->Size];
	for (int i = 0; i < Size; i++)
	{
		this->pVector[i] = v.pVector[i];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
        delete[]pVector;
		this->Size = 0;
		this-> = 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos < 0) || (pos >= this->Size + this->StartIndex))
	{
		throw ("index incorrect");
	}
	else
	{
		return this->pVector[pos - this->StartIndex];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if ((this->Size == v.Size))
	{
		for (int i = 0; i < Size; i++)
		{
			if (this->pVector[i] != v.pVector[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return !((*this) == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (this != &v)
	{
		if (this->Size != v.Size)
		{
			this->Size = v.Size;
			this->StartIndex = v.StartIndex;

			delete[] this->pVector;
			this->pVector = new ValType[v.Size];

			for (int i = 0; i < this->Size; i++)
			{
				this->pVector[i] = v.pVector[i];
			}
		}
		else
		{
			StartIndex = v.StartIndex;
			for (int i = 0; i < this->Size; i++)
			{
				this->pVector[i] = v.pVector[i];
			}
		}
	}

	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] + val;
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] - val;
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] * val;
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw ("Size not equal");
	}

	if (StartIndex < v.StartIndex)
	{
		TVector<ValType> tmp = *this;
		for (int i = 0; i < v.Size; i++)
		{
			tmp.pVector[i + v.StartIndex - StartIndex] = tmp.pVector[i + v.StartIndex - StartIndex] + v.pVector[i];
		}
		return tmp;
	}
	else
	{
		TVector<ValType> tmp = v;
		for (int i = 0; i < Size; i++)
		{
			tmp.pVector[i + StartIndex - v.StartIndex] = tmp.pVector[i + StartIndex - v.StartIndex] + pVector[i];
		}
		return tmp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw ("Size not equal");
	}

	if (StartIndex < v.StartIndex)
	{
		TVector<ValType> tmp = *this;
		for (int i = 0; i < v.Size; i++)
		{
			tmp.pVector[i + v.StartIndex - StartIndex] = tmp.pVector[i + v.StartIndex - StartIndex] - v.pVector[i];
		}
		return tmp;
	}

	if (StartIndex > v.StartIndex)
	{
		TVector<ValType> tmp(v);
		for (int i = 0; i < Size; i++)
		{
			tmp.pVector[i + StartIndex - v.StartIndex] = pVector[i] - tmp.pVector[i + StartIndex - v.StartIndex];
		}
		for (int i = 0; i < StartIndex - v.StartIndex; i++)
		{
			tmp.pVector[i] = tmp.pVector[i] - tmp.pVector[i] - tmp.pVector[i];
		}
		return tmp;
	}

	if (Size == v.Size)
	{
		TVector<ValType> tmp(Size, StartIndex);
		for (int i = 0; i < Size; i++)
		{
			tmp.pVector[i] = pVector[i] - v.pVector[i];
		}
		return tmp;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if (Size + StartIndex != v.Size + v.StartIndex)
	{
		throw "Size not equal";
	}

	ValType tmp = 0;

	if (StartIndex < v.StartIndex)
	{
		for (int i = 0; i < v.Size; i++)
		{
			tmp = tmp + pVector[v.StartIndex - StartIndex + i] * v.pVector[i];
		}
	}
	else
	{
		for (int i = 0; i < Size; i++)
		{
			tmp = tmp + pVector[i] * v.pVector[StartIndex - v.StartIndex + i];
		}
	}
	return tmp;
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
	if ((s < 0) || (s > MAX_MATRIX_SIZE))
	{
		throw ("incorrect size");
	}

	this->Size = s;
	for (int i = 0; i < s; i++)
	{
		this->pVector[i] = TVector <ValType>(this->Size - i, i);
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):TVector<TVector<ValType> >(mt) 
{
	this->Size = mt.Size;
	for (int i = 0; i < this->Size; i++)
	{
		this->pVector[i] = mt.pVector[i];
	}
}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt): TVector<TVector<ValType> >(mt)
{

}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	if (this->Size == mt.Size)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			if (this->pVector[i] != mt.pVector[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return !((*this) == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (this->Size != mt.Size)
	{
		this->Size = mt.Size;
		delete[] this->pVector;
		this->pVector = new TVector<ValType>[this->Size];

		for (int i = 0; i < this->Size; i++)
		{
			this->pVector[i] = mt.pVector[i];
		}
	}
	else
	{
		for (int i = 0; i < this->Size; i++)
		{
			this->pVector[i] = mt.pVector[i];
		}
	}

	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (this->Size != mt.Size)
	{
		throw ("Sizes not equal");
		return 0;
	}

	TMatrix<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] + mt.pVector[i];
	}
	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	if (this->Size != mt.Size)
	{
		throw ("Size not equal");
		return 0;
	}

	TMatrix<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] - mt.pVector[i];
	}

	return tmp;
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
