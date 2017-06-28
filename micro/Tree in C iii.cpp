//Pattern
#include <stdio.h>
#include <conio.h>



int main()
{
    int row,col;
    for(row=1;row<=5;row++)
    {
        for(col=5;col>row;col--)
        {
          printf(" ");
        }
        for(col=1;col<=row;col++)
        {
          printf("* ");
        }
        printf("\n");
    }
    getch();
}
