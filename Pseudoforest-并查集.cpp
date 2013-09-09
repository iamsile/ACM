#include <iostream>
using namespace std;
int f[10010],n,m,ans;
bool flag[10010];
struct node {
    int s,t,w;
}path[100100];

int find(int x)
{
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

bool Union(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if (fx==fy) {
        if (!flag[fx]) {
            flag[fx]=1;
            return 1;
        }
        return 0;
    }
    if (flag[fx]&&flag[fy])
        return 0;
    if (flag[fx])
        f[fy]=fx;
    else f[fx]=fy;
    return 1;
}

bool cmp(node a,node b)
{
    return a.w > b.w;
}

int main()
{
    int i;
    while (scanf("%d%d",&n,&m),n) {
        for (i=0; i<=n; i++)
            f[i]=i;
        memset(flag, 0, sizeof(flag));
        for (i=0; i<m; i++)
            scanf("%d%d%d",&path[i].s,&path[i].t,&path[i].w);
        sort(path, path+m, cmp);
        for (i=0,ans=0; i<m; i++)
            if (Union(path[i].s,path[i].t))
                ans+=path[i].w;
        printf("%d\n",ans);
    }
    return 0;
}
/*
 Problem Description
 In graph theory, a pseudoforest is an undirected graph in which every connected component has at most one cycle. The maximal pseudoforests of G are the pseudoforest subgraphs of G that are not contained within any larger pseudoforest of G. A pesudoforest is larger than another if and only if the total value of the edges is greater than another one’s.
 
 
 
 Input
 The input consists of multiple test cases. The first line of each test case contains two integers, n(0 < n <= 10000), m(0 <= m <= 100000), which are the number of the vertexes and the number of the edges. The next m lines, each line consists of three integers, u, v, c, which means there is an edge with value c (0 < c <= 10000) between u and v. You can assume that there are no loop and no multiple edges.
 The last test case is followed by a line containing two zeros, which means the end of the input.
 
 
 Output
 Output the sum of the value of the edges of the maximum pesudoforest.
 
 
 Sample Input
 3 3
 0 1 1
 1 2 1
 2 0 1
 4 5
 0 1 1
 1 2 1
 2 3 1
 3 0 1
 0 2 2
 0 0
 
 
 Sample Output
 3
 5
*/