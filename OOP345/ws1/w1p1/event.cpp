// Name: Alon
// ID:   109763201
// Email: araigorodetsky@myseneca.ca
// Date:  2021-09-19
// Section: NHH

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;

unsigned int g_sysClock = 0;


namespace sdds {
	Event::Event() {
		
		startTime = 0;
		eventDesc = nullptr;
		
	}

	Event::~Event() {
		eventDesc = nullptr;
		delete[] eventDesc;
	}

	void Event::display() {
		static int eventCount = 1;
		int hour = 0;
		int minute = 0;
		int second = 0;
		

		hour = startTime / 3600; // 1 hour
		minute = (startTime - (hour * 3600)) /60/*1 minute*/;
		second = (startTime - (hour * 3600) - (minute * 60));



		cout<< setw(2) << setfill(' ') << eventCount++ << ". ";

		if (eventDesc == nullptr )
		{
			cout << "| No Event |" << endl;
		}
		else
		{
			cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " => " << eventDesc << endl;
		}


	}

	void Event::set() {
		startTime = 0;
		if (eventDesc != nullptr && eventDesc[0] != '\0') {
			delete[] eventDesc;
			eventDesc = nullptr;
		}
	}


	void Event::set(const char* desc) {
		if (desc != nullptr && desc[0] != '\0')
		{
			if (eventDesc != nullptr)
			{
				delete[] eventDesc;
				eventDesc = nullptr;
			}
			eventDesc = new char[strlen(desc) + 1];
			
			strcpy(eventDesc, desc);
			
			startTime = g_sysClock;
		}
		else
		{
			delete[] eventDesc;
			eventDesc = nullptr;
			
		}
		
	}
	Event& Event::operator=(const Event& event)
	{
		if (event.eventDesc != nullptr)
		{
			delete[] this->eventDesc;
			this->eventDesc = new char[strlen(event.eventDesc) + 1];
			strcpy(this->eventDesc, event.eventDesc);
		}
		this->startTime = event.startTime;
		return *this;
	}
}