// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/14

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SSDS_TRUCK_H
#define SSDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* plate, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	};
	std::istream& operator >>(std::istream& in, Truck& t);
	std::ostream& operator <<(std::ostream& out, const Truck& t);
}
#endif // !SSDS_TRUCK_H
