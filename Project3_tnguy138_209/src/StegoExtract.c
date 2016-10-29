#include <string.h>
#include "image.h"

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

void print (byte *p)
{
        int i=0;
 for (i =0; i< 8; i++)
  {
        printf("%d \n", p[i]);
        PRINTBIN(p[i]);  printf("\n");
  }
}

byte getlsbs (byte *p)
{
	byte a =0;
        byte b;
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

int main (int argc, char *argv[])
{
  int i, j, k, cover_bits, bits;
  struct Image img = {0, NULL, NULL, NULL, NULL, 0, 0};

  if (argc!= 3)
    {
        printf("\n%s <stego_file> <extracted_file> \n", argv[0]);
        exit(1);
    }

  ReadImage(argv[1], &img);  
 
// Extract b.size 
	j =0; // index of Img
	byte bsize[4];
	for (i =0; i<4;i++)
	{  bsize[i] = getlsbs(&(GetGray(j))); j+=8; }
	
	int size = 0, tmp = 0;
	for (i=0; i<4;i++)
	{ tmp = bsize[i]; tmp = tmp << (32 - 8*(i+1)); size = size | tmp; }
// Extract hidden G#
	byte gN4bits[4], gNum[8]; 

	for (i =0; i<4; i++)
	{ gN4bits[i] = getlsbs(&(GetGray(j))); j+=8;} 
	k =0; 
	for (i=0 ; i<4 ; i++)
	{ gNum[k] = gN4bits[i] >>4; 
	  gNum[k+1] = gN4bits[i] <<4;gNum[k+1]= gNum[k+1] >>4 ;
	  k+=2; }

	printf("Hidden G#:G"); 
	for (i=0; i<8;i++) { printf("%d",gNum[i]);}

// Extract b.data
	
	byte *data = (byte *)malloc(sizeof(byte)*MIN_BUFFER_SIZE);
	if (data == NULL)
	{ printf("Error calling malloc!\n"); exit(1);}
	struct Buffer b = {data, size, MIN_BUFFER_SIZE};
	
	j = 64; byte val;
	for (i = 0; i<b.size; i++)
	{ val = getlsbs((&GetGray(j))); SetByte(i,val); j+=8;} 


 WriteBinaryFile(argv[2],b); // write the extracted file   
}
