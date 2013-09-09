#include <iostream>
using namespace std;
#define N 3000005
int phi[N+10];

int main()
{
    int i,j,n,m;
    for (i=1; i<=N; i++)
        phi[i]=(i&1)?i:i/2;
    for (i=3; i<=N; i+=2)
        if (phi[i]==i)
            for (j=i; j<=N; j+=i)
                phi[j]=phi[j]/i*(i-1);
    while (~scanf("%d%d",&n,&m)) {
        __int64 sum=0;
        for (i=n; i<=m; i++)
            sum+=phi[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
/*
#include <iostream>
#include <math.h>
using namespace std;
#define N 3000000
int len,a[N+10],b[N+10],p[N+10];

int phi(int n)
{
    int i,k=sqrt((double)n),ans=n;
    for (i=0; i<len&&p[i]<=k; i++) {
        if (n%p[i]==0)
            ans=ans/p[i]*(p[i]-1);
        while (!(n%p[i])) {
            n/=p[i];
        }
    }
    if (n!=1)
        ans=ans/n*(n-1);
    return ans;
}

int main()
{
    int i,j,n,m;
    len=0;
    for (i=2; i<=N; i++)
        a[i]=1;
    for (i=2; i<=sqrt((double)N); i++)
        if (a[i])
            for (j=i; j*i<=N; j++)
                a[j*i]=0;
    for (i=0; i<=N; i++)
        if (a[i])
            p[len++]=i;
    for (i=4; i<=N; i++)
        if (!a[i])
            b[i]=phi(i);
    while (~scanf("%d%d",&n,&m)) {
        int sum=0;
        for (i=n; i<=m; i++)
            if (a[i])
                sum+=i-1;
            else sum+=b[i];
        printf("%d\n",sum);
    }
    return 0;
}
*/
/*
 Problem Description
 The Euler function phi is an important kind of function in number theory, (n) represents the amount of the numbers which are smaller than n and coprime to n, and this function has a lot of beautiful characteristics. Here comes a very easy question: suppose you are given a, b, try to calculate (a)+ (a+1)+....+ (b)
 
 
 Input
 There are several test cases. Each line has two integers a, b (2<a<b<3000000).
 
 
 Output
 Output the result of (a)+ (a+1)+....+ (b)
 
 
 Sample Input
 3 100
 
 
 Sample Output
 3042
*/