#ifndef __MULT_H__ 
#define __MULT_H__ 

template <class T>
class MStack {
  int* pStack;
  int maxSize;
  int* size;
  int count;
  T* pMem;
public:
  MStack(int s, int c) {
    maxSize = s;
    count = c;

    pMem = new T[maxSize];
    size = new int[count];
    pStack = new int[count];

    for (int i = 0; i < count; i++)
    {
      size[i] = 0;
      pStack[i] = 0;
    }
  }

  ~MStack()
  {
    delete[] pStack;
    delete[] size;
    delete[] pMem;
  }

  void Put(T elem, int stackNum)
  {
    if (IsFull())
      throw "i'm full";


    for (int i = maxSize - 1; i > pStack[stackNum + 1]; i--)
    {
      pMem[i] = pMem[i - 1];
    }

    for (int i = stackNum + 1; i < count; i++)
    {
      pStack[i]++;
    }

    pMem[pStack[stackNum] + size[stackNum]] = elem;
    size[stackNum]++;
  }

  T Get(int stackNum)
  {
    if (IsEmpty(stackNum))
      throw "i'm empty";

    size[stackNum]--;
    auto tmp = pMem[pStack[stackNum] + size[stackNum]];

    for (int i = pStack[stackNum + 1]; i < maxSize - 1; i++)
    {
      pMem[i] = pMem[i + 1];
    }

    for (int i = stackNum + 1; i < count; i++)
    {
      pStack[i]--;
    }

    return tmp;

  }

  bool IsFull() 
  {
    int sum = 0;
    for (int i = 0; i < count; i++)
      sum += size[i];

    if (sum == maxSize)
      return true;

    return false;
  }

  bool IsEmpty()
  {
    for (int i = 0; i < count; i++)
      if (size[i] != 0)
        return false;

    return true;
  }

  bool IsEmpty(int i)	
  {
    if (size[i] == 0)
      return true;

    return false;
  }
};




#endif
