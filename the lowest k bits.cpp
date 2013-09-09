#include <iostream>
#include <math.h>
using namespace::std;

int find(unsigned /*__int64*/ d,int k)
{
	int j;
	unsigned /*__int64*/sum=0;
	int a[1001]={0};
	for(j=0;j<=k;j++)
	{
		if(d%2!=0)
			a[j]=1;
		else 
			a[j]=0;
		d/=2;
	}
	for(j=k-1;j>=0;j--)
		if(a[j]!=0)
			sum+=(unsigned /*__int64*/)pow(2, j);
	printf("%I64u\n",sum);
	return 0;
}

int main()
{
	int a,b;
	int n,i,k;
	unsigned /*__int64*/ dd;
	cin >> n;
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d%d",&a,&b,&k);
		dd=a*b; 
		find(dd,k);
	}
	return 0;
}
/*__int64是2的63方＋或－1，但是在苹果下无法定义;unsigned __int64的输出方式为%I64u
 give you two numbers a and b,you have to compute the product of them,and find the lowest k
 bits of the product
 input:
 the first line of input will be a positive integer indicaing how many data sets
 will be included(N).each of the next N lines will contain the a,b and k
 (0<=a<=2^32-1,0<=b<=2^32-1,1<=k<=32).
 output:
 for each dataset output a single number which is the last k bits of a*b
 sample input
 2
 2 4 3
 20 29 5
 sample output
 0
 4
 */
