#include "utmatrix.h"


//
//template <class T>
//TStack<T>::TStack()				// êîíñòðóêòîð ïî óìîë÷àíèþ
//{
//	size = 0;
//	mas = 0;
//	top = 0;
//}
//
//template <class T>
//TStack<T>::TStack(int _size)	 // êîíñòðóêòîð ñ ïàðàìåòðîì
//{
//	if (_size < 0)
//		throw "negative size";
//
//	if (_size == 0) 
//	{
//		size = 0;
//		mas = 0;
//		top = 0;
//	}
//	else 
//	{
//		mas = new T[_size];
//		size = _size;
//		top = 0;
//	}
//}
//
//template <class T>				// äåñòðóêòîð
//TStack<T>::~TStack()
//{
//	delete[] mas;
//}
//
//template <class T>				// êîíñòðóêòîð êîïèðîâàíèÿ
//TStack<T> :: TStack(TStack &h)
//{
//	size = h.size;
//	top = h.top;
//	if (size == 0)
//		mas = 0;
//	else 
//	{
//		mas = new T[size];
//		for (int i = 0; i < size; i++)
//			mas[i] = h.mas[i];
//	}
//}
//
//template <class T>				// ïðîâåðêà íà ïóñòîòó
//bool TStack<T>::IsEmpty() 
//{
//	if (top == 0)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//template <class T>				// ïðîâåðêà íà ïîëíîòó
//bool TStack<T>::IsFull() 
//{
//	return !IsEmpty();
//}
//
//template <class T>				// ïîëîæèì ÷òî-íèáóäü
//void TStack<T>::Put(T h) 
//{
//	if (IsFull())
//		throw "stack is full";
//	else 
//	{
//		mas[top] = h;
//		top++;
//	}
//}
//
//template <class T>				// âîçüì¸ì ÷òî-íèáóäü
//T TStack<T>::Get() 
//{
//	if (IsEmpty())
//		throw "stack is empty";
//	else 
//	{
//		top--;
//		return mas[top];
//	}
//}
//
