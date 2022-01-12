//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 16/10/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <stdexcept>
#include <string>
using namespace std;
namespace sdds {
	template <typename T>
	class Collection {
		string cName;
		T* cItem{};
		size_t cSize{};
		void (*observe)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const string& name) {
			cName = name;
			cItem = nullptr;
			cSize = 0;
			observe = nullptr;
		}

		Collection(Collection&) = delete;

		Collection& operator=(Collection&) = delete;

		~Collection() {
			delete[] cItem;
			cItem = nullptr;
		}

		const string& name() const {
			return cName;
		}

		size_t size() const {
			return cSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			observe = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool flag = false;

			for (size_t i = 0; i < cSize; ++i) {
				if (cItem[i].title() == item.title()) {
					flag = true;
				}
			}
			if (!flag) {
				if (cSize == 0) {
					cSize++;
					cItem = new T[cSize];
					cItem[0] = item;
				}
				else {
					T* temp = new T[cSize];
					for (size_t i = 0; i < cSize; ++i) {
						temp[i] = cItem[i];
					}
					delete[] cItem;
					cSize++;
					cItem = new T[cSize];
					for (size_t j = 0; j < cSize - 1; ++j) {
						cItem[j] = temp[j];
					}
					delete[] temp;
					cItem[cSize - 1] = item;
					if (observe != nullptr) {
						observe(*this, item);
					}
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= cSize || idx < 0) {
				string exception = { "Bad index [" + to_string(idx) + "]. " + "Collection has [" + to_string(cSize) + "] items." };
				throw out_of_range(exception);
			}
			else {
				return cItem[idx];
			}
		}

		T* operator[](string title) const {
			int itemNum = -1;
			for (size_t i = 0; i < cSize; i++) {
				if (cItem[i].title() == title) {
					itemNum = i;
				}
			}
			if (itemNum == -1) {
				return nullptr;
			}
			else {
				return &cItem[itemNum];
			}
		}

		friend ostream& operator<<(ostream& os, Collection& src) {
			for (size_t i = 0; i < src.size(); ++i) {
				os << src.cItem[i];
			}
			return os;
		}
	};
}
#endif