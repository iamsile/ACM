#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x,y,step;
    node() {
        x=y=step=0;
    }
};

int n,m,len,ans,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},d[30][30];
char map[30][30];
bool v[30][30],vi[1000];

int bfs(int cx,int cy,int tx,int ty)
{
    queue<node> q;
    node cur,nex;
    memset(v, 0, sizeof(v));
    cur.x=cx;
    cur.y=cy;
    cur.step=0;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            if (nex.x>=0&&nex.x<m&&nex.y>=0&&nex.y<n&&map[nex.x][nex.y]!='x'&&!v[nex.x][nex.y]) {
                v[nex.x][nex.y]=1;
                nex.step=cur.step+1;
                if (nex.x==tx&&nex.y==ty)
                    return nex.step;
                q.push(nex);
            }
        }
    }
    return -1;
}

void dfs(int s,int t,int l)
{
    if (l>ans)
        return;
    if (t==len-1) {
        if (l<ans)
            ans=l;
        return;
    }
    for (int i=1; i<len; i++) {
        if (!vi[i]) {
            vi[i]=1;
            dfs(i, t+1, l+d[i][s]);
            vi[i]=0;
        }
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        if (!n&&!m)
            break;
        memset(map, 0, sizeof(map));
        int i,j,flag=1;
        node path[1000];
        for (i=0,len=1; i<m; i++) {
            scanf("%s",map[i]);
            for (j=0; j<n; j++) {
                if (map[i][j]=='o') {
                    path[0].x=i;
                    path[0].y=j;
                }
                else if (map[i][j]=='*') {
                    path[len].x=i;
                    path[len++].y=j;
                }
            }
        }
        memset(d, 0, sizeof(d));
        for (i=0; i<len&&flag; i++) {
            for (j=0; j<len&&flag; j++) {
                if (i==j)
                    continue;
                if (d[i][j]==-1) {
                    flag=0;
                    break;
                }
                else if (!d[i][j]) {
                    d[i][j]=bfs(path[i].x, path[i].y, path[j].x, path[j].y);
                    d[j][i]=d[i][j];
                }
            }
        }
        if (!flag)
            printf("-1\n");
        else {
            ans=100000;
            memset(vi, 0, sizeof(vi));
            vi[0]=1;
            dfs(0, 0, 0);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
 Problem description
 Here, we want to solve path planning for a mobile robot cleaning a rectangular room floor with furniture.
 
 Consider the room floor paved with square tiles whose size fits the cleaning robot (1 * 1). There are 'clean tiles' and 'dirty tiles', and the robot can change a 'dirty tile' to a 'clean tile' by visiting the tile. Also there may be some obstacles (furniture) whose size fits a tile in the room. If there is an obstacle on a tile, the robot cannot visit it. The robot moves to an adjacent tile with one move. The tile onto which the robot moves must be one of four tiles (i.e., east, west, north or south) adjacent to the tile where the robot is present. The robot may visit a tile twice or more.
 
 Your task is to write a program which computes the minimum number of moves for the robot to change all 'dirty tiles' to 'clean tiles', if ever possible.
 
 Input
 The input consists of multiple maps, each representing the size and arrangement of the room. A map is given in the following format.
 
 w h
 c11 c12 c13 ... c1w
 c21 c22 c23 ... c2w
 ...
 ch1 ch2 ch3 ... chw
 
 The integers w and h are the lengths of the two sides of the floor of the room in terms of widths of floor tiles. w and h are less than or equal to 20. The character cyx represents what is initially on the tile with coordinates (x, y) as follows.
 
 '.' : a clean tile
 '*' : a dirty tile
 'x' : a piece of furniture (obstacle)
 'o' : the robot (initial position)
 
 In the map the number of 'dirty tiles' does not exceed 10. There is only one 'robot'.
 
 The end of the input is indicated by a line containing two zeros.
 
 
 Output
 For each map, your program should output a line containing the minimum number of moves. If the map includes 'dirty tiles' which the robot cannot reach, your program should output -1.
 
 Sample Input
 7 5
 .......
 .o...*.
 .......
 .*...*.
 .......
 15 13
 .......x.......
 ...o...x....*..
 .......x.......
 .......x.......
 .......x.......
 ...............
 xxxxx.....xxxxx
 ...............
 .......x.......
 .......x.......
 .......x.......
 ..*....x....*..
 .......x.......
 10 10
 ..........
 ..o.......
 ..........
 ..........
 ..........
 .....xxxxx
 .....x....
 .....x.*..
 .....x....
 .....x....
 0 0
 Sample Output
 8
 49
 -1
*/