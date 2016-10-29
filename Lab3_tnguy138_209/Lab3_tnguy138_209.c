/*
Created by Thi Nguyen 9/3/16
Topics: Branching, Loops and Functions
This program prints a menu and takes user choices as input. The user will make choices regarding different "triangles" 
that will be printed to the screen.
*/

#include <stdio.h>

void printMenu();
char promptChar();
int promptNumber();
void printTriangle1(int,char);
void printTriangle2(int,char);

main()
{
	char C =' ';
	int N =0;
	int in = 1;
	do
	{
		printMenu();
		char input;
		scanf(" %c", &input);
		printf("Your menu input is: %c\n",input);
		switch (input)
	{	case 'C': case 'c':
		    printf("Promt Character\n\n");
		    C = promptChar();
		    printf("The character you entered is:%c\n\n", C);
		    break;	
		case 'N' : case 'n':
		    printf("Promt Number\n\n");
		    N = promptNumber();
		    break;
		case '1':
		    printf("Print Triangle Type 1\n\n");
		    printTriangle1(N,C);	
		    break;
		case '2':
		    printf("Print Triangle Type 2\n\n");
		    printTriangle2(N,C);
		    break;
		case 'Q': case 'q':
		    printf("Quit the program. Goodbye!\n");
		    in = 0;
		    break;
		default: 
		    printf("Invalid input. Please try again.\n\n");
		    break;
	}
	} while(in == 1);
		    
}

void printMenu()	
{
	printf("Please select an option from the Menu Choice below:\n");
	printf("In order to \n");
	printf("Enter/Change Character, type C or c. \n");
	printf("Enter/Change Number, type N or n.\n");
	printf("Print Triangle Type 1 (Left Justified), type 1.\n");
	printf("Print Triangle Type 2 (Right Justified), type 2.\n");
	printf("Quit the program, type Q or q.\n");
}

char promptChar()
{
	char input;
	printf("Please enter a single character:\n");
	scanf(" %c", &input);
	return input;
}

int promptNumber()
{
	int validInput;
	int input;
	do
	{	
		printf("Please enter a number between 1 and 15 (inclusive):\n");
		scanf("%d",&input);
		if ( input >= 1 && input <= 15)
		{   printf("The number you entered is: %d\n\n", input);
		    validInput=1;
		}	
		else
		{   printf("Invalid number. Please try again.\n");
		    validInput =0;
		}
	}while (validInput==0);

	return input;
}	

void printTriangle2(int n, char c)
{
	int i, j;
	for (i = 1; i <= n;i++)
	{
	    for (j = 1; j <=i; j++)
		{ printf("%c",c);}
	    printf("\n");
	}
}		

void printTriangle1(int n, char c)
{
	int i, j, z;
	char blank=' ';
	for (i = 1; i <=n; i++)
	{
	    j = n- i;
	    z=i;		
	    for ( j ; j>0; j--)
	    {	 printf("%c",blank);}
	     
	      for ( z ; z>0; z--)
		 { printf("%c", c);}
  	    
	    printf("\n");
	}
} 
