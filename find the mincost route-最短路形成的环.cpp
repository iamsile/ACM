#include <iostream>
using namespace std;
const int inf=999999;

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        int i,j,x,y,t,k,ans=inf,map[101][101],d[101][101];
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                map[i][j]=inf;
        for (i=1; i<=m; i++) {
            scanf("%d%d%d",&x,&y,&t);
            if (map[x][y]>t) {
                map[x][y]=t;
                map[y][x]=t;
            }
        }
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                d[i][j]=map[i][j];
        for (k=1; k<=n; k++) {
            for (i=1; i<k; i++)
                for (j=i+1; j<k; j++)
                    ans=min(ans, map[i][j]+d[i][k]+d[k][j]);
            for (i=1; i<=n; i++)
                for (j=1; j<=n; j++)
                    if (map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
        }
        if (ans!=inf)
            printf("%d\n",ans);
        else printf("It's impossible.\n");
    }
    return 0;
}
/*
 Problem Description
 杭州有N个景区，景区之间有一些双向的路来连接，现在8600想找一条旅游路线，这个路线从A点出发并且最后回到A点，假设经过的路线为V1,V2,....VK,V1,那么必须满足K>2,就是说至除了出发点以外至少要经过2个其他不同的景区，而且不能重复经过同一个景区。现在8600需要你帮他找一条这样的路线，并且花费越少越好。
 
 
 Input
 第一行是2个整数N和M（N <= 100, M <= 1000)，代表景区的个数和道路的条数。
 接下来的M行里，每行包括3个整数a,b,c.代表a和b之间有一条通路，并且需要花费c元(c <= 100)。
 
 
 Output
 对于每个测试实例，如果能找到这样一条路线的话，输出花费的最小值。如果找不到的话，输出"It's impossible.".
 
 
 Sample Input
 3 3
 1 2 1
 2 3 1
 1 3 1
 3 3
 1 2 1
 1 2 3
 2 3 1
 
 
 Sample Output
 3
 It's impossible.
*/