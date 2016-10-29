/*
Created by Thi Nguyen 10/6/15
Topic: Command Line Arguments, File I/O and Using Macros for Debugging
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main ( int argc, char *argv[])
{
	FILE *infile = NULL;
	FILE *outfile = NULL;
	char c; 
	
	if ( argc != 3) 
	{ printf("You have entered an invalid command line. Please try again.\n");
	  exit(1);
	}
	
	infile = fopen( argv[1], "r");
	assert (infile != NULL);
	 if (infile == NULL)
        { printf("Error opening input file.\n");
          exit(1);
        } 
	
	outfile = fopen (argv[2], "w");
	 assert (outfile!= NULL);
	 if (outfile == NULL)
        { printf("Error opening output file.\n");
         exit(1);
        } 



	
	while ((c = fgetc(infile)) != EOF)
	{
	 #ifndef NDEBUG

		printf("%c",c);
	 #endif
		fprintf ( outfile, "%c" , c);	
	}

	fclose(infile);
	fclose(outfile);
	return 0;
}

