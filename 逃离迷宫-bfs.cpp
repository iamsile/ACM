#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x,y;
};

int n,m,s,sx,sy,tx,ty,v[105][105];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char map[105][105];
bool flag;

void bfs()
{
    queue<node> q;
    int step;
    node cur,nex;
    cur.x=sx;
    cur.y=sy;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        step=v[cur.x][cur.y]+1;
        for (int i=0; i<4; i++) {
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            while (nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=m
                   &&map[nex.x][nex.y]=='.') {
                if (v[nex.x][nex.y]==-1) {
                    if (nex.x==tx&&nex.y==ty&&step<=s) {
                        flag=1;
                        return;
                    }
                    v[nex.x][nex.y]=step;
                    q.push(nex);
                }
                nex.x+=dx[i];
                nex.y+=dy[i];
            }
            
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        getchar();
        int i,j;
        for (i=1; i<=n; i++) {
            for (j=1; j<=m; j++) {
                v[i][j]=-1;
                scanf("%c",&map[i][j]);
            }
            getchar();
        }
        scanf("%d%d%d%d%d",&s,&sy,&sx,&ty,&tx);
        flag=0;
        bfs();
        if (flag)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
/*
 Problem Description
 　　给定一个m × n (m行, n列)的迷宫，迷宫中有两个位置，gloria想从迷宫的一个位置走到另外一个位置，当然迷宫中有些地方是空地，gloria可以穿越，有些地方是障碍，她必须绕行，从迷宫的一个位置，只能走到与它相邻的4个位置中,当然在行走过程中，gloria不能走到迷宫外面去。令人头痛的是，gloria是个没什么方向感的人，因此，她在行走过程中，不能转太多弯了，否则她会晕倒的。我们假定给定的两个位置都是空地，初始时，gloria所面向的方向未定，她可以选择4个方向的任何一个出发，而不算成一次转弯。gloria能从一个位置走到另外一个位置吗？
 
 
 Input
 　　第1行为一个整数t (1 ≤ t ≤ 100),表示测试数据的个数，接下来为t组测试数据，每组测试数据中，
 　　第1行为两个整数m, n (1 ≤ m, n ≤ 100),分别表示迷宫的行数和列数，接下来m行，每行包括n个字符，其中字符'.'表示该位置为空地，字符'*'表示该位置为障碍，输入数据中只有这两种字符，每组测试数据的最后一行为5个整数k, x1, y1, x2, y2 (1 ≤ k ≤ 10, 1 ≤ x1, x2 ≤ n, 1 ≤ y1, y2 ≤ m),其中k表示gloria最多能转的弯数，(x1, y1), (x2, y2)表示两个位置，其中x1，x2对应列，y1, y2对应行。
 
 
 Output
 　　每组测试数据对应为一行，若gloria能从一个位置走到另外一个位置，输出“yes”，否则输出“no”。
 
 
 Sample Input
 2
 5 5
 ...**
 *.**.
 .....
 .....
 *....
 1 1 1 1 3
 5 5
 ...**
 *.**.
 .....
 .....
 *....
 2 1 1 1 3
 
 
 Sample Output
 no
 yes
*/