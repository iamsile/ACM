#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int n,i,k,a[10]={0},sum=0;
	cin >> n;
	k=sqrt(n);
	for(i=0;i<=k;i++)
	{
		if(n%2!=0)
			a[i]=1;
		else 
			a[i]=0;
		n/=2;
	}
	for(i=k;i>=0;i--)
		cout << a[i];
	cout << endl;
	for(i=k;i>=0;i--)
		if(a[i]!=0)
			sum+=pow(2, i);
	cout << sum << endl;
	return 0;
}
//把整数用数组的形式保存成二进制，然后在用整数的形式输出出来