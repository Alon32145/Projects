//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 07/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and -only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		inline void select(T test, std::list<const Vehicle*>& v) const
		{

			std::copy_if(m_vehicles.cbegin(), m_vehicles.cend(),
				back_inserter(v), test);
		}

		~Autoshop();

	};
}

#endif