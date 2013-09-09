#include <stdio.h>

int main()
{
	__int64 p,i,t,n,a[100]={0};
	while(scanf("%I64d",&p)!=EOF)
	{
		scanf("%I64d",&n);
		for(i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		t=1;
		for(i=0;i<n;i++)
			t=(t*a[i])%p;
		printf("%I64d\n",t);
	}
	return 0;
}
/*
 Problem description
 Modular arithmetic plays a big role in abstract algebra. In modular arithmetic, you carry out a "normal" arithmetic operation and then mod the result by some number, say p. Things get more interesting when p is a prime. You can, however, mod by any integer (or polynomial) that you care to. One way to do such arithmetic is to first carry out the arithmetic as usual (which, at the expense of annoying mathematicians, is essentially doing arithmetic mod infinity) and then subtract by p until you get a result between 0 and p - 1, inclusive. 
 
 Input
 Each line of input is one test case consisting of a list of numbers, p N a1 a2 ..., separated by spaces. p is a positive integer smaller than 216. N is a postivie interger between 1 and 50, inclusive. Following it N non-negative integers, all of which are smaller than 232. Input is terminated by end of file. 
 
 Output
 For each input set, output the result of a1a2... mod p. The answer should be an integer between 0 and p - 1, inclusive. The final answer will fit within 16 bits. Intermediate results, however, may exceed 32 bits.
 
 Sample Input
 157 4 150 3050 200 3004
 2 10 1 3 5 7 9 11 13 15 17 19
 2 9 1 3 5 7 9 11 13 15 6
 Sample Output
 79
 1
 0
*/