//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#include <algorithm>
#include "Autoshop.h"

namespace sdds
{
	
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl
			<< "| Cars in the autoshop!        |" << std::endl
			<< "--------------------------------" << std::endl;

		std::for_each(m_vehicles.cbegin(), m_vehicles.cend(),
			[&out](Vehicle* v) {
				v->display(out);
				out << std::endl;
			});
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop()
	{
		std::for_each(m_vehicles.begin(), m_vehicles.end(),
			[](Vehicle* v) {
				delete v;
				v = nullptr;
			});

		m_vehicles.clear();

	}

}