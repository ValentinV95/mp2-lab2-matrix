// ÍÍÃÓ, ÂÌÊ, Êóðñ "Ìåòîäû ïðîãðàììèðîâàíèÿ-2", Ñ++, ÎÎÏ
//
// utmatrix.h - Copyright (c) Ãåðãåëü Â.Ï. 07.05.2001
//   Ïåðåðàáîòàíî äëÿ Microsoft Visual Studio 2008 Ñûñîåâûì À.Â. (21.04.2015)
//
// Âåðõíåòðåóãîëüíàÿ ìàòðèöà - ðåàëèçàöèÿ íà îñíîâå øàáëîíà âåêòîðà

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Øàáëîí âåêòîðà
template <class ValType>
class TVector
{
protected:
	ValType * pVector;
	int Size;       // ðàçìåð âåêòîðà
	int StartIndex; // èíäåêñ ïåðâîãî ýëåìåíòà âåêòîðà
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);                // êîíñòðóêòîð êîïèðîâàíèÿ
	~TVector();
	int GetSize() { return Size; } // ðàçìåð âåêòîðà
	int GetStartIndex() { return StartIndex; } // èíäåêñ ïåðâîãî ýëåìåíòà
	ValType& operator[](int pos);             // äîñòóï
	bool operator==(const TVector &v) const;  // ñðàâíåíèå
	bool operator!=(const TVector &v) const;  // ñðàâíåíèå
	TVector& operator=(const TVector &v);     // ïðèñâàèâàíèå

											  // ñêàëÿðíûå îïåðàöèè
	TVector  operator+(const ValType &val);   // ïðèáàâèòü ñêàëÿð
	TVector  operator-(const ValType &val);   // âû÷åñòü ñêàëÿð
	TVector  operator*(const ValType &val);   // óìíîæèòü íà ñêàëÿð

											  // âåêòîðíûå îïåðàöèè
	TVector  operator+(const TVector &v);     // ñëîæåíèå
	TVector  operator-(const TVector &v);     // âû÷èòàíèå
	ValType  operator*(const TVector &v);     // ñêàëÿðíîå ïðîèçâåäåíèå

											  // ââîä-âûâîä
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

struct incorrect_value {
	string s;
	incorrect_value(int id) {
		if (id == 1) s = "Cannot create vector/matrix with negative length";
		else if (id == 2) s = "Cannot create vector/matrix with that large size";
		else if (id == 3) s = "Incorrect index of element";
		else if (id == 4) s = "Cannot add/subtract vectors with not equal size";
		else if (id == 5) s = "Cannot create vector with negative startindex";
	}
};


template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s <= 0) throw (incorrect_value(1));
	else if (s > MAX_VECTOR_SIZE) throw (incorrect_value(2));
	else if (si < 0) throw (incorrect_value(5));

	Size = s;
	pVector = new ValType[s];
	StartIndex = si;

} /*-------------------------------------------------------------------------*/

template <class ValType> //êîíñòðóêòîð êîïèðîâàíèÿ
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];

	for (int i = 0; i < Size; i++) {
		pVector[i] = v.pVector[i];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
	pVector = NULL;
} /*-------------------------------------------------------------------------*/

template <class ValType> // äîñòóï
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos < 0) throw (incorrect_value(3));
	else if (pos >= Size + StartIndex) throw (incorrect_value(3));
	else if (pos < GetStartIndex()) throw (incorrect_value(3));

	return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // ñðàâíåíèå
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (this == &v) return true;
	else if (Size != v.Size) return false;
	else if (StartIndex != v.StartIndex) return false;

	for (int i = 0; i < Size; i++) {

		if (pVector[i] != v.pVector[i]) return false;

	}

	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ñðàâíåíèå
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return !((*this) == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ïðèñâàèâàíèå
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (this != &v) {

		delete[] pVector;
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVector = new ValType[Size];

		for (int i = 0; i < Size; i++) {
			pVector[i] = v.pVector[i];
		}

	}
	return (*this);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ïðèáàâèòü ñêàëÿð
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector<ValType> res(Size + StartIndex);

	for (int i = 0; i < StartIndex; i++) {
		res.pVector[i] = val;
	}

	for (int i = StartIndex; i < Size + StartIndex; i++) {
		res.pVector[i] = (*this).pVector[i - StartIndex] + val;
	}

	return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // âû÷åñòü ñêàëÿð
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector<ValType> res = (*this);

	return res + val * (-1);
} /*-------------------------------------------------------------------------*/

