#include <stdio.h>
#include <conio.h>

void main()
{
	int count;

	for(count=1; count<=10; count++)
	{
		printf (" \n\t %d \t %d \t %d",count, count*count, count*count*count);
	}
	getch();
}