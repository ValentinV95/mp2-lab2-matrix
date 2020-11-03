
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
TVector<ValType>::TVector(int s = 0, int si = 0)
{
	if ((s > MAX_VECTOR_SIZE) || (s < 0) || (si < 0))
	{
		throw ("s > MAX_VECTOR_SIZE, or s < 0, or si < 0");
	}
	else
	{
		this->Size = s;
		this->StartIndex = si;
		this->pVector = new ValType [this->Size];

		for (int i = 0; i < Size; i++)
		{
			this->pVector[i] = 0;
		}
	}
} 

template <class ValType> 
TVector<ValType>::TVector(const TVector<ValType>& v)
{
		this->Size = v.Size;
		this->StartIndex = v.StartIndex;

		this->pVector = new ValType[this->Size];

		for (int i = 0; i < Size; i++)
		{
			this->pVector[i] = v.pVector[i];
		}	
} 

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
	this->Size = 0;
	this->StartIndex = 0;
} 

template <class ValType> 
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos < 0) || (pos >= this->Size + this->StartIndex))
	{
		throw ("(pos < 0) || (pos >= Size + StartIndex)");
	}

	return this->pVector[pos - this->StartIndex];
} 

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector& v) const
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
} 

template <class ValType> 
bool TVector<ValType>::operator!=(const TVector& v) const
{
	return !((*this) == v);
} 

template <class ValType> 
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (this->Size != v.Size)
	{
		this->Size = v.Size;
		this->StartIndex = v.StartIndex;

		delete[] this->pVector;
		this->pVector = new ValType[this->Size];

		for (int i = 0; i < this->Size; i++)
		{
			this->pVector[i] = v.pVector[i];
		}
	}
	else
	{
		this->StartIndex = v.StartIndex;

		for (int i = 0; i < this->Size; i++)
		{
			this->pVector[i] = v.pVector[i];
		}
	}
	
	return *this;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] + val;
	}

	return tmp;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] - val;
	}

	return tmp;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] * val;
	}

	return tmp;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
	if (this->Size != v.Size)
	{
		throw ("this->Size != v.Size");
		return 0;
	}
	
	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] + v.pVector[i];
	}

	return tmp;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	if (this->Size != v.Size)
	{
		throw ("this->Size != v.Size");
		return 0;
	}

	TVector<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] - v.pVector[i];
	}

	return tmp;
} 

template <class ValType> 
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if (this->Size != v.Size)
	{
		throw ("this->Size != v.Size");
		return 0;
	}

	ValType res = 0;

	for (int i = 0; i < this->Size; i++)
	{
		res += this->pVector[i] * v.pVector[i];
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

	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			in >> mt.pVector[i];
		}

		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			 out << mt.pVector[i] << endl;
		}
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if ((s > MAX_MATRIX_SIZE) || (s <= 0))
	{
		throw ("(s > MAX_MATRIX_SIZE) || (s <= 0)");
	}

	this->Size = s;

	for (int i = 0; i < Size; i++)
	{
		this->pVector[i] = TVector <ValType>(this->Size - i, i);
	}
}

template <class ValType> 
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) : TVector<TVector<ValType> >(mt)
{
	this->Size = mt.Size;

	for (int i = 0; i < this->Size; i++)
	{
		this->pVector[i] = mt.pVector[i];
	}

}

/*
template <class ValType> 
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{

}
*/

template <class ValType> 
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
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
} 

template <class ValType> 
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return !((*this) == mt);
} 

template <class ValType> 
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
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
}

template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	if(this->Size != mt.Size)
	{
		throw ("this->Size != v.Size");
		return 0;
	}

	TMatrix<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] + mt.pVector[i];
	}

	return tmp;
} 

template <class ValType> 
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	if (this->Size != mt.Size)
	{
		throw ("this->Size != v.Size");
		return 0;
	}

	TMatrix<ValType> tmp;
	tmp = *this;

	for (int i = 0; i < this->Size; i++)
	{
		tmp[i] = tmp[i] - mt.pVector[i];
	}

	return tmp;
} 

#endif
