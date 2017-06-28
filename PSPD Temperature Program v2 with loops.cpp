#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	float a;
	float b = 5.0/9.0;
	char c[4]; // creates a string array 3 for text and 1 for blank space in terminal
	char d[4];

	printf ("\n\n Welcome to the Fahrenheit to degree Celsius Program!");
	printf ("\n\n This program uses the following formula: \n Celcius= (5/9) x (F-32)");
	
	printf ("\n\n Would you like to convert? \n Type 'yes' or 'no' "); //check if user intends to use app
	scanf ("%s", &c); // %s for strings allows string comparisons

	if (strcmp (c,"yes")== 0 || strcmp(c,"y")== 0) // compares the two strings
	{
		printf ("\n\n Please key in the Fahrenheit value you wish to convert: ");
		scanf ("%f",&a);
		printf ("\n %.3f * (%.3f - 32)= %.3f",b ,a ,(b*(a-32.0)));
		printf ("\n\n press any key to continue...");
		getch(); 

		printf("\n\n Would you like to convert more? "); //loop
		scanf ("%s",d);
		
		if (strcmp (d, "yes") == 1 || strcmp(d,"y") ==1)
		{
			system ("cls"); // clear screen
			return main(); // completes the loop by starting from the start of main
		}

		if (strcmp (d, "no") == 1 || strcmp (d,"n") ==1)
		{
			printf (" Oh! okay... \n See you next time!");
		}
	}

	if (strcmp (c, "no")== 0 || strcmp(c, "n") ==0)
	{
		printf ("\n See you next time!");
	}

	printf ("\n\n press any key to exit..");
	getch();
	return 0; // exits program	
}

