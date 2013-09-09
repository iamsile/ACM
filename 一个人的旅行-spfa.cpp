#include <iostream>
#include <queue>
using namespace std;
const int inf=0x3fffffff;
int map[1010][1010],dis[1010],v[1010];

int main()
{
    int n,m,k;
    while (~scanf("%d%d%d",&n,&m,&k)) {
        int i,j,s,t,c,cur,maxn=-1,minn=inf;
        for (i=0; i<=1000; i++)
            for (j=0; j<=1000; j++)
                map[i][j]=inf;
        for (i=0; i<n; i++) {
            scanf("%d%d%d",&s,&t,&c);
            if (s>maxn)
                maxn=s;
            if (t>maxn)
                maxn=t;
            if (map[s][t]>c)
                map[s][t]=map[t][s]=c;
        }
        for (i=0; i<m; i++) {
            scanf("%d",&t);
            map[0][t]=map[t][0]=0;
        }
        for (i=0; i<=maxn; i++) {
            dis[i]=inf;
            v[i]=0;
        }
        dis[0]=0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            cur=q.front();
            q.pop();
            v[cur]=0;
            for (i=0; i<=maxn; i++)
                if (dis[i]>dis[cur]+map[cur][i]) {
                    dis[i]=dis[cur]+map[cur][i];
                    if (!v[i]) {
                        v[i]=1;
                        q.push(i);
                    }
                }
        }
        for (i=0; i<k; i++) {
            scanf("%d",&t);
            if (dis[t]<minn)
                minn=dis[t];
        }
        printf("%d\n",minn);
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
#define inf 999999
int map[1010][1010],maxn;

int dijkstra(int v,int p)
{
    int i,j,m,min,s[1010],d[1010];
    for (i=0; i<=maxn; i++) {
        s[i]=0;
        d[i]=map[v][i];
    }
    s[v]=1;
    d[v]=0;
    for (i=0; i<=maxn; i++) {
        min=inf;
        for (j=0; j<=maxn; j++)
            if (s[j]==0&&d[j]<min) {
                min=d[j];
                m=j;
            }
        if (min==inf)
            break;
        s[m]=1;
        for (j=0; j<=maxn; j++)
            if (s[j]==0&&d[j]>d[m]+map[m][j])
                d[j]=d[m]+map[m][j];
    }
    return d[p];
}

int main()
{
    int n,s,t;
    while (scanf("%d%d%d",&n,&s,&t)!=EOF) {
        int i,j,x,y,k,num;
        for (i=0; i<1005; i++)
            for (j=0; j<1005; j++)
                map[i][j]=inf;
        maxn=0;
        for (i=0; i<n; i++) {
            cin >> x >> y >> k;
            if (map[x][y]>k)
                map[x][y]=map[y][x]=k;
            if (x>maxn)
                maxn=x;
            if (y>maxn)
                maxn=y;
            
        }   
        maxn++;
        for (i=0; i<s; i++) {
            cin >> x;
            map[x][0]=map[0][x]=0;
        }
        for (i=0; i<t; i++) {
            cin >> x;
            map[x][maxn]=map[maxn][x]=0;
        }
        num=dijkstra(0,maxn);
        cout << num << '\n';
    }
    return 0;
}
/*
 Problem Description
 虽然草儿是个路痴（就是在杭电待了一年多，居然还会在校园里迷路的人，汗~),但是草儿仍然很喜欢旅行，因为在旅途中 会遇见很多人（白马王子，^0^），很多事，还能丰富自己的阅历，还可以看美丽的风景……草儿想去很多地方，她想要去东京铁塔看夜景，去威尼斯看电影，去阳明山上看海芋，去纽约纯粹看雪景，去巴黎喝咖啡写信，去北京探望孟姜女……眼看寒假就快到了，这么一大段时间，可不能浪费啊，一定要给自己好好的放个假，可是也不能荒废了训练啊，所以草儿决定在要在最短的时间去一个自己想去的地方！因为草儿的家在一个小镇上，没有火车经过，所以她只能去邻近的城市坐火车（好可怜啊~）。
 
 
 Input
 输入数据有多组，每组的第一行是三个整数T，S和D，表示有T条路，和草儿家相邻的城市的有S个，草儿想去的地方有D个；
 接着有T行，每行有三个整数a，b，time,表示a,b城市之间的车程是time小时；(1=<(a,b)<=1000;a,b 之间可能有多条路)
 接着的第T+1行有S个数，表示和草儿家相连的城市；
 接着的第T+2行有D个数，表示草儿想去地方。
 
 
 Output
 输出草儿能去某个喜欢的城市的最短时间。
 
 
 Sample Input
 6 2 3
 1 3 5
 1 4 7
 2 8 12
 3 8 4
 4 9 12
 9 10 2
 1 2
 8 9 10
 
 
 Sample Output
 9
*/