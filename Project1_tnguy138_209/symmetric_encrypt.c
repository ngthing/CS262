#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main ( int argc, char *argv[])
{
        FILE *infile = NULL;
        FILE *outfile = NULL;
        char p,p1,c,c1; 
	int key;	

        if ( argc != 4) 
        { printf("You have entered an invalid command line. Please try again.\n");
          exit(1);
        }

        infile = fopen( argv[2], "r");
       
         if (infile == NULL)
        { printf("Error opening input file.\n");
          exit(1);
        } 

        outfile = fopen (argv[3], "w");
   
         if (outfile == NULL)
        { printf("Error opening output file.\n");
         exit(1);
        }
	
	key = atoi(argv[1]);
	/*printf("key = %d\n", key);*/
	
	srandom(key);	 
	int r = random()%97;
        while ((p = fgetc(infile)) != EOF)
        {
	// Change all displayable characters to range [0...96]
	 if (p == '\t')
		p1 = 0;
	 else if (p == '\n')
		p1 = 1; 
	 else p1 = p - 30;
	 c1 = p1^r;
	
	// Turn all output values into displayable characters
	 if (c1 == 0) 
		c = '\t';
	 else if (c1 == 1)
		c = '\n';
	 else 
		c = c1+30;	
        
	
	 #ifndef NDEBUG

                printf("%c",p);
         #endif
	
	  	
                fprintf ( outfile, "%c" , c);
        }

        fclose(infile);
        fclose(outfile);
        exit(0);
}

