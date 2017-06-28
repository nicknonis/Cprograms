#include <stdio.h>
#include <conio.h>

void main()
{
	//Print multiplication table
	int count,a,b;
	printf("\n Please key in a value: ");
	scanf ("%d",&a);
	printf ("\n Up to what multiple would you like? ");
	scanf ("%d",&b);

	for(count=1; count<=b; count++)
	{
		printf ("\n %d * %d = %d",a,count,(a*count));
		printf ("\n current count is %d", count);
	}

	getch();
}