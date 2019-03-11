#include <iostream>

#include "List.h"

using namespace std;

int main()
{
List<int> l;
  int j = -1;
  int elem = 0, index = 0;
  int n = 0;
  do
  {
    cout << "Add - 1 / Insert - 2 / Delete - 3 / Print all - 4 / End - 0  ";
    cin >> j;
    try
    {
      switch (j)
      {
      case 1:
        cout << "Add. Input value: ";
        cin >> elem;
        l.Add(elem);
        n++;
        break;
      case 2:
        cout << "Insert. Input index: ";
        cin >> index;
        if (index > n)
        {
          cout << "Index out of range. Try again"<<endl;
          break;
        }
        cout << "Input value: ";
        cin >> elem;
        l.Insert(index, elem);
        n++;
        break;
      case 3:
        cout << "Delete. Input index: ";
        cin >> index;
        l.Delete(index);
        n--;
        break;
      case 4:
        cout << "Print all: " << endl;
        if (n == 0)
          cout << "No elements" << endl;
        else
        {
          for (int i = 0; i < n; i++)
            cout << l[i] << " ";
          cout << endl;
        }
        break;

        default:
          break;
    }

    }
    catch (...)
    {
      cout << "Out of range, try again"<<endl;		
    }
  } while (j != 0);

  return 0;
}
