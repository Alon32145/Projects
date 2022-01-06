/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Alon
	ID     : 109763201
	Email  : araigorodetsky@myseneca.ca
	Section: NDD
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3


int main(void)
{
	int Year, Month, i;


	float morningrating, totalmorningrating = 0, eveningrating, totaleveningrating = 0;



	printf("General Well-being Log\n");
	printf("======================\n");


	do
	{

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &Year, &Month);

		if (Year > 2021 || 2010 > Year)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}

		if (Month < 1 || 12 < Month)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	} while (Year > MAX_YEAR || Year < MIN_YEAR || Month < 1 || Month > 12);



	printf("\n*** Log date set! ***\n\n");



	if (Month == 1)
	{
		for (i = 1; i <= LOG_DAYS; i++)
		{
			printf("%d-JAN-0%d\n", Year, i);
			do
			{



				printf("Morning rating (0.0-5.0): ");
				scanf("%f", &morningrating);



				if (morningrating < 0.0 || 5.0 < morningrating)
				{
					printf("ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");


				}
				else
				{
					totalmorningrating += morningrating;
				}

			} while (morningrating < 0.0 || 5.0 < morningrating);

			do
			{
				printf("Evening rating (0.0-5.0): ");
				scanf(" %f", &eveningrating);

				if (eveningrating < 0.0 || 5.0 < eveningrating)
				{
					printf("ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");


				}
				else
				{
					totaleveningrating += eveningrating;
				}


			} while (eveningrating < 0.0 || 5.0 < eveningrating);

		}

		printf("%f", totalmorningrating);
		printf("%f", totaleveningrating);

	}

	return 0;
}