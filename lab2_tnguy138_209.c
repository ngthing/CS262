// Thi Nguyen G00987452
// CS262, 209
// Lab2

#include<stdio.h>


/* Calculate the tip amount and print all the costs */
void main()
{
	double originalcost, amounttip, totalcost;
	int percenttip;
	printf("Please enter the cost of your meal:\n");
	scanf("%lf",  &originalcost  );
	printf("Please enter the percentage to give as a tip:\n");
	scanf("%d", &percenttip); 
	amounttip = (originalcost*percenttip)/100;
	totalcost = originalcost + amounttip;
	printf("Your meal cost: %3.2lf\n", originalcost);
	printf("Tip percentage: %d\n", percenttip);
	printf("Tip amount: %3.2lf\n", amounttip);
	printf("Total cost: %3.2lf\n", totalcost);
}
	
