//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 19/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	
	List<Product> mergeRaw(const List<Description>& desc, 
						const List<Price>& price) {

		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		bool found {false};

		for(size_t i {0ul}; i < desc.size(); i++) {
			for(size_t j {0ul}; j < price.size() && !found; j++) {
				if(desc[i].code == price[j].code) {
					found = true;
					Product *tmp {new Product(desc[i].desc,
							price[j].price)};

					try {
						tmp->validate();
					} catch(const std::string& msg) {
						Product::Trace = false;
						delete tmp;
						Product::Trace = true;
						throw;
					}
					priceList += tmp;
					delete tmp;

				}
			}
			found = false;
		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, 
						const List<Price>& price) {

		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		// 		using smart pointers

		bool found {false};

		for(size_t i {0}; i < desc.size(); i++) {
			for(size_t j {0ul}; j < price.size() && !found; j++) {
				if(desc[i].code == price[j].code) {
					found = true;
					std::unique_ptr<Product> 
						tmp(new Product(desc[i].desc,
							price[j].price));

					tmp->validate();
					priceList += tmp;

				}
			}
			found = false;
		}


		return priceList;
	}
}
