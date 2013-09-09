#include <iostream>
using namespace std;
const int inf=99999;

void Dijkstra(int n,int v,int *dist,int *prev,int map[101][101])
{
    bool s[1001];// 判断是否已存入该点到S集合中
    int i,j,u,temp,newdist;
    for (i=1; i<=n; i++) {
        dist[i]=map[v][i];
        s[i]=0;// 初始都未用过该点
        if (dist[i]==inf)
            prev[i]=0;
        else prev[i]=v;
    }
    dist[v]=0;
    s[v]=1;
    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    for (i=2; i<=n; i++) {
        temp=inf;
        u=v;
        // 找出当前未使用的点j的dist[j]最小值
        for (j=1; j<=n; j++) {
            if (!s[j]&&dist[j]<temp) {
                temp=dist[j];
                u=j;// u保存当前邻接点中距离最小的点的号码
            }
        }
        s[u]=1;// 表示u点已存入S集合中
        // 更新dist
        for (j=1; j<=n; j++) {
            if (!s[j]&&map[u][j]<inf) {
                newdist=dist[u]+map[u][j];
                if (newdist<dist[j]) {
                    dist[j]=newdist;
                    prev[j]=u;
                }
            }
        }
    }
}

int main()
{
    int n,m;
    while (cin >> n >> m) {
        int i,j,p,q,len;
        int dist[10010],prev[10010],map[101][101];
        if (!n&&!m)
            return 0;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (i==j)
                    map[i][j]=0;
                else map[i][j]=inf;
        for (i=1; i<=n; i++)
            dist[i]=inf;
        for (i=1; i<=m; i++) {
            cin >> p >> q >> len;// 输入p, q两点及其路径长度
            if (map[p][q]>len) {
                map[p][q]=len;// p指向q
                map[q][p]=len;// q指向p，这样表示无向图
            }
        }
        Dijkstra(n,1,dist,prev,map);
        cout << dist[n] << '\n';
    }
    return 0;
}
/*
#include <iostream>
#include <queue>
using namespace std;
const int inf=0x3fffff;
int n,m,map[101][101],dis[10100],v[10100];

void spfa()
{
    int i,cur;
    for (i=1; i<=n; i++) {
        dis[i]=inf;
        v[i]=0;
    }
    v[1]=1;
    dis[1]=0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        v[cur]=0;
        for (i=1; i<=n; i++) {
            if (dis[i]>map[cur][i]+dis[cur]) {
                dis[i]=map[cur][i]+dis[cur];
                if (!v[i]) {
                    v[i]=1;
                    q.push(i);
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m),n||m) {
        int i,j,x,y,c;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (i==j)
                    map[i][j]=0;
                else
                    map[i][j]=inf;
        for (i=0; i<m; i++) {
            scanf("%d%d%d",&x,&y,&c);
            if (map[x][y]>c)
                map[x][y]=map[y][x]=c;
        }
        spfa();
        printf("%d\n",dis[n]);
    }
    return 0;
}
*/
/*
#include <stdio.h>
#define max 999999
int mp[1005][1005];

int main()
{
    int N, M;
    int i, j, k, min;
    int visit[1005], dis[1005];
    int A, B, C;
    while(scanf("%d%d", &N, &M), (N+M))
    {
        for (i = 0; i < 1005; i++)
            for (j = 0; j < 1005; j++)
            {
                mp[i][j] = max;
            }
        for (i = 0; i < M; i++)
        {
            scanf("%d%d%d", &A, &B, &C);
            mp[A][B] = mp[B][A] = C;
        }
        for (i = 1; i <= N; visit[i++] = 0);        
        for (i = 1; i <= N; i++) 
        {
            min = max;
            for (j = 1; j <= N; j++)
            {
                if (!visit[j] && min > mp[1][j])
                {
                    min = mp[1][j];
                    k = j;
                }
            }
            if (min == max) break;
            visit[k] = 1;
            for (j = 0; j <= N; j++)
            {
                if (!visit[j] && mp[1][j] > mp[1][k] + mp[k][j])
                    mp[1][j] = mp[1][k] + mp[k][j];
            }
        }
        printf("%d\n", mp[1][N]);
    }
}
*/
/*
 Problem Description
 在每年的校赛里，所有进入决赛的同学都会获得一件很漂亮的t-shirt。但是每当我们的工作人员把上百件的衣服从商店运回到赛场的时候，却是非常累的！所以现在他们想要寻找最短的从商店到赛场的路线，你可以帮助他们吗？
 
 
 
 Input
 输入包括多组数据。每组数据第一行是两个整数N、M（N<=100，M<=10000），N表示成都的大街上有几个路口，标号为1的路口是商店所在地，标号为N的路口是赛场所在地，M则表示在成都有几条路。N=M=0表示输入结束。接下来M行，每行包括3个整数A，B，C（1<=A,B<=N,1<=C<=1000）,表示在路口A与路口B之间有一条路，我们的工作人员需要C分钟的时间走过这条路。
 输入保证至少存在1条商店到赛场的路线。
 
 
 Output
 对于每组输入，输出一行，表示工作人员从商店走到赛场的最短时间
 
 
 Sample Input
 2 1
 1 2 3
 3 3
 1 2 5
 2 3 5
 3 1 2
 0 0
 
 
 Sample Output
 3
 2
*/