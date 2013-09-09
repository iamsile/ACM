#include <iostream>
using namespace std;
#define inf (1<<20)
int n,m,map[1100][1100];
bool v[1100];
long long r[1100],dis[1100];
void dijkstra(int s)
{
    int i,j,k;
    for (i=1; i<=n; i++) {
        v[i]=false;
        dis[i]=map[s][i];
    }
    v[s]=true;
    dis[s]=0;
    for (i=1; i<=n; i++) {
        int temp=inf;
        int index=0;
        for (j=1; j<=n; j++)
            if (!v[j]&&dis[j]<temp) {
                temp=dis[j];
                index=j;
            }
        v[index]=true;
        for (k=1; k<=n; k++)
            if (!v[k]&&dis[k]>dis[index]+map[k][index])
                dis[k]=dis[index]+map[k][index];
    }
}

long long bfs(int s)
{
    if (r[s]!=-1)
        return r[s];
    if (s==2)
        return 1;
    r[s]=0;
    for (int i=1; i<=n; i++) {
        if (map[i][s]!=inf&&dis[i]<dis[s])
            r[s]+=bfs(i);
    }
    return r[s];
}

int main()
{
    while (cin >> n&&n) {
        int i,j,s,t,w;
        for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++) {
                if (i==j)
                    map[i][j]=0;
                else map[i][j]=inf;
            }
        }
        cin >> m;
        for (i=1; i<=m; i++) {
            cin >> s >> t >> w;
            map[s][t]=map[t][s]=w;
        }
        dijkstra(2);
        memset(r, -1, sizeof(r));
        printf("%lld\n",bfs(1));
    }
    return 0;
}
//先求最短路，然后在bfs一次
/*
 Problem Description
 Jimmy experiences a lot of stress at work these days, especially since his accident made working difficult. To relax after a hard day, he likes to walk home. To make things even nicer, his office is on one side of a forest, and his house is on the other. A nice walk through the forest, seeing the birds and chipmunks is quite enjoyable. 
 The forest is beautiful, and Jimmy wants to take a different route everyday. He also wants to get home before dark, so he always takes a path to make progress towards his house. He considers taking a path from A to B to be progress if there exists a route from B to his home that is shorter than any possible route from A. Calculate how many different routes through the forest Jimmy might take. 
 
 
 Input
 Input contains several test cases followed by a line containing 0. Jimmy has numbered each intersection or joining of paths starting with 1. His office is numbered 1, and his house is numbered 2. The first line of each test case gives the number of intersections N, 1 < N ≤ 1000, and the number of paths M. The following M lines each contain a pair of intersections a b and an integer distance 1 ≤ d ≤ 1000000 indicating a path of length d between intersection a and a different intersection b. Jimmy may walk a path any direction he chooses. There is at most one path between any pair of intersections. 
 
 
 Output
 For each test case, output a single integer indicating the number of different routes through the forest. You may assume that this number does not exceed 2147483647
 
 
 Sample Input
 5 6
 1 3 2
 1 4 2
 3 4 3
 1 5 12
 4 2 34
 5 2 24
 7 8
 1 3 1
 1 4 1
 3 7 1
 7 4 1
 7 5 1
 6 7 1
 5 2 1
 6 2 1
 0
 
 
 Sample Output
 2
 4
*/