/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*
 * Stego.c : A program or manipulating images
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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

void setlsbs(byte *p, byte b0)
{
        byte a,b;
        int i;
        for (i = 0 ; i < 8 ; i++)
        { a = b0 >> i;
          a= a << 7; a=a>>7;
          b=  p[i] >> 1; b = b << 1;
          p[i] = b | a;
        }
}

int main (int argc, char *argv[])
{
  int i, j, k, cover_bits, bits; 
  struct Buffer b = {NULL, 0, 0};
  struct Image img = {0, NULL, NULL, NULL, NULL, 0, 0};

  if (argc!= 4)
    {
	printf("\n%s <cover_file> <stego_file> <file_to_hide> \n", argv[0]);
	exit(1);
    }

  ReadImage(argv[1], &img);	// read image file into the image buffer img
				// the image is an array or unsigned chars (bytes)
				// of NofR rows NofC columns, it should be accessed using provided macros
  ReadBinaryFile(argv[3], &b);  // Read binary data

  // hidden information
  // first four bytes is the size of the hidden file 
  // next 4 bytes is the G number (4 bits per digit) 

  if (!GetColor)
  cover_bits = img.NofC*img.NofR;
  else 
    cover_bits = 3*img.NofC*img.NofR;    
  bits = (8 + b.size)*8;
  if (bits > cover_bits)
    {
      printf("Cover file is not large enough %d (bits) > %d (cover_bits)\n",bits,cover_bits);
      exit(1);
    }
// embed four size bytes for the Buffer's size field
  // Create a byte array that holds 4 bytes of the b.size
	byte Bsize[4]={ b.size >>24, b.size >> 16, b.size >> 8, b.size};
	j=0; //From now on, j will be the byte index of img.gray (j)

  	for (i = 0; i<4; i++)
	{
 	   setlsbs(&(GetGray(j)), Bsize[i]);
	   j+=8; 
	}

 // embed the eight digits of your G# using 4 bits per digit

	byte gNum[8]= {0,0,9,8,7,4,5,2};
	byte gN4bits[4];
	byte a,c;

	k =0;

	for( i=0; i<8; i=i+2)
	{ a=gNum[i]; c=gNum[i+1]; a =a<<4;
  	  gN4bits[k] = a|c;
  	  k++;
	}
 
  	for (i = 0; i<4; i++)
	{
  	   setlsbs(&(GetGray(j)), gN4bits[i]);
   	   j+=8;// printf("j = %d\n",j);
	}

// Embed b.data to image

	for (i=0; i<b.size; i++)
	{
	  setlsbs(&(GetGray(j)), GetByte(i));
    	  j+=8;
    	}
 WriteImage(argv[2],img);  // output stego file (cover_file + file_to_hide)
}
