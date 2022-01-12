// Name: Alon Raigorodetsky
// ID:   109763201
// Email: araigorodetsky@myseneca.ca
// Date:  9/26/2021

// Section: NHH

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "StringSet.h"
#include <fstream>

namespace sdds {
	StringSet::StringSet() {
		strName = nullptr;
		count = 0;
	}
	StringSet::StringSet(const char* stringSet) {
		std::ifstream fin;
		std::string temp;
		fin.open(stringSet);
		if (fin.is_open()) {
			while (getline(fin, temp, ' ')) {
				++count;
			}
			fin.clear();
			fin.seekg(0, std::ios::beg);
			delete[] strName;
			strName = nullptr;
			strName = new std::string[count];
			for (size_t i = 0; i < count && fin; i++) {
				getline(fin, temp, ' ');
				strName[i] = temp;
			}
		}
		fin.close();
	}
	StringSet::StringSet(StringSet& stringSet) {
		operator= (stringSet);
	}
	StringSet::StringSet(StringSet&& stringSet) {
		*this = std::move(stringSet);
	}
	StringSet& StringSet::operator=(const StringSet& stringSet) {
		if (this != &stringSet) {
			count = stringSet.count;
			delete[] strName;
			strName = nullptr;
			strName = new std::string[count];
			for (size_t i = 0;i < count;i++) {
				strName[i] = stringSet.strName[i];
			}
		}
		return *this;
	}
	
	StringSet& StringSet::operator=(StringSet&& stringSet) {
		if (this != &stringSet) {
			count = stringSet.count;
			stringSet.count = 0;
			delete[] strName;
			strName = stringSet.strName;
			stringSet.strName = nullptr;
		}
		return *this;
	}
	StringSet::~StringSet() {
		
			delete[] strName;
			strName = nullptr;
	}
	size_t StringSet::size() {
		return count;
	}
	std::string StringSet::operator[](size_t index) const {
		std::string str;
		if (strName != nullptr && index < count) {
			str = strName[index];
		}
		return str;
	}
}