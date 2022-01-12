// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/14

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle(const char* licensePlate, int year)
	{
		m_year = year;
		strCpy(m_licensePlate, licensePlate);
		strCpy(m_currentAddress, "Factory");

	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_currentAddress, address) != 0)
		{
			cout << "|"
				<< setw(8) << right << m_licensePlate << "| |"
				<< setw(20) << right << m_currentAddress << " ---> "
				<< setw(20) << left << address << "|" << endl;
			strCpy(m_currentAddress, address);
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << m_year << " | " << m_licensePlate << " | " << m_currentAddress;
		return os;
	}
	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		cout << "License plate: ";
		in >> m_licensePlate;
		cout << "Current location: ";
		in >> m_currentAddress;
		return in;
	}
	std::istream& operator >>(std::istream& in, MotorVehicle& v)
	{
		return v.read(in);
	}
	std::ostream& operator <<(std::ostream& out, const MotorVehicle& v)
	{
		return v.write(out);
	}
}