#include<stdio.h>
#include<conio.h>

void main()
{
	int counter,ctrvalue;
	printf(" Key in the number of times you wish the program to loop: ");
	scanf ("%d",&ctrvalue);
	//for (initialization; condition check; increment/decrement)
	for(counter =1; counter <=ctrvalue; counter++)
	{
		printf ("\n Hello!! ");
		printf ("\n The current counter value is %d. ", counter);
	}

	getch();
}