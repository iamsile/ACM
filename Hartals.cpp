#include <iostream>
using namespace::std;

typedef struct {
    int x,y;
    int step;
}Amaze;
Amaze amaze,amazej,queue[1001];
char a[1010][1010];
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};

int position(Amaze amaze,int x1,int y1,int i,int n)
{
    int dx=amaze.x+x[i];
    int dy=amaze.y+y[i];
    if (dx>=0&&dx<n&&dy>=0&&dy<n&&a[dx][dy]=='.')
    {
        for (i=0; i<n; i++)
            if (dx==queue[i].x&&dy==queue[i].y)
                return 0;
        return 1;
    }
    return 0;
}

int findpath(Amaze amaze,int x1,int y1,Amaze amazej,int x2,int y2,int n)
{
    int i,lab=0,stop=0,flag=0;
    queue[0]=amaze;
    while (lab<=stop) 
    {
        for (i=0; i<4; i++) 
        {
            if (position(amaze,x1,y1,i,n)) 
            {
                stop++;
                queue[stop].x=amaze.x+x[i];
                queue[stop].y=amaze.y+y[i];
                queue[stop].step=amaze.step+1;
                if (a[queue[stop].x][queue[stop].y]=='J'||a[queue[stop].x-1][queue[stop].y]=='J'||
                    a[queue[stop].x][queue[stop].y+1]=='J'||a[queue[stop].x+1][queue[stop].y+1]=='J'||
                    a[queue[stop].x][queue[stop].y-1]=='J')
                    return queue[stop].step;
                flag=1;
                if (amazej.x<n&&amazej.x>=0&&amazej.y<n&&amazej.y>=0)
                    amazej.y+=1;
                else 
                    
            }
        }
        amaze=queue[++lab];
    }
    return queue[stop].step-1;
}

int main()
{
    int i,j,n,flag1,flag2,x1,x2,y1,y2;
    while (cin >> n&&n) 
    {
        getchar();
        flag1=0;
        flag2=0;
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                cin >> a[i][j];
        for (i=0; i<n; i++) 
            for (j=0; j<n; j++) 
            {
                if (a[i][j]=='F') 
                {
                    x1=i;
                    y1=j;
                    amaze.x=i;
                    amaze.y=j;
                    amaze.step=0;
                    flag1=1;
                }
                else if (a[i][j]=='J')
                {
                    x2=i;
                    y2=j;
                    amazej.x=i;
                    amazej.y=j;
                    amazej.step=0;
                    flag2=1;
                }
                if (flag1&&flag2)
                    break;
            }
        findpath(amaze,x1,y2,amazej,x2,y2,n);
        
    }
    return 0;
}