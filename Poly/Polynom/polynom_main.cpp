#include "Polynom.h"

using namespace std;

int main()
{
	int mon1[3] = { 1, 2, 3 };
	int mon2[3] = { 2, 2, 2 };
	int mon3[3] = { 1, 0, 3 };
	int mon4[3] = { 2, 2, 4 };
	int mon5[3] = { 3, 3, 3 };

	TMonom mymon1(3, mon1, 1.2);
	TMonom mymon2(3, mon2, 5);
	TMonom mymon3(3, mon3, 3);
	TMonom mymon4(3, mon4, 1);
	TMonom mymon5(3, mon5, 2.8);

	int h = 0;
	cout << "Do you want to show all monoms? " << endl << "No - 0, Yes - 1 " << endl;
	cin >> h;
	cout << endl;
	if (h == 1)
	{
		cout << "First monom: " << mymon1 << endl;
		cout << "Second monom: " << mymon2 << endl;
		cout << "Third monom: " << mymon3 << endl;
		cout << "Fourth monom: " << mymon4 << endl;
		cout << "Fifth monom: " << mymon5 << endl;
	}

	cout << endl;

	TPolynom pol1(3);
	pol1 += mymon1;
	pol1 += mymon2;
	pol1 += mymon3;
	cout << "First polynom: " << pol1 << endl;

	TPolynom pol2(3);
	pol2 += mymon4;
	pol2 += mymon5;
	cout << "Second polynom" << pol2 << endl;
			TPolynom pol(3);

		cout << endl;
	TPolynom polk(3);
			pol = pol1 + pol2;
	cout << "First polynom + Second polynom = " << endl << pol << endl;
			pol = pol1 - pol2;
	cout << "First polynom - Second polynom = " << endl << pol << endl;
			pol = pol1 * pol2;
	cout << "First polynom * Second polynom = " << endl << pol << endl;

	return 0;
}