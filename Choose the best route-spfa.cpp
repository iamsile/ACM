#include <iostream>
#include <queue>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,t,map[1011][1011],dis[1010],v[1010];

void spfa(int s)
{
    int i,cur;
    memset(v, 0, sizeof(v));
    memset(dis, inf, sizeof(dis));
    queue<int> q;
    q.push(s);
    v[s]=1;
    dis[s]=0;
    while (!q.empty()) {
        cur=q.front();
        v[cur]=0;
        q.pop();
        for (i=1; i<=n; i++)
            if (dis[i]>dis[cur]+map[cur][i]) {
                dis[i]=dis[cur]+map[cur][i];
                if (!v[i]) {
                    v[i]=1;
                    q.push(i);
                }
            }
    }
}

int main()
{
    while (~scanf("%d%d%d",&n,&m,&t)) {
        int i,j,x,y,c,cas,s,min=inf;
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                if (i==j)
                    map[i][j]=0;
                else
                    map[i][j]=0x3f3f3f3f;
        for (i=1; i<=m; i++) {
            scanf("%d%d%d",&x,&y,&c);
            if (map[y][x]>c)
                map[y][x]=c;
        }
        spfa(t);
        scanf("%d",&cas);
        for (i=0; i<cas; i++) {
            scanf("%d",&s);
            if (min>dis[s])
                min=dis[s];
        }
        if (min!=inf)
            printf("%d\n",min);
        else printf("-1\n");
    }
    return 0;
}
/*
 Problem Description
 One day , Kiki wants to visit one of her friends. As she is liable to carsickness , she wants to arrive at her friend’s home as soon as possible . Now give you a map of the city’s traffic route, and the stations which are near Kiki’s home so that she can take. You may suppose Kiki can change the bus at any station. Please find out the least time Kiki needs to spend. To make it easy, if the city have n bus stations ,the stations will been expressed as an integer 1,2,3…n.
 
 
 Input
 There are several test cases.
 Each case begins with three integers n, m and s,(n<1000,m<20000,1=<s<=n) n stands for the number of bus stations in this city and m stands for the number of directed ways between bus stations .(Maybe there are several ways between two bus stations .) s stands for the bus station that near Kiki’s friend’s home.
 Then follow m lines ,each line contains three integers p , q , t (0<t<=1000). means from station p to station q there is a way and it will costs t minutes .
 Then a line with an integer w(0<w<n), means the number of stations Kiki can take at the beginning. Then follows w integers stands for these stations.
 
 
 Output
 The output contains one line for each data set : the least time Kiki needs to spend ,if it’s impossible to find such a route ,just output “-1”.
 
 
 Sample Input
 5 8 5
 1 2 2
 1 5 3
 1 3 4
 2 4 7
 2 5 6
 2 3 5
 3 5 1
 4 5 1
 2
 2 3
 4 3 4
 1 2 3
 1 3 4
 2 3 2
 1
 1
 
 
 Sample Output
 1
 -1
*/