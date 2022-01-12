//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 10/02/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <iostream>
#include "Set.h"
using namespace std;
namespace sdds {
	template <size_t N, class T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const string& filter) const {
			T accumulator(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (accumulator.isCompatibleWith(this->get(i))) {
					accumulator += this->get(i);
				}
			}
			return accumulator;
		}
	};
}
#endif