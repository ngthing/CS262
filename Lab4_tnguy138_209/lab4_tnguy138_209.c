/*
Created by Thi Nguyen 6/9/16
Topic: Randing numbers and Sorting
This C program will create permutations of numbers. 
Specifically, it will initialize an array of numbers in counting order, and then will use a random number generator to create 
a permutation (random shuffle). It will then print the shuffled array of numbers to output
*/

#include <stdlib.h>
#include <stdio.h>

#define RNG_SEED 7452
#define ARRAY_SIZE 20

void InitializeArray (int *numArray, const int arrayLength);
void printArray (int *numArray, const int arrayLength);
void ShuffleArray (int *numArray, const int arrayLength);

int main()
{
	printf("My name is Thi Nguyen, and I am in lab section 209.\n");
	printf("This program will initialize an array of numbers in counting order,\n");
	printf("and then will use a random number generator to create a permutation (random shuffle).\n\n");
	
	int numArray[ARRAY_SIZE];
	srandom(RNG_SEED);
	int i;
	for (i = 0; i <10; i++)
	{			
	  InitializeArray(numArray, ARRAY_SIZE);
	  printArray (numArray, ARRAY_SIZE);
	  ShuffleArray(numArray, ARRAY_SIZE);
	  printArray (numArray, ARRAY_SIZE);
	  printf("\n");
	} 
	return 0; 	
}

void InitializeArray (int *numArray, const int arrayLength)
{
	int i;
	int n =1;
	for (i =0; i < arrayLength; i++)
	{ numArray[i] = n;
	  n++;
	}
}

void printArray (int *numArray, const int arrayLength)
{
	int i;
	for (i = 0; i < arrayLength ; i++)
	{ printf("%d ", numArray[i]);}
	printf("\n");
}

void ShuffleArray(int *numArray, const int arrayLength)
{
	int i, j;
	int n = arrayLength;
	int ivalue, jvalue; 
	for ( i = n - 1; i > 0 ; i--)
	{ 
	/*  printf("i = %d\n", i);*/
	  j = random()%(i+1);
	/*  printf("j = %d\n", j); */
	  ivalue = numArray[i];
	  jvalue = numArray[j];
	  numArray[i] = jvalue;
	  numArray[j] = ivalue;	
	}

}
