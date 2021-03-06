//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			string temp;
			size_t i = 0;
			while (file && i < SIZE) {
				getline(file, m_badWords[i], ' ');
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);
				getline(file, m_goodWords[i], '\n');
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
				i++;
			}
			file.close();
		}
	}

	void SpellChecker::operator()(string& text) {
		for (int i = 0; i < SIZE; i++) {
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				++CNT[i];
			}
		}
	}

	void SpellChecker::showStatistics(ostream& out) const {
		cout << "Spellchecker Statistics" << endl;
		for (int i = 0; i < SIZE; i++) {
			out << setw(15) << right << m_badWords[i] << ": " << CNT[i] << " replacements" << endl;
		}
	}
}