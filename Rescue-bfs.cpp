#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct node {
    int x,y,step;
}cur,next;

char map[204][204];
int n,m,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

bool bfs(int sx,int sy)
{
    queue<node> q;
    int i;
    map[sx][sy]='#';
    cur.x=sx;
    cur.y=sy;
    cur.step=1;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        for (i=0; i<4; i++) {
            next.x=cur.x+dx[i];
            next.y=cur.y+dy[i];
            if (next.x>=0&&next.x<n&&next.y>=0&&next.y<m) {
                if (map[next.x][next.y]=='.') {
                    next.step=cur.step+1;
                    map[next.x][next.y]='#';
                    q.push(next);
                }
                else if (map[next.x][next.y]=='x') {
                    next.step=cur.step+2;
                    map[next.x][next.y]='#';
                    q.push(next);
                }
                else if (map[next.x][next.y]=='a')
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        int i,j,sx,sy;
        char c;
        for (i=0; i<n; i++)
            for (j=0; j<m; j++) {
                cin >> c;
                map[i][j]=c;
                if (c=='r')
                    sx=i,sy=j;
            }
        if (bfs(sx, sy))
            cout << cur.step << '\n';
        else cout << "Poor ANGEL has to stay in the prison all his life.\n";
    }
    return 0;
}
/*
 Problem Description
 Angel was caught by the MOLIGPY! He was put in prison by Moligpy. The prison is described as a N * M (N, M <= 200) matrix. There are WALLs, ROADs, and GUARDs in the prison.
 
 Angel's friends want to save Angel. Their task is: approach Angel. We assume that "approach Angel" is to get to the position where Angel stays. When there's a guard in the grid, we must kill him (or her?) to move into the grid. We assume that we moving up, down, right, left takes us 1 unit time, and killing a guard takes 1 unit time, too. And we are strong enough to kill all the guards.
 
 You have to calculate the minimal time to approach Angel. (We can move only UP, DOWN, LEFT and RIGHT, to the neighbor grid within bound, of course.)
 
 
 Input
 First line contains two integers stand for N and M.
 
 Then N lines follows, every line has M characters. "." stands for road, "a" stands for Angel, and "r" stands for each of Angel's friend. 
 
 Process to the end of the file.
 
 
 Output
 For each test case, your program should output a single integer, standing for the minimal time needed. If such a number does no exist, you should output a line containing "Poor ANGEL has to stay in the prison all his life." 
 
 
 Sample Input
 7 8
 #.#####.
 #.a#..r.
 #..#x...
 ..#..#.#
 #...##..
 .#......
 ........
 
 
 Sample Output
 13
*/