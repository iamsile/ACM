#include <iostream>
using namespace std;

int main()
{
    int m;
    while (scanf("%d",&m),m) {
        int i,j,n,a[1010],b[1010]={0};
        for (i=0; i<m; i++)
            scanf("%d",&a[i]);
        scanf("%d",&n);
        if (n<5) {
            printf("%d\n",n);
            continue;
        }
        sort(a, a+m);
        for(i=0;i<m-1;i++)
		{
			for(j=n-5;j>=a[i];j--)
			{
				if(b[j]<b[j-a[i]]+a[i])
					b[j]=b[j-a[i]]+a[i];
			}
		}
		printf("%d\n",(n-b[n-5])-a[m-1]);
    }
    return 0;
}
/*
 Problem Description
 电子科大本部食堂的饭卡有一种很诡异的设计，即在购买之前判断余额。如果购买一个商品之前，卡上的剩余金额大于或等于5元，就一定可以购买成功（即使购买后卡上余额为负），否则无法购买（即使金额足够）。所以大家都希望尽量使卡上的余额最少。
 某天，食堂中有n种菜出售，每种菜可购买一次。已知每种菜的价格以及卡上的余额，问最少可使卡上的余额为多少。
 
 
 Input
 多组数据。对于每组数据：
 第一行为正整数n，表示菜的数量。n<=1000。
 第二行包括n个正整数，表示每种菜的价格。价格不超过50。
 第三行包括一个正整数m，表示卡上的余额。m<=1000。
 
 n=0表示数据结束。
 
 
 Output
 对于每组输入,输出一行,包含一个整数，表示卡上可能的最小余额。
 
 
 Sample Input
 1
 50
 5
 10
 1 2 3 2 1 1 2 3 2 1
 50
 0
 
 
 Sample Output
 -45
 32
*/