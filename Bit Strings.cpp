#include <iostream>
using namespace::std;

int main()
{
    int n;
    while(cin >> n&&n)
    {
       int *a=new int[n],i,num,flag;
        for(i=0;i<n;i++)
            a[i]=0;
        while(a[0]!=2)
        {
            a[n-1]++;
            i=n-1;
            while(a[i]==2&&i>0)
            {
                a[i--]=0;
                a[i]++;
            }
            if(a[0]==2)
                continue;
            num=0;
            flag=0;
            for(i=0;i<n;i++)
            {
                if(a[i]==1)
                    num++;
                if(a[i]==0)
                    if(flag==0&&num==2)
                    {
                        num=0;
                        flag=1;
                    }
                    else if(flag==1&&num!=2)
                        num=0;
                    else if(flag==1&&num==2)
                    {
                        flag=2;
                        break;
                    }
                    else
                        num=0;
                if(a[i]==1&&i==n-1)
                    if(num==2&&flag==0)
                        flag=1;
                    else if(num==2&&flag==1)
                        flag=2;
                if(num>2)
                    flag=2;
            }
            if(flag==1)
            {
                for(i=0;i<n;i++)
                    cout << a[i];
                cout << '\n';
            }
        }
        free(a);
    }
    return 0;
}
/*
#include "stdafx.h"

#include <cstdio>
int num;
int bit[15];

bool IsGood()
{
	int total=0;
	for(int i=1;i<num;i++)
		if(bit[i]==1&&bit[i+1]==1)
			total++;
	if(total==1)return 1;
	return 0;
}

void SetBit()
{
	for(int i=0;i<=num;i++)bit[i]=-1;
	int level=1;
	while(level>0)
	{
		if(level>num)
		{
			if(IsGood())
			{
				for(int i=1;i<=num;i++)
					printf("%d",bit[i]);
				printf("\n");
			}
		}
		else if(bit[level]<1)
		{
			bit[level]++;level++;continue;
		}
		bit[level]=-1;level--;
	}
}

int main()
{
	while(scanf("%d",&num)!=EOF)
		SetBit();
	return 0;
}
*/
/*
 Problem description
 Allow me to state the obvious: sequences of 1s and 0s are rather common in computer science. With that said, sometimes you want a particular sequence of 1s and 0s. For example, if we were looking for all sequences of length 4 that contained exactly 1 pair of consecutive 1s, we would have:
 1100
 1101
 0110
 1011
 0011
 
 
 Input
 Each line of input will be an integer, N, such that 2 <= N <= 12. 
 
 Output
 For each line of input, your program should print out all the bit strings of length N that have exactly 1 consecutive pairs of 1s. Strings should be ordered in ascending order according to their decimal equivalents. For ordering purposes, the leftmost bit will be considered the least significant bit. 
 
 Sample Input
 2
 3
 Sample Output
 11
 011
 110
*/