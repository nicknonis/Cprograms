#include <stdio.h>
#include <conio.h>

void main()
{
	int n,factorial=1 ,count;
	printf ("\n Please key in a value: ");
	scanf ("%d", &n);

	for (count=1; count <= n; count++)
	{
		factorial = factorial * count;
	}
	printf("\n Factorial of %d = %d", n ,factorial);


	getch();
}