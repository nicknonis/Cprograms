#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void main()
{
	int val1, val2, select;

	printf ("\n Welcome! \n");
	
	//values
	
	printf ("\n Enter 2 values: ");
	scanf ("%d  %d", &val1, &val2); fflush(stdin);
	
	do
	{
	//menu
	system ("cls");
	printf ("\n Choose an operation");
	printf ("\n 1. Add");
	printf ("\n 2. Subtract");
	printf ("\n 3. Multiply");
	printf ("\n 4. Divide");
	printf ("\n 5. Modulus");
	printf ("\n 6. Exit \n ");
	scanf ("%d", &select); fflush (stdin); 

	
	//switcher
	switch (select)
	{
	case 1:
		printf ("\n %d + %d = %d", val1, val2, (val1 + val2));
		break;
	case 2:
		printf ("\n %d - %d = %d", val1, val2, (val1 - val2));
		break;
	case 3:
		printf ("\n %d * %d = %d", val1, val2, (val1 * val2));
		break;
	case 4:
		printf ("\n %d / %d = %.3f", val1, val2, (float)(val1 / val2));
		break;
	case 5:
		printf ("\n %d %% %d = %d", val1, val2, (val1 % val2));
		break;
	case 6:
		printf ("\n Thank you for using this program!");
		printf ("\n Press any key to exit...");
		getch();
		return;

	default:
		printf ("\n Invalid!");
		break;
		
		
	}
	Sleep (4000);
	}while (select != 6);
	
	getch();
	
}

