#include <iostream>
using namespace std;
struct node {
    int x,y;
}path[64];

int dir[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
int xs,ys,xe,ye,v[9][9];

int bfs()
{
    node next;
    int front=0,rear=1,i,k,cur,step=0;
    v[xs][ys]=1;
    path[0].x=xs;
    path[0].y=ys;
    while (front<rear) {
        cur=rear;
        step++;
        for (i=front; i<rear; i++)
            for (k=0; k<8; k++) {
                next.x=path[i].x+dir[k][0];
                next.y=path[i].y+dir[k][1];
                if (next.x>=0&&next.x<8&&next.y>=0&&next.y<8&&v[next.x][next.y]==0) {
                    path[cur].x=next.x;
                    path[cur++].y=next.y;
                    v[next.x][next.y]=1;
                    if (v[xe][ye]) {
                        return step;
                    }
                }
            }
        front=rear;
        rear=cur;
    }
    return 0;
}

int main()
{
    char a,b,c,d;
    while (scanf("%c%c %c%c",&a,&b,&c,&d)!=EOF) {
        getchar();
        xs=a-'a';
        ys=b-'0'-1;
        xe=c-'a';
        ye=d-'0'-1;
        memset(v, 0, sizeof(v));
        if (xs==xe&&ys==ye)
            printf("To get from %c%c to %c%c takes 0 knight moves.\n",a,b,c,d);
        else printf("To get from %c%c to %c%c takes %d knight moves.\n",a,b,c,d,bfs());
        
    }
    return 0;
}
/*
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
};

int flag[9][9];                                                                                     //标记数组
int a[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};        //存储马的八种走法


int BFS(int sx,int sy,int ex,int ey)                 //广度优先搜索由(sx,sy)跳到结点(ex,ey)的最优路径                   
{
    Point s[64],t;
    int i,j,k,m,n,step=0;
    i=0;
    j=1;
    flag[sx][sy]=1;
    s[i].x=sx;
    s[i].y=sy;
    while(i<j)
    {
        step++;
        m=j;
        for(k=i;k<j;k++)
        {
            for(n=0;n<8;n++)                                             //扩展结点——就是马向八个方向跳一步
            {
                t.x=s[k].x+a[n][0];
                t.y=s[k].y+a[n][1];
                if(t.x>0&&t.x<=8&&t.y>0&&t.y<=8&&!flag[t.x][t.y])
                {
                    s[m].x=t.x;
                    s[m++].y=t.y;
                    flag[t.x][t.y]=1;
                    if(flag[ex][ey])                            //已跳到目标节点
                        return step;
                }
            }
        }
        i=j;
        j=m;
    }
    return -1;
}


int main()
{
    char c1,c2;
    int x1,y1,x2,y2,num;
    while(cin>>c1>>y1>>c2>>y2)
    {                                            
        x1=c1-'a'+1;
        x2=c2-'a'+1;
        if(x1==x2&&y1==y2)
            cout<<"To get from "<<c1<<y1<<" to "<<c2<<y2<<" takes 0 knight moves."<<endl;
        else
        {
            memset(flag,0,sizeof(flag));
            num=BFS(x1,y1,x2,y2);
            cout<<"To get from "<<c1<<y1<<" to "<<c2<<y2<<" takes "<<num<<" knight moves."<<endl;
        }
    }
    return 0;
}
*/
/*
 Description
 
 A friend of you is doing research on the Traveling Knight Problem (TKP) where you are to find the shortest closed tour of knight moves that visits each square of a given set of n squares on a chessboard exactly once. He thinks that the most difficult part of the problem is determining the smallest number of knight moves between two given squares and that, once you have accomplished this, finding the tour would be easy. 
 Of course you know that it is vice versa. So you offer him to write a program that solves the "difficult" part. 
 
 Your job is to write a program that takes two squares a and b as input and then determines the number of knight moves on a shortest route from a to b.
 Input
 
 The input will contain one or more test cases. Each test case consists of one line containing two squares separated by one space. A square is a string consisting of a letter (a-h) representing the column and a digit (1-8) representing the row on the chessboard.
 Output
 
 For each test case, print one line saying "To get from xx to yy takes n knight moves.".
 Sample Input
 
 e2 e4
 a1 b2
 b2 c3
 a1 h8
 a1 h7
 h8 a1
 b1 c3
 f6 f6
 Sample Output
 
 To get from e2 to e4 takes 2 knight moves.
 To get from a1 to b2 takes 4 knight moves.
 To get from b2 to c3 takes 2 knight moves.
 To get from a1 to h8 takes 6 knight moves.
 To get from a1 to h7 takes 5 knight moves.
 To get from h8 to a1 takes 6 knight moves.
 To get from b1 to c3 takes 1 knight moves.
 To get from f6 to f6 takes 0 knight moves.
*/