#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

__int64 cal(__int64 m)
{
	__int64 i=m,k=sqrt(m),flag=m;
	for(i=2;i<=k+1;i++) {
		if(m%i==0)
			flag=flag/i*(i-1);
		while(m%i==0)
			m/=i;
	}
	if(m!=1)
		flag=flag/m*(m-1);
	return flag;
}

int main()
{
	__int64 n;
	while(~scanf("%I64d",&n)) {
		__int64 i=n,k=(__int64)sqrt(n),ans=n,sum=0,m=n;
		for(i=2;i<=k;i++) {
			if(n%i==0) {
				sum+=cal(n/i)*i;
				if(i*i!=n)
					sum+=cal(n/(n/i))*(n/i);
			}
			if(m%i==0)
				ans=ans/i*(i-1);
			while(m%i==0)
				m/=i;
		}
		if(m!=1)
			ans=ans/m*(m-1);
		printf("%I64d\n",ans+sum+n);
	}
	return 0;
}
/*
 Description
 Longge is good at mathematics and he likes to think about hard mathematical problems which will be solved by some graceful algorithms. Now a problem comes: Given an integer N(1 < N < 2^31),you are to calculate ∑gcd(i, N) 1<=i <=N. 
 
 "Oh, I know, I know!" Longge shouts! But do you know? Please solve it. 
 Input
 Input contain several test case. 
 A number N per line. 
 Output
 For each N, output ,∑gcd(i, N) 1<=i <=N, a line
 Sample Input
 2
 6
 Sample Output
 3
 15
*/