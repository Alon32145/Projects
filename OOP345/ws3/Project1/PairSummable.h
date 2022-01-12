//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 10/02/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include <cstring>
#include "Pair.h"
using namespace std;
namespace sdds {
	template <class V, class K>
	class PairSummable : public Pair<V, K> {
		static V initial;	
		static size_t minfield;	
	public:
		
		PairSummable() {}

		PairSummable(const K& key, const V& value = initial) : Pair <V, K>(key, value) {
			
			auto keysize = key.size();
			if (keysize > minfield) {
				minfield = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const { 
			bool result;
			this->key() == b.key() ? result = true : result = false;
			return result;
		}

		PairSummable& operator+=(const PairSummable<V, K>& paramObj) {
			if (this->key() == paramObj.key()) {
				PairSummable newPairSummable(this->key(), this->value() + paramObj.value());
				*this = newPairSummable;
			}
			return (*this);
		}

		virtual void display(ostream& os) const {
			os.width(minfield);
			os << left;
			Pair<V, K>::display(os);
			os.width(0);
			os << right;
		}

		static const V& getInitialValue() {
			return initial;
		}
	};

	template<> string PairSummable<string, string>::initial = "";
	template<> int PairSummable<int, string>::initial = 0;

	template<> PairSummable<string, string>& PairSummable<string, string>::operator+=(const PairSummable& param) {
		if (this->key() == param.key()) {
			PairSummable newPairSummable(this->key(), this->value() + (this->value().compare("\0") ? ", " : "") + param.value());
			*this = newPairSummable;
		}
		return (*this);
	}

	template<typename V, typename K>
	size_t PairSummable<V, K>::minfield = 0;
}
#endif