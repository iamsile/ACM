#include <iostream>
#include <vector>
using namespace std;
#define N 1510
vector<int> g[N];
int v[N],flag[N];

bool dfs(int s)
{
    int i,k;
    for (i=0; i<g[s].size(); i++) {
        k=g[s][i];
        if (!v[k]) {
            v[k]=1;
            if (flag[k]==-1||dfs(flag[k])) {
                flag[k]=s;
                return 1;
            }
        }
        
    }
    return 0;
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        int i,j,s,m,t,sum=0;
        for (i=0; i<n; i++)
            g[i].clear();
        memset(flag, -1, sizeof(flag));
        for (i=0; i<n; i++) {
            scanf("%d:(%d)",&s,&m);
            if (m)
                for (j=0; j<m; j++) {
                    scanf("%d",&t);
                    g[s].push_back(t);
                    g[t].push_back(s);
                }
        }
        for (i=0; i<n; i++) {
            memset(v, 0, sizeof(v));
            if (dfs(i))
                sum++;
        }
        printf("%d\n",sum/2);
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
#define N 1510
int n,map[N][N],v[N],flag[N];

int dfs(int s)
{
    for (int i=0; i<n; i++)
        if (!v[i]&&map[s][i]) {
            v[i]=1;
            if (flag[i]==0||dfs(flag[i])) {
                flag[i]=s;
                return 1;
            }
        }
    return 0;
}

int main()
{
    while (~scanf("%d",&n)) {
        int i,j,s,m,t,sum=0;
        memset(map, 0, sizeof(map));
        for (i=0; i<n; i++) {
            scanf("%d:(%d)",&s,&m);
            for (j=0; j<m; j++) {
                scanf("%d",&t);
                map[s][t]=map[t][s]=1;
            }
            flag[i]=0;
        }
        for (i=0; i<n; i++) {
            memset(v, 0, sizeof(v));
            if (dfs(i))
                sum++;
        }
        printf("%d\n",sum/2);
    }
    return 0;
}
/*
 Problem Description
 Bob enjoys playing computer games, especially strategic games, but sometimes he cannot find the solution fast enough and then he is very sad. Now he has the following problem. He must defend a medieval city, the roads of which form a tree. He has to put the minimum number of soldiers on the nodes so that they can observe all the edges. Can you help him?
 
 Your program should find the minimum number of soldiers that Bob has to put for a given tree.
 
 The input file contains several data sets in text format. Each data set represents a tree with the following description:
 
 the number of nodes
 the description of each node in the following format
 node_identifier:(number_of_roads) node_identifier1 node_identifier2 ... node_identifier
 or
 node_identifier:(0)
 
 The node identifiers are integer numbers between 0 and n-1, for n nodes (0 < n <= 1500). Every edge appears only once in the input data.
 
 For example for the tree:
 
 
 
 the solution is one soldier ( at the node 1).
 
 The output should be printed on the standard output. For each given input data set, print one integer number in a single line that gives the result (the minimum number of soldiers). An example is given in the following table:
 
 
 Sample Input
 4
 0:(1) 1
 1:(2) 2 3
 2:(0)
 3:(0)
 5
 3:(3) 1 4 2
 1:(1) 0
 2:(0)
 0:(0)
 4:(0)
 
 
 Sample Output
 1
 2
*/