//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/6/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
	struct Population
	{
		char* postalCode;
		int population;
	};
	

	void display(const Population& the_postal_pop);

	void display();

	bool load(Population& population);

	bool load(const char filename[]);

	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_