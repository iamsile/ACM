#include <iostream>
using namespace::std;

unsigned long long a[10001];
int main()
{
	int v,n,i,j,m;
	a[0]=1;
	cin >> v >> n;
	for(i=1;i<=v;i++)
	{
		cin >> m;
		for(j=m;j<=10000;j++)
			a[j]+=a[j-m];
	}
	cout << a[n] << '\n';
	return 0;
}
//0－1背包问题
/*
 Problem description
 The cows have not only created their own government but they have chosen to create their own money system. In their own rebellious way, they are curious about values of coinage. Traditionally, coins come in values like 1, 5, 10, 20 or 25, 50, and 100 units, sometimes with a 2 unit coin thrown in for good measure.
 The cows want to know how many different ways it is possible to dispense a certain amount of money using various coin systems. For instance, using a system of {1, 2, 5, 10, ...} it is possible to create 18 units several different ways, including: 18x1, 9x2, 8x2+2x1, 3x5+2+1, and many others.
 
 Write a program to compute how many ways to construct a given amount of money using supplied coinage. It is guaranteed that the total will fit into both a signed long long (C/C++) and Int64 (Free Pascal).
 
 
 Input
 The number of coins in the system is V (1 <= V <= 25).
 The amount money to construct is N (1 <= N <= 10,000).
 Line 1:	Two integers, V and N
 Lines 2..:	V integers that represent the available coins (no particular number of integers per line)
 
 
 
 Output
 A single line containing the total number of ways to construct N money units using V coins.
 
 Sample Input
 3 10
 1 2 5
 Sample Output
 10
*/