//Pattern
#include <stdio.h>
#include <conio.h>

/*
Using Nested looping
Outer loop Row
Inner loop Column

88
88
88
88

*/

void main()
{
	int row, col;
	char bla = *;

	for( row= 1; row <=3; row ++)
	{
		for( col= 1; col <=4; row ++)
			printf ("%c",bla);
		printf("\n");
	}
	getch();
}

/*Pseudo Code*/
Begin
	declare row, col;
	
	for(row = 1 to 3) step 1
		for (col=1 to 4) step 1
			display "*"
		end-for	
		display newline
	end-for
End	