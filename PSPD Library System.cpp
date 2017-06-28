#include <stdio.h>
#include<conio.h>
#include<Windows.h>
#include <string.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS


/*****************BEGIN FUNCTION PROTOTYPES**************/
void menu();
void stdrec();
void addrec();
void modrec();
void delrec();
void viewrec();

void bookrec();
void searchbook();
void add_book();
void mod_book();
void del_book();
void view_book();

void loanrec();
void addloan();
void viewloan();
void returnloan();

/*Subset Functions of Various Loan Functions */
void viewloanByTp();
void viewloanByTitle();
void viewloanByBarcode();
void viewloanAll();
int loanConfirmationAction(int stdnt, int i, int bk);
int checkReturnDate(int dayDue, int monthDue, int yearDue);

/*Date View Functions*/
int whatDayIsIt(int whatDay);
int daysInMonth(int whatMonth, int whatYear);

/*Validation Printing Purposes*/

void isThisEmpty(char* wordHolder);



/*****************END FUNCTION PROTOTYPES**************/

/*****************BEGIN GLOBALS**************/
int previousStdntRec = 0, newTotalStdntRec = 0, newStdntRec;					//Variables for addrec Students loop
int previousBookRec = 0, newTotalBookRec = 0, newBookRec;						//Variables for addrec Books loop
int previousLoanRec = 0, newTotalLoanRec = 0, newLoanRec;						//Variables for addrec Loan loop
/*****************END GLOBALS**************/



/*****************BEGIN STRUCTS**************/
struct studentInfo
{

	char name[20];
	char tpnum[20];
	char email[50];
	char addressLine1[50];
	char addressLine2[50];
	char addressLine3[50];
	int bkBorrowed;
};
struct studentInfo student[11]; //creates 11 "Student" variables of type studenInfo with the above members.

struct bookInfo
{
	char btitle[50];
	char author[50];
	char isbn[50];
	char barcode[30];
	char publisher[50];
	char publocation[50];
	char pubyear[5];
	char borrowedBy[50];
	int borrowStatus;
	int borrowDay;
	int borrowMonth;
	int borrowYear;
	int dayDue;
	int monthDue;
	int yearDue;
};
struct bookInfo book[11];//declare "book" of type bookInfo


SYSTEMTIME getTime; //struct members are predefined in SYSTEMTIME.

/*****************END STRUCTS**************/



int main()
{

	int menuChoice;
	do{
		menuChoice = 0; //resets value
		printf("\t\t\tLibrary System Main Menu"
			"\n\n\n\n1. Student records"
			"\n2. Book records"
			"\n3. Loans"
			"\n4. Exit Application\n"
			"\n\n\n\t\t\t\tEnter choice:");
		scanf("%d", &menuChoice);
		fflush(stdin);
		switch (menuChoice){
		case 1:
			system("cls");
			stdrec();
			system("cls");
			break;
		case 2:
			system("cls");
			bookrec();
			system("cls");
			break;
		case 3:
			system("cls");
			loanrec();
			system("cls");
			break;
		case 4:
			system("cls");
			printf("\n\n");
			printf("\t\t\t\tExiting...");
			Sleep(1000);
			break;
		default:
			system("cls");
			printf("No such directory!\n"
				"Press anything to return.");
			_getch();
			system("cls");
			break;
		}
	} while (menuChoice != 4);
}

//----------------------------------------------------FUNCTIONS BELOW THIS LINE--------------------------------------------------



