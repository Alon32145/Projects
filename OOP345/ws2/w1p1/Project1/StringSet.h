// Name: Alon Raigorodetsky
// ID:   109763201
// Email: araigorodetsky@myseneca.ca
// Date:  9/26/2021

// Section: NHH

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <iostream>
#include <string>

namespace sdds {
	class StringSet {
		std::string* strName = nullptr;
		size_t count = 0;
	public:
		StringSet();
		StringSet(const char* file_name);
		StringSet(StringSet& stringSet);
		StringSet(StringSet&& stringSet);
		StringSet& operator=(const StringSet& stringSet);
		StringSet& operator=(StringSet&& stringSet);
		~StringSet();
		size_t size();
		std::string operator[](size_t index) const;
	};
}
#endif