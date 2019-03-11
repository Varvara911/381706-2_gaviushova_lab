template <class T>

class TQueue
{
protected:
  int size; // размер стека
  T* mas; // элементы стека
  int top; // верх
  int start; // начало очереди
  int end; // конец очереди
public:
  TQueue() // конструктор по умолчанию
  {
    size = 0;
    mas = 0;
    top = 0;
    start = 0;
    end = 0;
  }

  TQueue(int _size) // конструктор с параметром
  {
    if (_size < 0)
      throw "negative size";
    mas = new T[_size];
    size = _size;
    top = 0;
    start = 0;
    end = 0;
  }

  TQueue(TQueue &h) // конструктор копирования
  {
    size = h.size;
    start = h.start;
	end = h.end;
  }

  void Push(T h) // положить в конец очереди
  {
    if (IsFulll())
      throw "error: queue is full";
    else
    {
      mas[start] = h;
      start = (start + 1) % size;
      end++;
    }
  }

  T Pop() // взять первый элемент
  {
    if (IsEmptyy())
      throw "error: queue is empty";
    else
    {
      T tmp = mas[top];
      top = (top + 1) % size;
      end--;
      return tmp;
    }
  }

  bool IsFulll() // проверка на полноту
  {
    return (end == size);
  }

  bool IsEmptyy() // проверка на пустоту
  {
    return (end == 0);
  }
};
