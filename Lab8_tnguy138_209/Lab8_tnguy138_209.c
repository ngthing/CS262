// Thi Nguyen G00987452
// CS 262 Section 209 
// Lab8


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Location Location;

struct Location 
{
	char locName[35];
	char description[85];
	float  latitude;
	float longtitude;
};

int printMenu();
void addLocation(Location **array, int *currentLoc, int *numLoc);
void printLocations(Location *array, int numLoc);
void ResizeArray(Location **array,int  *currentSize);


int main()
{	
	int menuInput =0;
	int size ;
	int currentLoc =0;
	int numLoc = 0;
	printf("Please enter the number of locations.\n");
	scanf("%d", &size);
	 char newline;
        scanf("%c", &newline);

	Location *LocationArray = malloc(size*sizeof(Location));

	if ( LocationArray == NULL) // Check to see whether the memory is located 
	{	printf("Error! Insufficient memory!\n");
		exit(1);
	}
	
	do 
	{	menuInput = printMenu();
		if( menuInput == 1) // Add a location to Array
		{if(numLoc == size) // If array reachs its limit
		{ ResizeArray(&LocationArray, &size);} 
		 addLocation(&LocationArray, &currentLoc, &numLoc);}
		if (menuInput == 2) // Print the current list of locations
		{ printLocations(LocationArray, numLoc);} 
	}while (menuInput != 3);
	return 0;
}

int printMenu()
{	
	char input[25];
	char inputtoswitch;
	printf("\nPlease choose one of the options from the menu below.\n");
	printf("\n[A]dd an additional location to the LocationArray:\n Type A or a\n");
	printf("\n[P]rint the current list of locations (print all elements of each Location struct):\n");
	printf("type P or p\n");
	printf("\n[Q]uit the program: type Q or q\n");

	fgets(input, 50, stdin);
	{ int n = (strlen(input) -1);
          if(input[n] == '\n')
          { input[n] = '\0';}
        }
	
	if (strlen(input) > 1)
	{ printf("\nYou had entered an invalid input. Please try again!");
        return 4;}
	else
	 { inputtoswitch = input[0];}

	switch(inputtoswitch){
	case 'A' : case 'a': 
	printf("You chose to add an additional location to Location Array.\n");
	return 1;
	break;
	case 'P': case 'p':
	printf("\nYou chose to print the current list of locations.\n");
	return 2;
	break;
	case 'Q' : case 'q':
	printf("\nYou chose to quit the program. Thank you and goodbye!\n");
	return 3;
	break;
	default: 
	printf("\nYou had entered an invalid input. Please try again!");
	return 4;
	break;
	}
}

void ResizeArray(Location **array, int *currentSize)
{
	int oldSize = *currentSize;
	int newSize = oldSize*2; // double the current size of array
	*currentSize = newSize; // set the newSize to currentSize. Array size now is doubled

	//Create a temporary Location Array and then later copy the current LocationArray to Temp
	Location  *temp = malloc(newSize * sizeof(Location));
	
	//Check if memory is located successfully
	if (temp == NULL)
	{
	 printf("Error! Insufficient memory!\n");
	 exit(1);
	}
// Copy current LocationArray to Temp using memcpy
	memcpy (temp, *array, oldSize*sizeof(Location));
	free(*array); // free array pointer
	*array = temp; // assign the current LocationArray to the temporary one
}

void addLocation (Location **array, int *currentLoc, int *numLoc)
{
	int i = *currentLoc;
	int num = *numLoc;
	*numLoc = num +1;
	*currentLoc = i +1;
	printf("Please enter Location's Name:\n");
	fgets(((*array)[i].locName), 35, stdin);
	{ int n = (strlen((*array)[i].locName) -1);
	  if(((*array)[i].locName)[n] == '\n')
	  { ((*array)[i].locName)[n] = '\0';}
	}

	printf("Please enter Location's Description:\n");
	fgets(((*array)[i].description), 85, stdin);
        { int n = (strlen((*array)[i].description) -1);
          if(((*array)[i].description)[n] == '\n')
          { ((*array)[i].description)[n] = '\0';}
        }

	printf("Please enter Location's Latitude:\n");
	scanf("%f", &((*array)[i].latitude));
	printf("Please enter Location's Longtitude:\n");
	scanf("%f", &((*array)[i].longtitude));
	printf("\n");
}


void printLocations(Location *array, int numLoc)
{
	int i;
	for ( i = 0; i< numLoc ; i++)	
{
	printf("Location %d has \n", i+1);
	printf("Name: %s\n",array[i].locName);
	printf("Description: %s\n", array[i].description);
	printf("Latitude: %f\n", array[i].latitude);
	printf("Longtitude: %f\n", array[i].longtitude);
	printf("\n");
} 
}	

