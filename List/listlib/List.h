template <class T>
struct Node{
  Node<T>* pNext; // указатель на следующий эл-т
  T value;		// значение
};

template <class T>
class List {
protected:
  Node<T>* pFirst;    // указатель на первый эл-т
  int size;			// текущий размер
public:
  List() { pFirst = 0; size = 0; }
  List(const List<T>& list) 
  {
    size = list.size;
    for (int i = 0; i < list.size; i++)
    {
      Add(list[i]);
    }
  }

  void Add(T value)
  {
    Insert(size, value);
  }
  
  T operator[](int index)
  {
    if (index >= size || index < 0)
      throw "out of range";

    int i = 0;
    Node<T>* current = pFirst;

    while (i < index && current->pNext != 0)
    {
      current = current->pNext;
      ++i;
    }

    return current->value;
  }
  
  void Insert(int index, T value)
  {
    int i = 0;
    Node<T>* current = pFirst;
    if (current == 0)
    {
      Node<T>* newOne = new Node<T>();
      newOne->pNext = 0;
      newOne->value = value;
      pFirst = newOne;
    }
    else
    {
      while (i < index && current->pNext != 0)
      {
        current = current->pNext;
        ++i;
      }
      Node<T>* newOne = new Node<T>();
      newOne->pNext = current->pNext;
      newOne->value = value;
      current->pNext = newOne;
    }
  
    ++size;
  }
  void Delete(int index)
  {
    if (index >= size || index < 0)
      throw "out of range";

    if (index == 0)
    {
      Node<T>* tmp = pFirst;
      pFirst = pFirst->pNext;
      delete tmp;
      return;
    }

    int i = 0;
    Node<T>* current = pFirst;

    while (i < index && current->pNext != 0)
    {
      current = current->pNext;
      ++i;
    }

    Node<T>* tmp = current->pNext;
    current->pNext = current->pNext->pNext;
    delete tmp;

    --size;
  }

  ~List() {
    if (size != 0)
    {
      Node<T>* current = pFirst;
      while (current != 0)
    {
        Node<T>* tmp = current;
        current = current->pNext;				
        delete tmp;
      }
    }
  }
};

