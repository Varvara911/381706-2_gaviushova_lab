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
  int size;       // размер вектора
  int startIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v);                // конструктор копирования
  ~TVector();
  int GetSize()      { return size;       } // размер вектора
  int GetStartIndex(){ return startIndex; } // индекс первого элемента
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
    for (int i = 0; i < v.size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
  if (s < 0 || s > MAX_VECTOR_SIZE)
    throw "error";

  if (si < 0)
    throw "error";
	

  this->size = s;
  this->startIndex = si;

  this->pVector = new ValType[s];

  for (int i = 0; i < this->size; i++)
	  this->pVector[i] = (ValType)0;

} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	this->size = v.size;
	this->startIndex = v.startIndex;

	this->pVector = new ValType[size];
	for (int i = 0; i < this->size; i++)
	{
		this->pVector[i] = v.pVector[i];
	}
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] this->pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ - по индексу элемента достать значение (индексация другая)
ValType& TVector<ValType>::operator[](int pos)
{
  if (pos < this->startIndex || pos >= this->startIndex + size)
    throw "net";

  return pVector[pos - this->startIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
  if (this->size != v.size)
    return false;
  if (this->startIndex != v.startIndex)
    return false;
  for (int i = 0; i < this->size; i++)
  {
    if (this->pVector[i] != v.pVector[i])
      return false;
  }
  return true;

} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
  return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
  if (this->size != v.size)
  {
    delete[] this->pVector;
	this->pVector = new ValType[v.size];
	this->size = v.size;
  }

  this->startIndex = v.startIndex;
	
  for (int i = 0; i < size; i++)
  {
	  this->pVector[i] = v.pVector[i];
  }

	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
  TVector<ValType> tmp(*this);
  for (int i = 0; i < this->size; i++)
  {
    tmp.pVector[i] = tmp.pVector[i] + val;
  }

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
  TVector<ValType> tmp(*this);
  return tmp + (-val);

} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
  TVector<ValType> tmp(*this);  
  for (int i = 0; i < this->size; i++)
  {
    tmp.pVector[i] = tmp.pVector[i] * val;  
  }

  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
  if (this->size != v.size)
    throw "net";

  TVector<ValType> tmp(*this);
  for (int i = 0; i < this->size; i++)
  {
    tmp.pVector[i] = tmp.pVector[i] + v.pVector[i];
  }

	return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
  if (this->size != v.size)
    throw "net";

  TVector<ValType> tmp(*this);
  for (int i = 0; i < this->size; i++)
  {
    tmp.pVector[i] = tmp.pVector[i] - v.pVector[i];
  }

  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
  if (this->size != v.size)
    throw "net";

  ValType sum = (ValType)0;
  for (int i = 0; i < this->size; i++)
  {
    sum += this->pVector[i] * v.pVector[i];

  }

  return sum;
} 


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
    for (int i = 0; i < mt.size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
  if ( s > MAX_MATRIX_SIZE)
    throw "error";

  for (int i = 0; i < s; i++)
  {
    TVector<ValType> tmp(s-i,i);
	this->pVector[i] = tmp;
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
  if (this->size != mt.size)
  return false;

  for (int i = 0; i < this->size; i++)
    if (this->pVector[i] != mt.pVector[i])
      return false;
	
    return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
  return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
  if (this->size != mt.size)
  {
	  this->size = mt.size;
    delete[] this->pVector;
	this->pVector = new TVector<ValType>[mt.size];
  }

  for (int i = 0; i < this->size; i++)
	  this->pVector[i] = mt.pVector[i];

  return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
  TMatrix<ValType> tmp(*this);

  for (int i = 0; i < this->size; i++)
    tmp.pVector[i] = this->pVector[i] + mt.pVector[i];

  return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
  TMatrix<ValType> tmp(*this);

  for (int i = 0; i < this->size; i++)
    tmp.pVector[i] = this->pVector[i] - mt.pVector[i];

  return tmp;
} /*-------------------------------------------------------------------------*/

#endif
