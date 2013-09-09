#include<stdio.h>

int main()
{
    int i,j;
    __int64 a[52]={1,1};
    __int64 n=0;
    for(i=2;i<49;i=i+2)
	{
        a[i]=a[i-1]+a[i-2];
        a[i+1]=a[i]+a[i-1];
	}
    while(scanf("%I64d",&n)!=EOF)
	{
        if(n==0) 
			printf("0\n");
        else if(n==1) 
			printf("1\n");
        else if(n==2) 
			printf("10\n");
        else
		{
            for(j=1;j<49;j++)
                if(n<a[j+1]&&n>=a[j]) 
					break;
            for(i=0;i<j;i++)
			{
                printf("%d",n/a[j-i]);
                n=n%a[j-i];
			}
            printf("\n");
		}
	}
    return 0;
}
/*
 Problem description
 We are familiar with radix number representations where digits read from right-to-left (least significant to most significant) signify increasing powers of some radix (i.e. base) number, e.g. 100, 101, 102, 103, . . . in decimal representation or 20, 21, 22, 23, . . . in binary representation. For example, the binary number 101001 represents
 
 1·25+ 0·24+ 1·23+ 0·22+ 0·21+ 1·20 = 41.
 
 In this problem, we consider a number representation where digits read from right-to-left (least significant to most significant) signify increasing Fibonacci numbers 1, 2, 3, 5, 8, 13, 21, . . . we’ll call them fibary numbers. Each digit of a fibary number is either 0 or 1. For example, the fibary number 101001 represents
 
 1 · 13 + 0 · 8 + 1 · 5 + 0 · 3 + 0 · 2 + 1 · 1 = 19.
 
 While each number has exactly one radix representation without leading zeroes, it can have more than one fibary representation without leading zeroes. For example, the fibary number 11111 also represents
 
 1 · 8 + 1 · 5 + 1 · 3 + 1 · 2 + 1 · 1 = 19.
 
 However, each number has exactly one fibary representation without leading zeroes or successive ones—its canonical fibary representation. Of all the fibary representations of a number, the canonical one is the largest when viewed as a binary number.
 
 Input
 Each line contains the decimal representation of a nonnegative number less than 231.
 
 Output
 For each decimal number input, output a line containing its canonical fibary representation.
 
 Sample Input
 0
 19
 10
 100
 1000000000
 123456
 654321
 2009
 317810
 Sample Output
 0
 101001
 10010
 1000010100
 1010000100100001010101000001000101000101001
 1000000001001001000000000
 1001000100000100000000000001
 1001000010000001
 10101010101010101010101010
*/