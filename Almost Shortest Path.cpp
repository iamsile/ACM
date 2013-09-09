#include <iostream>
using namespace std;
#define inf 99999
int map1[1005][1005],map2[1005][1005],
dist1[1005],prev[1005],dist2[1005];
void Dijkstra(int n,int v,int *dist,int *prev,int map[1005][1005])
{
    bool s[1005];
    int i,j,u,temp,newdist;
    for (i=0; i<n; i++) {
        dist[i]=map[v][i];
        s[i]=0;
        if (dist[i]==inf)
            prev[i]=0;
        else prev[i]=v;
    }
    dist[v]=0;
    s[v]=1;
    for (i=1; i<n; i++) {
        temp=inf;
        u=v;
        for (j=0; j<n; j++)
            if (!s[j]&&dist[j]<temp) {
                temp=dist[j];
                u=j;
            }
        s[u]=1;
        for (j=0; j<n; j++)
            if (!s[j]&&map[u][j]<inf) {
                newdist=dist[u]+map[u][j];
                if (newdist<dist[j]) {
                    dist[j]=newdist;
                    prev[j]=u;
                }
            }
    }
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)) {
        if (!n&&!m)
            return 0;
        int i,j,p,q,s,t,l;
        scanf("%d%d",&s,&t);
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                if (i==j)
                    map1[i][j]=map2[i][j]=0;
                else map1[i][j]=map2[i][j]=inf;
        for (i=0; i<m; i++) {
            scanf("%d%d%d",&p,&q,&l);
            map1[p][q]=l;
            map2[q][p]=l;
        }
        Dijkstra(n,s,dist1,prev,map1);
        if (dist1[t]!=inf) {
            Dijkstra(n,t,dist2,prev,map2);
            for (i=0; i<n; i++)
                for (j=0; j<n; j++)
                    if (dist1[i]+map1[i][j]+dist2[j]==dist1[t])
                        map1[i][j]=inf;
            Dijkstra(n, s, dist1, prev, map1);
            if (dist1[t]!=inf)
                printf("%d\n",dist1[t]);
            else printf("-1\n");
        }
        else printf("-1\n");
    }
    return 0;
}
/*
 Problem description
 Finding the shortest path that goes from a starting point to a destination point given a set of points and route lengths connecting them is an already well known problem, and it’s even part of our daily lives, as shortest path programs are widely available nowadays.
 Most people usually like very much these applications as they make their lives easier. Well, maybe not that much easier.
 Now that almost everyone can have access to GPS navigation devices able to calculate shortest paths, most routes that form the shortest path are getting slower because of heavy traffic. As most people try to follow the same path, it’s not worth it anymore to follow these directions. With this in his mind, your boss asks you to develop a new application that only he will have access to, thus saving him time whenever he has a meeting or any urgent event. He asks you that the program must answer not the shortest path, but the almost shortest path. He defines the almost shortest path as the shortest path that goes from a starting point to a destination point such that no route between two consecutive points belongs to any shortest path from the starting point to the destination.
 For example, suppose the figure below represents the map given, with circles representing     location points, and lines representing direct, one-way routes with lengths indicated. The starting point is marked as S and the destination point is marked as D. The bold lines belong to a shortest path (in this case there are two shortest paths, each with total length 4). Thus, the almost shortest path would be the one indicated by dashed lines (total length 5), as no route between two consecutive points belongs to any shortest path. Notice that there could exist more than one possible answer, for instance if the route with length 3 had length 1. There could exist no possible answer as well.
 
 
 
 Input
 The input contains several test cases. The first line of a test case contains two integers N (2 ≤ N ≤ 500) and M (1 ≤ M ≤ 104), separated by a single space, indicating respectively the number of points in the map and the number of existing one-way routes connecting two points directly. Each point is identified by an integer between 0 and N − 1. The second line contains two integers S and D, separated by a single space, indicating respectively the starting and the destination points (S ≠ D; 0 ≤ S,D < N). Each one of the following M lines contains three integers U, V and P (U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103), separated by single spaces, indicating the existence of a one-way route from U to V with distance P. There is at most one route from a given point U to a given point V , but notice that the existence of a route from U to V does not imply there is a route from V to U, and, if such road exists, it can have a different length. The end of input is indicated by a line containing only two zeros separated by a single space.
 
 The input must be read from standard input.
 
 
 Output
 For each test case in the input, your program must print a single line, containing -1 if it is not possible to match the requirements, or an integer representing the length of the almost shortest path found.
 
 The output must be written to standard output.
 
 
 Sample Input
 7 9
 0 6
 0 1 1
 0 2 1
 0 3 2
 0 4 3
 1 5 2
 2 6 4
 3 6 2
 4 6 4
 5 6 1
 4 6
 0 2
 0 1 1
 1 2 1
 1 3 1
 3 2 1
 2 0 3
 3 0 2
 6 8
 0 1
 0 1 1
 0 2 2
 0 3 3
 2 5 3
 3 4 2
 4 1 1
 5 1 1
 3 0 1
 0 0
 Sample Output
 5
 -1
 6
*/