#ifndef __POLYNOM_H__

#define __POLYNOM_H__

#include <iostream>
#include "Monom.h"

class TPolynom
{
protected:
  TMonom *first;  // указатель на начало
  int n;          // кол-во переменных в мономе
  int size;       // кол-во мономов 
public:
  TPolynom(int _n = 3);
  TPolynom(TPolynom &p);
  ~TPolynom();
  int GetSize();
  TMonom* GetFirst();
  TPolynom operator-(TPolynom &p);
  TPolynom operator+(TPolynom &p);
  TPolynom& operator=(const TPolynom &p);
  bool operator==(const TPolynom &p);
  TPolynom operator*(TPolynom &p);
  TPolynom& operator+=(TMonom &M);
  TPolynom& operator-=(TMonom &M);
  friend std::ostream& operator<<(std::ostream& _s, TPolynom& Tm);
};

#endif