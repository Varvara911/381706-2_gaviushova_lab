#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  void Push(T el)
  {
  if (IsFull())
    throw "Stack is full";

  top++;
  pMem[top] = el;
  }

  T Pop()	// достаём последний элемент из стека и удаляем его
  {
  if (IsEmpty())
    throw "Stakc is empty";

  top--;
  return pMem[top + 1];
  }

  bool IsEmpty() { return top == -1; }
  bool IsFull() { return top == size - 1; }
};



#endif
