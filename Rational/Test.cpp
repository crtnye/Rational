#include "Rational.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


void main()
{
	//Tests for all of the public functions
	Rational test;
	cout << "0/1 " << test << endl; //tests default constructor
	Rational test1(5);
	cout << "5/1 " << test1 << endl; //tests constructor with 1 parameter
	Rational test2(-2, -4); 
	cout << "1/2 " << test2 << endl; //tests constructor with 2 parameters AND reduce()


	test1 = test2;
	cout << "1/2 " << test1 << endl; //tests the =
	cout << "1/2, 3/2 " << test1++ << ", " << test1 << endl; // tests the pre AND post increment operators ++
	cout << "3/2, 1/2 " << test1-- << ", " << test1 << endl; // tests the pre AND post decrement operators --
	cout << "1/2 " << test1() << endl; //tests the () operator
	cout << "0.5 " << double(test1) << endl; //tests the double() type conversion

	test1.setNumerator(2); //tests setNumerator()
	test1.setDenominator(3);//tests setDenominator()
	cout << "2 " << test1.getNumerator() << endl; //tests getNumerator()
	cout << "3 " << test1.getDenominator() << endl; //tests getDenominator()

	//Put tests for the global functions here!

	cout << "1/3, " << test1 * test2 << endl; //tests Rational * Rational
	cout << "4/1, " << test1 * 6 << endl; //tests Rational * long
	cout << "4/1, " << 6 * test1 << endl; //tests long * Rational

	cout << "4/3, " << test1 / test2 << endl; //tests Rational / Rational
	cout << "2/9, " << test1 / 3 << endl; //tests Rational / long
	cout << "9/2, " << 3 / test1 << endl; //tests long / Rational

	cout << "7/6, " << test1 + test2 << endl; //tests Rational + Rational
	cout << "17/3, " << test1 + 5 << endl; //tests Rational + long
	cout << "11/2, " << 5 + test2 << endl; //tests long + Rational

	cout << "1/6, " << test1 - test2 << endl; //tests Rational - Rational
	cout << "-7/3, " << test1 - 3 << endl; //tests Rational - long
	cout << "7/3, " << 3 - test1 << endl; //tests long - Rational
}