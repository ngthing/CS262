#include <stdio.h>
#include <stdlib.h>

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

#define PRINTBIN(x) printf(BYTETOBINARYPATTERN, BYTETOBINARY(x));

void print(unsigned char *p);
void setlsbs(unsigned char *p, unsigned char b0)
{
	unsigned char a,b;
	int i;
	for (i = 0 ; i < 8 ; i++)
	{ a = b0 >> i;
	  a= a << 7; a=a>>7;
	  b=  p[i] >> 1; b = b << 1; 
	  p[i] = b | a;
	}
}

unsigned char getlsbs (unsigned char *p)
{
	unsigned char a =0;
	unsigned char b;
	int i; 
	for (i = 0; i<8; i++)
	{ 
	  b = p[i];
	  b = b<<7; b= b>>7;
	  b = b<<i;
	  a = a|b;
	}
	return a;
}	
int main(int argc, char *argv[])
{
	if (argc != 2)
	{ printf("You have entered an invalid command line. \n");
	  exit(1);
	}
	
	int seed, i; 
	unsigned char p[8];
	seed = atoi(argv[1]);
	srandom(seed);
	printf("array p\n");	
	for(i=0 ; i<8 ; i++)
	{ p[i]= (unsigned char)random()% 256;
	  printf("%d \n ", p[i]); 	
	  PRINTBIN(p[i]);
	  printf("\n");
	}

	unsigned char byte0;
	byte0 = (unsigned char)random()% 256;
	printf("byte0 is %d \n", byte0);  
        PRINTBIN(byte0);
	printf("\n\n");
	
	setlsbs(p,byte0);
	printf("After set lsbs, the modified array p is:\n");
	print(p);
	unsigned char c = getlsbs(p);
	printf("\nreturn value of getlsbs is %d  " , c);
	PRINTBIN(c);
	printf("\n");
	return 0;
}


void print (unsigned char *p)
{
	int i=0;
 for (i =0; i< 8; i++)
  {
	printf("%d \n", p[i]);
	PRINTBIN(p[i]);  printf("\n");
  }
} 
