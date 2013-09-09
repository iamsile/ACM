#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node {
    int x,y,step;
    node () {
        x=y=step=0;
    }
};

int n,m,sx,sy,tx,ty,flag;
int dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};

void bfs()
{
    if (abs(sx-tx)/2>m||abs(sy-ty)/2>m)
        return;
    queue<node> q;
    map<pair<int, int>, int> v;
    v.clear();
    pair<int, int> b;
    node cur,nex;
    cur.x=sx;
    cur.y=sy;
    cur.step=0;
    b.first=cur.x;
    b.second=cur.y;
    v[b]=1;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        if (cur.step>m)
            continue;
        if (cur.x==tx&&cur.y==ty&&cur.step<=m) {
            flag=1;
            return;
        }
        for (int i=0; i<8; i++) {
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            b.first=nex.x;
            b.second=nex.y;
            if (nex.x>=1&&nex.x<=n&&nex.y>=1&&nex.y<=n&&!v[b]) {
                nex.step=cur.step+1;
                v[b]=1;
                q.push(nex);
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
        flag=0;
        bfs();
        if (flag)
            printf("Knight can reach Queen within %d moves!\n",m);
        else printf("Knight cannot reach Queen within %d moves!\n",m);
    }
    return 0;
}
/*
#include<iostream>
#include<cmath>
using namespace std;
int sx,sy,ex,ey;
int map[2][2]={0,3,3,2};
int n;
int s;
int func(int x,int y)
{
    int sum=0;
    if(x>=2)
    {
        if(y==1)
        {
            y=0;
            if(x%2==1)
            {
                sum+=2;
                x-=3;
            }
            else
            {
                x-=2;
                sum++;
            }
        }
        if(x%2==1)
        {
            sum+=3;
            if(x>=5)
                x-=5;
            else
                x--;
        }
        sum+=(x/4)*2+x%4;
        x=0;
    }
    sum+=map[x][y];
    return sum;
}
int main()
{
    while(scanf("%d%d",&n,&s)!=EOF)
    {
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        int x,y;
        int sum=0;
        x=abs(sx-ex);
        y=abs(sy-ey);
        if(n==3&&((sx==2&&sy==2)||(ex==2&&ey==2)))
            sum=999;
        if(x<y)
            swap(x,y);
        if((x==1&&y==1)&&(sx==1||ex==1||sx==n||ex==n)&&(sy==1||ey==1||sy==n||ey==n))
        {
            printf("Knight can");
            if(4>s)
                printf("not");
            printf(" reach Queen within %d moves!\n",s);
            continue;
        }
		int sb=(y/3)-1;
		y-=sb*3;
		x-=sb*3;
		sum+=sb*2;
        int x1=x,x2=x,y1=y,y2=y;
        int sum1=sum,sum2=sum;
        if(x>=2&&y>=2)
        {
            if(x/2>y)
            {
                sum1+=y;
                x1=x-y*2;
                y1=0;
            }
            else if(x/2<y)
            {
                sum1+=x/2;
                x1=x%2;
                y1=y-x/2;
                if(x1<y1)
                    swap(x1,y1);
            }
            y2=y%2;
            x2=x-y/2;
            sum2+=y/2;
            if(x2<y2)
                swap(x2,y2);
        }
        sum1+=func(x1,y1);
        sum=sum1;
        if(x1!=x2||y1!=y2)
        {
            sum2+=func(x2,y2);
            if(sum2<sum)
                sum=sum2;
        }
		printf("Knight can");
		if(sum>s)
			printf("not");
		printf(" reach Queen within %d moves!\n",s);
    }
    return 0;
}
*/
/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <ctype.h>
using namespace std;

int map[2000][2000];
int vst[2000][2000];
int n,m;
int sx,sy,ex,ey;
bool flag;
int ledgex1,ledgey1,ledgex2,ledgey2;
int dir[8][2]={
    2,1,
    1,2,
    -1,2,
    -2,1,
    -2,-1,
    -1,-2,
    1,-2,
    2,-1
};

struct node
{
    int x,y;
    int step;
}Node;

bool check(int x,int y)
{
    if(x>=(1000-ledgex1)&&x<(1000+n-ledgex1)&&y>=(1000-ledgey1)&&y<(1000+n-ledgey1)&&!vst[x][y])
        return true;
    else
        return false;
}

void bfs()
{
    int i;
    node pre,last;
    pre.x=1000;
    pre.y=1000;
    pre.step=0;
    queue<node>Que;
    Que.push(pre);
    while(!Que.empty())
    {
        pre=Que.front();
        Que.pop();
        if(pre.step>m)
        {
            flag=false;
            return;
        }
        if(pre.x==ex&&pre.y==ey)
        {
            if(pre.step>m)
                flag=false;
            return;
        }
        for(i=0;i<8;i++)
        {
            last.x=pre.x+dir[i][0];
            last.y=pre.y+dir[i][1];
            last.step=pre.step+1;
            if(check(last.x,last.y))
            {
                vst[last.x][last.y]=1;
                Que.push(last);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&ex,&ey))
    {
        flag=true;
        memset(vst,0,sizeof(vst));
        if(abs(ex-sx)>m*2||abs(ey-sy)>m*2)
            flag=false;
        else
        {
            sx--;
            ex--;
            sy--;
            ey--;
            ledgex1=(sx>ex?ex:sx)>513?513:(sx>ex?ex:sx);
            ledgey1=(sy>ey?ey:sy)>513?513:(sy>ey?ey:sy);
            ex=ex-sx+1000;
            ey=ey-sy+1000;
            bfs();
        }
        if(flag)
            printf("Knight can reach Queen within %d moves!\n",m);
        else
            printf("Knight cannot reach Queen within %d moves!\n",m);
    }
    return 0;
}
*/
/*
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
    int x,y,step;
}S,E;
int n,k,kx,ky,qx,qy;
int dx[8]={1,1,2,2.-1,-1,-2,-2},dy[8]={2,-2,1,-1,2,-2,1,-1};
bool vit[1000][1000],flag;
bool f(int x,int y)
{
    if(x<0||x>n||y<0||y>n)
        return false;
    return true;
}
int fun(node a,node b)
{
    queue<node>Q;
    while(!Q.empty())
        Q.pop();
    node head,temp;
    Q.push(a);
    while(!Q.empty())
    {
        head=Q.front();
        Q.pop();
        if(head.x==b.x&&head.y==b.y&&head.step<=k)
            return head.step;
        if(head.step<k)
        {
            for(int i=0;i<8;i++)
            {
                temp.x=head.x+dx[i];
                temp.y=head.y+dy[i];
                temp.step=head.step+1;
                if(!vit[temp.x][temp.y]&&f(temp.x,temp.y))
                {
                    vit[temp.x][temp.y]=true;
                    Q.push(temp);
                }
            }
        }
    }
    return 0;
}
int abs(int x)
{
    if(x>=0)
        return x;
    else
        return -x;
}
void inte()
{
    int x1,x2,y1,y2,m1,m2;
    x1=kx;y1=ky;x2=qx;y2=qy;
    if(abs(kx-qx)>2*k||abs(ky-qy)>2*k)
        flag=true;
    else
    {
        if(kx<=qx)
        {
            if(kx-2*k>=0)
            {
                kx=2*k;
                qx=qx-x1+2*k;
            }
        }
        else
        {
            if(qx-2*k>=0)
            {
                qx=2*k;
                kx=kx-x2+2*k;
            }
        }
        if(ky<=qy)
        {
            if(ky-2*k>=0)
            {
                ky=2*k;
                qy=qy-y1+2*k;
            }
        }
        else
        {
            if(qy-2*k>=0)
            {
                qy=2*k;
                ky=ky-y2+2*k;
            }
        }
    }
    S.x=kx;S.y=ky;E.x=qx;E.y=qy;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset(vit,false,sizeof(vit));
        flag=false;
        scanf("%d%d",&kx,&ky);
        scanf("%d%d",&qx,&qy);
        inte();
        int s=0;
        if(!flag)
            s=fun(S,E);
        if(s)
            printf("Knight can reach Queen within %d moves!\n",k);
        else
            printf("Knight cannot reach Queen within %d moves!\n",k);
    }
    return 0;
}
*/
/*
#include<cstdio>
#include<map>
#include<cmath>
#include<iostream>
using namespace std;
#define max 1000010
typedef struct
{
    int x,y;
    int t;
}node;
node q;
node que[max*3];//这里空间可能掌握不好 用queue容器这里很好 
int dir[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2},{-1,2}, {-2,1}, {-2,-1}, {-1,-2}};
int n,m;
map<pair<int ,int >,int> v;

int check(node tt)
{
	return tt.x>=1&&tt.x<=n&&tt.y>=1&&tt.y<=n;
}

int bfs(node s)
{
    pair<int ,int > a;
    int head=0,tail=0,i,tmp;
    if(abs(s.x-q.x)/2>m||abs(s.y-q.y)/2>m)return 0;//剪枝① 
	v.clear();
    a.first=s.x;
	a.second=s.y;
    v[a]=0;
    que[tail++]=s;
    if(v[a]>m)return 0;//特殊判断 输入的步数为负数 
    while(head<tail)
    {
        s=que[head++];
        a.first=s.x;
		a.second=s.y;
        tmp=v[a];
        if(tmp==m)continue;//剪枝 ② 
        for(i=0;i<8;i++)
        {
			node tt;
            tt.x=s.x+dir[i][0];
            tt.y=s.y+dir[i][1];
       		a.first=tt.x;
       		a.second=tt.y;
            if(tt.x==q.x&&(tt.y==q.y))
            {
                return 1;	
            }
       		if(check(tt)&&v.find(a)==v.end())
       		{
                v[a]=tmp+1;
                //if((tmp+1)<m)
                que[tail++]=tt;
	   		}
            
        }
    }
    return 0;
}

int main()
{
    int t;
    node s;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d%d%d%d",&s.x,&s.y,&q.x,&q.y);
        t=bfs(s);
        if(t)
            printf("Knight can reach Queen within %d moves!/n",m);
        else
            printf("Knight cannot reach Queen within %d moves!/n",m);
    }
    return 0;
}
*/
/*
 Problem description
 Marge walks in the house and finds Homer staring at a chessboard with a knight and a queen on it.
 
 Marge: Homer, are you OK? What’s up with these intellectual endeavors of yours recently?
 Homer: Oh, I’m OK. And I’m not playing chess anyway.
 Marge: So what are you doing?
 Homer: I’m imagining that I’m a knight.
 Marge: Yeah right.
 Homer: Well, a knight sitting on the chessboard. And I imagine you are my queen.
 Marge: I like that.
 Homer: Of course you are sitting on the chessboard too. Now I wonder if I can reach the square you’re sitting on in 16 or fewer moves.
 Marge: So can you?
 Homer: I’m still trying to figure it out.
 
 Write a program that, when given a knight and a queen on an n by n chessboard, finds if the knight can reach the queen in m or fewer than moves. One ”move” for a knight is defined as 2 squares in one direction, then one square in a perpendicular direction. Knights cannot move along diagonals. For example, if n = 8, kx = 3, and ky = 5, then possible positions for the knight after one move given in (kx, ky) are: (1,6), (1,4), (2,7), (2,3), (4,7), (4,3), (5,6), and (5,4).
 
 
 
 
 Input
 For each test the input consists of 3 lines. The first line contains 2 numbers: n and m. n is the dimension of the board, and m is the number of moves the knight is allowed to do.
 The second line contains two numbers: kx and ky, s.t. 1 ≤ kx ≤ n, 1 ≤ ky ≤ n. These two numbers indicate the position of the knight on the board.
 The last line again contains two numbers: qx and qy, s.t. 1 ≤ qx ≤ n, 1 ≤ qy ≤ n. They indicate the position of the queen on the board.
 
 Output
 If the queen is reachable by the knight with m or less moves, output should contain the following string on a single line ending with a newline:
 Knight can reach Queen within m moves!
 
 If the queen is not reachable by the knight with m or less moves, output should contain the following string on a single line ending with a newline:
 Knight cannot reach Queen within m moves!
 
 In the above, m should be the actual value from the input.   No test case will have the queen and the knight sitting on the same square. You can further assume that n ≤ 1000000,m ≤ 256. Your program should finish in less than one minute.
 
 Sample Input
 8 2
 3 5
 7 4
 
 8 3
 3 5
 7 4
 Sample Output
 Knight cannot reach Queen within 2 moves!
 Knight can reach Queen within 3 moves!
*/