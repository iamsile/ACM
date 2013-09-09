#include <iostream>
#include <stdio.h>
using namespace std;
const int inf=99999;

void Dijkstra(int n,int v,int *dist,int *prev,int map[101][101])
{
    bool s[1001];
    int temp,u,newdist,i,j;
    for (i=1; i<=n; i++) {
        dist[i]=map[v][i];
        s[i]=0;
        if (dist[i]==inf)
            prev[i]=0;
        else prev[i]=v;
    }
    s[v]=1;
    dist[v]=0;
    for (i=2; i<=n; i++) {
        temp=inf;
        u=v;
        for (j=1; j<=n; j++)
            if (!s[j]&&dist[j]<temp)
            {
                temp=dist[j];
                u=j;
            }
        s[u]=1;
        for (j=1; j<=n; j++)
            if (!s[j]&&map[u][j]<inf) {
                newdist=dist[u]+map[u][j];
                if (newdist<dist[j]) {
                    dist[j]=newdist;
                    prev[j]=u;
                }
            }
    }
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int i,j,p,q,len,start,end;
        int prev[1001],dist[1001],map[101][101];
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (i==j)
                    map[i][j]=0;
                else map[i][j]=inf;
        for (i=1; i<=m; i++) {
            cin >> p >> q >> len;
            if (map[p+1][q+1]>len) {
                map[p+1][q+1]=len;
                map[q+1][p+1]=len;
            }
        }
        for (i=1; i<=n; i++)
            dist[i]=inf;
        cin >> start >> end;
        Dijkstra(n,start+1,dist,prev,map);
        if (dist[end+1]!=inf)
            cout << dist[end+1] << '\n';
        else cout << "-1\n";
    }
    return 0;
}
/*
 Problem Description
 某省自从实行了很多年的畅通工程计划后，终于修建了很多路。不过路多了也不好，每次要从一个城镇到另一个城镇时，都有许多种道路方案可以选择，而某些方案要比另一些方案行走的距离要短很多。这让行人很困扰。
 
 现在，已知起点和终点，请你计算出要从起点到终点，最短需要行走多少距离。
 
 
 Input
 本题目包含多组数据，请处理到文件结束。
 每组数据第一行包含两个正整数N和M(0<N<200,0<M<1000)，分别代表现有城镇的数目和已修建的道路的数目。城镇分别以0～N-1编号。
 接下来是M行道路信息。每一行有三个整数A,B,X(0<A,B<N,A!=B,0<X<10000),表示城镇A和城镇B之间有一条长度为X的双向道路。
 再接下一行有两个整数S,T(0<=S,T<N)，分别代表起点和终点。
 
 
 Output
 对于每组数据，请在一行里输出最短需要行走的距离。如果不存在从S到T的路线，就输出-1.
 
 
 Sample Input
 3 3
 0 1 1
 0 2 3
 1 2 1
 0 2
 3 1
 0 1 1
 1 2
 
 
 Sample Output
 2
 -1
*/