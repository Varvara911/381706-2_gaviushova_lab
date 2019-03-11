#pragma once
#include <iostream>
#include "queue.h"

using namespace std;

template <class T>
class TArrList
{
private:
	T* mas;                    // список
	int *nextIndex;            // указатель на следующий элемент
	int *lastIndex;            // указатель на предыдущий элемент
	int size;                  // размер (задаваемый)
	int count;                 // текущее число
	int start;                 // начало
	int end;                   // конец
	TQueue <int> freeElem;     // элемент очереди
public:
	TArrList(int _size = 17);  // конструктор
	TArrList(TArrList<T> &A);  // конструктор копирования
	~TArrList();               // деструктор
	void Push(int n, T elem);  // добавить в середину
	T Pop(int n);			   // взять из середины
	void PushStart(T elem);    // добавить в начало
	void PushEnd(T elem);      // добавить в конец
	T PopStart();              // взять из начала
	T PopEnd();                // взять с конца
	bool IsFull();			   // проверка на полноту
	bool IsEmpty();			   // проверка на пустоту
	void Print();              // печать 
};

template <class T>
TArrList<T>::TArrList(int _size) : freeElem(_size)
{
	if (_size <= 0)
		throw "Negative size";
	size = _size;
	count = 0;
	start = -1;
	end = -1;
	mas = new T[size];
	nextIndex = new int[size];
	lastIndex = new int[size];
	for (int i = 0; i < size; i++)
	{
		nextIndex[i] = -2;
		lastIndex[i] = -2;
		freeElem.Push(i);
	}
}

template <class T>
TArrList<T>::TArrList(TArrList<T> &A)
{
	start = A.start;
	end = A.end;
	size = A.size;
	count = A.count;
	mas = new T[size];
	nextIndex = new int[size];
	lastIndex = new int[size];
	freeElem = A.freeElem;
	for (int i = 0; i < size; i++)
	{
		mas[i] = A.mas[i];
		nextIndex[i] = A.nextIndex[i];
		lastIndex[i] = A.lastIndex[i];
	}
}

template<class T>
inline TArrList<T>::~TArrList()
{
	delete[] mas;
	delete[] nextIndex;
	delete[] lastIndex;
}

template<class T>
void TArrList<T>::Push(int n, T elem)
{
	if (IsFull())
		throw "List is full";
	if (n < 1 || n > count - 1)
		throw "Wrong indexex";
	int ifree = freeElem.Pop();
	mas[ifree] = elem;
	int one = start;
	int two = nextIndex[start];
	for (int i = 0; i < n - 1; i++)
	{
		one = two;
		two = nextIndex[two];
	}
	nextIndex[ifree] = two;
	nextIndex[one] = ifree;

	lastIndex[ifree] = one;
	lastIndex[two] = ifree;
	count++;
}

template<class T>
T TArrList<T>::Pop(int n)
{
	if (IsEmpty())
		throw "List is empty";
	if (n < 1 || n > count - 1)
		throw "Wrong indexex";
	int index = start;
	for (int i = 0; i < n; i++)
		index = nextIndex[index];
	nextIndex[lastIndex[index]] = nextIndex[index];
	lastIndex[nextIndex[index]] = lastIndex[index];
	T temp = mas[index];
	freeElem.Push(index);
	count--;
	return temp;
}

template <class T>
void TArrList<T>::PushStart(T elem)
{
	if (IsFull())
		throw "List is full";
	int ifree = freeElem.Pop();
	mas[ifree] = elem;
	nextIndex[ifree] = start;
	if (start != -1)
		lastIndex[start] = ifree;
	else
		end = ifree;
	start = ifree;
	count++;
}

template <class T>
void TArrList<T>::PushEnd(T elem)
{
	if (IsFull())
		throw "List is full";
	int ifree = freeElem.Pop();
	mas[ifree] = elem;
	if (end != -1)
		nextIndex[end] = ifree;
	else
	{
		start = ifree;
		lastIndex[ifree] = -1;
	}
	lastIndex[ifree] = end;
	end = ifree;
	count++;
}

template <class T>
T TArrList<T>::PopStart()
{
	if (IsEmpty())
		throw "List is empty";
	T elem = mas[start];
	freeElem.Push(start);
	int newstart = nextIndex[start];
	nextIndex[start] = lastIndex[start] = -2;
	if (newstart != -1)
		lastIndex[newstart] = -1;
	count--;
	start = newstart;
	return elem;
}

template <class T>
T TArrList<T>::PopEnd()
{
	if (IsEmpty())
		throw "error: list is empty";
	T elem = mas[end];
	int newFinish = lastIndex[end];
	lastIndex[end] = nextIndex[end] = -2;
	freeElem.Push(end);
	end = newFinish;
	if (newFinish != -1)
		nextIndex[newFinish] = -1;
	else
		start = -1;
	count--;
	return elem;
}

template <class T>
bool TArrList<T>::IsFull()
{
	return (count == size);
}

template <class T>
bool TArrList<T>::IsEmpty()
{
	return (count == 0);
}

template<class T>
void TArrList<T>::Print()
{
	int t = start;
	for (int i = 0; i < count; i++)
	{
		cout << mas[t] << " ";
		t = nextIndex[i];
	}
}
