//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
using namespace std;
namespace sdds {
	class Book {
		string bAuthor{};
		string bTitle{};
		string bCountry{};
		size_t bYear{};
		double bPrice{};
		string bDesc{};
	public:
		Book() = default;
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		friend ostream& operator<<(ostream& os, Book& src);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(bDesc);
		}
	};
}
#endif