#include <stdio.h>
#include <math.h>
bool a[30000];
int p[10000],len;

void prime()
{
	int i,j,k;
	for(i=0;i<150;i++)
        for(k=2*i+3,j=k*i+k+i;j<30000;j+=k)
            a[j]=1;
	p[0]=2;
    len=1;
	for(i=0;i<30000;i++)
        if(!a[i])
            p[len++]=(i<<1)+3;
}

__int64 phi(__int64 n)
{
	__int64 d,i,ans;
	d=(__int64)sqrt(n);
	ans=n;
	for(i=0;i<len&&p[i]<=d;i++)
        if(n%p[i]==0)
        {
            ans=ans/p[i]*(p[i]-1);
            while(!(n%p[i]))
            {
                n/=p[i];
            }
        }
	if(n!=1)
        ans=ans/n*(n-1);
	return ans;
}

__int64 mod(__int64 x,__int64 n,__int64 p)
{
    __int64 ans=1;
    while(n)
    {
        if(n&1)ans=(ans*(x%p))%p;
        x=((x%p)*(x%p))%p;
        n>>=1;
    }
    return ans;
}

int main()
{
	prime();
    __int64 n,i,x,t,temp;
    while (scanf("%I64d",&n)!=EOF) 
    {
        if(n%2==0||n==1)
            printf("2^? mod %I64d = 1\n",n);
        else
        {
            x=phi(n);t=x;
            for(i=0;i<len&&p[i]<t;i++)
            {
                if(x%p[i]==0)
                {
                    temp=mod(2,x,n);
                    while(temp==1&&x%p[i]==0)
                    {
                        x/=p[i];
                        temp=mod(2,x,n);
                    }
                    if(temp!=1)x*=p[i];
                }
            }
            printf("2^%I64d mod %I64d = 1\n",x,n);
        }
    }
    return 0;
}
/*
 Problem description
 Give a number n, find the minimum x that satisfies 2^x mod n = 1. 
 
 Input
 One positive integer on each line, the value of n.(0 <= n <= 231-1)
 
 Output
 If the minimum x exists, print a line with 2^x mod n = 1. Print 2^? mod n = 1 otherwise. You should replace x and n with specific numbers.
 
 Sample Input
 2
 5
 Sample Output
 2^? mod 2 = 1
 2^4 mod 5 = 1
*/