#include <iostream>
#include <queue>
using namespace std;
const int inf=0x2fffffff;
#define N 1005

struct node {
    int v,w,next;
    node() {
        v=w=next=0;
    }
}e[N*N];

int n,m,cnt,dis[N],p[N],v[N],pre[N],map[N][N];

void add(int s,int t,int c)
{
    e[cnt].v=t;
    e[cnt].w=c;
    e[cnt].next=p[s];
    p[s]=cnt++;
}

void spfa(int flag)
{
    int i,nex,cur;
    for (i=1; i<=n; i++) {
        dis[i]=inf;
        v[i]=0;
    }
    dis[1]=0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        v[cur]=0;
        for (i=p[cur]; i!=-1; i=e[i].next) {
            nex=e[i].v;
            if (map[cur][nex]&&dis[nex]>dis[cur]+e[i].w) {
                dis[nex]=dis[cur]+e[i].w;
                if (flag)
                    pre[nex]=cur;
                if (!v[nex]) {
                    v[nex]=1;
                    q.push(nex);
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        int i,x,y,c,maxn=-1;
        memset(p, -1, sizeof(p));
        pre[1]=-1;
        for (i=0,cnt=0; i<m; i++) {
            scanf("%d%d%d",&x,&y,&c);
            add(x,y,c);
            add(y,x,c);
            map[x][y]=map[y][x]=1;
        }
        spfa(1);
        for (i=n; pre[i]!=-1; i=pre[i]) {
            map[i][pre[i]]=map[pre[i]][i]=0;
            spfa(0);
            if (dis[n]>maxn)
                maxn=dis[n];
            map[i][pre[i]]=map[pre[i]][i]=1;
        }
        printf("%d\n",maxn);
    }
    return 0;
}
/*tle
#include <iostream>
#include <queue>
using namespace std;
const int inf=0x2fffffff;
#define N 1000
int n,m,map[N+4][N+4],v[N+4],dis[N+4],e[N*N+4][2];

void spfa()
{
    int i,cur;
    for (i=1; i<=n; i++) {
        dis[i]=inf;
        v[i]=0;
    }
    dis[1]=0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        v[cur]=1;
        for (i=1; i<=n; i++)
            if (dis[i]>dis[cur]+map[cur][i]) {
                dis[i]=dis[cur]+map[cur][i];
                if (!v[i]) {
                    v[i]=1;
                    q.push(i);
                }
            }
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        int i,j,k,x,y,c,maxn=-1;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                map[i][j]=inf;
        for (i=0; i<m; i++) {
            scanf("%d%d%d",&x,&y,&c);
            if (map[x][y]>c) {
                map[x][y]=map[y][x]=c;
                e[i][0]=x;
                e[i][1]=y;
            }
        }
        for (i=0; i<m; i++) {
            k=map[e[i][0]][e[i][1]];
            map[e[i][0]][e[i][1]]=map[e[i][1]][e[i][0]]=inf;
            spfa();
            if (dis[n]!=inf&&dis[n]>maxn) {
                maxn=dis[n];
            }
            map[e[i][0]][e[i][1]]=map[e[i][1]][e[i][0]]=k;
        }
        printf("%d\n",maxn);
    }
    return 0;
}
 Problem Description
 Marica is very angry with Mirko because he found a new girlfriend and she seeks revenge.Since she doesn't live in the same city, she started preparing for the long journey.We know for every road how many minutes it takes to come from one city to another.
 Mirko overheard in the car that one of the roads is under repairs, and that it is blocked, but didn't konw exactly which road. It is possible to come from Marica's city to Mirko's no matter which road is closed.
 Marica will travel only by non-blocked roads, and she will travel by shortest route. Mirko wants to know how long will it take for her to get to his city in the worst case, so that he could make sure that his girlfriend is out of town for long enough.Write a program that helps Mirko in finding out what is the longest time in minutes it could take for Marica to come by shortest route by non-blocked roads to his city.
 
 
 Input
 Each case there are two numbers in the first row, N and M, separated by a single space, the number of towns,and the number of roads between the towns. 1 ≤ N ≤ 1000, 1 ≤ M ≤ N*(N-1)/2. The cities are markedwith numbers from 1 to N, Mirko is located in city 1, and Marica in city N.
 In the next M lines are three numbers A, B and V, separated by commas. 1 ≤ A,B ≤ N, 1 ≤ V ≤ 1000.Those numbers mean that there is a two-way road between cities A and B, and that it is crossable in V minutes.
 
 
 Output
 In the first line of the output file write the maximum time in minutes, it could take Marica to come to Mirko.
 
 
 Sample Input
 5 6
 1 2 4
 1 3 3
 2 3 1
 2 4 4
 2 5 7
 4 5 1
 
 6 7
 1 2 1
 2 3 4
 3 4 4
 4 6 4
 1 5 5
 2 5 2
 5 6 5
 
 5 7
 1 2 8
 1 4 10
 2 3 9
 2 4 10
 2 5 1
 3 4 7
 3 5 10
 
 
 Sample Output
 11
 13
 27

*/