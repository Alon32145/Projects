//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 10/09/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** reservation{ nullptr }; 
		size_t numOfGuests{ 0 };
	public:
		ConfirmationSender() = default;
		~ConfirmationSender();

		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		ConfirmationSender(ConfirmationSender&& src);

		ConfirmationSender& operator +=(const Reservation& res); 
		ConfirmationSender& operator -=(const Reservation& res); 

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& copy); 
	};
}

#endif
