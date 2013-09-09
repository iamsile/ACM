#include <iostream>
using namespace std;
int a[1001][1001],b[1001][1001],n,m;
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
void bfs(int x,int y)
{
    b[x][y]=1;
    for (int i=0; i<8; i++) {
        if (a[dx[i]+x][dy[i]+y]&&b[dx[i]+x][dy[i]+y]==0&&
            dx[i]+x>=0&&dx[i]+x<n&&dy[i]+y>=0&&dy[i]+y<m) {
            bfs(x+dx[i], y+dy[i]);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int i,j,sum=0;
        char s;
        for (i=0; i<n; i++)
            for (j=0; j<m; j++) {
                cin >> s;
                if (s=='@')
                    a[i][j]=1;
                else a[i][j]=0;
                b[i][j]=0;
            }
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                if (a[i][j]&&b[i][j]==0)
                {
                    bfs(i,j);
                    sum++;
                }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 Jangalestan is a country which its map is a m×n table. Each cell of this table is either empty or there is a tree in it. We call two cells of this table adjacent if they have an edge or vertex in common. We say there is a path between two trees in the cells (is,js) and (if,jf) of this table if there is a sequence (is,js), (i1,j1)(i2,j2),...(ik,jk), (if,jf) of the table cells such that each element of this sequence is adjacent to its previous and next elements. A city in Jangalestan is a maximal set of trees such that each pair of trees in the set has a path to each others. 
 You are given the map of Jangalestan. You should find the number of cities in Jangalestan.
 
 
 Input
 First line of Inputs contains number of the tests.
 For each test case, first you are given 1≤m≤100 and 1≤n≤100 the number of rows and columns in Jangalestan’s plan. Then, in the next m line, in each line you are given n character. Character ‘@’ means that there is a tree in that cell and character ‘*’ shows that it’s an empty cell. 
 
 Output
 For each test case output the number of cities in Jangalestan. 
 
 Sample Input
 2
 2 3
 *@*
 @**
 4 4
 ***@
 @***
 ***@
 *@@@
 Sample Output
 1
 3
*/