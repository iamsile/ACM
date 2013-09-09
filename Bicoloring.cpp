#include <iostream>
using namespace std;
#include<stdlib.h>
int map[201][201]={0},visited[201]={0},color[201]={0};
int n,m;
int i,x,y,flag;
void dfs(int begin)
{
    if(begin==n) {
        flag=0;
        return;
    }
    if(flag==0)
        return;
    int i,flagx=0,flagy=0;
    for(i=0;i<visited[begin];i++) {
        if(color[map[begin][i]]==1) 
            flagx=1;
        else if(color[map[begin][i]]==2) 
            flagy=1;
    }   
    if(flagx==0&&flagy==1) {
        color[begin]=1; 
        dfs(begin+1);
    }
    else if(flagx==1&&flagy==0)  {
        color[begin]=2;
        dfs(begin+1);
    }
    if(flagx==0&&flagy==0) {
        color[begin]=1;
        dfs(begin+1);
        color[begin]=2; 
        dfs(begin+1);
    }
}
int main()
{
    while(cin >> n&&n)
    {
        cin >> m;
        for(i=0;i<n;i++) {
            visited[i]=0;
            color[i]=0;
        }
        for(i=0;i<m;i++)
        {
            cin >> x >> y;
            map[x][visited[x]]=y;
            map[y][visited[y]]=x;
            visited[x]++;visited[y]++;
        }
        flag=1;
        dfs(0);
        if(flag==0) 
            cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
/*
 The four-color theorem states that every planar map can be colored using only four colors in such a way that no region is colored using the same color as a neighbor. After being open for over 100 years, the theorem was proven in 1976 with the assistance of a computer.
 Here you are asked to solve a simpler problem. Decide whether a given connected graph can be bicolored, i.e., can the vertices be painted red and black such that no two adjacent vertices have the same color.
 
 To simplify the problem, you can assume the graph will be connected, undirected, and not contain self-loops (i.e., edges from a vertex to itself).
 
 Input
 
 The input consists of several test cases. Each test case starts with a line containing the number of vertices n, where 1 < n < 200. Each vertex is labeled by a number from 0 to n - 1. The second line contains the number of edges l. After this, l lines follow, each containing two vertex numbers specifying an edge.
 An input with n = 0 marks the end of the input and is not to be processed.
 
 Output
 
 Decide whether the input graph can be bicolored, and print the result as shown below.
 Sample Input
 
 3
 3
 0 1
 1 2
 2 0
 9
 8
 0 1
 0 2
 0 3
 0 4
 0 5
 0 6
 0 7
 0 8
 0
 Sample Output
 
 NOT BICOLORABLE.
 BICOLORABLE.
*/