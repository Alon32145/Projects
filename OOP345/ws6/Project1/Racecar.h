//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H


#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster{ 0.0 };

	public:
		
		Racecar(std::istream& in);

		void display(std::ostream& out) const override;

		double topSpeed() const noexcept override;

		~Racecar() override = default;
	};
}

#endif 