/* Student record section*/
void stdrec()
{
	int stdmenuChoice;	//student record
	do
	{
		stdmenuChoice = 0; //resets value
		fflush(stdin);
		printf("\t\t\t\tStudent Record\n\n\n\n"
			"1. Add record\n"
			"2. Modify record\n"
			"3. Delete record\n"
			"4. View record\n"
			"5. Exit to Main Menu\n"
			"\n\n\n\t\t\t\tEnter choice:");
		scanf("%d", &stdmenuChoice);
		fflush(stdin);
		switch (stdmenuChoice)
		{
			system("cls");
		case 1:
			addrec();
			break;
		case 2:
			modrec();
			break;
		case 3:
			delrec();
			break;
		case 4:
			viewrec();
			break;
		case 5:
			printf("Returning to Main Menu......");
			Sleep(300);
			system("cls");
			break;
		default:
			system("cls");
			printf("Invalid!\n"
				"Press anything to continue.");
			stdmenuChoice = 0;
			getch();
			system("cls");
		}
	} while (stdmenuChoice != 5);
}
void addrec()
{
	int i;
	char confirm;
	printf("\n\n\n\n");
	printf("\t\t\t\tLoading...\n\n\n\n");
	Sleep(100);
	system("cls");

	do{
		printf("Enter the number of records you wish to add, or type 0 to exit\n\nNumber of New Student Records: ");
		scanf("%d", &newStdntRec);
		fflush(stdin);

		if (newStdntRec == 0)
		{
			printf("Returning to Student Menu......");
			Sleep(1000);
			system("cls");
			return;
		}

		printf("\nPotential New Records: %d\nPlease confirm number (Y/N)\n", newStdntRec);
		printf("Confirmation: ");
		confirm = getchar();
		fflush(stdin);
		system("cls");

		if (confirm == 'n' || confirm == 'N')
		{
			printf("Returning to Student Menu......");
			Sleep(1000);
			system("cls");
			return;
		}

	} while (confirm != 'y'&&confirm != 'Y');

	if (newStdntRec != 0)
	{
		newTotalStdntRec = newStdntRec + previousStdntRec;

		for (i = previousStdntRec + 1; i <= newTotalStdntRec; i++)
		{
			system("cls");

			do
			{
				printf("\nStudent name %d: \n", i);
				gets(student[i].name);
				fflush(stdin);

				isThisEmpty(student[i].name);

			} while (student[i].name[0] == '\0'); //do while first char of array is nullterminator

			do
			{
				printf("\nTP Number: \n");
				gets(student[i].tpnum);
				fflush(stdin);

				isThisEmpty(student[i].tpnum);

			} while (student[i].tpnum[0] == '\0'); ////do while first char of array is nullterminator

			printf("\nEmail: \n");
			gets(student[i].email);
			fflush(stdin);

			printf("\nStudent Address Line 1: \n");
			gets(student[i].addressLine1);
			fflush(stdin);
			printf("\nStudent Address Line 2: \n");
			gets(student[i].addressLine2);
			fflush(stdin);
			printf("\nStudent Address Line 3: \n");
			gets(student[i].addressLine3);
			fflush(stdin);

			student[i].bkBorrowed = 0;
		}

		system("cls");
		printf("\t\t\t*****  Student Details *****\n");
		for (i = previousStdntRec + 1; i <= newTotalStdntRec; i++)
		{
			printf("\n%d. Name: %s"
				"\n TP Number: %s"
				"\n Email: %s"
				"\n Student Address:\n"
				"\t\t%6s \n"
				"\t\t%6s \n"
				"\t\t%6s \n",
				i, student[i].name, student[i].tpnum, student[i].email, student[i].addressLine1, student[i].addressLine2, student[i].addressLine3);
		}

		printf("\n\n End Printing of Student Details. \nPress Any Key to Return to Student Menu.");

		previousStdntRec = i - 1; //NEW CODE HERE <<------------------------------------

		getch();
		system("cls");
	}
	else
		system("cls");
	printf("Returning to Student Menu...");
	Sleep(500);
	system("cls");
}
void modrec()
{
	int i;
	int chooserec, c2modrec;
	int modrecChoice;
	char more, newname[20], newintake[20], newemail[20], newadd1[20], newadd2[20], newadd3[20];
	system("cls");
	do
	{
		printf("\t\t\t\tModify Record\n\n"
			"\n1. Modify whole record"
			"\n2. Modify Name"
			"\n3. Modify TP Number"
			"\n4. Modify Email"
			"\n5. Modify Address 1"
			"\n6. Modify Address 2"
			"\n7. Modify Address 3"
			"\n8. Exit"
			"\n\n\n\t\t\t\t Enter choice:");
		scanf("%d", &modrecChoice);
		switch (modrecChoice)
		{
		case 1:
			system("cls");
			printf("\n Please key in the record number you wish to edit: ");
			scanf("%d", &chooserec);

			//Edit the selected record
			if (chooserec <= previousStdntRec)
			{
				system("cls");
				fflush(stdin);
				printf("\nStudent name %d: \n", chooserec);
				do
				{
					gets(student[chooserec].name);

					isThisEmpty(student[chooserec].name);

				} while (student[chooserec].name[0] == '\0'); //gets accepts space as characters too.
				fflush(stdin);

				printf("\nTP Number: \n");
				do
				{
					gets(student[chooserec].tpnum);

					isThisEmpty(student[chooserec].tpnum);

				} while (student[chooserec].tpnum[0] == '\0');
				fflush(stdin);

				printf("\nEmail: \n");
				gets(student[chooserec].email);
				fflush(stdin);

				printf("\nStudent Address Line 1: \n");
				gets(student[chooserec].addressLine1);
				fflush(stdin);
				printf("\nStudent Address Line 2: \n");
				gets(student[chooserec].addressLine2);
				fflush(stdin);
				printf("\nStudent Address Line 3: \n");
				gets(student[chooserec].addressLine3);
				fflush(stdin);

				printf("\n Press any key to continue...");
				getch();

				system("cls");
				printf("\t\t\t*****  Student Details *****\n");
				printf("\n%d. Name: %13s"
					"\n TP Number: %7s"
					"\n Email: %13s"
					"\n Student Address:\n"
					"\t\t%6s \n"
					"\t\t%6s \n"
					"\t\t%6s \n",
					chooserec, student[chooserec].name, student[chooserec].tpnum, student[chooserec].email, student[chooserec].addressLine1, student[chooserec].addressLine2, student[chooserec].addressLine3);

				printf("\n\n Press any key to continue...");
				getch();
				system("cls");

				printf("\n Would you like to edit another another record? [Y/N]");
				scanf("%c", &more); fflush(stdin);
				system("cls");

				if (more == 'y' || more == 'Y')
				{
					break;
				}
				else if (more == 'n' || more == 'N')
				{
					modrecChoice = 3;
					printf("\n Press any key to return to the student record menu.");
					getch();
					system("cls");
				}
				else
				{
					printf("Invalid Input");
					getch();
					system("cls");
				}
			}
			else
				printf("\n\n\t\t\t\tNo such record!");
			Sleep(1000);
			system("cls");
			break;

		case 2:
			system("cls");
			printf("Which record's name you wish to change?\n");
			scanf("%d", &c2modrec); fflush(stdin);
			printf("Current Record Name: %s\n", student[c2modrec].name);
			printf("Please input new name\n");
			gets(newname);
			strncpy(student[c2modrec].name, newname, 20);
			printf("\t\t\tThe name has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 3:
			system("cls");
			printf("Which record's TP Number you wish to change?\n");
			scanf("%d", &c2modrec); fflush(stdin);
			printf("Current Record TP Number: %s\n", student[c2modrec].tpnum);
			printf("Please input new TP Number\n");
			gets(newintake);
			strncpy(student[c2modrec].tpnum, newintake, 20);
			printf("\t\t\tThe intake has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 4:
			system("cls");
			printf("Which record's email you wish to change?\n");
			scanf("%d", &c2modrec); fflush(stdin);
			printf("Current Record Email: %s\n", student[c2modrec].email);
			printf("Please input new email\n");
			gets(newemail);
			strncpy(student[c2modrec].email, newemail, 50);
			printf("\t\t\tThe email has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 5:
			system("cls");
			printf("Which record's first address you wish to change?\n");
			scanf("%d", &c2modrec); fflush(stdin);
			printf("Current Record Address1: %s\n", student[c2modrec].addressLine1);
			printf("Please input new address\n");
			gets(newadd1);
			strncpy(student[c2modrec].addressLine1, newadd1, 50);
			printf("\t\t\tThe address has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 6:
			system("cls");
			printf("Which record's second address you wish to change?\n");
			scanf("%d", &c2modrec); fflush(stdin);
			printf("Current Record Address2: %s\n", student[c2modrec].addressLine2);
			printf("Please input new address\n");
			gets(newadd2);
			strncpy(student[c2modrec].addressLine2, newadd2, 50);
			printf("\t\t\tThe address has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 7:
			system("cls");
			printf("Which record's third address you wish to change?\n");
			scanf("%d", &c2modrec); fflush(stdin);
			printf("Current Record Address3: %s\n", student[c2modrec].addressLine3);
			printf("Please input new address\n");
			gets(newadd3);
			strncpy(student[c2modrec].addressLine3, newadd3, 50);
			printf("\t\t\tThe address has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;
		case 8:
			printf("Returning to Student Menu......");
			Sleep(300);
			system("cls");
			break;
		default:
			system("cls");
			printf("Invalid!\n"
				"Press anything to continue.");
			_getch();
			system("cls");
			break;
		}
	} while (modrecChoice != 8);
}
void delrec() // Fixed dat "n".
{
	int i;
	int delrecord;
	int x;
	int ctr;
	char confirm;

	system("cls");

	printf("Student Names:\n");
	for (ctr = 1; ctr <= previousStdntRec; ctr++)
	{
		printf("%d. %s\n", ctr, student[ctr].name);
	}

	printf("\nWhich record you wish to delete?\n");
	scanf("%d", &delrecord);
	fflush(stdin);
	system("cls");

	if (delrecord <= previousStdntRec)
	{
		printf("Are you sure you want to delete Record %d as shown below? Y/N \n\n", delrecord);
		printf("Name: %s\n", student[delrecord].name);
		printf("Intake: %s\n", student[delrecord].tpnum);

		scanf("%c", &confirm);
		fflush(stdin);
		system("cls");

		if (confirm == 'y' || confirm == 'Y')
		{
			for (x = delrecord; x <= previousStdntRec; x++)
			{
				strncpy(student[x].name, student[x + 1].name, 20);
				strncpy(student[x].tpnum, student[x + 1].tpnum, 20);
				strncpy(student[x].email, student[x + 1].email, 50);
				strncpy(student[x].addressLine1, student[x + 1].addressLine1, 50);
				strncpy(student[x].addressLine2, student[x + 1].addressLine2, 50);
				strncpy(student[x].addressLine3, student[x + 1].addressLine3, 50);
			}
			previousStdntRec = previousStdntRec - 1;
			printf("Record %d has been deleted. \n\n Press any key to return to Student Records.", delrecord);
			_getch();
			system("cls");
		}

		else if (confirm == 'n' || confirm == 'N')
		{
			printf("Deletion Aborted. Press any key to return to Student Records.");
			_getch();
			system("cls");
		}

		else
		{
			printf("Invalid Input! Returning to Student Records......");
			Sleep(400);
			system("cls");
		}
	}
	else
		printf("Record does not exist. \n\nReturning to Student Records......");
	Sleep(400);
	system("cls");
}
void viewrec()
{
	int i;
	int viewrecChoice;
	do{
		int sel, g;
		char cont;
		char namesearch[50], norec;


		system("cls");
		printf("\t\t\t\tView Record"
			"\n\n1. View by number"
			"\n2. View by searching name"
			"\n3. Exit"
			"\n\n\n\n\t\t\t\tEnter choice:");
		scanf("%d", &viewrecChoice); fflush(stdin);

		switch (viewrecChoice)
		{
		case 1:
			do
			{
				system("cls");
				printf("\n Please key in the record number you wish to view:");
				scanf("%d", &sel); fflush(stdin);
				system("cls");
				if (sel <= previousStdntRec)
				{
					printf("\t\t\t*****  Student Details *****\n");
					printf("\n%d. Name: %13s"
						"\n TP Number: %7s"
						"\n Email: %13s"
						"\n Student Address:\n"
						"\t\t%6s \n"
						"\t\t%6s \n"
						"\t\t%6s \n",

						sel, student[sel].name, student[sel].tpnum, student[sel].email, student[sel].addressLine1, student[sel].addressLine2, student[sel].addressLine3);
					getch();
				}
				else printf("No such record!");
				Sleep(200);
				system("cls");

				printf("Do you wish to view more records?[Y/N]\n");
				scanf("%c", &cont); fflush(stdin);
			} while (cont == 'y' || cont == 'Y');

			if (cont == 'n' || cont == 'N')
			{
				system("cls");
				viewrecChoice = 3;
				printf("\n Returning to the View menu......");
				Sleep(600);
				system("cls");
			}
			else
			{
				printf("Invalid Input, Press Any Key to Return to View menu");
				getch();
				system("cls");
			}
			break;
		case 2:
			do
			{
				int recordFound = 0;
				system("cls");

				printf("\nPlease enter name: ");
				gets(namesearch); fflush(stdin);

				for (g = 1; g <= previousStdntRec + 1; g++)
				{
					if (strcmp(namesearch, student[g].name) == 0)
					{
						recordFound = 1;
						printf("\t\t\t*****  Student Details *****\n");
						printf("\n%d. Name: %13s"
							"\n TP Number: %7s"
							"\n Email: %13s"
							"\n Student Address:\n"
							"\t\t%6s \n"
							"\t\t%6s \n"
							"\t\t%6s \n",

							g, student[g].name, student[g].tpnum, student[g].email, student[g].addressLine1, student[g].addressLine2, student[g].addressLine3);
						g = previousStdntRec + 1; //or else g<=previousStdntRec will print everything above until it reaches previousStdntRec.
					}
				}
				if (recordFound != 1)
				{
					printf("Record not Found!\n");
				}
				printf("Do you wish to view more? [Y/N]");
				scanf("%c", &cont); fflush(stdin);
				system("cls");
			} while (cont == 'y' || cont == 'Y');

			if (cont == 'n' || cont == 'N')
			{
				viewrecChoice = 3;
				printf("\n Returning to the View menu......");
				Sleep(600);
				system("cls");
			}
			else
			{
				printf("Invalid Input"
					"Returning to View menu");
				Sleep(1000);
				system("cls");
			}
			break;
		case 3:
			printf("Exiting...");
			Sleep(1000);
			system("cls");
			break;

		default:
			printf("Invalid!\n"
				"Press anything to continue.");
			_getch();
			system("cls");
		}
	} while (viewrecChoice != 3);
}


/*Book section*/
void bookrec()
{
	int bookrecChoice;
	do {
		printf("\t\t\t\tBook records\n\n\n" /* Sample */
			"1. Add record\n"
			"2. Modify record\n"
			"3. Delete record\n"
			"4. View record\n"
			"5. Exit to Main Menu\n"
			"\n\n\n\t\t\t\tEnter choice:");
		scanf("%d", &bookrecChoice);
		fflush(stdin);
		switch (bookrecChoice){
			system("cls");
		case 1:
			add_book();
			break;
		case 2:
			mod_book();
			break;
		case 3:
			del_book();
			break;
		case 4:
			view_book();
			break;
		case 5:
			printf("Exiting...");
			Sleep(300);
			system("cls");
			break;
		default:
			system("cls");
			printf("Invalid!\n"
				"Press anything to continue.");
			_getch();
			system("cls");
		}
	} while (bookrecChoice != 5);
}
void add_book()
{
	int i;
	int bookPrinted = 1;
	char confirm;
	printf("\n\n\n\n");
	printf("\t\t\t\tLoading......");
	Sleep(70);
	system("cls");

	do
	{
		printf("Enter the number of records you wish to add, or enter 0 to exit. \n\nNumber of New Book Records:");
		scanf("%d", &newBookRec); fflush(stdin);

		if (newBookRec == 0)
		{
			printf("Returning to Book Menu......");
			Sleep(1000);
			system("cls");
			return;
		}

		printf("\nPotential New Records: %d\nPlease confirm number (Y/N)\n", newBookRec);
		printf("Confirmation: ");
		confirm = getchar();
		fflush(stdin);
		system("cls");

		if (confirm == 'n' || confirm == 'N')
		{
			printf("Returning to Book Menu......");
			Sleep(1000);
			system("cls");
			return;
		}


	} while (confirm != 'y'&&confirm != 'Y');


	newTotalBookRec = newBookRec + previousBookRec;

	for (i = previousBookRec + 1; i <= newTotalBookRec; i++) //runs until a is reached, allows user to input multiple records once addrec() is accessed
	{
		system("cls");

		printf("\nBook Title %d: \n", bookPrinted);
		do
		{
			gets(book[i].btitle);

			isThisEmpty(book[i].btitle);

		} while (book[i].btitle[0] == '\0');
		fflush(stdin);

		printf("\nBarcode: \n");
		do
		{
			gets(book[i].barcode);

			isThisEmpty(book[i].barcode);

		} while (book[i].barcode[0] == '\0');

		printf("\nISBN: \n");
		gets(book[i].isbn);
		fflush(stdin);

		printf("\nAuthor: \n");
		gets(book[i].author);
		fflush(stdin);

		printf("\nPublisher: \n");
		gets(book[i].publisher);
		fflush(stdin);

		printf("\nPublished Location: \n");
		gets(book[i].publocation);
		fflush(stdin);

		printf("\nYear Published: \n");
		scanf("%s", &book[i].pubyear);
		fflush(stdin);

		book[i].borrowStatus = 0;
		bookPrinted++;
	}

	system("cls");
	printf("\t\t\t*****  Books ***** \n");
	for (i = previousBookRec + 1; i <= newTotalBookRec; i++)
		printf("\n %d.Book Title : %s"
		"\n BarCode: %s"
		"\n ISBN: %s"
		"\n Publisher: %s"
		"\n Author: %s"
		"\n Place Published: %s"
		"\n Year Published: %s \n\n\n",
		i, book[i].btitle, book[i].barcode, book[i].isbn, book[i].author, book[i].publisher, book[i].publocation, book[i].pubyear);

	printf("\n\n End Printing of Book Details. \n Press Any Key to Return to Book Menu.");

	previousBookRec = i - 1;
	getch();
	system("cls");
}
void mod_book()
{
	int i;
	int chooserec, c2modbook;
	int modbookChoice;
	char more, newname[50], newbarcode[30], newisbn[50], newauthor[50], newpublisher[50], newpubloc[50], newyrpub[5];
	system("cls");
	do
	{
		printf("\t\t\t\tModify Record\n\n"
			"\n1. Modify whole record"
			"\n2. Modify Title"
			"\n3. Modify Barcode"
			"\n4. Modify ISBN"
			"\n5. Modify Author"
			"\n6. Modify Publisher"
			"\n7. Modify Published Location"
			"\n8. Modify Year Published"
			"\n9. Exit"
			"\n\n\n\t\t\t\t Enter choice:");
		scanf("%d", &modbookChoice);
		switch (modbookChoice)
		{
		case 1:
			system("cls");
			printf("\n Please key in the record number you wish to edit: ");
			scanf("%d", &chooserec);
			if (chooserec <= previousBookRec)
			{
				system("cls");
				fflush(stdin);
				printf("\nTitle %d: \n", chooserec);
				do
				{
					gets(book[chooserec].btitle);
					isThisEmpty(book[chooserec].btitle);

				} while (book[chooserec].btitle[0] == '\0'); //gets accepts space as characters too.
				fflush(stdin);

				printf("\nBarcode: \n");
				do
				{
					gets(book[chooserec].barcode);
					isThisEmpty(book[chooserec].barcode);

				} while (book[chooserec].barcode[0] == '\0');
				fflush(stdin);

				printf("\nISBN: \n");
				gets(book[chooserec].isbn);
				fflush(stdin);

				printf("\nAuthor: \n");
				gets(book[chooserec].author);
				fflush(stdin);

				printf("\nPublisher: \n");
				gets(book[chooserec].publisher);
				fflush(stdin);

				printf("\nPlace Published: \n");
				gets(book[chooserec].publocation);
				fflush(stdin);

				printf("\nYear Published: \n");
				gets(book[chooserec].pubyear);
				fflush(stdin);

				printf("\n Press any key to continue...");
				getch();

				system("cls");
				printf("\t\t\t*****  Book Details *****\n");
				printf("\n%d.Title: %s"
					"\n Barcode: %s"
					"\n ISBN: %s\n"
					"\n Author: %s\n"
					"\n Publisher: %s\n"
					"\n Published Location: %s\n"
					"\n Year Published: %s \n",
					chooserec, book[chooserec].btitle, book[chooserec].barcode, book[chooserec].isbn, book[chooserec].author, book[chooserec].publisher, book[chooserec].publocation, book[chooserec].pubyear);

				printf("\n\n Press any key to continue...");
				getch();

				printf("\n Would you like to edit another another record? [Y/N]");
				scanf("%c", &more); fflush(stdin);
				system("cls");

				if (more == 'y' || more == 'Y')
				{
					break;
				}
				else if (more == 'n' || more == 'N')
				{
					modbookChoice = 3;
					printf("\n Press any key to return to the book record menu.");
					getch();
					system("cls");
				}
				else
				{
					printf("Invalid Input");
					getch();
					system("cls");
				}
			}
			else
				printf("\n\n\t\t\t\tNo such record!");
			Sleep(1000);
			system("cls");
			break;
		case 2:
			system("cls");
			printf("Which book's title you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new Title\n");
			gets(newname);
			strncpy(book[c2modbook].btitle, newname, 50);
			printf("\t\t\tThe name has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 3:
			system("cls");
			printf("Which book's Barcode you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new Barcode\n");
			gets(newbarcode);
			strncpy(book[c2modbook].barcode, newbarcode, 30);
			printf("\t\t\tThe barcode has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 4:
			system("cls");
			printf("Which book's ISBN you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new ISBN\n");
			gets(newisbn);
			strncpy(book[c2modbook].isbn, newisbn, 50);
			printf("\t\t\tThe book's ISBN has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 5:
			system("cls");
			printf("Which book's author you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new Author\n");
			gets(newauthor);
			strncpy(book[c2modbook].author, newauthor, 50);
			printf("\t\t\tThe book's author has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 6:
			system("cls");
			printf("Which book's publisher you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new Publisher\n");
			gets(newpublisher);
			strncpy(book[c2modbook].publisher, newpublisher, 50);
			printf("\t\t\tThe book's publisher has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 7:
			system("cls");
			printf("Which book's published location you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new published location\n");
			gets(newpubloc);
			strncpy(book[c2modbook].publocation, newpubloc, 50);
			printf("\t\t\tThe book's published location has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;

		case 8:
			system("cls");
			printf("Which book's publication year you wish to change?\n");
			scanf("%d", &c2modbook); fflush(stdin);
			printf("Please input new publication year\n");
			gets(newyrpub);
			strncpy(book[c2modbook].pubyear, newyrpub, 5);
			printf("\t\t\tThe book's publication year has been modified\n."
				"\t\t\t\tReturning to menu");
			Sleep(1000);
			system("cls");
			break;
		case 9:
			printf("Returning to Book Menu......");
			Sleep(300);
			system("cls");
			break;
		default:
			system("cls");
			printf("Invalid!\n"
				"Press anything to continue.");
			_getch();
			system("cls");
			break;
		}
	} while (modbookChoice != 9);
}
void del_book()
{
	int i;
	int delrecord;
	int x;
	int ctr;
	char confirm;

	system("cls");

	printf("Book Titles\n");
	for (ctr = 1; ctr <= previousBookRec; ctr++)
	{
		printf("%d. %s\n", ctr, book[ctr].btitle);
	}

	printf("\nWhich record you wish to delete?\n");
	scanf("%d", &delrecord);
	fflush(stdin);
	system("cls");
	if (delrecord <= previousBookRec)
	{
		printf("Are you sure you want to delete Record %d as shown below? Y/N \n", delrecord);
		printf("\nBook Title: %s", book[delrecord].btitle);
		printf("\nBarcode: %s\n", book[delrecord].barcode);

		scanf("%c", &confirm);
		fflush(stdin);
		system("cls");

		if (confirm == 'y' || confirm == 'Y')
		{
			for (x = delrecord; x <= previousBookRec; x++)
			{
				strncpy(book[x].btitle, book[x + 1].btitle, 50);
				strncpy(book[x].barcode, book[x + 1].barcode, 30);
				strncpy(book[x].isbn, book[x + 1].isbn, 50);
				strncpy(book[x].author, book[x + 1].author, 50);
				strncpy(book[x].publisher, book[x + 1].publisher, 50);
				strncpy(book[x].publocation, book[x + 1].publocation, 50);
				strncpy(book[x].pubyear, book[x + 1].pubyear, 5);

			}

			printf("Record %d has been deleted. \n\n Press any key to return to Book Records.", delrecord);
			previousBookRec = previousBookRec - 1;
			_getch();
			system("cls");
		}
		else if (confirm == 'n' || confirm == 'N')
		{
			printf("Deletion Aborted. Press any key to return to Book Records.");
			_getch();
			system("cls");
		}
		else
		{
			printf("Invalid Input! Returning to Book Records......");
			Sleep(400);
			system("cls");
		}
	}
	else
		printf("Record does not exist. \n\nReturning to Book Records......");
	Sleep(400);
	system("cls");
}
void view_book()
{
	int i;
	int viewrecChoice;
	do{
		int sel, g;
		char cont;
		char namesearch[50], norec, isbnsearch[20];

		system("cls");
		printf("\t\t\t\tView Record"
			"\n\n1. View by number"
			"\n2. View by searching name"
			"\n3. View by searching Barcode"
			"\n4. Exit"
			"\n\n\n\n\t\t\t\tEnter choice:");
		scanf("%d", &viewrecChoice); fflush(stdin);

		switch (viewrecChoice)
		{
		case 1:
			do
			{
				system("cls");
				printf("\n Please key in the record number you wish to view:");
				scanf("%d", &sel); fflush(stdin);
				system("cls");
				if (sel <= previousBookRec)
				{
					printf("\t\t\t*****  Books ***** \n");
					printf("\n %d.Book Title : %s"
						"\n BarCode: %s"
						"\n ISBN: %s"
						"\n Publisher: %s"
						"\n Author: %s"
						"\n Place Published: %s"
						"\n Year Published: %s \n\n\n",
						sel, book[sel].btitle, book[sel].barcode, book[sel].isbn, book[sel].author, book[sel].publisher, book[sel].publocation, book[sel].pubyear);
					getch();
				}
				else printf("No such record! ");
				Sleep(200);
				system("cls");

				printf("Do you wish to view more records?[Y/N]\n");
				scanf("%c", &cont); fflush(stdin);
			} while (cont == 'y' || cont == 'Y');
			if (cont == 'n' || cont == 'N')
			{
				system("cls");
				viewrecChoice = 3;
				printf("\n Press any key to return to the book record menu.");
				getch();
				system("cls");
			}
			else
			{
				printf("Invalid Input, Returning to View menu");
				getch();
				system("cls");
			}
			break;

		case 2:
			do
			{
				int bookFound = 0;
				system("cls");
				printf("\nPlease enter Book Title: ");
				gets(namesearch); fflush(stdin);
				for (g = 1; g <= previousBookRec; g++)
				{
					if (strcmp(namesearch, book[g].btitle) == 0)
					{
						bookFound = 1;
						printf("\n %d.Book Title : %s"
							"\n BarCode: %s"
							"\n ISBN: %s"
							"\n Publisher: %s"
							"\n Author: %s"
							"\n Place Published: %s"
							"\n Year Published: %s \n\n\n",

							g, book[g].btitle, book[g].barcode, book[g].isbn, book[g].author, book[g].publisher, book[g].publocation, book[g].pubyear);
					}
				}

				if (bookFound != 1)
				{
					printf("Book Record not Found.\n\n");
				}

				printf("Do you wish to view another book? [Y/N]");
				scanf("%c", &cont); fflush(stdin);
				system("cls");
			} while (cont == 'y' || cont == 'Y');

			if (cont == 'n' || cont == 'N')
			{
				viewrecChoice = 3;
				printf("\n Press any key to return to the book record menu.");
				getch();
				system("cls");
			}
			else
			{
				printf("Invalid Input\n"
					"Returning to View menu");
				getch();
				system("cls");
			}
			break;

		case 3:
			do
			{
				int bookFound = 0;
				system("cls");
				printf("\nPlease enter Book Barcode: ");
				gets(isbnsearch); fflush(stdin);
				for (g = 1; g <= previousBookRec; g++)
				{
					if (strcmp(isbnsearch, book[g].barcode) == 0)
					{
						bookFound = 1;
						printf("\n %d.Book Title : %s"
							"\n BarCode: %s"
							"\n ISBN: %s"
							"\n Publisher: %s"
							"\n Author: %s"
							"\n Place Published: %s"
							"\n Year Published: %s \n\n\n",

							g, book[g].btitle, book[g].barcode, book[g].isbn, book[g].author, book[g].publisher, book[g].publocation, book[g].pubyear);
					}
				}

				if (bookFound != 1)
				{
					printf("Book Record not Found.\n\n");
				}

				printf("Do you wish to view another book? [Y/N]");
				scanf("%c", &cont); fflush(stdin);
				system("cls");
			} while (cont == 'y' || cont == 'Y');

			if (cont == 'n' || cont == 'N')
			{
				viewrecChoice = 3;
				printf("\n Press any key to return to the book record menu.");
				getch();
				system("cls");
			}
			else
			{
				printf("Invalid Input\n"
					"Returning to View menu");
				getch();
				system("cls");
			}
			break;
		case 4:
			printf("Exiting...");
			Sleep(300);
			system("cls");
			break;

		default:
			printf("Invalid!\n"
				"Press anything to continue.");
			getch();
			system("cls");
		}
	} while (viewrecChoice != 4);
}

/* Loan section*/
void loanrec()
{
	int loanrecChoice;				//loan section
	do{
		printf("\t\t\t\tLoan records\n\n\n"
			"1. Add record\n"
			"2. View record\n"
			"3. Return Book\n"
			"4. Exit to Main Menu\n"
			"\n\n\n\t\t\t\tEnter choice:");
		scanf("%d", &loanrecChoice);
		switch (loanrecChoice){
			system("cls");
		case 1:
			addloan();
			break;
		case 2:
			viewloan();
			break;
		case 3:
			returnloan();
			break;
		case 4:
			printf("Exiting...");
			Sleep(300);
			system("cls");
			break;
		default:
			system("cls");
			printf("Invalid!\n"
				"Press anything to continue.");
			_getch();
			system("cls");
		}
	} while (loanrecChoice != 4);
}
void addloan()
{
	fflush(stdin);
	char stdntTp[50];
	char borrowbarcode[50];
	int bk;
	int stdnt;
	int i;
	int nameFound = 0;
	int bookFound = 0;

	system("cls");

	printf("\n\n\n\n");
	printf("\t\t\t\tLoading...\n\n\n\n");
	Sleep(100);
	system("cls");

	printf("Please enter student TP Number: ");
	do
	{
		gets(stdntTp);
	} while (stdntTp[0] == '\0');

	fflush(stdin);


	for (stdnt = 1; stdnt <= previousStdntRec + 1; stdnt++)
	{
		if (strcmp(stdntTp, student[stdnt].tpnum) == 0)
		{
			nameFound = 1;
			system("cls");
			printf(" Student Name: %s\n Student TP: %s\n This student has borrowed a total of %d book(s). \n\n Press Any Key to Continue."
				, student[stdnt].name, student[stdnt].tpnum, student[stdnt].bkBorrowed);
			getch();

			system("cls");

			printf("\nEnter Book Barcode: ");
			do
			{
				gets(borrowbarcode);
			} while (borrowbarcode[0] == '\0');
			fflush(stdin);
			system("cls");

			for (bk = 1; bk <= previousBookRec + 1; bk++)
			{
				if (strcmp(borrowbarcode, book[bk].barcode) == 0)
				{
					bookFound = 1;
					if (book[bk].borrowStatus != 1)
					{
						newTotalLoanRec = 1 + previousLoanRec;
						//ONCE BORROWSTATUS CHECK PASSES LOAN MUST OCCUR OR ERRORS IN NEXT ITERATION
						//DUE TO newTotalLoanRec = 1 + previousLoanRec;. TAKE INTO ACCOUNT WHEN ADDING Y\N OPTIONS
						for (i = previousLoanRec + 1; i <= newTotalLoanRec; i++)
						{
							GetSystemTime(&getTime);

							printf("Current Date (DD/MM/YYYY): %d-%d-%d, ", getTime.wDay, getTime.wMonth, getTime.wYear);

							whatDayIsIt(getTime.wDayOfWeek); //function prints day Eg: Monday, Tuesday, etc.
							printf("\n Student: %s\n", student[stdnt].name);
							printf(" TP Number: %s\n\n", student[stdnt].tpnum);
							printf(" Book Title: %s\n", book[bk].btitle);
							printf(" Barcode: %s\n\n", book[bk].barcode);
							printf(" This Book is available.\n");

							loanConfirmationAction(stdnt, i, bk); //performs scanf for Y/N and changes records accordingly
						}
					}
					else
					{
						printf("This Book is already borrowed. \nPress any key to return to Book Menu.");
						getch();
						system("cls");
					}

					break; //stops the (g = 1; g <= previousBookRec + 1; g++) loop.
				}
			}


			break; // stops (i = 1; i <= previousStdntRec + 1; i++)	
		}
	}
	if (nameFound != 1)
	{
		printf("Student Record Not Found!\nPress Any Key to Return to Loan Menu.");
		getch();
	}
	if (nameFound == 1 && bookFound != 1)
	{
		printf("Book Record Not Found!\nPress Any Key to Return to Loan Menu.");
		getch();
	}

	system("cls");
}
void viewloan()
{
	system("cls");
	int choice;

	do {
		printf("\t\t\t*****  View Loan Menu ***** \n\n\n");
		printf("1. Enter TP Number to Search\n"
			"2. Enter Book Title to Search\n"
			"3. Enter Barcode to Search\n"
			"4. Print All Existing Loans\n"
			"5. Exit to  Loan Menu.\n\n");

		printf("Enter Choice: ");
		scanf("%d", &choice);
		fflush(stdin);

		switch (choice)
		{
		case 1:
			viewloanByTp();
			break;

		case 2:
			viewloanByTitle();
			break;

		case 3:
			viewloanByBarcode();
			break;

		case 4:
			viewloanAll();
			break;
		case 5:
			system("cls");
			printf("Exiting to Loan Menu......");
			Sleep(500);
			system("cls");
			break;

		default:
			system("cls");
			printf("Invalid Input! Press Any Key to Continue......");
			getch();
			system("cls");
			break;
		}
		break;
	} while (choice != 4);
}
void returnloan()
{
	int i;
	char barcode[50];
	int x;
	char confirm;

	int barcodeFound;

	fflush(stdin);
	system("cls");
	printf("Enter Book Barcode to return book. \n");
	do
	{
		gets(barcode);
	} while (barcode[0] == '\0');
	fflush(stdin);
	system("cls");

	for (i = 1; i <= previousBookRec; i++)
	{
		if (strcmp(book[i].barcode, barcode) == 0)// i reflects correct book number after match found
		{
			barcodeFound = 1;
			GetSystemTime(&getTime);

			printf("\t\t\t*****  Book Details *****\n");
			printf("\n%d. Book Title: %s"
				"\n Book Author: %s"
				"\n\n Borrower TP: %s\n",
				i, book[i].btitle, book[i].author, book[i].borrowedBy);
			printf(" Borrow Date: %d-%d-%d\n", book[i].borrowDay, book[i].borrowMonth, book[i].borrowYear);
			printf(" Date Due: %d-%d-%d\n", book[i].dayDue, book[i].monthDue, book[i].yearDue);
			printf(" Today's Date: %d-%d-%d\n\n", getTime.wDay, getTime.wMonth, getTime.wYear);

			if (getTime.wDay>book[i].dayDue)
			{
				if (getTime.wMonth >= book[i].monthDue)
				{
					printf(" This Book is Overdue. \n\n");
				}
			}

			for (x = 1; x <= previousStdntRec; x++)
			{
				if (strcmp(book[i].borrowedBy, student[x].tpnum) == 0) //x reflects correct student record number on match found
				{
					printf(" Borrower Name: %s\n", student[x].name);
					break;
				}
			}
			break;
		}


	}

	if (barcodeFound == 1)
	{
		printf(" Confirm Book Check In (Y/N): ");
		scanf("%c", &confirm);
		fflush(stdin);
		system("cls");

		if (confirm == 'y' || confirm == 'Y')
		{
			GetSystemTime(&getTime);

			checkReturnDate(book[i].dayDue, book[i].monthDue, book[i].yearDue);

			book[i].borrowStatus = 0;

			strncpy(book[i].borrowedBy, book[0].borrowedBy, 50);
			book[i].borrowDay = book[0].borrowDay;
			book[i].borrowMonth = book[0].borrowMonth;
			book[i].borrowYear = book[0].borrowYear;
			student[x].bkBorrowed = student[x].bkBorrowed - 1;

			printf("Book Title: %s", book[i].btitle);
			printf("\nThe above book has been returned. \n\n"
				"Student Name: %s\n"
				"Books On Loan: %d\n"
				"\n\nPress any key to return to Loan Menu.", student[x].name, student[x].bkBorrowed);
			getch();
			system("cls");
		}
		else if (confirm == 'n' || confirm == 'N')
		{
			system("cls");
			printf("Return Aborted. Press any key to return to Loans.");
			_getch();
			system("cls");
		}
		else
		{
			printf("Invalid Input! Returning to Loans......");
			Sleep(400);
			system("cls");
		}
	}

	if (barcodeFound != 1)
	{
		printf("Record not Found!\n");
		printf("Press Any Key to Continue...\n");
		getch();
		system("cls");
	}
}
void viewloanByTp(){
	int g;
	int bkSearch;
	char tpsearch[20];
	int cont;
	int bookPrinted = 1; //used for %d.Book Title: LoremIpsum
	int  tpFound;

	fflush(stdin);
	system("cls");
	printf("\nPlease enter TP number: ");
	do
	{
		gets(tpsearch);
	} while (tpsearch[0] == '\0'); fflush(stdin);
	system("cls");

	for (g = 1; g <= previousStdntRec; g++)
	{
		if (strcmp(tpsearch, student[g].tpnum) == 0) //compare entered TP with student TP record, g will reflect correct student record on found
		{
			tpFound = 1;
			printf("\t\t\t*****  Basic Student Info ***** \n");
			printf("\n Student Name : %s\n"
				" TP Number: %s\n\n",
				student[g].name, student[g].tpnum);

			printf("\t\t\t*****  Books Borrowed ***** \n");

			for (bkSearch = 1; bkSearch <= previousBookRec; bkSearch++)
			{
				if (strcmp(student[g].tpnum, book[bkSearch].borrowedBy) == 0)
				{
					printf("%d. Book Title: %s\n"
						" Book Barcode: %s\n",
						bookPrinted, book[bkSearch].btitle, book[bkSearch].barcode);// bksearch will reflect correct bookrecord on found

					printf(" Borrow Date: %d-%d-%d\n", book[bkSearch].borrowDay, book[bkSearch].borrowMonth, book[bkSearch].borrowYear);
					printf(" Date Due: %d-%d-%d\n\n", book[bkSearch].dayDue, book[bkSearch].monthDue, book[bkSearch].yearDue);

					bookPrinted = bookPrinted + 1;
				}
			}

			printf("\n\n\n End of Record Printing. \n Press Any Key to Return to View Loan Menu.");
			getch();
			bookPrinted = 1; //resets value to 1 for next print run
			break; //breakout of g<=previousStdntRec loop since match has been found and printed
		}
	}

	if (tpFound != 1)
	{
		printf("Record not found!\n Press Any Key to Continue...");
		getch();
	}
	system("cls");
	printf("Returning to View Loan Menu......");
	Sleep(500);
	system("cls");
}
void viewloanByBarcode()
{
	system("cls");
	int g;
	int stdSearch;
	char barsearch[20];
	int barcodeFound;

	fflush(stdin);
	system("cls");
	printf("\nPlease enter Book Barcode: ");
	gets(barsearch); fflush(stdin);
	system("cls");

	fflush(stdin);
	for (g = 1; g <= previousBookRec; g++)
	{
		if (strcmp(barsearch, book[g].barcode) == 0) //compare entered barcode with book barcode, g will reflect correct book record on match found
		{
			barcodeFound = 1;
			if (book[g].borrowStatus == 1)
			{
				for (stdSearch = 0; stdSearch <= previousStdntRec; stdSearch++)
				{
					if (strcmp(student[stdSearch].tpnum, book[g].borrowedBy) == 0)// stdSearch will reflect correct studentrecord on match found
					{
						printf("\n Book Title : %s\n"
							"\n Borrower: %s\n"
							"\n Borrower TP Number: %s\n",
							book[g].btitle, student[stdSearch].name, book[g].borrowedBy);
						printf(" Borrow Date: %d-%d-%d\n", book[g].borrowDay, book[g].borrowMonth, book[g].borrowYear);
						printf(" Date Due: %d-%d-%d\n\n", book[g].dayDue, book[g].monthDue, book[g].yearDue);

						printf(" This Book is currently on Loan.");
						break;
					}
				}

				printf("\n\n\n End of Record Printing. \n Press Any Key to Return to View Loan Menu.");
				getch();
				break;
			}
			else
			{
				printf("Book Title: %s\n"
					"Status: Available\n"
					"Press Any key to Return to View Loan Menu.", book[g].btitle);
				getch();
				break;
			}
		}
	}

	if (barcodeFound != 1)
	{
		printf("Record not found!\n Press Any Key to Continue...");
		getch();
	}
	system("cls");
	printf("Returning to View Loan Menu......");
	Sleep(1000);
	system("cls");
}
void viewloanByTitle()
{
	system("cls");
	int g;
	int stdSearch;
	char btitlesearch[20];
	int titleFound;

	fflush(stdin);
	system("cls");
	printf("\nPlease enter Book Title: ");
	do
	{
		gets(btitlesearch);
	} while (btitlesearch[0] == '\0'); fflush(stdin);
	system("cls");

	fflush(stdin);
	for (g = 1; g <= previousBookRec; g++)
	{
		if (strcmp(btitlesearch, book[g].btitle) == 0) //compare entered barcode with book barcode, g will reflect correct book record on match found
		{
			titleFound = 1;
			if (book[g].borrowStatus == 1)
			{
				for (stdSearch = 0; stdSearch <= previousStdntRec; stdSearch++)
				{
					if (strcmp(student[stdSearch].tpnum, book[g].borrowedBy) == 0)// stdSearch will reflect correct studentrecord on match found
					{
						printf("\n Book Title : %s\n"
							"\n Borrower: %s\n"
							"\n Borrower TP Number: %s\n",
							book[g].btitle, student[stdSearch].name, student[stdSearch].tpnum);
						printf(" Borrow Date: %d-%d-%d\n", book[g].borrowDay, book[g].borrowMonth, book[g].borrowYear);
						printf(" Date Due: %d-%d-%d\n\n", book[g].dayDue, book[g].monthDue, book[g].yearDue);

						printf(" This Book is currently on Loan.");
						break;
					}
				}

				printf("\n\n\n End of Record Printing. \n Press Any Key to Return to View Loan Menu.");
				getch();
				break;
			}
			else
			{
				printf("Book Title: %s\n"
					"Status: Available\n"
					"Press Any key to Return to View Loan Menu.", book[g].btitle);
				getch();
				break;
			}
		}
	}

	if (titleFound != 1)
	{
		printf("Record not found!\n Press Any Key to Continue...");
		getch();
	}

	system("cls");
	printf("Returning to View Loan Menu......");
	Sleep(500);
	system("cls");
}
void viewloanAll(){
	int booksPrinted = 1;
	int x;
	int y;

	system("cls");
	printf("\t\t\t*****  Loan Summary ***** \n");
	for (x = 1; x <= previousBookRec; x++)
	{
		if (book[x].borrowStatus == 1)
		{
			printf("%d. Book Title: %s"
				"\tBook Barcode: %s", booksPrinted, book[x].btitle, book[x].barcode);
			for (y = 1; y <= previousStdntRec; y++)
				if (strcmp(book[x].borrowedBy, student[y].tpnum) == 0)
				{
				printf("\tBorrower: %s\n"
					"\tBorrower TP Number: %s\n", student[y].name, student[y].tpnum);
				printf(" Borrow Date: %d-%d-%d\n", book[x].borrowDay, book[x].borrowMonth, book[x].borrowYear);
				printf(" Date Due: %d-%d-%d\n\n", book[x].dayDue, book[x].monthDue, book[x].yearDue);
				}
			booksPrinted++;

		}
	}

	printf("\n\n\n End of Record Printing. \n Press Any Key to Return to View Loan Menu.");
	getch();
	system("cls");
}
int loanConfirmationAction(int stdnt, int i, int bk)
{
	int dayHolder;
	char confirm;

	printf("\nAre you sure you want to borrow this book? (Y/N) \n\n"
		" Choice: ");
	scanf("%c", &confirm);
	fflush(stdin);

	if (confirm == 'Y' || confirm == 'y')
	{
		system("cls");

		GetSystemTime(&getTime);

		dayHolder = daysInMonth(getTime.wMonth, getTime.wYear);//checks for number of days in month and returns it

		book[bk].borrowDay = getTime.wDay;
		book[bk].borrowMonth = getTime.wMonth;
		book[bk].borrowYear = getTime.wYear;

		book[bk].dayDue = getTime.wDay + 6; //Assumes 7 days of loan, starting from day borrowed
		book[bk].monthDue = getTime.wMonth;
		book[bk].yearDue = getTime.wYear; //Leap Year Accounted For, February accounted for

		if (book[bk].dayDue > dayHolder)
		{
			book[bk].dayDue = book[bk].dayDue - dayHolder;
			book[bk].monthDue = book[bk].monthDue + 1;
		}

		book[bk].borrowStatus = 1;
		student[stdnt].bkBorrowed = student[stdnt].bkBorrowed + 1;
		strncpy(book[bk].borrowedBy, student[stdnt].tpnum, 20);//accessed by returnLoan function.

		printf(" Book Title: %s\n", book[bk].btitle);
		printf(" Borrowed By: %s\n", student[stdnt].name);
		printf(" Borrower TP: %s\n", student[stdnt].tpnum);
		printf(" Borrow Date: %d-%d-%d\n", book[bk].borrowDay, book[bk].borrowMonth, book[bk].borrowYear);
		printf(" Date Due: %d-%d-%d\n", book[bk].dayDue, book[bk].monthDue, book[bk].yearDue);
		printf(" Book Status: Borrowed\n\n");
		printf(" \t\t\t***** Process Complete. *****\n\nPress Any Key to Continue to Loan Summary.");
		getch();

		system("cls");
		printf("\t\t\t*****  Loan Summary ***** \n");
		for (i = previousLoanRec + 1; i <= newTotalLoanRec; i++)
			printf("\n Student Name : %s\n"
			"\n TP Number: %s\n"
			"\n Book Title: %s\n"
			"\n Book Barcode: %s\n",
			student[stdnt].name, student[stdnt].tpnum, book[bk].btitle, book[bk].barcode);
		printf("\n Borrow Date: %d-%d-%d\n", book[bk].borrowDay, book[bk].borrowMonth, book[bk].borrowYear);
		printf(" Date Due: %d-%d-%d\n", book[bk].dayDue, book[bk].monthDue, book[bk].yearDue);

		printf("\n\nEnd of Loan Record Printing. \nPress Any Key to Return to Loan Menu.");

		previousLoanRec = i - 1;
		getch();
		system("cls");
	}
	else if (confirm == 'N' || confirm == 'n')
	{
		system("cls");
		newTotalLoanRec = previousLoanRec - 1; //reversal for newTotalLoanRec = 1 + previousLoanRec
		printf("Borrow Process Aborted. \nPress Any key to return to Book Menu.");
		getch();
		system("cls");
	}
	else
	{
		newTotalLoanRec = previousLoanRec - 1; //reversal for newTotalLoanRec = 1 + previousLoanRec
		printf("Invalid Input. Returning to Book Menu...");
		Sleep(1000);
		system("cls");
	}

	return 0;
}
int checkReturnDate(int dayDue, int monthDue, int yearDue)
{
	int daysLate = 0;
	int dayHolder = 0;
	int monthSub = 0;
	char confirm;
	fflush(stdin);

	GetSystemTime(&getTime);
	if (getTime.wMonth < monthDue)
	{
		printf("This Book is returned on time.\n");
		printf("Date Due: %d-%d-%d\n", dayDue, monthDue, yearDue);
		printf("Actual Return Date: %d-%d-%d\n", getTime.wDay, getTime.wMonth, getTime.wYear);
		printf("\t\t\tPress Any Key to Continue.\n\n");
		getch();
		system("cls");
	}

	if (getTime.wMonth == monthDue)
	{
		daysLate = getTime.wDay - dayDue;
		if (daysLate <= 0)
		{
			printf("This Book is returned on time.\n");
			printf("Date Due: %d-%d-%d\n", dayDue, monthDue, yearDue);
			printf("Actual Return Date: %d-%d-%d\n", getTime.wDay, getTime.wMonth, getTime.wYear);
			printf("\t\t\tPress Any Key to Continue.\n\n");
			getch();
			system("cls");
		}
		else
		{
			printf("\t\t\tWarning: This Book is overdue.\n");
			printf("\t\t\tPress Any Key to Continue.\n\n");
			getch();
			system("cls");

			printf("\t\t\t*****  OVERDUE BOOK *****\n\n");
			printf("Date Due: %d-%d-%d\n", dayDue, monthDue, yearDue);
			printf("Actual Return Date: %d-%d-%d\n", getTime.wDay, getTime.wMonth, getTime.wYear);
			printf("Days Late: %d\n\n", daysLate);

			//bookmark
			printf("Please Enter 'Y' or 'y' to confirm you have read this message.\nThis is to confirm proper action for an overdue book.\n\n");
			do
			{
				confirm = getchar();
				getchar();
				fflush(stdin);
				system("cls");

			} while (confirm != 'y' && confirm != 'Y');

			fflush(stdin);
			system("cls");

			printf("Confirmation performed Successfully.\n");
			printf("Press Any Key to Continue.\n");
			getch();
			system("cls");
		}
	}
	if (getTime.wMonth > monthDue)
	{
		printf("\t\t\tWarning: This Book is overdue.\n");
		printf("\t\t\tPress Any Key to Continue.\n\n");
		getch();
		system("cls");

		dayHolder = daysInMonth(monthDue, yearDue);//snags totalDays value from daysInMonth function THIS IS FOR THE ORIGINAL MONTH

		daysLate = dayHolder - dayDue;//Total Days in month - Supposed Return Date

		daysLate = daysLate + getTime.wDay;//number of days into late month

		monthSub = getTime.wMonth;

		monthSub = monthSub - 1;

		do
		{
			if (monthSub != monthDue)
			{
				dayHolder = daysInMonth(monthSub, getTime.wYear);
				daysLate = daysLate + dayHolder;

				monthSub = monthSub - 1;
			}

			if (monthSub == monthDue)
			{
				printf("\t\t\t*****  OVERDUE BOOK *****\n\n");
				printf("Date Due: %d-%d-%d\n", dayDue, monthDue, yearDue);
				printf("Actual Return Date: %d-%d-%d\n", getTime.wDay, getTime.wMonth, getTime.wYear);
				printf("Days Late: %d\n\n", daysLate);

				//bookmark

				printf("Please Enter 'Y' or 'y' to confirm you have read this message and taken the necessary actions for an overdue book.\n\n");
				do
				{
					confirm = getchar();
					fflush(stdin);
					system("cls");
				} while (confirm != 'y' && confirm != 'Y');

				fflush(stdin);
				system("cls");

				printf("Confirmation performed Successfully.\n");
				printf("Press Any Key to Continue.");
				getch();
				system("cls");

				break;
			}

		} while (monthSub != monthDue);

	}
	return 0;//bookmark any values needed?

	//MAJOR ASSUMPTIONS: NO CROSS YEAR BORROWING (pls no)

	//System Borrowing Time is dependent upon accuracy of computer used for the operation.
}

/*Date Functions*/
int whatDayIsIt(int whatDay){
	switch (whatDay)
	{
	case 1:
		printf("Monday\n");
		break;
	case 2:
		printf("Tuesday\n");
		break;
	case 3:
		printf("Wednesday\n");
		break;
	case 4:
		printf("Thursday\n");
		break;
	case 5:
		printf("Friday\n");
		break;
	case 6:
		printf("Saturday\n");
		break;
	case 7:
		printf("Sunday\n");
		break;
	}

	return 0;
}
int daysInMonth(int month, int year){
	int totalDays = 0;
	int x;

	int bigMonth[] = { 1, 3, 5, 7, 8, 10, 12 };
	int smallMonth[] = { 4, 6, 7, 9, 11 };
	int feb = 2;


	for (x = 0; x < 6; x++)
	{
		if (month == bigMonth[x])
		{
			totalDays = 31;
			break;
		}
		if (month == smallMonth[x])
		{
			totalDays = 30;
			break;
		}
		if (month == feb)
		{
			if (year / 4 != 0)
			{
				totalDays = 28;
			}
			else
			{
				totalDays = 29;
			}
		}
	}

	return totalDays;
}

/*Validation Print Functions*/

void isThisEmpty(char* wordHolder)
{
	if (wordHolder[0] == '\0')
	{
		system("cls");
		printf("This field cannot be empty!\n");
		Sleep(2000);
		system("cls");
	}
}