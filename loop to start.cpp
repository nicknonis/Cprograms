#include <stdio.h>
#include <conio.h>


void main()
{
	//Print multiplication table
	int count,a;
	char ans;
	
	do
	{
		printf("\n Please key in a value: ");
		scanf ("%d",&a);fflush(stdin);

		for(count=1; count<=10; count++)
		{
			printf ("\n %d * %d = %d",a,count,(a*count));
			printf ("\n current count is %d", count);
		}
		
		printf ("\n Do you wish to continue? [Y/N]: ");
		scanf ("%c", &ans); fflush(stdin);
		
	}while(ans =='y' || ans =='Y');
	
}
	