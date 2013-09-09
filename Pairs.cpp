#include <iostream>
using namespace::std;

int main()
{
	int sum,n,a[110],i,j,k;
	while (cin >> n&&n)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin >> a[i];
			sum+=a[i];
		}
		if (n%2!=0)
		{
			printf("No\n");
			continue;
		}
		k=sum/(n/2);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if(a[i]+a[j]==k&&a[i]!=-1&&a[j]!=-1)
				{
					a[i]=-1;
					a[j]=-1;
				}
			}
		for(i=0;i<n;i++)
			if(a[i]!=-1)
				break;
		if(i==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
/*
 Problem description
 Given n positive integers, is it possible to divide them into pairs so that the sum of each pair to the same？
 
 Input
 The input contains several test cases. The first line of each case contains a single integer n (2 <=n<=100).The second line contains n positive integers not greater than 1000. The last case is followed by a single zero, which should not be processed.
 
 Output
 For each case, output ’Yes’ or ‘No’ depending on whether or not the pairing is possible.
 
 Sample Input
 4
 1 3 4 6
 3
 1 1 1
 0
 Sample Output
 Yes
 No
*/