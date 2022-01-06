

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3


int main(void)
{
	int Year, Month, i;

	double morningrating, eveningrating;
	double totalmorningrating = 0.0;
	double	 totaleveningrating = 0.0;
	double combined;

	printf("General Well-being Log\n");
	printf("======================\n");


	do
	{

		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &Year, &Month);

		if (Year > MAX_YEAR || MIN_YEAR > Year)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}

		if (Month < 1 || 12 < Month)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
	} while (Year > MAX_YEAR || Year < MIN_YEAR || Month < 1 || Month > 12);


	printf("\n*** Log date set! ***\n\n");


	for (i = 1; i <= LOG_DAYS; i++)
	{



		switch (Month)
		{
		case 1:
			printf("%d-JAN-%02d\n", Year, i);
			break;
		case 2:
			printf("%d-FEB-%02d\n", Year, i);
			break;
		case 3:
			printf("%d-MAR-%02d\n", Year, i);
			break;
		case 4:
			printf("%d-APR-%02d\n", Year, i);
			break;
		case 5:
			printf("%d-MAY-%02d\n", Year, i);
			break;
		case 6:
			printf("%d-JUN-%02d\n", Year, i);
			break;
		case 7:
			printf("%d-JUL-%02d\n", Year, i);
			break;
		case 8:
			printf("%d-AUG-%02d\n", Year, i);
			break;
		case 9:
			printf("%d-SEP-%02d\n", Year, i);
			break;
		case 10:
			printf("%d-OCT-%02d\n", Year, i);
			break;
		case 11:
			printf("%d-NOV-%02d\n", Year, i);
			break;
		case 12:
			printf("%d-DEC-%02d\n", Year, i);
			break;
		}

		do
		{
			printf("Morning rating (0.0-5.0): ");
			scanf("%lf", &morningrating);


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
			scanf(" %lf", &eveningrating);

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
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", totalmorningrating);
	printf("Evening total rating: %.3lf\n", totaleveningrating);
	printf("---------------------------\n");

	combined = totaleveningrating + totalmorningrating;
	printf("Overall total rating: %.3lf\n\n", combined);

	printf("Average morning rating: %.1lf\n", totalmorningrating / LOG_DAYS);
	printf("Average evening rating: %.1lf\n", totaleveningrating / LOG_DAYS);
	printf("---------------------------\n");
	printf("Average overall rating: %.1lf", (totaleveningrating + totalmorningrating) / ((double)LOG_DAYS * 2));

	return 0;
}