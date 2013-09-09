#include <stdio.h>

int main()
{
	__int64 m;
	scanf("%I64d",&m);
	while(m--)
	{
		__int64 n,sum,lab;
		scanf("%I64d",&n);
		sum=1;
		lab=n;
		while(lab>2)
		{
			sum*=n;
			lab--;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
/*
 Problem description
 There are n cities on the map, you are asked to bulid roads that satisfy this condition: For each pair of different cities of A and B, there is only one way between A and B when each road can be visited at most once. Then how many methods can you adopt?
 
 Input
 The first line contains the number of test cases T, then the following T lines each contains an integer number n (2 <= n <= 17)， represent the number of cities in the map.
 
 Output
 For each test case, print the number of methods to build the roads that satisfy the conditions.
 
 Sample Input
 2
 2
 3
 Sample Output
 1
 3
*/