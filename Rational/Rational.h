#pragma once
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::istream;

class Rational
{
public:
	Rational(long num = 0, long denom = 1);
	~Rational();

	const Rational& operator=(const Rational & rValue);
	Rational& operator++();
	Rational operator++(int Garbage);
	Rational& operator--();
	Rational operator--(int Garbage);
	string operator()() const;
	explicit operator double();

	long getNumerator() const;
	long getDenominator() const;
	void setNumerator(long num);
	void setDenominator(long denom);

	void reduce();

private:
	long numerator;
	long denominator;

	long greatestCommonDivisor(long x, long y) const;
};

long leastCommonMultiple(long x, long y);

//all should take parameters by const reference

ostream& operator<<(ostream &out, const Rational &rational);
//istream& operator>>(istream &in, const Rational &rational);

Rational operator+(const Rational &lValue, const Rational &rValue);
Rational operator-(const Rational &lValue, const Rational &rValue);
Rational operator*(const Rational &lValue, const Rational &rValue);
Rational operator/(const Rational &lValue, const Rational &rValue);


//These should take an lValue, rValue, 
//+=
//-=
//*=
//\=

//>
//<
//>=
//<=
bool operator==(const Rational & lValue, const Rational & rValue);
//!=
//^