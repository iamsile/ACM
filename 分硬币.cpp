#include <iostream>
#include <stdlib.h>
using namespace::std;

int	cmp(const void *a,const void *b)
{
	if(a>b)
		return 1;
	if(a<b)
		return -1;
	return 0;
}
int main()
{ 
	int n,j,a[100],b[110],min;
	int suma,sumb,k,t;
	while(cin >> n&&n)
	{
		for(j=0;j<n;j++)
			cin >> a[j];
        memcpy(b,a,sizeof(int)*n);
		qsort(a,n,sizeof(a[0]),cmp);
		for(min=10000,j=0;j<1000;j++)
		{
			for(suma=sumb=k=0;k<n;k++)
			{
				t=rand()%n;
				if(a[t]==-1)
				{
					for(t=0;a[t]==-1;t++)
						;
				}
				if(sumb>suma)
					suma+=a[t];
				else
					sumb+=a[t];
				a[t]=-1;
			}
			memcpy(a,b,sizeof(int)*n);
			t=(suma>sumb?suma-sumb:sumb-suma);
			if(t<min)
				min=t;
		}
		cout << min << '\n';
	}
	return 0;
}
/*
 最开始看着个题觉得很熟悉，但无从下手，半年之后人品爆发终于想到了，
 这就是一个0-1背包问题啊！ 
 将总钱数除二，默认下取整就行，其实就是求以这个数为包的最大容量的背包问题，
 也就是说你要求两个人的钱币中较少的那一份的最大的钱数，动态规划求解就OK。
 一个背包里最多有100枚硬币,要将这些硬币分给两个人,使得两人得到的钱差距最小.
 首先求出面值总额 total; 问题可转化为求若干枚硬币的组合,
 使它们的总价值r不大于total / 2 且最接近 total / 2 ,这是一个0 1 背包问题,
 可用动态规划求解,最终答案应为total – 2r
 int f(int i,int y)
 {
 if(i==n)
 return (y<w[n])>0:p[n];
 if(y<w[i])
 return f(i+1,y);
 return max(f(i+1,y),f(i+1,y-w[i])+p[i]);
 }
 */
/*
 Problem description
 一个背包里面最多有100枚硬币，要将这些硬币分给两个人，使得两人得到的钱差距最小。每枚硬币的面值范围是1分到500分，不允许将一枚硬币分开。
 
 Input
 第一行有一个非负整数m（m<=100），表示硬币数。 第二行有m个正整数，表示每枚硬币的面值，中间用空格分开。
 
 Output
 每组仅输出一个非负整数，表示两人所分到钱的最小差值。
 
 Sample Input
 3
 2 3 5
 4
 1 2 4 6
 Sample Output
 0
 1
 */