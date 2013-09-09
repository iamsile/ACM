#include <stdio.h>
long int a[50000]={0};

int main()
{
	long int n,i,flag;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%ld",a+i);
		flag=a[0];
		if(a[0]>=a[1])
			printf("1\n");
		for(i=1;i<n;i++)
		{
			if(a[i]>=flag&&a[i]>=a[i+1])
			{
				flag=a[i];
				printf("%ld\n",i+1);
			}
			else if(i+1==n&&a[i]>=flag)
				printf("%ld\n",i+1);
			else 
				flag=a[i];
		}
	}
	return 0;
}
/*
给出一个序列，如果序列中的数比它相邻的两个数都大就输出它的编号，否则继续。
*/
/*
 Problem description
 FJ will use the traditional high explosives to destroy the stumps. These high explosives are formulated to destroy adjacent stumps as long as those adjacent stumps are strictly shorter than the nearest stump being destroyed. The blast can continue past the closest adjacent stump to the next adjacent stump if it is even shorter than the nearest stump just destroyed. As soon as a stump encountered by the blast wave is not shorter, though, no more destruction occurs on that side of the target stump (the other side follows the same rules with whatever stumps might appear there). 
 
 Consider a line of nine stumps with these heights: 
 
 1 2 5 4 3 3 6 6 2
 If FJ blows up the third stump (with height 5), then the second stump will also be destroyed (height 2) and the first stump (height 1) will also be destroyed. Likewise, the fourth stump (height 4) and fifth stump (height 3) will be destroyed since they are successively shorter, leaving the line like this: 
 
 * * * * * 3 6 6 2
 Two more explosives (at stumps 7 and 8) will destroy the rest. 
 
 Help FJ determine the minimum number of explosive charges he needs to destroy the stumps.
 
 
 Input
 Line 1: A single integer, N(0 < N <= 50000) 
 
 Lines 2..N+1: Line i+1 contains H_i
 
 Output
 Lines 1..?: Each line contains one integer which is the index of a stump to blow up. The indices must be listed in increasing order.
 
 Sample Input
 9
 1
 2
 5
 4
 3
 3
 6
 6
 2
 Sample Output
 3
 7
 8
*/