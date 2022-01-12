//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 10/02/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template <unsigned int N, class T>
	class Set {
		T result[N];			
		unsigned elements = 0;	
	public:
		
		size_t size() const {
			return elements;
		}

		
		const T& get(size_t idx) const {
			return result[idx];
		}

		void operator+=(const T& item) {
			if (elements < N) {
				result[elements] = item;	
				elements++;					
			}
		}
	};
}
#endif