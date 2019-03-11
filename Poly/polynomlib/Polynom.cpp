#include <iostream>
#include "Polynom.h"

using namespace std;

TPolynom::TPolynom(int _n)
{
	if (_n <= 0)
		throw "error numbers of monom";
	n = _n;
	size = 0;
	first = 0;
}
TPolynom::TPolynom(TPolynom &A)	// копирование
{
	n = A.n;
	size = A.size;
	if (A.first == 0)
		first = 0;
	else
	{
		first = new TMonom(*A.first);
		TMonom* a = A.first;
		TMonom* b = first;
		while (a->GetNext() != 0)
		{
			b->SetNext(new TMonom(*(a->GetNext())));
			b = b->GetNext();
			a = a->GetNext();
		}
		b->SetNext(NULL);
	}
}

TPolynom::~TPolynom()
{}

int TPolynom::GetSize()
{
	return size;
}

TMonom* TPolynom::GetFirst()
{
	return first;
}

TPolynom TPolynom::operator+(TPolynom &A)
{
	if (this->n != A.n)
		throw "error: wrong size";
	TPolynom rez(n);
	TMonom *a = first, *b = A.first, *c = rez.first;
	while ((a != 0) && (b != 0))
	{
		TMonom *t;
		if ((*a) == (*b))
		{
			TMonom k = (*a);
			k += (*b);
			t = new TMonom(k);
			if (t->GetK() == 0)
				continue;
			a = a->GetNext();
			b = b->GetNext();
		}
		else if ((*a) < (*b))
		{
			t = new TMonom((*b));
			if (t->GetK() == 0)
				continue;
			b = b->GetNext();
		}
		else if ((*a) > (*b))
		{
			t = new TMonom((*a));
			if (t->GetK() == 0)
				continue;
			a = a->GetNext();
		}
		if (c == 0)
		{
			c = t;
			rez.first = t;
			rez.size++;
		}
		else
		{
			c->SetNext(t);
			rez.size++;
			c = c->GetNext();
		}
	}
	if (a == 0)
		a = b;
	while (a != 0)
	{
		if (a->GetK() == 0)
			continue;
		c->SetNext(new TMonom(*a));
		a = a->GetNext();
		rez.size++;
		c = c->GetNext();
	}
	return rez;
}

TPolynom TPolynom::operator-(TPolynom &A)
{
	if (this->n != A.n)
		throw "error: wrong size";
	TPolynom rez(n);
	TMonom *a = first, *b = A.first, *i = rez.first;
	while ((a != 0) && (b != 0))
	{
		TMonom *t;
		if ((*a) == (*b))
		{
			TMonom k = (*a);
			k -= (*b);
			t = new TMonom(k);
			a = a->GetNext();
			b = b->GetNext();
		}
		else if ((*a) < (*b))
		{
			t = new TMonom((*b));
			if (t->GetK() == 0)
				continue;
			t->SetK(t->GetK() * (-1));
			b = b->GetNext();
		}
		else if ((*a) > (*b))
		{
			t = new TMonom((*a));
			if (t->GetK() == 0)
				continue;
			a = a->GetNext();
		}
		if (t->GetK() == 0)
			continue;
		if (i == 0)
		{
			i = t;
			rez.first = t;
			rez.size++;
		}
		else
		{
			i->SetNext(t);
			rez.size++;
			i = i->GetNext();
		}
	}
	while (a != 0)
	{
		if (a->GetK() == 0)
			continue;
		i->SetNext(new TMonom(*a));
		a = a->GetNext();
		rez.size++;
		i = i->GetNext();
	}
	while (b != 0)
	{
		if (b->GetK() == 0)
			continue;
		TMonom t(*b);
		t.SetK(t.GetK() * (-1));
		i->SetNext(&t);
		b = b->GetNext();
		rez.size++;
		i = i->GetNext();
	}
	return rez;
}

TPolynom& TPolynom::operator=(const TPolynom &A)
{
	if (*this == A)
		return *this;
	if (this->n != A.n)
		throw "error: wrong size";
	else
	{
		size = A.size;
		TMonom *buf1 = first, *buf2 = first;
		while (buf1 != 0)
		{
			buf1 = buf1->GetNext();
			delete buf2;
			buf2 = buf1;
		}
		buf1 = A.first->GetNext();
		buf2 = new TMonom(*A.first);
		first = buf2;
		while (buf1 != 0)
		{
			buf2->SetNext(new TMonom(*buf1));
			buf2 = buf2->GetNext();
			buf1 = buf1->GetNext();
		}
		return *this;
	}
}

