#include <iostream>
using namespace std;

int main()
{
    int n,s,m,t;
    while(~scanf("%d%d%d%d",&n,&s,&m,&t)) {
        int i,j,dp[105][105];
        memset(dp,0,sizeof(dp));
        dp[s][0]=1;
        for(j=1;j<=m;j++)
            for(i=1;i<=n;i++)
                dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1];
        printf("%d\n",dp[t][m]);
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
int N,P,T,M;
int f[155][155];

int abs(int x)
{
    return x<0?0-x:x;
}
 
int dfs(int t,int x)
{
    
    if(t<0 || x<1 || x>N )
        return 0;
    if(t==0 && x==P)
        return 1;
    if(f[t][x]!=0)
        return f[t][x];
    
    if(x==1){
        f[t][x]=f[t-1][x+1]=dfs(t-1,x+1);
	}
    else if(x==N){
        f[t][x]=f[t-1][x-1]=dfs(t-1,x-1);
	}
    else{
        f[t-1][x+1]=dfs(t-1,x+1);
        f[t-1][x-1]=dfs(t-1,x-1);
        f[t][x]=f[t-1][x+1]+f[t-1][x-1];
    }
    return f[t][x];
}
int main()
{
    while(scanf("%d%d%d%d",&N,&P,&M,&T)==4)
    {
        memset(f,0,sizeof(f));
        printf("%d\n",dfs(M,T));
    }
}
/*
 Problem Description
 自从见识了平安夜苹果的涨价后，Lele就在他家门口水平种了一排苹果树，共有N棵。
 
 突然Lele发现在左起第P棵树上(从1开始计数)有一条毛毛虫。为了看到毛毛虫变蝴蝶的过程，Lele在苹果树旁观察了很久。虽然没有看到蝴蝶，但Lele发现了一个规律：每过1分钟，毛毛虫会随机从一棵树爬到相邻的一棵树上。
 
 比如刚开始毛毛虫在第2棵树上，过1分钟后，毛毛虫可能会在第1棵树上或者第3棵树上。如果刚开始时毛毛虫在第1棵树上，过1分钟以后，毛毛虫一定会在第2棵树上。
 
 现在告诉你苹果树的数目N，以及毛毛刚开始所在的位置P，请问，在M分钟后，毛毛虫到达第T棵树，一共有多少种行走方案数。
 
 
 Input
 本题目包含多组测试，请处理到文件结束(EOF)。
 每组测试占一行，包括四个正整数N,P,M,T(含义见题目描述，0<N,P,M,T<100)
 
 
 Output
 对于每组数据，在一行里输出一共的方案数。
 题目数据保证答案小于10^9
 
 
 Sample Input
 3 2 4 2
 3 2 3 2
 
 
 Sample Output
 4
 0
*/