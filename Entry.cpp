#include <stdio.h>

int main()
{
	__int64 m,n;
	while(scanf("%I64d%I64d",&m,&n)!=EOF)
	{
		__int64 i,sum=1;
		for(i=m;i<m+n;i++)
			sum*=i;
		printf("%I64d\n",sum);
		
	}
	return 0;
}
/*
 Problem description
 The number of entrance is m in square,each entrance could pass through only a car every time.The number of car is n,please write a program which calculate the number of method of entry.
 
 Input
 The input contains only a line which contain m and n.
 
 Output
 The output contains a line which is the number of method of entry,the result will be less than 263.
 
 Sample Input
 5 2
 Sample Output
 30
*/