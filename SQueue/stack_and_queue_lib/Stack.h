#pragma once
template<class T>
class TStack
{
	int l;
	T* m;
	int t;
	int count;
public:
	TStack(int n=0);
	TStack(Stack<T> &A);
	void Put(T &A);
	T Get();

	bool IsFull();
	bool IsEmpty();

	~Stack();
};

template<class T>
TStack::TStack(int n = 0)
{
	if (n == 0)
	{
		l = 0;
		m = 0;
		count = 0;
		t = 0;
	}
	else if (n < 0)
		throw 1;
	else
	{
		l = n;
		m = new T[l];
		for (int i = 0; i < l; i++)
			m[i] = 0;
		count = 0;
		t = 0;
	}
}

template<class T>
TStack::TStack(Stack<T> &A)
{
	if (A.l!=0)
	{
		l = A.l;
		m = new T[l];

		for (int i = 0; i < l; i++)
		{
			m[i] = A.m[i];
		}
	}
	else if (A.l==0)
	{
		count = A.count;
		t = A.t;
	}
}

template<class T>
void TStack::Put(T &A)
{
	if (IsFull())
		throw 1;
	m[t] = A;
	count++;
	t++;
}

template<class T>
T TStack::Get()
{
	if (!IsEmpty())
	{
		throw 1;
	}
	t--;
	count--;
	return m[t + 1];
}

template<class T>
bool TStack::IsFull()
{
	return count == l;
}

template<class T>
bool TStsck<T>::IsEmpty()
{
	return count == 0;
}

template<class T>
TStack::~Stack()
{
	delete[]m;
}