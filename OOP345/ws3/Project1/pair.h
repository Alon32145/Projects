//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 10/02/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
using namespace std;
namespace sdds {
	template <class V, class K>
	class Pair {
		
		K classKey;
		V classValue;
	public:
		Pair() :classKey{ 0 }, classValue{ 0 } {};

		Pair(const K& key, const V& value) {
			classKey = key;
			classValue = value;
		}

		const V& value() const {
			return classValue;
		}

		const K& key() const {
			return classKey;
		}

		virtual void display(std::ostream& os) const {
			os << classKey << " : " << classValue << std::endl;  //Display KEY : VALUE<endl>
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		}
	};
}
#endif