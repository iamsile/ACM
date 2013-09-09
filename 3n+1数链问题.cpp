#include <iostream>
using namespace::std;

int main()
{
	int m,n,k,l=0,lab,a[10000]={0};
	cin >> n >> m;
	lab=m;
	while(m>=n)
	{
		k=m;
		l=0;
		while(k!=1)
		{
			if(k%2==0)
			{
				k/=2;
				a[m-1]=++l;
			}
			else 
			{
				k=3*k+1;
				a[m-1]=++l;
			}
		}
		m--;
	}
	sort(a+1,a+lab);
	cout << a[lab-1]+1 << '\n';
	return 0;
}
/*
 Problem description
 
 现在我们有这么一个问题如下：
 （1）	输入一个正整数n；
 
 （2）	把n显示出来；
 
 （3）	如果n=1则结束；
 
 （4）	如果n是奇数则n变为3*n+1，否则n变为n/2；
 
 （5）	转入第二步。
 
 例如对于输入的正整数22，应该有如下数列被显示出来：
 
 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
 
 我们推测：对于任意一个正整数，经过以上算法最终会推倒1。尽管这个算法能简单，但是我们还不能确定我们的推断是否正确。不过好在我们有计算，我们验证了小于1000000的正整数都满足。对于给定的正整数n，我们把显示出来的数的个数称为n的链长。求给定区间中数的最大链长。 
 
 
 Input
 
 输入两个数i,j(0<=i<=j<10000)。 
 
 Output
 
 输出在区间[i,j]中数的最大链长。
 
 Sample Input
 1 10
 Sample Output
 20
*/