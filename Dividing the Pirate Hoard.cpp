#include <iostream>
using namespace::std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int i,k,sum;
		for(i=b,sum=a;i>0;i--)
		{
			k=a/b+a%b;
			a-=k;
			sum-=k;
			if(i<b)
				cout << ' ';
			cout << k;
		}
		cout << '\n' << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 After raiding an island N pirates end up with M coins. After the raid everybody gathers coins and puts them together in a community pile, to be divided the next day. During the night one pirate decides to take his share himself. He sneaks his way to the hoard and divides the M coins into N equal piles, with K coins left over. He keeps the extra K coins for himself, hides his pile of coins, and puts the other piles of coins back into a single pile. The other pirates then do the same thing one at a time, each dividing the remaining coins into N piles, taking one pile, and keeping any extra coins to keep the remaining piles even.
 Given the number of pirates and coins, find out how many coins each pirate will have his own hidden pile (his equal-sized pile plus remaining coins) and how many coins are left in the community pile at the end of the night.
 
 
 Input
 The input will be the number of coins, followed by the number of pirates. 
 
 Output
 The output should be the number of coins received by each pirate from largest to smallest (separated by spaces), followed by the total number of coins remaining in the hoard on a second line.
 
 Sample Input
 Sample Input 1:
 12 2
 
 Sample Input 2:
 10 3
 Sample Output
 Sample Output 1:
 6 3 
 3
 
 Sample Output 2:
 4 2 2 
 2
*/