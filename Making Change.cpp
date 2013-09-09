#include <iostream>
using namespace::std;

int main()
{
	int a,b,c,d,e;
	while(cin >> a >> b >> c >> d >> e &&a)
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
			cout << l1 << ' ' << l2 << ' ' << l3 << ' ' << l4 <<'\n';
		else
			cout << "Not enough change\n";
	}
	return 0;
}
/*
 Problem description
 In the old days before everything was electronic, you could pay for stuff with cash and (maybe) get change back. The number of coins you get could vary. For example, 10 cents in change can be done with 1 dime, or 2 nickels, or 1 nickel and 5 pennies, or 10 pennies. The rule of thumb was for the cashier to give the least amount of coins from the selection of coins in the register. Now since the cashiers may not be quick enough to give you the coins, you're to write a program that produces the correct amount of change in the fewest coins 
 
 Input
 Each line of input will have 5 integers on it. The first number is the amount of change to make. The second number is the number of pennies available, followed by the number of nickels, then the number of dimes and finally the number of quarters. 
 
 Output
 For each input, print a line that has the number of pennies, the number of nickels, the number of dimes and the number of quarters needed to make the given change using the least number of coins. If the requested amount of change can't be made from the given amount of coins, then print the message "Not enough change". 
 
 Sample Input
 89 3 0 1 2
 89 10 10 10 10
 89 0 0 0 4
 45 45 0 0 0
 Sample Output
 Not enough change
 4 0 1 3
 Not enough change
 45 0 0 0
*/