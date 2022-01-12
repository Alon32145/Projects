//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 10/09/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "ConfirmationSender.h"

namespace sdds {

	
	ConfirmationSender::~ConfirmationSender() {
		delete[] reservation;
		reservation = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src) {
			numOfGuests = src.numOfGuests;
			delete[] reservation;
			reservation = new const Reservation * [numOfGuests];
			for (size_t i = 0; i < numOfGuests; i++) {
				reservation[i] = src.reservation[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)  {
		if (this != &src) {
			delete[] this->reservation;

			this->reservation = src.reservation;
			this->numOfGuests = src.numOfGuests;

			src.reservation = nullptr;
			src.numOfGuests = 0;
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)  {
		*this = move(src);
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag = false;
		for (size_t i = 0; i < numOfGuests; i++) {
			if (reservation[i] == &res) {
				flag = true;
			}
		}
		if (!flag) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [numOfGuests + 1];
			for (size_t j = 0; j < numOfGuests; ++j) {
				temp[j] = reservation[j];
			}
			temp[numOfGuests] = &res;
			numOfGuests++;
			delete[] reservation;
			reservation = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool flag = false;
		size_t index{ 0 };
		for (size_t i = 0; i < numOfGuests; ++i) {
			if (reservation[i] == &res) {
				flag = true;
				index = i;
				i = numOfGuests;
			}
		}
		if (flag) {
			this->reservation[index] = nullptr;
			const Reservation** temp = reservation;
			this->reservation = new const Reservation * [numOfGuests - 1];
			size_t diff = 0;
			for (size_t i = 0; i < numOfGuests; i++) {
				if (temp[i] != nullptr) {
					this->reservation[i - diff] = temp[i];
				}
				else {
					diff = 1;
				}
			}
			this->numOfGuests--;
			delete[] temp;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& copy) {
		os << "--------------------------\n"
			<< "Confirmations to Send\n"
			<< "--------------------------\n";
		if (copy.numOfGuests == 0) {
			os << "There are no confirmations to send!\n";
		}
		for (size_t i = 0; i < copy.numOfGuests; i++) {
			if (copy.reservation[i] != nullptr) {
				os << *copy.reservation[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}