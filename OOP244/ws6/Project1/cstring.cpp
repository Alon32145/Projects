// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/06

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];

		}
		des[i] = 0;
	}
	int strLen(const char* s)
	{
		int len = 0;
		while (*s != '\0')
		{
			len++;
			s++;
		}
		return len;
	}
	void strCat(char* des, const char* src)
	{

		char* ptr = des + strLen(des);


		while (*src != '\0') {
			*ptr++ = *src++;
		}

		*ptr = '\0';

	}
}