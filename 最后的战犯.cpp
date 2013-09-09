#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace::std;

typedef struct {
    int x,y,step,deep;
}Amaze;
Amaze queue[11000],amaze;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char a[110][110],d[26],dir;
bool b[110][110];
int n,x1,x2,y1,y2,cnt;

bool position(int i)
{
    x1=amaze.x+dx[i];
    y1=amaze.y+dy[i];
    if (x1>=0&&x1<n&&y1>=0&&y1<n&&!b[x1][y1]&&a[x1][y1]!='*')
        return true;
    return false;
}

bool pos(char dir,int x2,int y2)
{
    if (dir=='N'&&(x2-1<0||a[x2-1][y2]=='*'))
    {
        cnt++;
        return false;
    }
    if (dir=='S'&&(x2+1>=n||a[x2+1][y2]=='*'))
    {
        cnt++;
        return false;
    }
    if (dir=='W'&&(y2-1<0||a[x2][y2-1]=='*'))
    {
        cnt++;
        return false;
    }
    if (dir=='E'&&(y2+1>=n||a[x2][y2+1]=='*'))
    {
        cnt++;
        return false;
    }
    return true;
}

int findpath(int xp,int yp)
{
    int i,lab=0,stop=1,deepth;
    memset(b, false, sizeof(b));
    amaze.x=xp;
    amaze.y=yp;
    amaze.step=0;
    amaze.deep=1;
    deepth=0;
    queue[0]=amaze;
    dir='N';
    b[xp][yp]=true;
    if ((xp==x2&&yp==y2)||(abs(xp-x2)==1&&abs(yp-y2)==0)||abs(yp-y2)==1&&abs(xp-x2)==0)
        return 0;
    while (lab!=stop) 
    {
        if (amaze.deep==deepth+1)
        {
            deepth=amaze.deep;
            cnt=0;
            while (!pos(dir,x2,y2)&&cnt<4)
                dir=d[dir-'A'];
            if (cnt>=4)
                return -1;
            if (dir=='N')
                x2--;
            if (dir=='E')
                y2++;
            if (dir=='S')
                x2++;
            if (dir=='W')
                y2--;
        }
        for (i=0; i<4; i++) 
        {
            if (position(i)) 
            {
                if ((x1==x2&&y1==y2)||(abs(x1-x2)==1&&abs(y1-y2)==0)||
                    (abs(y1-y2)==1&&abs(x1-x2)==0))
                    return queue[lab].step+1;
                queue[stop].x=x1;
                queue[stop].y=y1;
                queue[stop].step=queue[lab].step+1;
                queue[stop].deep=queue[lab].deep+1;
                stop++;
                b[x1][y1]=true;
            }
        }
        amaze=queue[++lab];
    }
    return -1;
}

int main()
{
    int i,j,xp,yp,result;
    d[4]='S';
    d[13]='E';
    d[18]='W';
    d[22]='N';
    while (cin >> n&&n) {
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=0; i<n; i++) 
            for (j=0; j<n; j++)
            {
                if (a[i][j]=='F')
                {
                    xp=i;
                    yp=j;
                }
                if (a[i][j]=='J')
                {
                    x2=i;
                    y2=j;
                }
            }
        result=findpath(xp,yp);
        if (result!=-1)
            cout << result << '\n';
        else 
            cout << "No solution.\n";
    }
    return 0;
}
/*
 Problem description
 话说Lucky和Feli以3721部队为诱饵，歼灭了大批日军。但顽固的日军军官小犬蠢一狼（以下简称小犬）在全军覆灭之后仍然不肯认输。他躲在山区的一个岩洞中，等待日军的救援部队。他妄图凭借复杂的地形躲避我军的追踪。于是，总部派出足智多谋的Feli前往岩洞搜寻小犬。
 
 Feli来到岩洞入口，发现岩洞其实是一个巨大的迷宫。迷宫地形极为复杂，为一个正方形，其中布满了障碍物。迷宫可以分为N*N（2≤N≤100）个区域，每个区域或者是空地，或者是不可逾越的障碍物。小犬就躲藏在其中某一个区域内。由于小犬已经忍受了几天的饥饿，Feli进入迷宫时他已经失去思维处于迷乱状态。小犬每秒钟只会沿着他的方向直线前进，如果遇到障碍物或者迷宫边界，他会立刻向右转90度（不会花去时间），继续沿直线前进（初始方向向北）。Feli每秒钟可以自主决定往哪个方向走。如果同一时刻Feli与小犬位于同一个区域，或者相邻的区域（非对角线相邻），Feli可以立刻将小犬抓住。
 
 Feli本来打算先确定小犬的位置，然后沿最短路线抓住他，但是Feli前进时小犬同时也在移动，就不能采取这种方法了。请你帮助Feli确定一种方案，使Feli抓获小犬所用的时间最短。 
 
 Input
 输入数据第一行是一个整数N。以下N行每行N个字符，“*”表示岩洞中的障碍物，“.”表示空地，“J”表示小犬（一开始他会向北走），“F”表示Feli。上北下南左西右东。 
 
 Output
 输出数据仅一行，如果Feli能抓到小犬，那么输出所需的最短时间，如果Feli抓不到小犬，那么这个最后的日本战犯将在岩洞中饿死（因为Feli将在离开的时候封闭岩洞的所有出口），此时输出“No solution.”，不要输出引号。
 
 Sample Input
 3
 F*J
 .*.
 ...
 Sample Output
 3
*/