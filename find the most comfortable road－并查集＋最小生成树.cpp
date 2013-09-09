#include <iostream>
using namespace std;
int f[1001];
const int inf=999999;
struct node {
    int s,t,w;
}path[1001];

int cmp(const void *a,const void *b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;
    return c->w - d->w;
}

int find(int x)
{
    return f[x]==x ? x : find(f[x]);
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,m,t,st,end,min,pathx,pathy;
        cin >> m;
        for (i=0; i<m; i++)
            cin >> path[i].s >> path[i].t >> path[i].w;
        qsort(path, m, sizeof(path[0]), cmp);
        cin >> t;
        while (t--) {
            cin >> st >> end;
            min=inf;
            for (i=0; i<m; i++) {
                for (j=1; j<=n; j++)
                    f[j]=j;
                for (j=i; j<m; j++) {
                    pathx=find(path[j].s);
                    pathy=find(path[j].t);
                    f[pathx]=pathy;
                    if (find(st)==find(end))
                        break;
                }
                if (j>=m)
                    break;
                if (j<m)
                    if (path[j].w-path[i].w<min) 
                        min=path[j].w-path[i].w;
            }
            if (min!=inf)
                cout << min << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}
/*
 Problem Description
 XX星有许多城市，城市之间通过一种奇怪的高速公路SARS(Super Air Roam Structure---超级空中漫游结构）进行交流，每条SARS都对行驶在上面的Flycar限制了固定的Speed，同时XX星人对 Flycar的“舒适度”有特殊要求，即乘坐过程中最高速度与最低速度的差越小乘坐越舒服 ,(理解为SARS的限速要求，flycar必须瞬间提速/降速，痛苦呀 ),
 但XX星人对时间却没那么多要求。要你找出一条城市间的最舒适的路径。(SARS是双向的）。
 
 
 Input
 输入包括多个测试实例，每个实例包括：
 第一行有2个正整数n (1<n<=200)和m (m<=1000),表示有N个城市和M条SARS。
 接下来的行是三个正整数StartCity,EndCity,speed,表示从表面上看StartCity到EndCity,限速为speedSARS。speed<=1000000
 然后是一个正整数Q（Q<11),表示寻路的个数。
 接下来Q行每行有2个正整数Start,End, 表示寻路的起终点。
 
 
 Output
 每个寻路要求打印一行，仅输出一个非负整数表示最佳路线的舒适度最高速与最低速的差。如果起点和终点不能到达，那么输出-1。
 
 
 Sample Input
 4 4
 1 2 2
 2 3 4
 1 4 1
 3 4 2
 2
 1 3
 1 2
 
 
 Sample Output
 1
 0
*/