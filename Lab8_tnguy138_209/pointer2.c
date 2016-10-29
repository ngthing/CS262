#include <stdio.h>
#include <stdlib.h>

typedef int* Int_ptr;

int main()
{
	Int_ptr ptr1, ptr2;
	ptr1 = (Int_ptr) malloc(sizeof(int));
	ptr2 = (Int_ptr) malloc(sizeof(int));
	
	if (ptr1 == NULL)
   {
     printf("Error allocating memory for ptr1!\n");
     exit(1);
   }
 
  if (ptr2 == NULL)
  {
     printf("Error allocating memory for ptr2\n");
     exit(1);
  }

  *ptr1 = 25;     // set value of int pointed to by ptr1

   ptr2 = ptr1;    // ptr2 now points at same address as ptr1

	 // We just created a memory leak. The original memory pointed
	 //    // to by ptr2 is now inaccessable
	
	*ptr2 = *ptr2 + 50;     // What values does this change??

   printf("ptr1 now points to the value: %d\n", *ptr1);
   printf("ptr2 now points to the value: %d\n", *ptr2);

   printf("The actual value of ptr1 is: 0x%x\n", ptr1);

   free(ptr2);      // free memory back to the heap
 // Warning! What happens if we uncomment the next line?
 //    //free(ptr1);      // free memory back to the heap
   
	 printf("After freeing the memory, ptr1 now points to the value %d\n", *ptr1);
 
       }  // end main()	

