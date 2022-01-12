// Name: Alon Raigorodetsky
// ID:   109763201
// Email: araigorodetsky@myseneca.ca
// Date:  9/26/2021

// Section: NHH

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "TimedEvents.h"

namespace sdds
{
	TimedEvents::TimedEvents()
	{
		NumOfRecords = { 0 };
		startPoint = {};
		endPoint = {};
		events->eventName = {};
		events->eventTime = {};
		events->duration = {};
	}

	void TimedEvents::startClock()
	{
		startPoint = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		endPoint = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name)
	{
		auto duration = std::chrono::duration_cast<chrono::nanoseconds>(endPoint - startPoint);
		if (NumOfRecords < MAX)
		{
			events[NumOfRecords].eventName = name;  
			events[NumOfRecords].eventTime = "nanoseconds";	
			events[NumOfRecords].duration = duration;	
			NumOfRecords++;	
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& timedEvents)
	{
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";

		for (int i = 0; i < timedEvents.NumOfRecords; i++)
			os << setw(20) << left << timedEvents.events[i].eventName << " "
			<< setw(12) << right << timedEvents.events[i].duration.count() << " "
			<< timedEvents.events[i].eventTime << '\n';
		os << "--------------------------\n";

		return os;
	}
}