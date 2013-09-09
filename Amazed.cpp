#include <iostream>
#include <string.h>
#include <iomanip.h>
using namespace::std;
typedef struct {
    int x,y;
    int step;
}Amaze;
Amaze amaze,queue[1000201];
char a[1010][1010];
int x1[4]={-1,0,1,0};
int y1[4]={0,1,0,-1};
int c[1010][1010];
bool b[1010][1010]={1};
int position(Amaze amaze,int i,int x,int y,int stop)
{
    int dx=amaze.x+x1[i];
    int dy=amaze.y+y1[i];
    if (dx>=0&&dx<x&&dy>=0&&dy<y&&a[dx][dy]==' '&&b[dx][dy]) //图的范围是[0,m) [0,n)
    {
        for (i=0; i<4; i++)
            if (dx==queue[i].x&&dy==queue[i].y)
                return 0;
        return 1;
    }
    return 0;
}

int findpath(Amaze amaze ,int x,int y,int n,int m)
{
    int i,lab=0,stop=0;
    queue[0]=amaze;//把迷宫压入队列
    b[x][y]=true;
    c[x][y]=0;
    while (lab<=stop) 
    {
        for (i=0; i<4; i++)//四个方向
        {
            if (position(amaze,i,n,m,stop)) 
            {
                stop++;//步数
                queue[stop].x=amaze.x+x1[i];//把新的点压入队列
                queue[stop].y=amaze.y+y1[i];
                c[queue[stop].x][queue[stop].y]=c[amaze.x][amaze.y]+1;
                queue[stop].step=amaze.step+1;
                b[queue[stop].x][queue[stop].y]=false;
            }
        }
        amaze=queue[++lab];
    }
    return 0;
}

int main()
{
    int n,m,i,j,x,y;
    while (scanf("%d%d",&n,&m)!=EOF) 
    {
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        memset(b, true, sizeof(b));
        getchar();
        for (i=0; i<n; i++) //输入
        {
            for (j=0; j<m; j++)
                a[i][j]=getchar();
            getchar();
        }
        for (i=0; i<n; i++) //输入迷宫
            for (j=0; j<m; j++)
                if (a[i][j]=='S') 
                {
                    a[i][j]='0';
                    x=i;
                    y=j;
                    amaze.x=i;
                    amaze.y=j;
                    amaze.step=0;
                    break;
                }
        findpath(amaze,x,y,n,m);
        for (i=0; i<n; i++) 
        {
            for (j=0; j<m; j++)
            {
                if (a[i][j]=='W')
                    cout << "WWWWW";
                else if (b[i][j]==false)
                    cout << " " << setw(3) << c[i][j] << ' ';
                else if (a[i][j]==' '&&b[i][j]==true)
                    cout << " inf ";
                else if (b[x][y])
                    cout << "   0 ";
            }
            cout << '\n';
        }
    }
    return 0;
}
/*
 Problem description
 In this problem, we consider traversing a rectangular maze with walls that prohibit passage, and seek to find the shortest distance from a given starting cell to all other cells. Technically, a maze is a rectangular grid of cells, each of which may or may not contain a blocking wall. When traversing a maze, one starts at a given cell (without a wall) and makes successive horizontal or vertical steps to adjacent cells without walls. One is not allowed to make a diagonal step, even if a diagonally adjacent cell contains no wall. The presence of walls might make it impossible to reach some cells from the starting cell, in which case they’re considered to be infinitely distant.
 
 Input
 The input contains one or more mazes, each described by some successive lines of input. The first line of a maze contains two positive integers r and c describing the number of rows and columns in the cell grid. The next r lines each contain c characters fromthe alphabet {’ ’, ’W’, ’S’}. ’ ’ represents a cell without a wall, ’W’ represents a cell containing a wall, and ’S’ represents the starting cell (without a wall). There is exactly one starting cell in a maze.
 
 Output
 For each maze in the input, output the maze to show the cells with walls labeled by ’WWWWW’ and the cells without walls labeled by the least number of steps to traverse there from the starting cell. Widen each input cell to five output columns wide, outputting ’WWWWW’ for each ’W’ input, and up to a 3-digit number (or inf representing1) with a blank on either side for each ’ ’ or ’S’ input.
 
 Sample Input
 6 7
 WWWWW W
 W  WW  
 WS WW
 W  W WW
 W
 WWWWWWW
 8 12
 WWWWWWWWWWWW
 W   W S  W  
 W W  WWW W W
 W W      W W
 W WWWWWWWW W
 W          W
 W  W    WW W
 WWWWWWWWWWWW
 Sample Output
 WWWWWWWWWWWWWWWWWWWWWWWWW inf WWWWW
 WWWWW   9   10 WWWWWWWWWW inf  inf 
 9    8 WWWWW   0    1 WWWWWWWWWW
 WWWWW   7    6 WWWWW   2 WWWWWWWWWW
 7    6    5    4    3    4 WWWWW
 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
 
 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
 WWWWW  13   12   11 WWWWW   1    0    1    2 WWWWW  30   31 
 WWWWW  14 WWWWW  10    9 WWWWWWWWWWWWWWW   3 WWWWW  29 WWWWW
 WWWWW  15 WWWWW   9    8    7    6    5    4 WWWWW  28 WWWWW
 WWWWW  16 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW  27 WWWWW
 WWWWW  17   18   19   20   21   22   23   24   25   26 WWWWW
 WWWWW  18   19 WWWWW  21   22   23   24 WWWWWWWWWW  27 WWWWW
 WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
*/