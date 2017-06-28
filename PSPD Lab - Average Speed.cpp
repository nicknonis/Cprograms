#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b;
	printf ("\n\n Key in distance travelled (in meters(m))");
	scanf ("%d",&a);
	printf ("\n\n Key in time taken (in seconds (s))");
	scanf ("%d",&b);

	printf ("\n\n %d / %d  = %.3f",a,b,(float)(a/b));
	printf ("press any key to continue...");
	getch();
}
