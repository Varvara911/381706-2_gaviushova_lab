#include <iostream>
#pragma once

using namespace std;

class TMonom
{
protected:
	TMonom* next;  // указатель на следующий моном
	int *power;    // массив степеней
	double k;      // коэффицтент
	int n;         // степень монома (кол-во переменных)
public:
	TMonom();
	TMonom(int _n, int* _power, double _k);
	TMonom(const TMonom& A);
	virtual ~TMonom();

	TMonom* GetNext();
	int* GetPower();
	double GetK();
	int GetN();

	void SetNext(TMonom* _next);
	void SetPower(int* _power);
	void SetK(double _k);
	void SetN(int _n);

	TMonom& operator=(const TMonom& A);
	TMonom operator+(TMonom& A);
	TMonom operator-(TMonom& A);
	TMonom operator*(const TMonom& A) const;
	TMonom operator*=(TMonom& A);
	TMonom operator+=(TMonom& A);
	TMonom operator-=(TMonom& A);
	bool operator==(TMonom& A);
	bool operator<(TMonom& A);
	bool operator>(TMonom& A);


	friend istream& operator>>(istream& istr, TMonom& A);
	friend ostream& operator<<(ostream& ostr, TMonom& A);
};