// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/14

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef  SDDS_MOTORWVEHICLE_H
#define SDDS_MOTORWVEHICLE_H
#include <iostream>

namespace sdds
{
	class MotorVehicle
	{
	public:
		MotorVehicle(const char* licensePlate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	private:
		char m_licensePlate[9];
		char m_currentAddress[64];
		int  m_year;
	};

	std::istream& operator >>(std::istream& in, MotorVehicle& v);
	std::ostream& operator <<(std::ostream& out, const MotorVehicle& v);
}
#endif // ! SDDS_MOTORWVEHICLE_H
