#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define SENTINEL -1

int main()
{
	
		int sale, sum = 0,count=1;
		
		do
		{
		printf("Enter your total sale: ");
		scanf("%d",&sale);

		if(sale == SENTINEL)
		{
			system("cls");
			printf ("\nSum: %d", sum);
			printf ("\nAverage: %d \n", (sum/count));
			printf ("\nPress any key to continue...");
			getch();
			printf ("Terminating...");
			Sleep(100);
			return 0;
		}
		sum = sum + sale;
		count ++ ;

		}while (sale != SENTINEL);

	getch();
	
	
	return 0;
}