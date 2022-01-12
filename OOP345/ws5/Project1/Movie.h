//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	class Movie {
		string mTitle{};
		size_t mYear{};
		string mDesc{};
	public:
		Movie() = default;
		const string& title() const;
		Movie(const string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(mTitle);
			spellChecker(mDesc);
		}
		friend ostream& operator<<(ostream& os, const Movie& src);
	};
}
#endif