bool TPolynom::operator==(const TPolynom &A)
{
	if (this->n != A.n)
		throw "error: wrong size";
	if (this->size != A.size)
		return false;
	TMonom* a = first;
	TMonom* b = A.first;
	while (a != 0)
	{
		if (!(*a == *b))
			return false;
		if (a->GetK() != b->GetK())
			return false;
		a = a->GetNext();
		b = b->GetNext();
	}
	return true;
}

TPolynom TPolynom::operator*(TPolynom &A)
{
	if (this->n != A.n)
		throw "error: wrong size";
	TPolynom rez(n);
	TMonom *_st = first;
	TMonom *_pst = A.first;
	while (_st != 0)
	{
		if (_st->GetK() == 0)
			continue;
		while (_pst != 0)
		{
			if (_pst->GetK() == 0)
				continue;
			TMonom k = (*_st);
			k *= (*_pst);
			TMonom* f = new TMonom(k);
			f->SetNext(NULL);
			rez += *f;
			_pst = _pst->GetNext();
		}
		_st = _st->GetNext();
		_pst = A.first;
	}
	return rez;
}

TPolynom &TPolynom::operator+=(TMonom &M)
{
	if (this->n != M.GetN())
		throw "error: wrong size";
	if (M.GetK() == 0)
		return *this;
	if (first == 0)
		first = new TMonom(M);
	else
	{
		TMonom *_first, *_end;
		_first = first;
		_end = first->GetNext();
		if (*first < M)
		{
			TMonom* tmp = new TMonom(M);
			tmp->SetNext(first);
			first = tmp;
		}
		else if (*first == M)
		{
			*first += M;
			if (first->GetK() == 0)
			{
				TMonom* temp = first->GetNext();
				delete[] first;
				first = temp;
			}
		}
		else
		{
			while (_end != 0)
			{
				if (*_end == M)
				{
					*_end += M;
					if (_end->GetK() == 0)
					{
						first->SetNext(_end->GetNext());
						delete[] _end;
					}
					// size++;
					return *this;
				}
				if (*_end < M)
				{
					TMonom* tmp = new TMonom(M);
					_first->SetNext(tmp);
					tmp->SetNext(_end);
					size++;
					return *this;
				}
				_first = _end;
				_end = _end->GetNext();
			}
			_first->SetNext(new TMonom(M));
		}
	}
	size++;
	return *this;
}

TPolynom &TPolynom::operator-=(TMonom &M)
{
	if (this->n != M.GetN())
		throw "error: wrong size";
	if (M.GetK() == 0)
		return *this;
	M.SetK(M.GetK() * (-1));
	if (first == 0)
		first = new TMonom(M);
	else
	{
		TMonom *_first, *_end;
		_first = first;
		_end = first->GetNext();
		if (*first < M)
		{
			TMonom* tmp = new TMonom(M);
			tmp->SetNext(first);
			first = tmp;
		}
		else if (*first == M)
		{
			*first -= M;
			if (first->GetK() == 0)
			{
				TMonom* temp = first->GetNext();
				delete[] first;
				first = temp;
			}
		}
		else
		{
			while (_end != 0)
			{
				if (*_end == M)
				{
					*_end -= M;
					if (_end->GetK() == 0)
					{
						first->SetNext(_end->GetNext());
						delete[] _end;
					}
					size++;
					return *this;
				}
				if (*_end < M)
				{
					TMonom* tmp = new TMonom(M);
					_first->SetNext(tmp);
					tmp->SetNext(_end);
					size++;
					return *this;
				}
				_first = _end;
				_end = _end->GetNext();
			}
			_first->SetNext(new TMonom(M));
		}
	}
	size++;
	return *this;
}

ostream& operator<<(ostream& _s, TPolynom& M)
{
	TMonom *tmp = M.first;
	if (tmp != 0)
	{
		_s << *tmp;
		tmp = tmp->GetNext();
	}
	while (tmp != 0)
	{
		if (tmp->GetK() != 0)
			_s << " + " << *tmp;
		tmp = tmp->GetNext();
	}
	return _s;
}