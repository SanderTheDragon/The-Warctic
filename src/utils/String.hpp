#ifndef STRING_HPP_
#define STRING_HPP_

#include <string>
#include <vector>

class String
{
public:
	static std::string Combine(int count, ...);                                  //Combines strings
	
	static std::string ToHexString(int number);                                  //Int to hex string
	
	static std::string ToString(int number);                                     //Int to string
	static std::string ToString(uint number) { return ToString((int)number); }   //Unsigned int to string
	static int ToInt(std::string number);                                        //Convert string to int
	
	static std::string ToString(bool value);                                     //Boolean to string
	static bool ToBool(std::string value);                                       //Convert string to boolean
	
	static bool IsNumber(std::string number);                                    //Check if string is numeric
	
	static std::vector<std::string> Split(std::string string, char delim);       //Split string at delim
};

#endif
