#include <iostream>
using namespace std;

struct node {
    int s,t,w;
}path[5010];
int f[110],ans;

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

void Union(int x,int y,int l)
{
    if (x==y)
        return;
    if (x<y)
        f[y]=x;
    else f[x]=y;
    ans+=l;
}

int main()
{
    int n;
    while (scanf("%d",&n),n) {
        int i,k=n*(n-1)/2;
        for (i=0; i<=n; i++)
            f[i]=i;
        for (i=0; i<k; i++)
            scanf("%d%d%d",&path[i].s,&path[i].t,&path[i].w);
        qsort(path, k, sizeof(path[0]), cmp);
        for (i=0,ans=0; i<k; i++)
            Union(find(path[i].s),find(path[i].t),path[i].w);
        printf("%d\n",ans);
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int map[101][101];
const int inf=99999;

int main()
{
    int n;
    while (~scanf("%d",&n)&&n) {
        int i,j,x,y,w,min,flag,sum=0,k=n*(n-1)/2,v[5011];
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                if (i==j)
                    map[i][i]=inf;
                else map[i][j]=map[j][i]=0;
        for (i=0; i<k; i++) {
            scanf("%d%d%d",&x,&y,&w);
            map[x-1][y-1]=map[y-1][x-1]=w;
        }
        memset(v, 0, sizeof(v));
        v[0]=1;
        for (i=1; i<n; i++) {
            min=inf;
            for (j=0; j<n; j++)
                if (!v[j]&&map[0][j]<min) {
                    min=map[0][j];
                    flag=j;
                }
            sum+=min;
            v[flag]=1;
            for (j=0; j<n; j++)
                if (!v[j]&&map[0][j]>map[flag][j])
                    map[0][j]=map[flag][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}
*/
/*
 Problem Description
 某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。
 
 
 Input
 测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。
 当N为0时，输入结束，该用例不被处理。
 
 
 Output
 对每个测试用例，在1行里输出最小的公路总长度。
 
 
 Sample Input
 3
 1 2 1
 1 3 2
 2 3 4
 4
 1 2 1
 1 3 4
 1 4 1
 2 3 3
 2 4 2
 3 4 5
 0
 
 
 Sample Output
 3
 5
*/