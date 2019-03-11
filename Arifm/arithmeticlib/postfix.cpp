#include "postfix.h"
#include "stack.h"

void TPostfix::MoveState(StackState* s1, StackState* s2, StackState to)
{
  *s1 = *s2;
  *s2 = to;
}

void TPostfix::FillLine(TStack<char>* st)
{
  char cLetter = st->Pop();
  while (cLetter != '(')
  {
    postfix += cLetter;
    postfix += " ";
    cLetter = st->Pop();
  }

  try {
    char tmp = st->Pop();
    st->Push(tmp);
  }
  catch(...) {
    st->Push('(');
  }
	
}

string TPostfix::ToPostfix()
{
  int lb = 0;
  int rb = 0;

  for (auto c : infix)
    if (c == '(')
      lb++;
    else if (c == ')')
      rb++;

  if (lb != rb)
    throw "brackets";

  StackState cState = LEFT_BRACKET;
  StackState lState = LEFT_BRACKET;

  TStack<char> st(infix.length());
  st.Push('(');

  string tmp = "";
  for (auto c : infix)
    if (c != ' ')
      tmp += c;

  infix = tmp + ")";

  for (auto c : infix)
  {
    if (c == ')'
      || c == '('
      || c == '+'
      || c == '/'
      || c == '-'
      || c == '*'
      ) 
  {
     switch (c)
      {
      case '(': {MoveState(&lState, &cState, LEFT_BRACKET); break; }
      case ')': {MoveState(&lState, &cState, RIGHT_BRACKET); break; }
      case '*': {MoveState(&lState, &cState, MULT); break; }
      case '/': {MoveState(&lState, &cState, MULT); break; }
      case '+': {MoveState(&lState, &cState, ADD); break; }
      case '-': {MoveState(&lState, &cState, ADD); break; }
      }
      switch (cState)
      {
      case LEFT_BRACKET : {
        st.Push('(');
        break;
      }
      case RIGHT_BRACKET: {
        FillLine(&st);
        break;
      }
      case ADD: {
        if (lState == MULT || lState == RIGHT_BRACKET)
          FillLine(&st);
        st.Push(c);
        break;
      }
      case MULT: {
        st.Push(c);
        break;
      }			
      }
    }
    else {
      postfix += c;
      postfix += " ";
    }
  }


  return postfix;


}

double TPostfix::Calculate()
{
  TStack<double> tokens(postfix.length());
  int startIndex = 0;
  for (int i = 0; i < postfix.length(); i++)
  {
    char c = postfix[i];
    if (c == '+'
      || c == '/'
     || c == '-'
     || c == '*'
     )
    {
     switch (c)
     {
     case '*': {
       auto ro = tokens.Pop();
       auto lo = tokens.Pop();
       tokens.Push(lo * ro);
       break;
     }
     case '/': {
       auto ro = tokens.Pop();
       auto lo = tokens.Pop();
       if (ro == 0)
         throw "divide by zero";
       tokens.Push(lo / ro);
       break;
     }
     case '+': {
       auto ro = tokens.Pop();
       auto lo = tokens.Pop();
       tokens.Push(lo + ro);
       break;
     }
     case '-': {
       auto ro = tokens.Pop();
       auto lo = tokens.Pop();
       tokens.Push(lo - ro);
       break;
     }
     }
     i += 1;
     startIndex += 2;
  }
  else
      if (postfix[i] == ' ')
      {
        double number;
        if (TryParce(postfix.substr(startIndex, i - startIndex), &number)) {
          tokens.Push(number);
          startIndex = i + 1;
        }
      }
  }
  return tokens.Pop();
}

bool TPostfix::TryParce(string s, double* d) // переводит строку в double
{
  if (s == "")
    return false;

  int point = 0;		// кол-во точек
  for (int i = 0; i < s.length(); i++)	// проверка на правильность записи
  {
    if (!isdigit(s[i]))
      return false;

  if (s[i] == '.')
  {
      if (point > 1)
        return false;
      point++;
    }

  }

  *d = 0.0;	// нейтральный элемент для умножения

  int dec = 1;	// вспомогательная переменная

  int dotIndex = s.find('.');
  if (dotIndex == -1)
    dotIndex = s.length();

  string z = s.substr(0, dotIndex);	// целая часть числа
  z.reserve();
  for (auto e : z)
  {
    *d += ((e - '0') * dec);
    dec += 10;
  }

  if (dotIndex == s.length())
    return true;

  string m = s.substr(dotIndex + 1, s.length() - dotIndex);	// мантисса
  double ddec = 0.1;	// вспомогательная переменная
  for (auto e : m)
  {
    *d += ((e - '0') * ddec);
    ddec *= 0.1;
  }

  return true;
}
