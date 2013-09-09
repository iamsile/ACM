#include <iostream>
using namespace std;
int f[110];

struct node{
    int s,t,l,flag;
};

int find(int x)
{
    return f[x]==x ? x : find(f[x]);
}

void Union(int x,int y)
{
    f[find(x)]=f[find(y)];
}

int cmp(const void *a,const void *b)
{
    struct node *c=(node *)a;
    struct node *d=(node *)b;
    if (c->flag!=d->flag)
        return d->flag - c->flag;
    else return c->l - d->l;
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,m,x,y,cnt=0,sum=0,map[110][110],v[110][110];
        node path[10110];
        memset(v, 0, sizeof(v));
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                cin >> map[i][j];
        cin >> m;
        for (i=1; i<=m; i++) {
            cin >> x >> y;
            v[x][y]=1;
        }
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (map[i][j]) {
                    cnt++;
                    path[cnt].s=i;
                    path[cnt].t=j;
                    path[cnt].l=map[i][j];
                    path[cnt].flag=v[i][j];
                }
        for (i=1; i<=n; i++)
            f[i]=i;
        qsort(path+1, cnt, sizeof(path[1]), cmp);
        for (i=1; i<=cnt; i++)
            if (find(path[i].s)!=find(path[i].t)) {
                Union(path[i].s,path[i].t);
                if (!path[i].flag)
                    sum+=path[i].l;
            }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem Description
 There are N villages, which are numbered from 1 to N, and you should build some roads such that every two villages can connect to each other. We say two village A and B are connected, if and only if there is a road between A and B, or there exists a village C such that there is a road between A and C, and C and B are connected. 
 
 We know that there are already some roads between some villages and your job is the build some roads such that all the villages are connect and the length of all the roads built is minimum.
 
 
 Input
 The first line is an integer N (3 <= N <= 100), which is the number of villages. Then come N lines, the i-th of which contains N integers, and the j-th of these N integers is the distance (the distance should be an integer within [1, 1000]) between village i and village j.
 
 Then there is an integer Q (0 <= Q <= N * (N + 1) / 2). Then come Q lines, each line contains two integers a and b (1 <= a < b <= N), which means the road between village a and village b has been built.
 
 
 Output
 You should output a line contains an integer, which is the length of all the roads to be built such that all the villages are connected, and this value is minimum. 
 
 
 Sample Input
 3
 0 990 692
 990 0 179
 692 179 0
 1
 1 2
 
 
 Sample Output
 179
*/