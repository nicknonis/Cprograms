#include <stdio.h>
#include <conio.h>
#define SENTINEL -1

void main ()
{
	printf ("\n Welcome to the Sentinel-Controlled Loop.");

	int cnt, a,sum=0;
	cnt = 1;
	
		do{

		printf ("\n\n Enter a value [-1 to end]: ");
		scanf ("%d", &a);
		
		if(a == -1 )
		{
			printf ("This is the sentinel. Thank you for using the program.");
		}

		sum = a + sum ;
		printf ("\n The sum is %d", sum);
		printf ("\n The average is %.2f",(float)(sum/cnt));
		cnt++;

		}while(a != SENTINEL);

	getch();
}
