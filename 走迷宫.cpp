#include <iostream>
#include<stdio.h>
#include <string.h>
#define N 101
using namespace::std;

class p{
public:
	int x,y,step;
};
p queue[5001],temp;
char a[N][N];
int x1[4]={0,1,0,-1};
int y1[4]={1,0,-1,0};
char b[10001]={0};
int position(p temp,int i,int x,int y,int stop)
{
	int dx=temp.x+x1[i];
	int dy=temp.y+y1[i];
	if(dx>=0&&dx<x&&dy>=0&&dy<y&&a[dx][dy]!='*')
	{
		for(i=0;i<=stop;i++)
			if(dx==queue[i].x&&dy==queue[i].y)

				return 0;
		return 1;
	}	
	return 0;
}

int find(p temp,int x,int y,int m,int n)
{
	int i,lab=0,stop=0;
	queue[0]=temp;
	while(lab<=stop)
	{
		for(i=0;i<4;i++)
		{
			if(position(temp,i,m,n,stop))
			{
				if(a[temp.x+x1[i]][temp.y+y1[i]]=='T')
					return temp.step +1;
				stop++;
				queue[stop].x=temp.x+x1[i];
				queue[stop].y=temp.y+y1[i];
				queue[stop].step=temp.step +1;
			}
		}
		temp=queue[++lab];
	}
	return -1;
}

int main()
{
	int x=0,y=0,m,n;
	int i,j;
	scanf("%d %d",&m,&n);
	printf("%d%d\n",m,n);
	for(i=0;i<m;i++)
		
	{
		//cin >> a[i];
		scanf("%s",a[i]);
		cout << m <<"1111";
	}			
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(a[i][j]=='S')
			{
				x=i;
				y=j;
				temp.x=i;
				temp.y=j;
				//temp.step=0;
				break;
			}
	a[x][y]='0';
	//find(temp,x,y,m,n);
	for(i=0;i<m;i++)
	{
	   for(j=0;j<n;j++)
			cout>> a[i][j];
	   cout << endl;
	}
	return 0;
}
