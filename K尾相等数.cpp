#include <iostream>
using namespace::std;

int main()
{
	int n,m,a[1000];
	cin >>m;
	while(m--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		int b=0,k=1,t=1;
		if(n>=1000)
		{
			b=1;
			n=n%1000;
		}
		while(1)
		{
			k=n*k;
			if((k>=1000)||(b==1))
			{
				if(a[k%1000]==0)
					a[k%1000]=t;
				else{
					a[k%1000]+=t;
					break;
				}
			}
			if(k>=1000)
				k=k%1000;
			t++;
		}
		cout << a[k%1000] << '\n';
	}
	return 0;
}
/*
 Problem description
 
 输入一个自然数K，若存在自然数M和N（M>N），使得K^M和K^N均大于或等于1000，且它们的末尾三位数相等，则称M和N是一对K尾相等数。情书求出M+N值最小的K尾相等数。
 
 Input
 
 第一行输出一个整数T，表示接下来输出的行数，接下来每一行输入一个自然数K。
 
 Output
 
 M+N值最小的K尾相等数，输出T行，每行输出M+N的值。
 
 Sample Input
 1
 2
 Sample Output
 120
*/