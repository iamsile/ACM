#include <stdio.h>
const int max=1000023;
__int64 dp[2][max],a[max];
int n,m;

void init()
{
    int i;
    dp[0][0]=dp[1][0]=0;
    for (i=1; i<=n; i++) {
        scanf("%I64d",a+i);
        dp[0][i]=dp[1][i]=0;
    }
}

void solve()
{
    int i,j,t=1;
    for (i=1; i<=m; i++) {
        dp[t][i]=dp[1-t][i-1]+a[i];
        dp[1-t][i]=(dp[1-t][i-1]>dp[1-t][i]?dp[1-t][i-1]:dp[1-t][i]);
        for (j=i+1; j<=n-m+i; j++) {
            dp[t][j]=a[j]+(dp[t][j-1]>dp[1-t][j-1]?dp[t][j-1]:dp[1-t][j-1]);
            dp[1-t][j]=(dp[1-t][j]>dp[1-t][j-1]?dp[1-t][j]:dp[1-t][j-1]);
        }
        t=1-t;
    }
    t=(m&1);
    __int64 ans=-1000000000000000;
    for (i=m; i<=n; i++)
        ans=(ans>dp[t][i]?ans:dp[t][i]);
    printf("%I64d\n",ans);
}

int main()
{
    while (scanf("%d%d",&m,&n)!=EOF) {
        init();
        solve();
    }
    return 0;
}
/*
 1024 求的是给定n个数,求m个不相交的子段和的最大值.
 
 dp[i][j]=max(dp[i][j-1]+a[j],max(dp[i-1][t])+a[j]);(i<=t<j)
 
 代码写成f[j]=max(f[j-1],best[cur][j-1])+a[j]; //对应于下面的第一点
 
 best[1-cur][j]=max(f[j],best[1-cur][j-1]);//第二点
 
 dp[i][j]表示是前j个数据,i个子段并且包含a[j]的最大值,求dp[i][j]时分为两种情况.
 
 1,前j-1个数据,i个字段并且包含a[j-1]的最大值,然后加上a[j],此时a[j]并入a[j-1]所在的段.
 
 2.求出前j-1个数据中i个子段的最大值,注意这里的最大值与dp[i][j-1]是有区别的.不一定包含a[j-1],然后再加上a[j](单独作为一段).
 
 最后在dp[m][j]中(m<=j<=n)找出最大值才是最后的结果,(开始自己没理解透,后来总算知道dp[i][j]并不是最好要求的值,而是在找到最大的),希望同样懵懂的朋友看了之后能明白一点.
#include <iostream>
using namespace std;
int f[1000003];
int best[2][1000003];
int n,m,a[1000003];
int sum[1000003];

int main()
{
    while (scanf("%d%d",&m,&n)!=EOF) {
        int i,j,cur,ans=-2000000000;
        sum[0]=0;
        for (i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for (i=0; i<=n; i++)
            best[0][i]=0;
        cur=0;
        for (j=1; j<=m; j++) {
            for (i=0; i<=j-1; i++)
                best[1-cur][i]=-2000000000;
            for (i=j; i<=n; i++) {
                if (i==j)
                    f[i]=sum[i];
                else f[i]=max(best[cur][i-1], f[i-1])+a[i];
                best[1-cur][i]=max(best[1-cur][i-1],f[i]);
                if (j==m)
                    ans=max(ans,f[i]);
            }
            cur=1-cur;
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/
//状态:   dp[i][j] --- 表示前j个数中的最大i段子段和,并且a[j]包涵于最后一个子段
//状态转移方程: dp[i][j]=max{dp[i][j-1]+A[j],dp[i-1][t]+a[j] (i-1<=t<n-m+i) }
//关于状态转移方程的解释:
//       dp[i][j]由两种情况得到,    
//      一、a[j]包涵于最后一个子段，这种情况的最大值就是dp[i][j-1]+a[j];
//      二、a[j]就是最后一个子段，这种情况的最大值是 dp[i-1][t]+a[j] (i-1<=t<=n-m+i) 中
// 的最大值.
// 以下用滚动数组进行DP
// 在求 dp[i][j]时也顺便把 max{dp[i - 1][t]} ( i - 1 <= t < j) 求出来,这样的话
// 时间复杂度仅为 O(N*(N - M + 1)) , 空间为 O( N )  
/*
 Problem Description
 Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer, we always challenge ourselves to more difficult problems. Now you are faced with a more difficult problem.
 
 Given a consecutive number sequence S1, S2, S3, S4 ... Sx, ... Sn (1 ≤ x ≤ n ≤ 1,000,000, -32768 ≤ Sx ≤ 32767). We define a function sum(i, j) = Si + ... + Sj (1 ≤ i ≤ j ≤ n).
 
 Now given an integer m (m > 0), your task is to find m pairs of i and j which make sum(i1, j1) + sum(i2, j2) + sum(i3, j3) + ... + sum(im, jm) maximal (ix ≤ iy ≤ jx or ix ≤ jy ≤ jx is not allowed).
 
 But I`m lazy, I don't want to write a special-judge module, so you don't have to output m pairs of i and j, just output the maximal summation of sum(ix, jx)(1 ≤ x ≤ m) instead. ^_^
 
 
 Input
 Each test case will begin with two integers m and n, followed by n integers S1, S2, S3 ... Sn.
 Process to the end of file.
 
 
 Output
 Output the maximal summation described above in one line.
 
 
 Sample Input
 1 3 1 2 3
 2 6 -1 4 -2 3 -2 3
 
 
 Sample Output
 6
 8
*/