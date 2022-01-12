//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include <sstream>
#include "Book.h"
namespace sdds {

	const string& Book::title() const {
		return bTitle;
	}

	const string& Book::country() const {
		return bCountry;
	}

	const size_t& Book::year() const {
		return bYear;
	}

	double& Book::price() {
		return bPrice;
	}

	Book::Book(const string& strBook) {
		stringstream line(strBook);
		string tempInt{};

		getline(line, bAuthor, ',');
		bAuthor.erase(0, bAuthor.find_first_not_of(' '));
		bAuthor.erase(bAuthor.find_last_not_of(' ') + 1);

		getline(line, bTitle, ',');
		bTitle.erase(0, bTitle.find_first_not_of(' '));
		bTitle.erase(bTitle.find_last_not_of(' ') + 1);

		getline(line, bCountry, ',');
		bCountry.erase(0, bCountry.find_first_not_of(' '));
		bCountry.erase(bCountry.find_last_not_of(' ') + 1);

		getline(line, tempInt, ',');
		bPrice = stod(tempInt);

		getline(line, tempInt, ',');
		bYear = stoi(tempInt);

		getline(line, bDesc, '\n');
		bDesc.erase(0, bDesc.find_first_not_of(' '));
		bDesc.erase(bDesc.find_last_not_of(' ') + 1);
	}

	ostream& operator<<(ostream& os, Book& src) {
		os << right << setw(20) << setfill(' ') << src.bAuthor << " | ";
		os << setw(22) << src.title() << " | ";
		os << setw(5) << src.country() << " | ";
		os << setw(4) << src.year() << " | ";
		os << setw(6) << fixed << setprecision(2) << setprecision(2) << src.price() << " | ";
		os << left << src.bDesc << endl;
		return os;
	}
}