//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
using namespace std;
const int SIZE = 6;
namespace sdds {
	class SpellChecker {
		string m_badWords[SIZE];
		string m_goodWords[SIZE];
		int CNT[SIZE]{ 0 };
	public:
		SpellChecker(const char* filename);
		void operator()(string& text);
		void showStatistics(ostream& out) const;
	};
}
#endif