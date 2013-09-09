# include<iostream>
using namespace std;
int b[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
typedef struct 
{
    int x,y;
    int adj;
}point;
bool used[10000]={0};
int bfs(char a[][82],int n,int m)
{
    point *qu[10000],*p,*p1;
    int front=0,rear=0,num=1,i,r,c,flag=0;
    p=(point*)malloc(sizeof(point));
    p->x=p->y=0;p->adj=1;
    used[0]=1;
    rear=(rear+1)%10000;
    qu[rear]=p;
    while(front!=rear)
    {
        front=(front+1)%10000;
        p=qu[front];
        for(i=0;i<8;i++)
        {
            r=p->x+b[i][0];c=p->y+b[i][1];
            if(r>=0&&c>=0&&r<n&&c<m)
                if(a[r][c]=='O'&&used[r*m+c]==0) 
                {
                    used[r*m+c]=1;
                    p1=(point*)malloc(sizeof(point));
                    p1->x=r;p1->y=c;p1->adj=p->adj+1;
                    rear=(rear+1)%10000;
                    qu[rear]=p1;
                }
            if(r==n-1&&c==m-1)
            {
                num=p->adj+1;
                flag=1;break;
            }
        }
        if(flag==1)break;
    }
    return num;
}                
int main()
{
    int n,m,num=0,i;
    char a[82][82];
    i=0;
    while(scanf("%s",a[i])!=EOF)
        i++;
    n=i;
    m=strlen(a[0]);
    num=bfs(a,n,m);
    printf("%d\n",num);
    return 0;
}
/*
#include<cstdio>
#include<queue>
#include<list>
#include<cstdlib>
#include<memory.h>
using namespace std;

class Point{
public:
	int x,y;
	void Set(int ax,int ay){x=ax;y=ay;}
	Point(){}
	Point(int ax,int ay){Set(ax,ay);}
	void Get(int &ax,int &ay){ax=x;ay=y;}
};
class Maze{
private:
	char map[100][100];
	char hi,wd;
	vector<Point> dir;
	Point start,end;
public:
	Maze(){
		memset(map, 0, sizeof(map));
		for(hi=1;EOF!=scanf("%s",map[hi]+1);++hi);
		--hi;
		wd=strlen(map[1]+1);
		start.Set(1,1);
		end.Set(hi,wd);
	}
	void InitDir(){
		dir.push_back(Point(-1,-1));
		dir.push_back(Point(-1,0));
		dir.push_back(Point(-1,1));
		dir.push_back(Point(0,-1));
		dir.push_back(Point(0,1));
		dir.push_back(Point(1,-1));
		dir.push_back(Point(1,0));
		dir.push_back(Point(1,1));
	}
	int GoThrough(){
		short rote[100][100]={0};
		queue<Point, list<Point> > record;
		record.push(start);
		rote[start.x][start.y]=1;
		int x,y,dx,dy;
		while(!record.empty()){
			if(rote[end.x][end.y])break;
			record.front().Get(x,y);
			for(int i=0;i<dir.size();++i){
				dx=x+dir[i].x;dy=y+dir[i].y;
				if(dx<=0||dx>hi)continue;
				if(dy<=0||dy>wd)continue;
				if(map[dx][dy]=='O'	&&
                   (rote[dx][dy]==0||rote[dx][dy]>rote[x][y]+1)){
					rote[dx][dy]=rote[x][y]+1;
					record.push(Point(dx,dy));
				}
			}
			record.pop();
		}
		return rote[end.x][end.y];
	}
};
int main(){
	Maze aex;
	aex.InitDir();
	printf("%d", aex.GoThrough());
	return 0;
}
*/
/*
 Problem description
 The Maize Maze is a maze made completely out of corn. The designers of the maze allow people to run through the maze and very promptly get lost. They would, however, like to know how long the shortest path through the maze is. That's your job. 
 
 Input
 There will be one test case that consists of one maze. Each line of input will describe one row of the maze. There will no more than 80 columns and no more than 80 rows. The given maze will always be rectangular, though, not necessarily a square. 
 
 Each position of the maze is one of two characters. A `O' means you may move onto that position. A `X' means that space is occupied by a wall.
 
 You are allowed to move in any direction (up, down, left, right, diagonal) provided that the square you move into isn't an `X'. 
 
 You always start in the upper left hand corner of the maze. The exit is always at the lower right hand corner of the maze. There will always be at least one path through the maze. 
 
 Output
 The output is the shortest number of squares you must step in to complete the maze.
 
 Sample Input
 OXXXOOXXX
 OOXXXOOXX
 OOXXXXOXX
 OXXXXXOXO
 OOXXXXOXO
 XOOOOOOOO
 XOXXXXXOO
 Sample Output
 12
*/