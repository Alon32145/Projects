//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 19/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ELEMENT_H
#define SDDS_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace sdds {

	struct Description {
		unsigned code {0};
		std::string desc {};

		
		bool load(std::ifstream& f) 
		{
			f >> code >> desc;
			return f.good();
		}

		void display(std::ostream& os) const 
		{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price {
		unsigned code {0};
		double price {0.0};
		bool load(std::ifstream& f) 
		{
			f >> code >> price;
			return f.good();
		}
		void display(std::ostream& os) const 
		{
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string m_desc {};
		double m_price {0.0};
		int m_id {0};
		static size_t idGenerator;
		static bool Trace;
		Product() 
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" 
					<< std::endl;
		}
		Product(const std::string& str, double p) 
		{
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" 
					<< std::endl;
		}
		Product(const Product& other) 
		{
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
					<< "] from [" << other.m_id << "]"
					<< std::endl;
		}
		~Product() 
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" 
					<< std::endl;
		}

		// TODO: add a function here to validate the price
		void validate() const 
		{
			if(this->m_price < 0)
				throw std::string("*** Negative prices are "
						"invalid ***");
		}
		void display(std::ostream& os) const 
		{
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif