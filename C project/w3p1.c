

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021


int main(void)
{
	int Year, Month;
	
	

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
		printf("Log starting date: %d-JAN-01\n", Year);
	}
	else if (Month == 2)
	{
		printf("Log starting date: %d-FEB-01\n", Year);
	}
	else if (Month == 3)
	{
		printf("Log starting date: %d-MAR-01\n", Year);
	}
	else if (Month == 4)
	{
		printf("Log starting date: %d-APR-01\n", Year);
	}
	else if (Month == 5)
	{
		printf("Log starting date: %d-MAY-01\n", Year);
	}
	else if (Month == 6)
	{
		printf("Log starting date: %d-JUN-01\n", Year);
	}
	else if (Month == 7)
	{
		printf("Log starting date: %d-JUL-01\n", Year);
	}
	else if (Month == 8)
	{
		printf("Log starting date: %d-AUG-01\n", Year);
	}
	else if (Month == 9)
	{
		printf("Log starting date: %d-SEP-01\n", Year);
	}
	else if (Month == 10)
	{
		printf("Log starting date: %d-OCT-01\n", Year);
	}
	else if (Month == 11)
	{
		printf("Log starting date: %d-NOV-01\n", Year);
	}
	else if (Month == 12)
	{
		printf("Log starting date: %d-DEC-01\n", Year);
	}
	


	return 0;
}