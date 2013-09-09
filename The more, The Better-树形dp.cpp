#include <iostream>
using namespace std;
#define N 205
int n,m,map[N][N],dp[N][N],v[N];

void dfs(int s)
{
    dp[s][1]=v[s];
    int i,cur,j,k;
    for (i=1; i<=map[s][0]; i++) {
        cur=map[s][i];//s之后可以选择攻占的城市
        dfs(cur);
        for (j=m+1; j>0; j--)
            for (k=1; k+j<=m+1; k++)
                dp[s][j+k]=max(dp[s][j+k], dp[s][j]+dp[cur][k]);
    }
}

int main()
{
    while (scanf("%d%d",&n,&m),n||m) {
        int i,s;
        for (i=0; i<=n; i++)
            map[i][0]=0;
        v[0]=0;
        for (i=1; i<=n; i++) {
            scanf("%d%d",&s,&v[i]);
            map[s][0]++;
            map[s][map[s][0]]=i;
        }
        memset(dp, 0, sizeof(dp));
        //问题的关键在于将0作为第零个城堡，价值为零，这样就可以实现大一统！
        dfs(0);
        printf("%d\n",dp[0][m+1]);//加入了第零个城堡，则m+1
    }
    return 0;
}
/*
 //状态转移方程：    dp[i][j]=max(dp[i][j],dp[i][j-k]+dp[son[i]][k])
 //                    以第i个城市为起点，攻占j个城市的最大收益
 Problem Description
 ACboy很喜欢玩一种战略游戏，在一个地图上，有N座城堡，每座城堡都有一定的宝物，在每次游戏中ACboy允许攻克M个城堡并获得里面的宝物。但由于地理位置原因，有些城堡不能直接攻克，要攻克这些城堡必须先攻克其他某一个特定的城堡。你能帮ACboy算出要获得尽量多的宝物应该攻克哪M个城堡吗？
 
 
 Input
 每个测试实例首先包括2个整数，N,M.(1 <= M <= N <= 200);在接下来的N行里，每行包括2个整数，a,b. 在第 i 行，a 代表要攻克第 i 个城堡必须先攻克第 a 个城堡，如果 a = 0 则代表可以直接攻克第 i 个城堡。b 代表第 i 个城堡的宝物数量, b >= 0。当N = 0, M = 0输入结束。
 
 
 Output
 对于每个测试实例，输出一个整数，代表ACboy攻克M个城堡所获得的最多宝物的数量。
 
 
 Sample Input
 3 2
 0 1
 0 2
 0 3
 7 4
 2 2
 0 1
 0 4
 2 1
 7 1
 7 6
 2 2
 0 0
 
 
 Sample Output
 5
 13
*/