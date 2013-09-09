#include <iostream>
#include <queue>
using namespace std;
typedef struct
{
    int x,y,z,steps;
}node;
node start,end;
int ex,ey,ez,t,n;
int map[51][51][51];
int dir[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};

int bfs()
{
    queue<node>q;
    int i;
    node cur,next;
    start.x=0;
    start.y=0;
    start.z=0;
    if(start.x==ex-1&&start.y==ey-1&&start.z==ez-1)//考虑起点和终点相同的情况
        return 0;
    start.steps=0;
    map[start.x][start.y][start.z]=1;
    q.push(start);
    while(!q.empty())
    {
        cur=q.front();//取队首元素
        q.pop();
        for(i=0;i<6;i++) //广度优先搜索
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            next.z=cur.z+dir[i][2];
            if(next.x==ex-1 && next.y==ey-1 && next.z==ez-1) //下一步就是目的地
                return cur.steps+1;
            if(next.x>=0&&next.x<ex&&next.y>=0&&next.y<ey&&next.z>=0&&
               next.z<ez&&map[next.x][next.y][next.z]!=1) {
                map[next.x][next.y][next.z]=1;
                next.steps=cur.steps+1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    int i,j,k,ans;
    scanf("%d\n",&n);
    while(n--)
    {
        scanf("%d %d %d %d",&ex,&ey,&ez,&t);
        for(i=0;i<ex;i++)
            for(j=0;j<ey;j++)
                for(k=0;k<ez;k++)
                    scanf("%d",&map[i][j][k]);
        if(ex+ey+ez-3>t) {
            printf("-1\n");
            continue;
        }
        if(map[ex-1][ey-1][ez-1]==1) {
            printf("-1\n");
            continue;
        }
        ans=bfs();
        if(ans>=0&&ans<=t)
            printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 51

struct student
{
    int x;
    int y;
    int z;
    int step;
}a[1000];

int map[max][max][max],vist[max][max][max];
int n,m,l,road;
int x1[7]={1,-1,0,0,0,0};
int y1[7]={0,0,1,-1,0,0};
int z1[7]={0,0,0,0,1,-1};
int bfs(int x0,int y0,int z0)
{
    int i;
    int aa=0,tail=0,head=0;
    a[0].x=x0;
    a[0].y=y0;
    a[0].z=z0;
    a[0].step=0;
    vist[0][0][0]=1;
    struct student now,newstep;
    while(head<=tail)
    {
        now=a[head];
        for(i=0;i<6;i++)
        {
            newstep.x=now.x+x1[i];
            newstep.y=now.y+y1[i];
            newstep.z=now.z+z1[i];
            if(newstep.x>=0&&newstep.x<n&&newstep.y>=0&&newstep.y<m&&newstep.z>=0&&newstep.z<l&&map[newstep.x][newstep.y][newstep.z]==0)
            {
                if(newstep.x==n-1&&newstep.y==m-1&&newstep.z==l-1)return now.step+1;
                if(!vist[newstep.x][newstep.y][newstep.z])
                {
                    newstep.step=now.step+1;
                    a[++tail]=newstep;
                    vist[newstep.x][newstep.y][newstep.z]=1;
                    if(newstep.step>road)return -1;
                }
                
            }
            
        }
        head++;
    }
    return -1;
}
int main()
{
    int cas,i,j,k;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(vist,0,sizeof(vist));
        scanf("%d%d%d%d",&n,&m,&l,&road);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                for(k=0;k<l;k++)
                    scanf("%d",&map[i][j][k]);
        printf("%d\n",bfs(0,0,0));
        
    }
    return 0;
}



 Problem Description
 Ignatius被魔王抓走了,有一天魔王出差去了,这可是Ignatius逃亡的好机会.
 
 魔王住在一个城堡里,城堡是一个A*B*C的立方体,可以被表示成A个B*C的矩阵,刚开始Ignatius被关在(0,0,0)的位置,离开城堡的门在(A-1,B-1,C-1)的位置,现在知道魔王将在T分钟后回到城堡,Ignatius每分钟能从一个坐标走到相邻的六个坐标中的其中一个.现在给你城堡的地图,请你计算出Ignatius能否在魔王回来前离开城堡(只要走到出口就算离开城堡,如果走到出口的时候魔王刚好回来也算逃亡成功),如果可以请输出需要多少分钟才能离开,如果不能则输出-1.
 
 
 
 
 
 Input
 输入数据的第一行是一个正整数K,表明测试数据的数量.每组测试数据的第一行是四个正整数A,B,C和T(1<=A,B,C<=50,1<=T<=1000),它们分别代表城堡的大小和魔王回来的时间.然后是A块输入数据(先是第0块,然后是第1块,第2块......),每块输入数据有B行,每行有C个正整数,代表迷宫的布局,其中0代表路,1代表墙.(如果对输入描述不清楚,可以参考Sample Input中的迷宫描述,它表示的就是上图中的迷宫)
 
 特别注意:本题的测试数据非常大,请使用scanf输入,我不能保证使用cin能不超时.在本OJ上请使用Visual C++提交.
 
 
 Output
 对于每组测试数据,如果Ignatius能够在魔王回来前离开城堡,那么请输出他最少需要多少分钟,否则输出-1.
 
 
 Sample Input
 1
 3 3 4 20
 0 1 1 1
 0 0 1 1
 0 1 1 1
 1 1 1 1
 1 0 0 1
 0 1 1 1
 0 0 0 0
 0 1 1 0
 0 1 1 0
 
 
 Sample Output
 11
*/