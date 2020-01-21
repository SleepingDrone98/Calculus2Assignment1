/*******************************************************************************
Name:											Phillip Clarke
Student number:									040832994
Assignment number:								1
Course name and number:							Numerical Computing CST8233
Lab section number:								300
Professor's name:								Abdullah Kadri
Due date of assignment:							Sunday, September 29th 2019
Submission date of assignment:					Saturday, September 28th 2019
List of source and header files in the project:	ass1.c
********************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#define e 2.71828
/******************************************************************************************************************************************************************************
Function name:	Main
Purpose:		To run the logic of the program - asking the user for a number of terms over a given timeframe and calculating a level of accuracy based on the given numbers.
Function		In parameters: None
Function		Out parameters: Int (returns 0 upon success and closes the program)
Version:		1.0
Author:			Phillip Clarke
*******************************************************************************************************************************************************************************/
int main()
{
	
	char choice = "";
	while (choice != '2')//The loop that allows the user to calculate multiple levels of precision in the same runtime of the program.
	{
		printf("Evaluate the Maclaurin Series approximation to exp(-t)*cos(t)\n\n");
		printf("1: Evaluate the series\n");
		printf("2: quit\n");
		scanf_s(" %c", &choice);
		//prompts the user to select a menu option
			if (choice == '1')
			{
				double time = 0.0, realTime = 0.0, expValue = 0.0, error = 0.0;
				double dNorm = 0.0, d = 0.0, truncHolder = 0.0, trunc = 0.0;
				int terms = 0;
				double ex = 0.0, cosx = 0.0;
				//creates the variables to be used in the logic
				printf("Please enter the number of terms in the series (max 5 terms): ");
				scanf_s("%d", &terms);
				if (terms < 0 || terms > 5)//validates the number entered is a positive number and within the bounds of the program
				{
					printf("Number out of the bounds of the program\n");
				}
				else
				{
					printf("\nEnter a time between 0.0 and 2.0: ");
					scanf_s("%lf", &time);
					if (time < 0.0 || time > 2.0)//validates the number entered is a positive number and within the bounds of the program
					{
						printf("Number out of the bounds of the program\n");
					}
					else
					{
						time /= 10;//sets the T increment for the program

						printf("\nt\t\tSeries\t\tExact\t\tExact %% Error\t\tTrunc. %% Error\n");
						for (int y = 0; y < 11; y++)//Loop that runs increasing the time and displays the logic based on the current time
						{
							d = exp(-realTime) * cos(realTime); //Calculates the exact number for the equation
							if (terms == 1)//First term calculation with second term calculation for trunc error
							{
								dNorm = 1;
								truncHolder = 1 - realTime;
							}
							if (terms == 2)//Second term calculation with third term calculation for trunc error
							{
								dNorm = 1 - realTime;
								truncHolder = 1 - realTime + (realTime * realTime * realTime / 3);

							}
							if (terms == 3)//Third term calculation with fourth term calculation for trunc error
							{

								dNorm = 1 - realTime + (realTime * realTime * realTime / 3);
								truncHolder = 1 - realTime + (realTime * realTime * realTime / 3) - (realTime * realTime * realTime * realTime / 6);
							}
							if (terms == 4)//Fourth term calculation with fifth term calculation for trunc error
							{

								dNorm = 1 - realTime + (realTime * realTime * realTime / 3) - (realTime * realTime * realTime * realTime / 6);
								truncHolder = 1 - realTime + (realTime * realTime * realTime / 3) - (realTime * realTime * realTime * realTime / 6) + (realTime * realTime * realTime * realTime * realTime / 30);
							}
							if (terms == 5)//Fifth term calculation with sixth term calculation for trunc error
							{
								dNorm = 1 - realTime + (realTime * realTime * realTime / 3) - (realTime * realTime * realTime * realTime / 6) + (realTime * realTime * realTime * realTime * realTime / 30);
								truncHolder = 1 - realTime + (realTime * realTime * realTime / 3) - (realTime * realTime * realTime * realTime / 6) + (realTime * realTime * realTime * realTime * realTime / 30) - (realTime * realTime * realTime * realTime * realTime * realTime * realTime  / 630);
							}
							error = (100 * (d - dNorm)) / d;//Calculates the error between the generated number based on the entered terms and the exact number
							if (realTime == 0.0)
							{
								trunc = (100 * (dNorm - truncHolder)) / dNorm;//Equation to handle the truncation error
							}
							else
								trunc = -(100 * (dNorm - truncHolder)) / dNorm;//Equation to handle the truncation error
							
							printf("%.3e\t%.5e\t%.5e\t%.5e\t%.5e\n", realTime, dNorm, d, error, trunc);//Prints the current status of the equations based on time
							realTime += time;//Increments the current time by user entered time divided by 10
						}
					}
				}	
		}
	}
	return 0;	
}
