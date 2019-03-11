// Arr.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include "arrlist.h"

using namespace std;

int main()
{
	int n = 1;
	cout << "size: ";
	int helpSize;
	cin >> helpSize;
	TArrList<int> A(helpSize);
	while (n)
	{
		cout << "Push element - 1 / Get element - 2 / Print all - 3 / Exit - 0" << endl;;
		cin >> n;
		int f;
		switch (n)
		{
		case 1:
			cout << "Push in: Start - 1 / End - 2 / Center - 3 / Exit - 0" << endl;
			cin >> n;
			switch (n) {
			case 1:
				cout << "Element: ";
				cin >> f;
				A.PushEnd(f);
				break;
			case 2:
				cout << "Element: ";
				cin >> f;
				A.PushStart(f);
				break;
			case 3:
				int p;
				cout << "Position: ";
				cin >> p;
				cout << "Element: ";
				cin >> f;
				A.Push(p, f);
				break;
			case 0:
				break;
			default:
				cout << "Wrong command!\n";
				break;
			}
			break;

		case 2:
			cout << "Pop in: Start - 1 / End - 2 / Center - 3 / Exit - 0" << endl;
			cin >> n;
			switch (n) {
			case 1:
				A.PopEnd();
				break;
			case 2:
				A.PopStart();
				break;
			case 3:
				int p;
				cout << "Index: ";
				cin >> p;
				A.Pop(p);
				break;
			case 0:
				break;
			default:
				cout << "error " << endl;
				break;
			}
			break;

		case 3:
			A.Print();
			break;

		case 0:
			return 0;

		default:
			cout << "error " << endl;
			break;
		}
	}
}

