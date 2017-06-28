#include <stdio.h>
#include <conio.h>


 void main()
{
int r,c,b;
for(r=1; r<=4; r++)
  {
	for(c=1; c<=4; c++)
	  {
		  if((c % 2) == 0)
		  {
		   printf("**\n");
		  }
		  else
			  printf("***\n");
	  }
	}
getch();
	  
}

/* FIXED */

#include <stdio.h>
#include <conio.h>


 void main()
{
int row,col,end;
for(row=1; row<=5; row++)
  {
	if(row==2 || row == 4)
		end=2;
	else
		end=3;
	for(col=1;col<=end;col++)
		printf("* ");
	printf("\n\n");
	}
	getch();
}	  


   /* Pseudo Code
 Begin
	Declare row, col, end
	for (row=1 to 5) step 1
		if(row=2 or 4)
			end=2
		else
			end=3
		end-if
		for(col=1 to end) step 1
			print "*"
		end-for

		print newline
	end-for
End
*/