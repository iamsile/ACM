#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int inf=0x3fffffff;

int n,map[510][510],dis[600],v[600],cnt[600];

bool spfa()
{
    int i,cur;
    for (i=1; i<=n; i++) {
        dis[i]=inf;
        v[i]=0;
        cnt[i]=0;
    }
    dis[1]=0;
    v[1]=1;
    cnt[1]=1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        v[cur]=0;
        for (i=1; i<=n; i++)
            if (dis[i]>dis[cur]+map[cur][i]) {
                dis[i]=dis[cur]+map[cur][i];
                if (!v[i]) {
                    cnt[i]++;
                    v[i]=1;
                    if (cnt[i]>=n)
                        return 0;
                    q.push(i);
                }
            }
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int i,j,m,k,x,y,c;
        scanf("%d%d%d",&n,&m,&k);
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                map[i][j]=inf;
        for (i=0; i<m; i++) {
            scanf("%d%d%d",&x,&y,&c);
            if (map[x][y]>c)
                map[x][y]=map[y][x]=c;
        }
        for (i=0; i<k; i++) {
            scanf("%d%d%d",&x,&y,&c);
            map[x][y]=0-c;
        }
        if (!spfa())
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
 Description
 
 While exploring his many farms, Farmer John has discovered a number of amazing wormholes. A wormhole is very peculiar because it is a one-way path that delivers you to its destination at a time that is BEFORE you entered the wormhole! Each of FJ's farms comprises N (1 ≤ N ≤ 500) fields conveniently numbered 1..N, M (1 ≤ M ≤ 2500) paths, and W (1 ≤ W ≤ 200) wormholes.
 
 As FJ is an avid time-traveling fan, he wants to do the following: start at some field, travel through some paths and wormholes, and return to the starting field a time before his initial departure. Perhaps he will be able to meet himself :) .
 
 To help FJ find out whether this is possible or not, he will supply you with complete maps to F (1 ≤ F ≤ 5) of his farms. No paths will take longer than 10,000 seconds to travel and no wormhole can bring FJ back in time by more than 10,000 seconds.
 
 Input
 
 Line 1: A single integer, F. F farm descriptions follow.
 Line 1 of each farm: Three space-separated integers respectively: N, M, and W
 Lines 2..M+1 of each farm: Three space-separated numbers (S, E, T) that describe, respectively: a bidirectional path between S and E that requires T seconds to traverse. Two fields might be connected by more than one path.
 Lines M+2..M+W+1 of each farm: Three space-separated numbers (S, E, T) that describe, respectively: A one way path from S to E that also moves the traveler back T seconds.
 Output
 
 Lines 1..F: For each farm, output "YES" if FJ can achieve his goal, otherwise output "NO" (do not include the quotes).
 Sample Input
 
 2
 3 3 1
 1 2 2
 1 3 4
 2 3 1
 3 1 3
 3 2 1
 1 2 3
 2 3 4
 3 1 8
 Sample Output
 
 NO
 YES
*/