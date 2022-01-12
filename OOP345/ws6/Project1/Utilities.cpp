//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#include <limits>
#include "Racecar.h"
#include "Utilities.h"

namespace sdds
{
	
	Vehicle* createInstance(std::istream& is)
	{
		char type{ EOF };
		Vehicle* tmp{ nullptr };

		is >> type;
		if (is.good()) {
			is.ignore(std::numeric_limits
				<std::streamsize>::max(), ',');

			if (type == 'c' || type == 'C')
				tmp = new Car(is);
			else if (type == 'r' || type == 'R')
				tmp = new Racecar(is);
			else
				throw std::string("Unrecognized ")
				+ "record type: "
				+ "[" + type + "]";

		}

		return tmp;
	}
}