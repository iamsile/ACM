#include <iostream>
using namespace std;
int f[1001],ans;

struct node {
    int s,t,w,flag;
}path[5011];

int cmp(const void *a,const void *b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;
    if (c->flag!=d->flag)
        return d->flag - c->flag;
    else return c->w - d->w;
}

int find(int x)
{
    return f[x]==x ? x : find(f[x]);
}

void Union(int x,int y,int l,int lab)
{
    if (x==y)
        return;
    f[y]=x;
    if (!lab)
        ans+=l;
}

int main()
{
    int n;
    while (~scanf("%d",&n)&&n) {
        int i,k=n*(n-1)/2;
        for (i=0; i<=n; i++)
            f[i]=i;
        for (i=0; i<k; i++)
            scanf("%d%d%d%d",&path[i].s,&path[i].t,&path[i].w,&path[i].flag);
        qsort(path, k, sizeof(path[0]), cmp);
        for (i=0,ans=0; i<k; i++)
            Union(find(path[i].s),find(path[i].t),path[i].w,path[i].flag);
        printf("%d\n",ans);
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
const int inf=999999;

int main()
{
    int n;
    while (~scanf("%d",&n)&&n) {
        int i,j,s,t,w,f,k=n*(n-1)/2,lab,min,sum=0,map[101][101]={0},v[1001];
        for (i=0; i<k; i++) {
            scanf("%d%d%d%d",&s,&t,&w,&f);
            if (f==0)
                map[s-1][t-1]=map[t-1][s-1]=w;
            else map[s-1][t-1]=map[t-1][s-1]=0;
        }
        memset(v, 0, sizeof(v));
        v[0]=1;
        for (i=1; i<n; i++) {
            min=inf;
            for (j=0; j<n; j++)
                if (!v[j]&&map[0][j]<min) {
                    min=map[0][j];
                    lab=j;
                }
            sum+=min;
            v[lab]=1;
            for (j=0; j<n; j++)
                if (!v[j]&&map[0][j]>map[lab][j]) {
                    map[0][j]=map[lab][j];
                }
        }
        printf("%d\n",sum);
    }
    return 0;
}
*/
/*
 Problem Description
 省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
 
 
 Input
 测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。
 
 当N为0时输入结束。
 
 
 Output
 每个测试用例的输出占一行，输出全省畅通需要的最低成本。
 
 
 Sample Input
 3
 1 2 1 0
 1 3 2 0
 2 3 4 0
 3
 1 2 1 0
 1 3 2 0
 2 3 4 1
 3
 1 2 1 0
 1 3 2 1
 2 3 4 1
 0
 
 
 Sample Output
 3
 1
 0
*/