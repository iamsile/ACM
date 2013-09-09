#include <iostream>
using namespace::std;

int main()
{
	int a,b,c,d,e;
	while(cin >> e >> d >> c >> b >> a 
		  &&(a||b||c||d||e))
	{
		int i,j,k,l,flag=0,l1,l2,l3,l4,min;
		min=b+c+d+e;
		for(i=0;i<=e;++i)
			for(j=0;j<=d;++j)
				for(k=0;k<=c;++k)
					for(l=0;l<=b;++l)
						if((i*25+j*10+k*5+l)==a)
						{
							if(i+j+k+l<=min&&i<=e&&j<=d&&k<=c&&l<=b)
							{
								min=i+j+k+l;
								l1=l;
								l2=k;
								l3=j;
								l4=i;
							}
							flag=1;
							break;
						}
		if(flag)
			printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",l4,l3,l2,l1);
		else
			printf("Cannot dispense the desired amount.\n");
	}
	return 0;
}
/*
 Description
 
 Grocery stores have long struggled with how to avoid long checkout lines that leave customers frustrated. The "10 item or less" express line has been a common technique, but many stores a now trying to do even better by featuring self-service checkout lines. Such a system needs to have a mechanism to give correct change to the customer at the end of the transaction. 
 Write a program that, given the amount of change in the machine, can determine the quantities of each type of coins to return to the customer while minimizing the total number of coins dispersed.
 Input
 
 Input consists of one or more lines, each of the form: 
 Q D N P C
 
 where Q is the number of quarters in the dispenser, D is the number of dimes, N the number of nickels, P the number of pennies, and C is the number of cents (0. . . 99) owed to the customer. 
 End of the input is signaled by a line of 5 zeros.
 Output
 
 For each line of input data, your program should output either: 
 Dispense # quarters, # dimes, # nickels, and # pennies. 
 or 
 Cannot dispense the desired amount. 
 if it is not possible to dispense the exact amount.
 Sample Input
 
 5 9 9 9 37
 0 9 9 9 37
 10 10 10 0 37
 1 3 0 10 30
 1 3 6 10 30
 0 0 0 0 0
 Sample Output
 
 Dispense 1 quarters, 1 dimes, 0 nickels, and 2 pennies.
 Dispense 0 quarters, 3 dimes, 1 nickels, and 2 pennies.
 Cannot dispense the desired amount.
 Dispense 0 quarters, 3 dimes, 0 nickels, and 0 pennies.
 Dispense 1 quarters, 0 dimes, 1 nickels, and 0 pennies.
*/