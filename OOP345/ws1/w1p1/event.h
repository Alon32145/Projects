// Name: Alon
// ID:   109763201
// Email: araigorodetsky@myseneca.ca
// Date:  2021-09-19
// Section: NHH

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H_ 
#define SDDS_EVENT_H_ 
extern unsigned int g_sysClock; 
namespace sdds {
	class Event
	{
	public:
		Event();
		~Event();
		void display();
		void set();
		void set(const char* desc);
		Event& operator=(const Event& e);

	private:
		char* eventDesc;
		unsigned int startTime;
	};
}
#endif