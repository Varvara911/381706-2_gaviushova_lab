#include <iostream>
#include "utmatrix.h"
#include <ctime>
//---------------------------------------------------------------------------

  int main()
  {
  int n;

  setlocale(LC_ALL, "Russian");

  cout << "Ââåäèòå ðàçìåð ìàòðèöû" << endl;
  cin >> n ;
  TVector<int> f(n);
  TMatrix<int> a(n), b(n), c(n);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Òåñòèðîâàíèå ïðîãðàìì ïîääåðæêè ïðåäñòàâëåíèÿ òðåóãîëüíûõ ìàòðèö"
	<< endl;
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }

  float start_time = clock();
  c = a + b;
  float end_time = clock();

  cout << "Ñëîæåíèå ìàòðèö:" << endl;
  float search_time = end_time - start_time;
  cout << search_time << " ìèëëèñåêóíä" << endl;	// 1 ñåê = 1000 ìèëèñåê

  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
	 
  return 0;
}
