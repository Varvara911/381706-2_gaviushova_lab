#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

enum StackState {LEFT_BRACKET, RIGHT_BRACKET, ADD, MULT};
class TPostfix
{
  string infix;
  string postfix;
  void MoveState(StackState* s1, StackState* s2, StackState to);
  void FillLine(TStack<char>* st);
  bool TryParce(string s, double* d);
public:
  TPostfix()
  {
    infix = "1 + 3";
  }
  TPostfix(string s)
  {
	  infix = s;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
