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
    while (cin >> n >> m) {
        int i,j,sum=0;char s;
        if (n==0&&m==0)
            return 0;
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
 The GeoSurvComp geologic survey company is responsible for detecting underground oil deposits. GeoSurvComp works with one large rectangular region of land at a time, and creates a grid that divides the land into numerous square plots. It then analyzes each plot separately, using sensing equipment to determine whether or not the plot contains oil. A plot containing oil is called a pocket. If two pockets are adjacent, then they are part of the same oil deposit. Oil deposits can be quite large and may contain numerous pockets. Your job is to determine how many different oil deposits are contained in a grid.
 
 Input
 The input contains one or more grids. Each grid begins with a line containing m and n, the number of rows and columns in the grid, separated by a single space. If m = 0 it signals the end of the input; otherwise 1 <= m <= 100 and 1 <= n <= 100. Following this are m lines of n characters each (not counting the end-of-line characters). Each character corresponds to one plot, and is either `*', representing the absence of oil, or `@', representing an oil pocket. 
 
 Output
 are adjacent horizontally, vertically, or diagonally. An oil deposit will not contain more than 100 pockets. 
 
 Sample Input
 1 1
 *
 3 5
 *@*@*
 **@**
 *@*@*
 1 8
 @@****@*
 5 5 
 ****@
 *@@*@
 *@**@
 @@@*@
 @@**@
 0 0
 Sample Output
 0
 1
 2
 2
*/