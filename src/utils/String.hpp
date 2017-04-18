#ifndef STRING_HPP_
#define STRING_HPP_

#include <string>

class String
{
public:
	static std::string Combine(int count, ...); //Combines strings
	
	static std::string ToHexString(int number); //Int to hex string
	
	static std::string ToString(int number);    //Int to string
	static int ToInt(std::string number);       //Convert string to int
	
	static bool IsNumber(std::string number);   //Check if string is numeric
};

#endif
