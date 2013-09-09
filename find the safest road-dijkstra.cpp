#include <iostream>
#include <string>
using namespace std;
const double esp=1e-11;
const int maxn=1001;
int n;
double Map[maxn][maxn];
double dis[maxn];
int vis[maxn];
double Dijkstra(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dis[s]=1;
    for(int i=0;i<n;i++)
    {
        int u;
        double ans=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j] && dis[j]>ans)
            {
                ans=dis[j];
                u=j;
            }
        vis[u]=1;
        if(u==t)return ans;
        for(int j=1;j<=n;j++)
            if(!vis[j] && dis[j]<Map[u][j]*dis[u])
                dis[j]=Map[u][j]*dis[u];
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                Map[i][j]=0.0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%lf",&Map[i][j]);
        int m,s,t;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&s,&t);
            double ans=Dijkstra(s,t);
            if(ans)
                printf("%.3lf\n",ans);
            else
                puts("What a pity!");
        }
    }
    return 0;
}
/*
 Problem Description
 XX星球有很多城市，每个城市之间有一条或多条飞行通道，但是并不是所有的路都是很安全的，每一条路有一个安全系数s,s是在 0 和 1 间的实数(包括0，1)，一条从u 到 v 的通道P 的安全度为Safe(P) = s(e1)*s(e2)…*s(ek) e1,e2,ek是P 上的边 ，现在8600 想出去旅游，面对这这么多的路，他想找一条最安全的路。但是8600 的数学不好，想请你帮忙 ^_^
 
 
 Input
 输入包括多个测试实例，每个实例包括：
 第一行：n。n表示城市的个数n<=1000;
 接着是一个n*n的矩阵表示两个城市之间的安全系数，(0可以理解为那两个城市之间没有直接的通道)
 接着是Q个8600要旅游的路线,每行有两个数字，表示8600所在的城市和要去的城市
 
 
 Output
 如果86无法达到他的目的地，输出"What a pity!",
 其他的输出这两个城市之间的最安全道路的安全系数,保留三位小数。
 
 
 Sample Input
 3
 1 0.5 0.5
 0.5 1 0.4
 0.5 0.4 1
 3
 1 2
 2 3
 1 3
 
 
 Sample Output
 0.500
 0.400
 0.500
*/