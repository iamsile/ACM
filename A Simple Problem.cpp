#include <stdio.h>

int main()
{
	__int64_t a[14]={1};
	int i,j,t,m,k,f;
	for(i=1;i<14;i++)
		a[i]=a[i-1]*i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		for(i=1;i<14;i++)
			if(a[i]>m)
				break;
		printf("%d = ",m);
		for(f=0,j=i;j>=1;j--)
			if(m>=a[j])
			{
				if(m>j*a[j])
					k=j;
				else
					k=m/a[j];
				m-=a[j]*k;
				if(f)
					printf(" + ");
				if(k!=1)
					printf("%d*%d!",k,j);
				else 
					printf("%d!",j);
				if(!f)
					f=1;
			}
		printf("\n");
	}
	return 0;
}
/*
 Problem description
 We often use decimal system in daily , for example the number 1234 is expressed as
 
 1234 = 1*103 + 2*102 + 3 *101 + 4*100
 
 This method can be applied to P number system(Binary system(p=2) Hexadecimal system(p=16)).
 Computer use the Binary system.
 Now there is a new way to express integer number.we know the Factorial:
 (n!) = (n-1 + 1)*(n-1)!
 = (n-1)*(n-1)! + (n-2 + 1)*(n-2)!
 ...
 = (n-1)*(n-1)!+(n-2)*(n-2)!+(n-3)*(n-3)! ...+2*2!+1!+0!
 every integer number M can be expressed in this way.
 m = An-1(n-1)! + An-2(n-2)! + An-3(n-3)! + ... + a1,
 (0<=ai<=i,i = 1,2,...,n-1.)
 Can you do it ? 
 
 Input
 The first line of input is T, then following T lines,each line contains a number m(0 < m <2^30); 
 
 Output
 For each testcase, you should printed the number in Factorial.
 
 Sample Input
 2
 3
 4000
 Sample Output
 3 = 2! + 1!
 4000 = 5*6! + 3*5! + 4! + 2*3! + 2*2!
*/