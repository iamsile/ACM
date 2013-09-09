#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int v[5][6],sx,sy,cnt;
int dir[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
bool flag;

void dfs(int x,int y)
{
    int i,dx,dy;
    for (i=0; i<8; i++) {
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if (dx>0&&dx<=4&&dy>0&&dy<=5&&v[dx][dy]==0) {
            v[dx][dy]=1;
            dfs(dx, dy);
            v[dx][dy]=0;
        }
        else if (dx==sx&&dy==sy) {
            flag=true;
            cnt++;
        }
    }
}

int main()
{
    while (scanf("%d%d",&sx,&sy)!=EOF) {
        if (sx<1||sx>4||sy<1||sy>5) {
            cout << "ERROR\n";
            continue;
        }
        memset(v, 0, sizeof(v));
        cnt=0;
        v[sx][sy]=1;
        flag=false;
        dfs(sx,sy);
        if (flag)
            cout << cnt-1 << '\n';
        else cout << "ERROR\n";
    }
    return 0;
}
/*
 Problem description
 
 在一个4*5的棋盘上，马的起始位置（纵，横）由键盘输入，求马能返回初始位置的所有不同走法的总数（马走过的位置不能重复，随便提醒一下，马是走“日”字哟），如果不能返回则输出ERROR。
 
 Input
 
 输入一行，为马所在初始位置。
 
 Output
 
 马返回初始位置走法的总数。
 
 Sample Input
 2 2
 Sample Output
 4595
*/