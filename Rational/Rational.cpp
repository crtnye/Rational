#include "Rational.h"

Rational::Rational(long num, long denom) : numerator(num), denominator(denom) 
{
	this->reduce();
}

Rational::~Rational()
{}

long Rational::getNumerator() const
{
	return numerator;
}

long Rational::getDenominator() const
{
	return denominator;
}

void Rational::setNumerator(long num)
{
	numerator = num;
}

void Rational::setDenominator(long denom)
{
	denominator = denom;
}

void Rational::reduce()
{
	long GCD = greatestCommonDivisor(numerator, denominator);
	numerator = numerator / GCD;
	denominator = denominator / GCD;
	if (numerator < 0 && denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	else if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

long Rational::greatestCommonDivisor(long x, long y) const
{
	long remainder = x % y;
	while (remainder != 0)
	{
		x = y;
		y = remainder;
		remainder = x % y;
	}
	return y;
}


//METHODS

long leastCommonMultiple(long x, long y)
{
	long result = x;
	while (result % y != 0)
	{
		result += x;
	}
	return result;
}

const Rational& Rational::operator=(const Rational & rValue)
{
	numerator = rValue.numerator;
	denominator = rValue.denominator;
	reduce();
	return *this;
}

Rational& Rational::operator++()
{
	numerator += denominator;
	reduce();
	return *this;
}

Rational Rational::operator++(int Garbage)
{
	Rational result = *this;
	numerator += denominator;
	reduce();
	return result;
}

Rational& Rational::operator--()
{
	numerator -= denominator;
	reduce();
	return *this;
}

Rational Rational::operator--(int Garbage)
{
	Rational result = *this;
	numerator -= denominator;
	reduce();
	return result;
}

string Rational::operator()() const
{
	std::ostringstream oss;
	oss << numerator << "/" << denominator;
	string rational = oss.str();
	return rational;
}

Rational::operator double() //needs a to handle 0 in the denominator
{
	double result;
	result = double(numerator) / double(denominator);
	return result;
}

//*******************
//FUNCTIONS
//*******************

bool operator==(const Rational & lValue, const Rational & rValue)
{
	bool result = true;
	if (lValue.getNumerator() != rValue.getNumerator() || lValue.getDenominator() != rValue.getDenominator())
	{
		result = false;
	}
	return result;
}

ostream& operator<<(ostream &out, const Rational &rational)
{
	out << rational.getNumerator() << "/" << rational.getDenominator();
	return out;
}

//istream& operator>>(istream &in, const Rational &rational)
//{
//	out << rational.getNumerator() << "\\" << rational.getDenominator();
//	return out;
//}

Rational operator+(const Rational &lValue, const Rational &rValue)
{
	Rational result;
	result.setDenominator(lValue.getDenominator() * rValue.getDenominator());
	result.setNumerator((lValue.getNumerator() * rValue.getDenominator()) 
		+ (rValue.getNumerator() * lValue.getDenominator()));
	result.reduce();
	return result;
}

Rational operator-(const Rational &lValue, const Rational &rValue)
{
	Rational result;
	result.setDenominator(lValue.getDenominator() * rValue.getDenominator());
	result.setNumerator((lValue.getNumerator() * rValue.getDenominator())
		- (rValue.getNumerator() * lValue.getDenominator()));
	result.reduce();
	return result;
}

Rational operator*(const Rational &lValue, const Rational &rValue)
{
	Rational result;
	result.setNumerator(lValue.getNumerator() * rValue.getNumerator());
	result.setDenominator(lValue.getDenominator() * rValue.getDenominator());
	result.reduce();
	return result;
}

Rational operator/(const Rational &lValue, const Rational &rValue)
{
	Rational result;
	result.setNumerator(lValue.getNumerator() * rValue.getDenominator());
	result.setDenominator(lValue.getDenominator() * rValue.getNumerator());
	result.reduce();
	return result;
}
