#include <iostream>
using namespace std;
const int inf=999999;
int minn,k,n,r,v[10001],flag[10001];
struct {
    int s,t,l,cos,next;
}path[10001];

void dfs(int cur,int dis,int cost)
{
    if (dis>minn)
        return;
    if (cost<0)
        return;
    if (cur==n&&cost>=0&&dis<minn) {
        minn=dis;
        return;
    }
    for (int i=flag[cur]; i>-1; i=path[i].next) {
        int y=path[i].t;
        int z=path[i].l;
        if (!v[y]&&cost>=path[i].cos) {
            v[y]=1;
            dfs(y, dis+z, cost-path[i].cos);
            v[y]=0;
        }
    }
}

int main()
{
    while (~scanf("%d%d%d",&k,&n,&r)) {
        int i,cnt=0,x,y,z,w;
        minn=inf;
        memset(flag, -1, sizeof(flag));
        for (i=0; i<r; i++) {
            scanf("%d%d%d%d",&x,&y,&z,&w);
            path[cnt].s=x;
            path[cnt].t=y;
            path[cnt].l=z;
            path[cnt].cos=w;
            path[cnt].next=flag[x];
            flag[x]=cnt++;
        }
        memset(v, 0, sizeof(v));
        dfs(1,0,k);
        if (minn==inf)
            cout << "-1\n";
        else cout << minn << '\n';
    }
    return 0;
}
/*
 Problem description
 编号为1…N 的N个城市之间以单向路连接，每一条道路有两个参数： 路的长度和通过这条路需付的费用。 Bob和Alice生活在城市1，但是当Bob发现了Alice玩扑克时欺骗他之后，他决定与她翻脸，离开城市1前往城市N. Bob想尽快到达城市N，他是他的钱不多。 我们希望你帮助Bob找到一条从城市1到城市N的总费用不超过Bob的承受能力的最短路径。 
 
 Input
 输入的第1行包含一个整数K, 0 <= K <= 10000, 表示Bob能承受的最大费用； 第2行包含一个整数N, 2 <= N <= 100,表示城市的总数； 第3行包含整数R, 1 <= R <= 10000,表示道路的条数； 接下来的R行，每行用S D L T（以空格隔开）表示一条道路： 　　S：表示道路的出发城市，1 <= S <= N D：表示道路的目标城市，1 <= D <= N L：表示道路的长度，1 <= L <= 100 T：表示通过这条道路需付的费用，0 <= T <=100 
 
 Output
 　仅有的一行中输出总费用小余或等于最大费用K的最短路径的长度。如果这样的路径不存在，则仅仅输出 -1 。 
 
 Sample Input
 5
 6
 7
 1 2 2 3
 2 4 3 3
 3 4 2 4
 1 3 4 1
 4 6 2 1
 3 5 2 0
 5 4 3 2
 Sample Output
 11
*/