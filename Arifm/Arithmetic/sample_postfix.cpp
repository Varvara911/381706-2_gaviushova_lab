#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;	// выражение, введёное с клавиатуры
 
  double res;			// результат выражения

  //setlocale(LC_ALL, "Russian");
  cout << "Enter expression: ";
  cin >> expression;
  cout << expression << endl;
  TPostfix postfix(expression);		// нужно для получения конечного результата (реализует логику класса)
  cout << "Areefmeticheskoe virazhenie: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Posmotret' na postfix: " << postfix.GetPostfix() << endl;
  res = postfix.Calculate();
  cout << res << endl;

  return 0;
}
