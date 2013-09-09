#include <iostream>
#include <queue>
using namespace std;
const int inf=0x3fffffff;

int map[1024][1024],cost[1024][1024];

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m)
            break;
        int i,j,x,y,d,c,s,t,cur;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++) {
                cost[i][j]=inf;
                map[i][j]=inf;
            }
        for (i=0; i<m; i++) {
            scanf("%d%d%d%d",&x,&y,&d,&c);
            if (map[x][y]>d) {
                map[x][y]=map[y][x]=d;
                cost[x][y]=cost[y][x]=c;
            }
        }
        scanf("%d%d",&s,&t);
        int dis[1010],cos[1010],v[1010];
        for (i=1; i<=n; i++) {
            dis[i]=inf;
            cos[i]=inf;
        }
        dis[s]=0;
        cos[s]=0;
        v[s]=1;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            cur=q.front();
            q.pop();
            v[cur]=0;
            for (i=1; i<=n; i++) {
                if (dis[i]>dis[cur]+map[cur][i]) {
                    dis[i]=dis[cur]+map[cur][i];
                    cos[i]=cos[cur]+cost[cur][i];
                    if (!v[i]) {
                        v[i]=1;
                        q.push(i);
                    }
                }
                if (dis[i]==dis[cur]+map[cur][i]&&
                    cos[i]>cos[cur]+cost[cur][i])
                    cos[i]=cos[cur]+cost[cur][i];
            }
        }
        printf("%d %d\n",dis[t],cos[t]);
    }
    return 0;
}
/*
 Problem Description
 给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
 
 
 Input
 输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数 s,t;起点s，终点。n和m为0时输入结束。
 (1<n<=1000, 0<m<100000, s != t)
 
 
 Output
 输出 一行有两个数， 最短距离及其花费。
 
 
 Sample Input
 3 2
 1 2 5 6
 2 3 4 5
 1 3
 0 0
 
 
 Sample Output
 9 11
*/