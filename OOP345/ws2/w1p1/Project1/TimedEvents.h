// Name: Alon Raigorodetsky
// ID:   109763201
// Email: araigorodetsky@myseneca.ca
// Date:  9/26/2021

// Section: NHH

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 10	

namespace sdds
{

	class TimedEvents
	{
	public:
		int NumOfRecords;
		std::chrono::steady_clock::time_point startPoint;
		std::chrono::steady_clock::time_point endPoint;
		struct
		{
			const char* eventName;
			const char* eventTime;
			std::chrono::steady_clock::duration duration;
		} events[MAX];

		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventName);

		friend ostream& operator<<(ostream& os, const TimedEvents& timedEvents);

	private:

	};

}

#endif