#include "link.h"


ListNode *newList(void)

{
  ListNode *dummy = malloc(sizeof(ListNode));
  if ( dummy == NULL)
        { printf("Error allocating memory in heap. Please try again.\n");
          exit(1);
        }	
  dummy->num = 0;
  dummy->next = NULL;
  return dummy;
}

void printList(ListNode *head)
// print the list
{
  ListNode *curr;
  curr = head->next;
  int len = 0;
  while (curr !=NULL)
    {
      if (len == 8)
	{
	  printf("\n"); len = 0;
	}
      printf("%10d ",curr->num);
      len++;
      curr = curr->next;
    }
  printf("\n");
}

ListNode *insert_tail(ListNode *tail, int num)
{
	ListNode *newNode = malloc(sizeof(ListNode));
	if ( newNode == NULL)
	{ printf("Error allocating memory in heap. Please try again.\n");
	  exit(1);
	}
	newNode->next = NULL;
	newNode->num = num;
	//set the current tail->next value to newNode value
	tail->next = newNode;
	return newNode; // newNode now is the new tail
}

void deleteList (ListNode *head)
{
	ListNode *current = head;
	ListNode *next;

	while (current!= NULL)
	{ next = current->next;
	  free(current);
	  current = next;
	}
	head = NULL;
}

int linkLength (ListNode *head)
{
	int i =0;
	ListNode *tmp = head;
	while(tmp->next!=NULL)
	{ tmp = tmp->next;
	  i++;
	}
	return i;
}

ListNode *insert_tail_node(ListNode *tail, ListNode *node)
{
	if(node->num == 0) //if Node is a dummy head
	{ tail->next=node->next;}
	else	
	{ tail->next = node;}
	ListNode *tmp = tail;
	while(tmp->next!=NULL)
	{ tmp = tmp->next;}
	return tmp; //tmp now points to the new tail
}

ListNode *find (ListNode *head, int num)
{
	ListNode *tmp = head;
	ListNode *returnVal;
	while ((tmp->next!=NULL)&&(tmp->next->num!=num))
	{ tmp=tmp->next;}
	if (tmp->next!=NULL)
	{ returnVal = tmp;}
	else if (tmp->next==NULL)
	{ printf("%d is not in this list.\n",num);
	  returnVal= NULL;
	}
	return returnVal;
}

ListNode *delete(ListNode *prev)
{	
	ListNode *delNode;
	delNode=prev->next;
	prev->next = delNode->next;
	delNode->next=NULL;
	return delNode;
} 
