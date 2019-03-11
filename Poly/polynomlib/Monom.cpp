#include <iostream>
#include "Monom.h"

using namespace std;

TMonom::TMonom()
{
	next = NULL;
	power = NULL;
	k = 0;
	n = 0;
}

TMonom::TMonom(int _n, int* _power, double _k)
{
	if (_n < 0)
		throw "error: negative size";
	else if (_n == 0)
	{
		power = NULL;
		n = _n;
		k = _k;
		next = NULL;
	}
	else
	{
		n = _n;
		k = _k;
		next = NULL;
		power = new int[_n];
		for (int i = 0; i < _n; i++)
		{
			if (_power[i] >= 0)
				power[i] = _power[i];
			else
				throw "error: negative power";
		}
	}
}

TMonom::TMonom(const TMonom &A)
{
	n = A.n;
	k = A.k;
	next = A.next;
	power = new int[n];
	for (int i = 0; i < n; i++)
	{
		power[i] = A.power[i];
	}
}

TMonom::~TMonom()
{
	if (power != 0)
		delete[]power;
	n = 0;
	k = 0;
	next = 0;
}

TMonom* TMonom::GetNext()
{
	return next;
}

int* TMonom::GetPower()
{
	return power;
}

double TMonom::GetK()
{
	return k;
}

int TMonom::GetN()
{
	return n;
}

void TMonom::SetNext(TMonom* _next)
{
	next = _next;
}

void TMonom::SetPower(int* _power)
{
	for (int i = 0; i < n; i++)
	{
		if (_power[i] >= 0)
			power[i] = _power[i];
		else
			throw "error: negative power";
	}
}

void TMonom::SetK(double _k)
{
	k = _k;
}

void TMonom::SetN(int _n)
{
	if (_n < 0)
		throw "error: negative size";
	else if (_n == 0)
	{
		if (power != 0)
			delete[] power;
		power = 0;
		n = 0;
	}
	else
	{
		int *tmp = new int[n];
		for (int i = 0; i < n; i++)
			tmp[i] = power[i];
		delete[]power;
		power = new int[_n];
		int i = 0;
		if (n < _n)
		{
			for (; i < n; i++)
				power[i] = tmp[i];
			for (; i < _n; i++)
				power[i] = 0;
		}
		if (_n < n)
			for (; i < _n; i++)
				power[i] = tmp[i];
		n = _n;
	}
}

TMonom& TMonom::operator=(const TMonom& A)
{
	if (n != A.n)
		throw "error: wrong size";
	k = A.k;
	n = A.n;
	next = A.next;
	delete[] power;
	power = new int[n];
	for (int i = 0; i < n; i++)
		power[i] = A.power[i];
	return *this;
}

TMonom TMonom::operator+(TMonom& A)
{
	TMonom tmp(A);
	if (n != A.n)
		throw "error: wrong n";
	if (!(*this == A))
		throw "error: wrong power";
	tmp.k = k + A.k;
	return tmp;
}

TMonom TMonom::operator+=(TMonom & A)
{
	if (n != A.n)
		throw "error: wrong n";
	if (!(*this == A))
		throw "error: wrong power";
	k += A.k;
	return *this;
}

TMonom TMonom::operator-(TMonom& A)
{
	TMonom tmp(A);
	if (n != A.n)
		throw "error: wrong n";
	if (!(*this == A))
		throw "error: wrong power";
	tmp.k = k - A.k;
	return tmp;
}

TMonom TMonom::operator-=(TMonom & A)
{
	if (n != A.n)
		throw "error: wrong n";
	if (!(*this == A))
		throw "error: wrong power";
	k -= A.k;
	return *this;
}

TMonom TMonom::operator*(const TMonom& A) const
{
	if (n != A.n)
		throw "error: wrong n";
	TMonom tmp(A);
	tmp.k = k * A.k;
	for (int i = 0; i < n; i++)
		tmp.power[i] = power[i] + A.power[i];
	return tmp;
}

TMonom TMonom::operator*=(TMonom& A)
{
	if (n != A.n)
		throw "error: wrong n";
	k = k * A.k;
	for (int i = 0; i < n; i++)
		power[i] += A.power[i];
	return *this;
}

bool TMonom::operator==(TMonom& A)
{
	if (n != A.n)
		throw "error: wrong size";
	for (int i = 0; i < n; i++)
		if (power[i] != A.power[i])
			return false;
	return true;
}

bool TMonom::operator<(TMonom& A)
{
	if (n != A.n)
		throw "error: wrong n";
	if (*this == A)
		throw "error: monoms are equal";
	for (int i = 0; i < n; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] < A.power[i])
			return true;
		else
			return false;
	}
	if (k > A.k)
		return false;
	return true;
}

bool TMonom::operator>(TMonom& A)
{
	if (n != A.n)
		throw "error: wrong n";
	if (*this == A)
		throw "error: monoms are equal";
	for (int i = 0; i < n; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] > A.power[i])
			return true;
		else
			return false;
	}
	return true;
}

istream& operator>>(istream& istr, TMonom& A)
{
	istr >> A.k;
	for (int i = 0; i < A.n; i++)
		istr >> A.power[i];
	return istr;
}

ostream& operator<<(ostream& ostr, TMonom& A)
{
	ostr << A.k;
	if (A.k != 0)
	{
		for (int i = 0; i < A.n; i++)
			if (A.power[i] != 0)
			{
				ostr << "*x" << i;
				if (A.power[i] != 1)
					ostr << "^" << A.power[i];
			}
	}
	return ostr;
}