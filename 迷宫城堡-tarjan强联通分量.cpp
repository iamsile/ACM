#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> q;
vector<int> map[10010];

int cnt,sum,d[10010],l[10010];
bool flag[10010];

void tarjan(int s)
{
    d[s]=l[s]=++cnt;
    flag[s]=1;
    q.push(s);
    int i,j;
    for (i=0; i<map[s].size(); i++) {
        j=map[s][i];
        if (!d[j]) {
            tarjan(j);
            if (l[j]<l[s])
                l[s]=l[j];
        }
        else if (flag[j]&&d[j]<l[s])
            l[s]=d[j];
    }
    if (l[s]==d[s]) {
        sum++;
        while (j!=s) {
            j=q.top();
            q.pop();
            flag[j]=0;
        }
    }
}
 
int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m),n||m) {
        int i,s,t;
        for (i=1; i<=n; i++)
            map[i].clear();
        for (i=0; i<m; i++) {
            scanf("%d%d",&s,&t);
            map[s].push_back(t);
        }
        memset(d, 0, sizeof(d));
        memset(l, 0, sizeof(l));
        for (i=1,cnt=0,sum=0; i<=n; i++)
            if (!d[i])
                tarjan(i);
        if (sum>1)
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
/*
 Problem Description
 为了训练小希的方向感，Gardon建立了一座大城堡，里面有N个房间(N<=10000)和M条通道(M<=100000)，每个通道都是单向的，就是说若称某通道连通了A房间和B房间，只说明可以通过这个通道由A房间到达B房间，但并不说明通过它可以由B房间到达A房间。Gardon需要请你写个程序确认一下是否任意两个房间都是相互连通的，即：对于任意的i和j，至少存在一条路径可以从房间i到房间j，也存在一条路径可以从房间j到房间i。
 
 
 Input
 输入包含多组数据，输入的第一行有两个数：N和M，接下来的M行每行有两个数a和b，表示了一条通道可以从A房间来到B房间。文件最后以两个0结束。
 
 
 Output
 对于输入的每组数据，如果任意两个房间都是相互连接的，输出"Yes"，否则输出"No"。
 
 
 Sample Input
 3 3
 1 2
 2 3
 3 1
 3 3
 1 2
 2 3
 3 2
 0 0
 
 
 Sample Output
 Yes
 No
*/