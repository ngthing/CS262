#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int randomInt;
	struct Node *next;
};

void insertNodeSorted (Node *head, int data)
{
	Node *newNode = malloc (sizeof(Node));
	// check if memory is successfully allocated
	if (newNode == NULL)
	{ printf("Error allocating memory in the heap.\n");
	 exit(1);}

	newNode->next = NULL;
	newNode->randomInt = data;

	Node *tmp = head; // create a temporary node that points to head
		
	while ((tmp->next !=NULL) && (tmp->next->randomInt < newNode->randomInt))
	{ tmp = tmp->next;}

	newNode->next = tmp->next;
	tmp->next = newNode;
}

void printList(Node *head)
{
	Node *tmp = head->next;
	printf("The list of random integers is:\n");
	while (tmp != NULL)
	{ 
	  printf("%d ", tmp->randomInt);
	  tmp = tmp->next;
	}
	printf("\n");
}

void deleteList (Node *head)
{
	Node *current = head;
	Node *next;

	while (current!= NULL)
	{ next = current->next;
	  free(current);
	  current = next;
	}
	head = NULL;
}

int main(int agrc, char *argv[] )
{
	int seed; //seed for generate random number
	int num; // the number of random integers that the user request
	int rand_max; // the maximum possible value of the random numbers generated
	int data, i;
	
	seed = atoi(argv[1]);//convert the string at argv[1] to integer
	num = atoi(argv[2]);
	rand_max = atoi(argv[3]);

	srandom(seed); // seed random generator
	
	// create a head of a Link List
	Node *head = malloc (sizeof(Node));
	// check if memory is successfully allocated
         if (head == NULL)	 
         { printf("Error allocating memory in the heap.\n");
  	   exit(1);}
	head->next = NULL;
	
	for(i = 0; i < num ; i++)
	{ data = random()%(rand_max + 1); // generate random integers range from 0 to rand_max
	  printf("The %d random integer is %d\n", i+1 , data);
	  insertNodeSorted(head,data);
	}
	
	printList(head);
	deleteList(head);
	return 0;
}