template <class ValType> // óìíîæèòü íà ñêàëÿð
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> res = (*this);

	for (int i = 0; i < Size; i++) {
		res.pVector[i] = res.pVector[i] * val;
	}

	return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ñëîæåíèå
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex)) throw (incorrect_value(4));
	
	if (Size > v.Size) {

		TVector<ValType> res = (*this);

		for (int i = v.StartIndex; i < res.Size; i++) {
			res.pVector[i] += v.pVector[i - v.StartIndex];
		}

		return res;

	}
		
	TVector<ValType> res = v;

	for (int i = StartIndex; i < res.Size; i++) {
		res.pVector[i] += pVector[i - StartIndex];
	}

	return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // âû÷èòàíèå
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex)) throw (incorrect_value(4));
	
	if (Size > v.Size) {

		TVector<ValType> res = (*this);

		for (int i = v.StartIndex; i < res.Size; i++) {
			res.pVector[i] -= v.pVector[i - v.StartIndex];
		}

		return res;

	}

	for (int i = StartIndex; i < res.Size; i++) {
		res.pVector[i] -= pVector[i - StartIndex];
	}

	return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ñêàëÿðíîå ïðîèçâåäåíèå
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if ((Size + StartIndex) != (v.Size + v.StartIndex)) throw (incorrect_value(4));
	
	if (Size > v.Size) {

		TVector<ValType> res = v;

		for (int i = 0; i < res.Size; i++) {
			res.pVector[i] *= pVector[i + StartIndex];
		}

		return res;

	}

	TVector<ValType> res = (*this);

	for (int i = 0; i < res.Size; i++) {
		res.pVector[i] *= v.pVector[i + v.StartIndex];
	}

	return res;
} /*-------------------------------------------------------------------------*/


  // Âåðõíåòðåóãîëüíàÿ ìàòðèöà
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt);                    // êîïèðîâàíèå
	TMatrix(const TVector<TVector<ValType> > &mt); // ïðåîáðàçîâàíèå òèïà
	bool operator==(const TMatrix &mt) const;      // ñðàâíåíèå
	bool operator!=(const TMatrix &mt) const;      // ñðàâíåíèå
	TMatrix& operator= (const TMatrix &mt);        // ïðèñâàèâàíèå
	TMatrix  operator+ (const TMatrix &mt);        // ñëîæåíèå
	TMatrix  operator- (const TMatrix &mt);        // âû÷èòàíèå

												   // ââîä / âûâîä
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
	if (s > MAX_MATRIX_SIZE) throw (incorrect_value(2));
	else if (s < 0) throw (incorrect_value(1));

	for (int i = 0; i < s; i++) {
		TVector<ValType> s(s - i, i);
		(*this)[i] = s;
	}

} /*-------------------------------------------------------------------------*/

template <class ValType> // êîíñòðóêòîð êîïèðîâàíèÿ
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // êîíñòðóêòîð ïðåîáðàçîâàíèÿ òèïà
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // ñðàâíåíèå
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>>::operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ñðàâíåíèå
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return !(mt == (*this));
} /*-------------------------------------------------------------------------*/

template <class ValType> // ïðèñâàèâàíèå
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	TVector<TVector<ValType>>::operator=(mt);
	return (*this);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ñëîæåíèå
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // âû÷èòàíèå
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/

  // TVector Î3 Ë2 Ï4 Ñ6
  // TMatrix Î2 Ë2 Ï3 Ñ3
#endif