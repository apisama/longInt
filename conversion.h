#ifndef CONVERSION_H
#define CONVERSION_H
#include <string>
#include <sstream>   
/*
@Number to string and string to number converter
@Written By Negdo Mesa
@
*/
//*this is an old file I wrote containing helper functions to handle integer to string conversion and vice versa

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NumberToString will allow us to enter a number as a paremeter, it will convert it into a string and return it
//e.g:
/*
	int num = 5;
	string mystr;
	mystr = NumberToString<int>(num); // <int> specifies what data type we are working with, we could use <double> if we want
	cout<<mystr;  // 5
*/
template <typename T> 
std::string NumberToString ( T Number )
{
	std::stringstream ss;
	ss << Number;
	return ss.str();
}
/*StringToNumber will allow us to enter a string as a paremeter, check if it is a number (if the input is a name instead of a
number it will return false), if it's true (the string starts with a number) then it will convert it into a 
number and return it. If it's false, it will return 0.
e.g:

	int num1, num2, num3;
	string mystr1 = "1234123";
	string mystr2 = "414ohsolemio90";
	string mystr3 = "trololol";
	num1 =  StringToNumber<int>(mystr1);
	num2 =  StringToNumber<int>(mystr2);
	num3 =  StringToNumber<int>(mystr3);
	cout<<num1;  // 1234123    <--- Converts the whole number
	cout<<num2;  // 414		<--- Converts until it finds a letter (ignores everything else)
	cout<<num3;  // 0			<--- Since there is not a single number it will return 0
*/
template <typename T> T StringToNumber (std::string &Text)
{                             
	std::stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;

}


#endif 
