//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include "Car.h"

namespace sdds
{
	
	Car::Car(std::istream& is)
	{
		getline(is, maker, ',');
		trim(maker);

		is >> carCondition;
		if (carCondition == ',')
			carCondition = 'n';
		else if (carCondition != 'n' && carCondition != 'u' && carCondition != 'b')
			is.setstate(std::ios::failbit);
		else
			is.ignore(std::numeric_limits
				<std::streamsize>::max(), ',');

		is >> maxSpeed;
		if (is.fail()) {
			is.clear();
			throw std::string("Invalid record!");
		}

	}

	
	std::string Car::condition() const
	{
		std::string str;

		if (carCondition == 'n')
			str = "new";
		else if (carCondition == 'u')
			str = "used";
		else if (carCondition == 'b')
			str = "broken";

		return str;
	}

	double Car::topSpeed() const noexcept
	{
		return maxSpeed;
	}

	
	void Car::display(std::ostream& out) const {
		out << "| " << std::right << std::setw(10) << maker;
		out << " | " << std::left << std::setw(6) << condition();
		out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed();
		out << " |";
	}

	
	void trim(std::string& str)
	{
		size_t i = str.find_first_not_of(' ');
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}
}