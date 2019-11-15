#include <string>

#ifndef MODIFYSTRING_HPP
	#define MODIFYSTRING_HPP
/**
 * Append an integer to a string
 * @param referencedString string to append integer to
 * @param n append (n % 10) to referencedString
 * @return New length of referencedString
 */
int modifyString(std::string& referencedString, int n);
#endif