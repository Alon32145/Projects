//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <sstream>
#include <iomanip>
#include "Movie.h"
using namespace std;
namespace sdds {
	const string& Movie::title() const {
		return mTitle;
	}

	Movie::Movie(const string& strMovie) {
		if (!strMovie.empty()) {
			stringstream line(strMovie);
			string temp{};
			getline(line, mTitle, ',');
			mTitle.erase(0, mTitle.find_first_not_of(' '));
			mTitle.erase(mTitle.find_last_not_of(' ') + 1);

			getline(line, temp, ',');
			mYear = stoi(temp);

			getline(line, mDesc, '\n');
			mDesc.erase(0, mDesc.find_first_not_of(' '));
			mDesc.erase(mDesc.find_last_not_of(' ') + 1);
		}
		else {
			*this = Movie();
		}
	}

	ostream& operator<<(ostream& os, const Movie& src) {
		os << setw(40) << right << src.mTitle << " | ";
		os << setw(4) << src.mYear << " | ";
		os << left << src.mDesc << endl;
		return os;
	}
}