// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/14

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <ostream>
#include"cstring.h"
#include "Truck.h"

using namespace std;

using namespace std;

namespace sdds
{
	Truck::Truck(const char* plate, int year, double capacity, const char* address) : MotorVehicle(plate, year)
	{
		m_capacity = capacity;
		m_cargo = 0;
		moveTo(address);

	}
	bool Truck::addCargo(double cargo)
	{
		bool add = false;
		if (m_cargo < m_capacity)
		{
			if (m_cargo + cargo > m_capacity)
				m_cargo = m_capacity;
			else
				m_cargo += cargo;
			add = true;
		}

		return add;
	}
	bool Truck::unloadCargo()
	{
		bool unload = m_cargo > 0;
		m_cargo = 0;
		return unload;
	}

	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;

		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;

	}

	std::istream& operator >> (std::istream& in, Truck& t)
	{
		return t.read(in);
	}
	std::ostream& operator <<(std::ostream& out, const Truck& t)
	{
		return t.write(out);
	}
}