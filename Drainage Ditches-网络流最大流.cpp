#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int inf=0x7fffffff;

int map[205][205],v[205];

int dfs(int n,int s,int f,int t)
{
    if(s==t)
        return f;
    if(v[s])
        return 0;
    v[s]=1;
    int i,flag;
    for (i=1; i<=n; i++) {
        if (map[s][i]&&(flag=dfs(n, i, f<map[s][i]?f:map[s][i], t))) {
            map[s][i]-=flag;
            map[i][s]+=flag;
            return flag;
        }
    }
    return 0;
}

int mflow(int n,int s,int t)
{
    memset(v, 0, sizeof(v));
    int sum,maxn=0;
    while ((sum=dfs(n,s,inf,t))) {
        memset(v, 0, sizeof(v));
        maxn+=sum;
    }
    return maxn;
}

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        memset(map, 0, sizeof(map));
        int i,x,y,c;
        for (i=0; i<n; i++) {
            scanf("%d%d%d",&x,&y,&c);
            map[x][y]+=c;
        }
        printf("%d\n",mflow(m,1,m));
    }
    return 0;
}
/*
#include <iostream>
#include <queue>
using namespace std;
const int inf=0x2fffffff;

int map[205][205],v[205];

int mflow(int n,int s,int t) //结点，起点，终点
{
    int i,k,cur,pre[205],min_flow[205],flow[205][205],ans=0;
    //pre用来纪录结点的父亲结点；min_flow表示当前路径中最小的一段的值，也即限制值；
    //flow纪录当前网络中的流，ans表示最终的结果
    memset(flow, 0, sizeof(flow));
    while (1) {//一直循环，直到不存在增广路径
        queue<int> q;
        memset(pre, -1, sizeof(pre));
        q.push(s);
        min_flow[s]=inf;
        pre[s]=-2;//起点的父亲点需要特殊标示
        while (!q.empty()) {//bfs寻找增广路径
            cur=q.front();
            q.pop();
            for (i=1; i<=n; i++)//由结点cur开始向外拓展
                if (pre[i]==-1&&flow[cur][i]<map[cur][i]) {//当结点i还未被探索到，并且还有可用流量
                    q.push(i);
                    pre[i]=cur;//标示父结点
                    min_flow[i]=min(min_flow[cur],(map[cur][i]-flow[cur][i]));//求得min_flow
                }
            if (pre[t]!=-1) {//t的父亲节点不为初始值，说明bfs已经找到了一条路径
                k=t;
                while (pre[k]>=0) {
                    flow[pre[k]][k]+=min_flow[t];//将新的流量加入flow
                    flow[k][pre[k]]=-flow[pre[k]][k];
                    k=pre[k];
                }
                break;
            }
        }
        if (pre[t]==-1)
            return ans;//不存在增广路径，返回
        else ans+=min_flow[t];
    }
}

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)) {
        memset(map, 0, sizeof(map));
        int i,x,y,c;
        for (i=0; i<n; i++) {
            scanf("%d%d%d",&x,&y,&c);
            map[x][y]+=c;
        }
        printf("%d\n",mflow(m,1,m));
    }
    return 0;
}
*/
/*
 Problem Description
 Every time it rains on Farmer John's fields, a pond forms over Bessie's favorite clover patch. This means that the clover is covered by water for awhile and takes quite a long time to regrow. Thus, Farmer John has built a set of drainage ditches so that Bessie's clover patch is never covered in water. Instead, the water is drained to a nearby stream. Being an ace engineer, Farmer John has also installed regulators at the beginning of each ditch, so he can control at what rate water flows into that ditch.
 Farmer John knows not only how many gallons of water each ditch can transport per minute but also the exact layout of the ditches, which feed out of the pond and into each other and stream in a potentially complex network.
 Given all this information, determine the maximum rate at which water can be transported out of the pond and into the stream. For any given ditch, water flows in only one direction, but there might be a way that water can flow in a circle.
 
 
 Input
 The input includes several cases. For each case, the first line contains two space-separated integers, N (0 <= N <= 200) and M (2 <= M <= 200). N is the number of ditches that Farmer John has dug. M is the number of intersections points for those ditches. Intersection 1 is the pond. Intersection point M is the stream. Each of the following N lines contains three integers, Si, Ei, and Ci. Si and Ei (1 <= Si, Ei <= M) designate the intersections between which this ditch flows. Water will flow through this ditch from Si to Ei. Ci (0 <= Ci <= 10,000,000) is the maximum rate at which water will flow through the ditch.
 
 
 Output
 For each case, output a single integer, the maximum rate at which water may emptied from the pond.
 
 
 Sample Input
 5 4
 1 2 40
 1 4 20
 2 4 20
 2 3 30
 3 4 10
 
 
 Sample Output
 50
*/