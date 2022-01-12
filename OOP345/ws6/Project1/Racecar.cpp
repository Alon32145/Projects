//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#include <limits>
#include "Racecar.h"

namespace sdds
{
	
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		in.ignore(std::numeric_limits<std::streamsize>::max(), ',');
		in >> m_booster;
	}

	
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}

	double Racecar::topSpeed() const noexcept
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}