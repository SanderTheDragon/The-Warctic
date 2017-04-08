#ifndef STRING_HPP_
#define STRING_HPP_

#include <string>
#include <vector>

class String
{
public:
	static std::string Combine(int count, ...); //Combines strings
	
	static std::string ToHexString(int number); //Int to Hex String
	
	static int ToInt(std::string number);       //Convert string to int
};

#endif
