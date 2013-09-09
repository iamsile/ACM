#include <iostream>
#include <math.h>
using namespace std;

char map[11][11];
int n,m,t,x,y,ex,ey,move[4][2]={0,-1,-1,0,0,1,1,0};
bool lab;
void dfs(int x,int y,int step)
{
    if (x>n||y>m||x<=0||y<=0)
        return;
    if (step==t&&x==ex&&y==ey) {
        lab=1;
        return;
    }
    int temp=(t-step)-abs(x-ex)-abs(y-ey);
    if (temp<0||temp&1)
        return;
    for (int i=0; i<4; i++) {
        int dx=x+move[i][0];
        int dy=y+move[i][1];
        if (map[dx][dy]!='X') {
            map[dx][dy]='X';
            dfs(dx, dy, step+1);
            if (lab) return;
            map[dx][dy]='.';
        }
    }
    return;
}

int main()
{
    while (cin >> n >> m >> t) {
        if (!n&&!m&&!t)
            break;
        int i,j,w=0;
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++) {
                cin >> map[i][j];
                if (map[i][j]=='S') {
                    x=i;
                    y=j;
                   
                }
                if (map[i][j]=='D') {
                    ex=i;
                    ey=j;
                }
                if (map[i][j]=='X')
                    w++;
            }
        if (n*m-w<=t) {
            cout << "NO\n";
            continue;
        }
        lab=0; 
        map[x][y]='X';
        dfs(x,y,0);
        if (lab)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
//迷宫地图
//X: 墙壁，小狗不能进入
//S: 小狗所处的位置
//D: 迷宫的门
//. : 空的方格
char map[9][9];
int n,m,t,di,dj; //(di,dj):门的位置
bool escape;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}}; //分别表示下、上、左、右四个方向
void dfs(int si,int sj,int cnt)  //表示起始位置为(si,sj)，要求在第cnt秒达到门的位置
{
    int i,temp;
    if( si>n || sj>m || si<=0 || sj<=0 ) return;
    if( si==di && sj==dj && cnt==t )
    {
        escape = 1;
        return;
    }
    //abs(x-ex) + abs(y - ey)表示现在所在的格子到目标格子的距离（不能走对角线）
    //t-cnt是实际还需要的步数，将他们做差
    //如果temp < 0或者temp为奇数，那就不可能到达！
    temp = (t-cnt) - abs(si-di) - abs(sj-dj);
    if( temp<0 || temp&1 ) return;
    for( i=0; i<4; i++ )
    {
        if( map[ si+dir[i][0] ][ sj+dir[i][1] ] != 'X')
        {
            map[ si+dir[i][0] ][ sj+dir[i][1] ] = 'X';
            dfs(si+dir[i][0], sj+dir[i][1], cnt+1);
            if(escape) return;
            map[ si+dir[i][0] ][ sj+dir[i][1] ] = '.';
        }
    }
    return;
}

int main()
{
    int i,j,si,sj;
    while( cin >> n >> m >> t)
    {
        if( n==0 && m==0 && t==0 )
            break;
        int wall = 0;
        for( i=1; i<=n; i++ )
            for( j=1; j<=m; j++ )
            {
                cin >> map[i][j];
                if(map[i][j]=='S') { si=i; sj=j; }
                else if( map[i][j]=='D' ) { di=i; dj=j; }
                else if( map[i][j]=='X' ) wall++;
            }
        if( n*m-wall <= t )
        {
            cout << "NO" << endl;
            continue;
        }
        escape = 0;
        map[si][sj] = 'X';
        dfs( si, sj, 0 );
        if( escape ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
*/
/*
 Problem Description
 The doggie found a bone in an ancient maze, which fascinated him a lot. However, when he picked it up, the maze began to shake, and the doggie could feel the ground sinking. He realized that the bone was a trap, and he tried desperately to get out of this maze.
 
 The maze was a rectangle with sizes N by M. There was a door in the maze. At the beginning, the door was closed and it would open at the T-th second for a short period of time (less than 1 second). Therefore the doggie had to arrive at the door on exactly the T-th second. In every second, he could move one block to one of the upper, lower, left and right neighboring blocks. Once he entered a block, the ground of this block would start to sink and disappear in the next second. He could not stay at one block for more than one second, nor could he move into a visited block. Can the poor doggie survive? Please help him.
 
 
 Input
 The input consists of multiple test cases. The first line of each test case contains three integers N, M, and T (1 < N, M < 7; 0 < T < 50), which denote the sizes of the maze and the time at which the door will open, respectively. The next N lines give the maze layout, with each line containing M characters. A character is one of the following:
 
 'X': a block of wall, which the doggie cannot enter; 
 'S': the start point of the doggie; 
 'D': the Door; or
 '.': an empty block.
 
 The input is terminated with three 0's. This test case is not to be processed.
 
 
 Output
 For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.
 
 
 Sample Input
 4 4 5
 S.X.
 ..X.
 ..XD
 ....
 3 4 5
 S.X.
 ..X.
 ...D
 0 0 0
 
 
 Sample Output
 NO
 YES
*/