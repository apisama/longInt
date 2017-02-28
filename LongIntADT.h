/*
@	Written by Negdo A. Mesa
@	Long Integer ADT
@	For CS435 (Algorithm Design)
*/
#ifndef LONG_INT_ADT_H
#define LONG_INT_ADT_H

#include <string>
#include "ListADT.h"
#include "conversion.h"
#include <iostream>
#include <cstdlib>

using namespace std;


class LongIntADT{	
protected:
	/*Useful static constants like amount of decimal digits in a single long digit*/
	static const int DIGIT_S;
	static const int BASE_TEN;
	static const int BASE_LONGINT;
	static const int MAX_DIGIT;

	//variables 
	ListADT list;
	bool sign; 


	//	helper functions for handling the initializing string
	
	/*	check if the initializing string is valid, returns true on success and false otherwise*/
	bool parse(string&);
	/*	fills a given string to a multiple of DIGIT_S by adding leading zeroes.
		this is useful for dividing a string into sections of DIGIT_S*/
	void fill(string&)const;
	//"String to long integer". Converts a valid, filled string into a long integer 
	void stli(string&);

	
public:
	/*calculates number of digits in a given integer */
	static int digit(int);
	/*Given an integer, it returns the overflow with respect 
	to a number of base 10000  and converts it
	into the maximum allowed size for that number's base(i.e. 9999).
	UPDATE: Fixed overflow function to correctly return a carry number instead of the amount exceding the allowed size (9999)*/
	static int over_flow(int&);

	LongIntADT();
	LongIntADT(string);
	//copy constructor
	LongIntADT(const LongIntADT&);
	//assignment constructor

	//Overloaded operators
	LongIntADT& operator= (const LongIntADT&);
	LongIntADT& operator= (const string&);
	LongIntADT& operator= (int);
	bool operator== (const LongIntADT&)const;
	bool operator> (const LongIntADT&)const;
	bool operator< (const LongIntADT&)const;
	const LongIntADT operator+(const LongIntADT&) const;
	const LongIntADT operator-(const LongIntADT&) const;
	const LongIntADT operator*(const LongIntADT&) const;
	const LongIntADT operator/(const LongIntADT&) const;
	//integer equivalents
	const LongIntADT operator+(int) const;
	const LongIntADT operator-(int) const;
	const LongIntADT operator*(int) const;
	const LongIntADT operator^(int) const;

	/*Populates a the long integer with the contents of the string*/
	void initialize(string);

	/*Sign operations*/
	char get_sign()const;
	void set_sign(char c);
	/*digit operations*/
	int get_digit_count() const;
	/*display operations*/
	void print()const;
	/*Helper functions for number handling*/
	//Absolute value of a given long integer
	const LongIntADT longAbs()const;
	//This function removes leading zeroes in the long integer
	void sanitize();
	
	/*Comparison operations*/
	/*UPDATE: Fixed greater than (and by extension less_than). See .cpp file for details*/
	bool greater_than(const LongIntADT&)const;
	bool less_than(const LongIntADT&)const;
	bool equal_to(const LongIntADT&)const;
	

	const LongIntADT add(const LongIntADT&) const;
	const LongIntADT subtract(const LongIntADT&)const;
	const LongIntADT multiply(const LongIntADT&)const;
	const LongIntADT divide(const LongIntADT&)const;
	const LongIntADT power(int)const;
	int extract_int_front(const LongIntADT&, int)const ;
};

#endif