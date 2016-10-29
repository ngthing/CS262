
#include <stdlib.h>
#include <stdio.h>
#include "link.h"


int main( int argc, char *argv[])
{
	int seed, N, low, high;
	int i, randomNum;
	if (argc != 5)
	{ printf("You have entered invalid command. Please try again.\n");
	  exit(1);
	}
	
	seed = atoi(argv[1]);
	N = atoi(argv[2]);
	low = atoi (argv[3]);
	high = atoi (argv[4]);
	srandom(seed);
	
	// Create a ListNode that holds the sequence of random numbers
	ListNode *sequenceHead = newList();
	ListNode *sequenceTail = sequenceHead; 
	ListNode *tmpTail;
	//Generate N random numbers and add them to the sequence 
	for ( i=0; i < N ; i++)
	{ randomNum = random()%(high-low+1) + low;
	  tmpTail= insert_tail(sequenceTail, randomNum);
	  sequenceTail = tmpTail;
	  free(tmpTail);
	} 
	// Create an ArrayHeads and ArrayTails
	ListNode *arrayHeads[10];
	ListNode *arrayTails[10];
	// Initialize the array and let the Tail point to the Head since no item on head yet
	for (i = 0; i<10; i++)
	{ arrayHeads[i] = newList();
	  arrayTails[i] = arrayHeads[i]; 
	}
	// At this point, we have an array of ListNode heads with 10 ListNode tails with 10 ListNodes
	// now we can start Radix Sort	
	
	int x = 0, digit=0;
	int n =1, m =10;
	int len, len1 ;
	do{
	while(sequenceHead->next!=NULL)
	{ x=sequenceHead->next->num;
	  digit = x % m;
	  digit = digit / n;
	  arrayTails[digit] = insert_tail(arrayTails[digit],x);
	  delete(sequenceHead); // delete the node that we just read
	}// End while loop means we have sorted through all the numbers in the sequence
	// The sequence now is empty, so we need to assign sequenceTail to sequenceHead
	sequenceTail = sequenceHead;
	// Now add node to the sequence
	for (i =0; i< 10; i++)
	{ if (i == 0)
 	   { len = linkLength(arrayHeads[i]);}
	  sequenceTail = insert_tail_node(sequenceTail, arrayHeads[i]);
	}
	//update m and n
	m = m*10;
	n = n*10;
	
	for (i = 0; i<10; i++)
	{ len1 = linkLength(arrayHeads[i]);
	  if (len1 == 0)
	  {free(arrayHeads[i]);}
	}
 	
	for (i = 0; i<10; i++)
        {
	  arrayHeads[i] = newList();
          arrayTails[i] = arrayHeads[i]; 
        }
	}while (len!=N); //If the length of arrayHeads[0] = N, the sequence is sorted 	  
	printf("Sorted sequence:\n");
	printList(sequenceHead);	
	deleteList(sequenceHead);
	for (i = 0; i<10; i++)
	{ deleteList(arrayHeads[i]);
	}
	
	return 0;
}
	
