#include <iostream>
#include <math.h>
using namespace::std;
unsigned int a[1299710];

int main()
{
	unsigned int m,i,j;
	cin >> m;
	for(i=1;i<=1299710;i++)
		a[i]=1;
	for(i=2;i<=1299710;i++)
		if(a[i])
			for(j=i;i*j<=1299710;j++)
				a[j*i]=0;
	while(m--)
	{
		unsigned int n,num=1;
		cin >> n;
		if(a[n])
			cout << "0\n";
		else 
		{
			for(i=n;i<=1299710;i++)
				if(a[i]==0)
					num++;
				else if(a[i])
					break;
			for(i=n-1;i>=2;i--)
				if(a[i]==0)
					num++;
				else if(a[i])
					break;
			cout << num << '\n';
		}
	}
	return 0;
}
/*
 另外一种更快的筛选法
 a[2]=1;
 for(i=3;i<N;i=i+2) a[i]=1;
 for(i=2;i<sqrt(N);i++)  
 if(a[i]==1)
 for(j=i*i;j<N;j=j+2*i)  a[j]=0;      
*/
/*
 Problem description
 处于相邻的两个素数p和p + n之间的n - 1个连续的合数所组成的序列我们将其称为 长度为n的素数槽。例如，< 24, 25, 26, 27, 28 >是处于素数23和素数29之间的一 个长度为6的素数槽。
 你的任务就是写一个程序来计算包含整数k的素数槽的长度。如果k本身就 是素数，那么认为包含k的素数槽的长度为0。
 
 
 Input
 第一行是一个数字n，表示需要测试的数据的个数。后面有n行，每行是一个正整数k ， k大于1并且小于或等于的第十万个素数（也就是1299709）。
 
 
 Output
 对于输入部分输入的每一个k，都对应输出一个非负整数，表示包含k的素数槽的长 度，每个非负整数占一行。
 
 
 Sample Input
 5
 10
 11
 27
 2
 492170
 Sample Output
 4
 0
 6
 0
 114
*/