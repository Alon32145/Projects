//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds
{
	

	class Car : public Vehicle
	{
		std::string maker{};
		char carCondition{ '\0' };
		double maxSpeed{ 0.0 };

	public:
		
		Car(std::istream& is);

		
		std::string condition() const override;

		double topSpeed() const noexcept override;

		
		void display(std::ostream& os) const override;

		
		~Car() override = default;
	};

	
	void trim(std::string& str);
}

#endif 