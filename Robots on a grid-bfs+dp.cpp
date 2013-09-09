#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
const int mod=0x7fffffff;
struct node {
    int x,y;
    node() {
        x=y=0;
    }
};

char map[1015][1015];
bool v[1015][1015];
int n,ans,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
long long dp[1015][1015];

void bfs()
{
    queue<node> q;
    node cur,nex;
    cur.x=n-1;
    cur.y=n-1;
    v[n-1][n-1]=1;
    q.push(cur);
    while (!q.empty()) {
        cur=q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            if (nex.x>=0&&nex.x<n&&nex.y>=0&&nex.y<n&&!v[nex.x][nex.y]
                &&map[nex.x][nex.y]=='.') {
                if (dp[nex.x][nex.y]) {
                    ans=1;
                    return;
                }
                v[nex.x][nex.y]=1;
                q.push(nex);
            }
        }
    }
    ans=2;
}

int main()
{
    while (~scanf("%d",&n)) {
        int i,x,y;
        ans=0;
        memset(dp, 0, sizeof(dp));
        for (i=0; i<n; i++)
            scanf("%s",map[i]);
        dp[0][0]=1;
        for (i=1; i<n+n; i++) {
            x=i<n?i:n;
            y=i-x;
            for (; x>=0&&y<n; x--,y++)
                if (map[x][y]=='.')
                    dp[x][y]=(dp[x-1][y]+dp[x][y-1])%mod;
        }
        if (dp[n-1][n-1])
            printf("%lld\n",dp[n-1][n-1]); 
        else {
            memset(v, 0, sizeof(v));
            bfs();
            printf("%s\n",ans==1?"THE GAME IS A LIE":"INCONCEIVABLE");
        }
    }
    return 0;
}
/*
#include<iostream>
#include<queue>
#define Max 2147483647
using namespace std;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char a[1001][1001];
int flag[1001][1001];
__int64 dp[1001][1001];
int n;
int bigstep;
int r,c;
struct node
{
	int x,y;
	int step;
};
void bfs()
{
	int i;
	node p,temp;
	p.x=0;
	p.y=0;
	p.step=1;
	flag[0][0]=1;
	queue<node>q;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			temp=p;
			temp.x+=dir[i][0];
			temp.y+=dir[i][1];
			temp.step=p.step+1;
			if(temp.x<0||temp.x>=n||temp.y<0||temp.y>=n||a[temp.x][temp.y]=='#')
				continue;
			if(a[temp.x][temp.y]=='.'&&flag[temp.x][temp.y]==0)
			{
				q.push(temp);
				flag[temp.x][temp.y]=1;
			}
			if(temp.x==n-1&&temp.y==n-1)
			{
				bigstep=temp.step;
				return;
			}
		}
	}
}
int main()
{
	int i,j;
	//freopen("C:\Users\Administrator\Documents\Tencent\robots.4.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
			gets(a[i]);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(i=0;i<n;i++)
		{
			if(a[0][i]!='#')
				dp[0][i]=1;
			else
				break;
		}
		for(i=0;i<n;i++)
		{
			if(a[i][0]!='#')
				dp[i][0]=1;
			else
				break;
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(a[i][j]!='#')
				{
					dp[i][j]=(dp[i][j-1]+dp[i-1][j])%Max;
				}
				else
				{
					dp[i][j]=0;
					continue;
				}
			}
		}
		if(dp[n-1][n-1])
			printf("%I64d\n",dp[n-1][n-1]%Max);
		else
		{
			bigstep=0;
			memset(flag,0,sizeof(flag));
			bfs();
			if(bigstep)
				printf("THE GAME IS A LIE\n");
			else
				printf("INCONCEIVABLE\n");
		}
	}
	return 0;
}
*/
/*
 Problem description
 
 You have recently made a grid traversing robot that can find its way from the top left corner of a grid to the bottom right corner. However, you had forgotten all your AI programming skills, so you only programmed your robot to go rightwards and downwards (that's after all where the goal is). You have placed your robot on a grid with some obstacles, and you sit and observe. However, after a while you get tired of observing it getting stuck, and ask yourself "How many paths are there from the start position to the goal position?", and "If there are none, could the robot have made it to the goal if it could walk upwards and leftwards?"
 So you decide to write a program that, given a grid of size nn with some obstacles marked on it where the robot cannot walk, counts the different ways the robot could go from the top left corner s to the bottom right t, and if none,tests if it were possible if it could walk up and left as well. However, your program does not handle very large numbers, so the answer should be given modulo 231-1.
 
 Input
 On the first line is one integer, 1 <= n <= 1000. Then follows n lines, each with n characters,where each character is one of '.' and '#', where '.' is to be interpreted as a walkable tile and '#' as a non-walkable tile. There will never be a wall at s, and there will never be a wall at t.
 
 Output
 Output one line with the number of dierent paths starting in s and ending in t (modulo 231-1) or THE GAME IS A LIE if you cannot go from s to t going only rightwards and downwards but you can if you are allowed to go left and up as well, or INCONCEIVABLE if there simply is no path from s to t.
 
 Sample Input
 5
 .....
 #..#.
 #..#.
 ...#.
 .....
 7
 ......#
 ####...
 .#.....
 .#...#.
 .#.....
 .#..###
 .#.....
 Sample Output
 6
 THE GAME IS A LIE
*/