#include <iostream>
using namespace std;
const int inf=0x2fffffff;

struct node {
    int s,t,w;
}edge[50010];

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,flag,x=inf,y=-1,dis[50010];
        for (i=0; i<n; i++) {
            scanf("%d%d%d",&edge[i].s,&edge[i].t,&edge[i].w);
            edge[i].t++;
            if (x>edge[i].s)
                x=edge[i].s;
            if (y<edge[i].t)
                y=edge[i].t;
        }
        for (i=x; i<=y; i++)
            dis[i]=0;
        for (i=x+1; i<y; i++) {
            flag=1;
            for (j=0; j<n; j++)
                if (dis[edge[j].t]-edge[j].w<dis[edge[j].s]) {
                    dis[edge[j].s]=dis[edge[j].t]-edge[j].w;
                    flag=0;
                }
            for (j=y; j>x; j--)
                if (dis[j]<dis[j-1]) {
                    dis[j-1]=dis[j];
                    flag=0;
                }
            for (j=x+1; j<=y; j++)
                if (dis[j-1]+1<dis[j]) {
                    dis[j]=dis[j-1]+1;
                    flag=0;
                }
            if (flag)
                break;
        }
        printf("%d\n",dis[y]-dis[x]);
    }
    return 0;
}
/*
#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
const int inf=0x2fffffff;

struct node {
    int v,len;
}edge;

vector<node> g[50010];

int main()
{
    int m;
    scanf("%d",&m);
    int i,x,y,c,maxn=-1,minn=inf,cur,dis[50010]={0},v[50010]={0};
    for (i=0; i<m; i++) {
        scanf("%d%d%d",&x,&y,&c);
        if (y+1>maxn)
            maxn=y+1;
        if (x<minn)
            minn=x;
        edge.v=y+1;
        edge.len=c;
        g[x].push_back(edge);
    }
    for (i=minn; i<=maxn; i++) {
        edge.v=i+1;
        edge.len=0;
        g[i].push_back(edge);
        edge.v=i;
        edge.len=-1;
        g[i+1].push_back(edge);
    }
    for (i=minn; i<=maxn; i++)
        dis[i]=-inf;
    v[minn]=1;
    dis[minn]=0;
    queue<int> q;
    q.push(minn);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        v[cur]=0;
        for (i=0; i<g[cur].size(); i++)
            if (dis[g[cur][i].v]<dis[cur]+g[cur][i].len) {
                dis[g[cur][i].v]=dis[cur]+g[cur][i].len;
                if (!v[g[cur][i].v]) {
                    v[g[cur][i].v]=1;
                    q.push(g[cur][i].v);
                }
            }
    }
    printf("%d\n",dis[maxn]-dis[minn]);
    return 0;
}
*/
/*
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
const int inf=0x1ffffff;

struct node {
    int v,w,nex;
}edge[250010];


int main()
{
    int i,m,x,y,c,cur,maxn=-1,minn=inf,cnt=0;
    int pre[250010],dis[50010],v[50010];
    for (i=0; i<50010; i++) {
        pre[i]=-1;
        v[i]=0;
    }
    scanf("%d",&m);
    for (i=0; i<m; i++) {
        scanf("%d%d%d",&x,&y,&c);
        edge[cnt].v=y+1;
        edge[cnt].w=c;
        edge[cnt].nex=pre[x];
        pre[x]=cnt++;
        if (y+1>maxn)
            maxn=y+1;
        if (x<minn)
            minn=x;
    }
    for (i=minn; i<=maxn; i++) {
        edge[cnt].v=i+1;
        edge[cnt].w=0;
        edge[cnt].nex=pre[i];
        pre[i]=cnt++;
        edge[cnt].v=i;
        edge[cnt].w=-1;
        edge[cnt].nex=pre[i+1];
        pre[i+1]=cnt++;
    }
    for (i=minn; i<=maxn; i++)
        dis[i]=-inf;
    dis[minn]=0;
    v[minn]=1;
    queue<int> q;
    q.push(minn);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        v[cur]=0;
        for (i=pre[cur]; i!=-1; i=edge[i].nex)
            if (dis[edge[i].v]<dis[cur]+edge[i].w) {
                dis[edge[i].v]=dis[cur]+edge[i].w;
                if (!v[edge[i].v]) {
                    v[edge[i].v]=1;
                    q.push(edge[i].v);
                }
            }
    }
    printf("%d\n",dis[maxn]-dis[minn]);
    return 0;
}
*/
/*
 Problem Description
 You are given n closed, integer intervals [ai, bi] and n integers c1, ..., cn.
 
 Write a program that:
 
 > reads the number of intervals, their endpoints and integers c1, ..., cn from the standard input,
 
 > computes the minimal size of a set Z of integers which has at least ci common elements with interval [ai, bi], for each i = 1, 2, ..., n,
 
 > writes the answer to the standard output
 
 
 Input
 The first line of the input contains an integer n (1 <= n <= 50 000) - the number of intervals. The following n lines describe the intervals. The i+1-th line of the input contains three integers ai, bi and ci separated by single spaces and such that 0 <= ai <= bi <= 50 000 and 1 <= ci <= bi - ai + 1.
 
 Process to the end of file.
 
 
 
 Output
 The output contains exactly one integer equal to the minimal size of set Z sharing at least ci elements with interval [ai, bi], for each i = 1, 2, ..., n.
 
 
 Sample Input
 5
 3 7 3
 8 10 3
 6 8 1
 1 3 1
 10 11 1
 
 
 Sample Output
 6
*/