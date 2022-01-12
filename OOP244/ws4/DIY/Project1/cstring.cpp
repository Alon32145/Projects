//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/20/2021
//email: araigorodetsky@myseneca.ca


#include <iostream>
#include "cstring.h"

namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];

		}
		des[i] = 0;
	}

	void strnCpy(char* des, const char* src, int len)
	{
		int i = 0;
		for (i = 0; i < len; i++)
		{
			des[i] = src[i];
		}

	}

	int strCmp(const char* s1, const char* s2)
	{
		while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
		{
			s1++;
			s2++;
		}

		if (*s1 == *s2)
		{
			return 0;
		}

		else
		{
			return *s1 - *s2;
		}
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
		{
			s1++;
			s2++;
			--len;
		}
		if (len == 0)
		{
			return 0;
		}
		else
		{
			return *s1 - *s2;
		}

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

	const char* strStr(const char* str1, const char* str2)
	{

		char c, sc;
		int len;

		if ((c = *str2++) != 0) {
			len = strLen(str2);
			do {
				do {
					if ((sc = *str1++) == 0)
						return NULL;
				} while (sc != c);
			} while (strnCmp(str1, str2, len) != 0);
			str1--;
		}
		return str1;
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