#include <iostream>
using namespace std;
#define maxn 1<<30-1

int a[2010],dp[2010][2010];

int minn(int a,int b)
{
    if (a<b)
        return a;
    return b;
}

int main()
{
    int n,k;
    while (~scanf("%d%d",&n,&k)) {
        int i,j;
        for (i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1, a+n+1);
        for (i=1; i<=n; i++)
            for (j=1; j<=k; j++)
                dp[i][j]=maxn;
        dp[2][1]=(a[1]-a[2])*(a[1]-a[2]);
        for (i=3; i<=n; i++)
            for (j=1; j*2<=i; j++)//&j<=k
                dp[i][j]=minn(dp[i-1][j], dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
/*
 1.排序
 2.DP
 dp[i][j]=min{dp[i-1][j],dp[i-2][j-1]+item[i]*item[i-1]}
 dp[i][j]表示前i件物品中选出j对的最小值
 可以包括i,那么他一定和i-1组合，差值最小
 如果不包括i,则为dp[i-1][j]
 Problem Description
 搬寝室是很累的,xhd深有体会.时间追述2006年7月9号,那天xhd迫于无奈要从27号楼搬到3号楼,因为10号要封楼了.看着寝室里的n件物品,xhd开始发呆,因为n是一个小于2000的整数,实在是太多了,于是xhd决定随便搬2*k件过去就行了.但还是会很累,因为2*k也不小是一个不大于n的整数.幸运的是xhd根据多年的搬东西的经验发现每搬一次的疲劳度是和左右手的物品的重量差的平方成正比(这里补充一句,xhd每次搬两件东西,左手一件右手一件).例如xhd左手拿重量为3的物品,右手拿重量为6的物品,则他搬完这次的疲劳度为(6-3)^2 = 9.现在可怜的xhd希望知道搬完这2*k件物品后的最佳状态是怎样的(也就是最低的疲劳度),请告诉他吧.
 
 
 Input
 每组输入数据有两行,第一行有两个数n,k(2<=2*k<=n<2000).第二行有n个整数分别表示n件物品的重量(重量是一个小于2^15的正整数).
 
 
 Output
 对应每组输入数据,输出数据只有一个表示他的最少的疲劳度,每个一行.
 
 
 Sample Input
 2 1
 1 3
*/ 
 Sample Output
 4

