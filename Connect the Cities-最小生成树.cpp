#include<stdio.h>
#include<stdlib.h>
struct t
{
    int x,y,cost;       
}kru[25024];
int set[524];
int cmp( const void *a,const void *b )
{
    return ( ( t * )a)->cost - (( t * )b )->cost;
}
inline int find( int x )
{
    return set[x]==x ? x : set[x]=find ( set[x] );    
}
bool judge( int N )
{
    int count=0;
    for (int i=1;i<=N; i++ )
    {
        if(set[i]==i )
        {
            count++;
            if(count==2 )
                return false;
        } 
    }
    return true;     
}

int kruscal( int N,int n )
{
    int sum=0,X,Y;
    for(int i=0;i<N;i++)
    {
        if(( X=find( kru[i].x )) !=( Y=find( kru[i].y )))
        {
            sum+=kru[i].cost;
            set[Y]=X;
        }     
    } 
    if( judge( n ))  return sum;
    else return -1;   
}

int main()
{
    
    int T,n,m,k,N,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<=n;i++)
        {
            set[i]=i;     
        }       
        for( int i=0;i<m; i++ )
        {
            scanf("%d%d%d",&kru[i].x,&kru[i].y,&kru[i].cost);   
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&N);
            scanf( "%d",&x);
            int X=find(x);
            for(int i=1;i<N;i++)
            {
                scanf("%d",&y);
                set[find(y)]=X;     
            }     
        }
        qsort(kru,m,sizeof(kru[0]),cmp);
        printf("%d\n",kruscal(m ,n));
    }
    return 0;    
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 510

int map[MAXN][MAXN], lowcost[MAXN];
bool visit[MAXN];
int alr[MAXN];
int num, sum;

void prim()
{
	int temp, k;
	memset(visit, false, sizeof(visit));
	for(int i = 1; i <= num; ++i)
		lowcost[i] = map[1][i];
	sum = 0;
	visit[1] = true;
	for(int i = 1; i <= num; ++i)
	{
		temp = INF;
		for(int j = 1; j <= num; ++j)
			if(!visit[j] && temp > lowcost[j])
				temp = lowcost[k = j];
		if(temp == INF)
			break;
		visit[k] = 1;
		sum += temp;
		for(int j = 1; j <= num; ++j)
			if(!visit[j] && lowcost[j] > map[k][j])
				lowcost[j] = map[k][j];
	}
}

int main()
{
	int ncase;
	int road, already;
	int a, b, cost;
	int nodenum, node;
	bool flag;
	scanf("%d", &ncase);
	while(ncase--)
	{
		flag = true;
		memset(alr, INF, sizeof(alr));
		memset(map, INF, sizeof(map));
		scanf("%d%d%d", &num, &road, &already);
		for(int i = 1; i <= road; ++i)
		{
			scanf("%d%d%d", &a, &b, &cost);
			if(cost < map[a][b])
				map[a][b] = map[b][a] = cost;
		}
		for(int i = 1; i <= already; ++i) //处理这些权值为0的边
		{
			scanf("%d", &nodenum);
			for(int j = 1; j <= nodenum; ++j)
				scanf("%d", &alr[j]);
			int k;
			for(int j = 1; j < nodenum; ++j)
			{
				k = j + 1;
				map[alr[j]][alr[k]] = map[alr[k]][alr[j]] = 0;
			}
		}
		prim();
		for(int i = 1; i <= num; ++i) //判断图的连通性
			if(visit[i] == false)
				flag = false;
		if(flag)
			printf("%d\n", sum);
		else
			printf("-1\n");
	}
	return 0;
}
*/
/*
 Problem Description
 In 2100, since the sea level rise, most of the cities disappear. Though some survived cities are still connected with others, but most of them become disconnected. The government wants to build some roads to connect all of these cities again, but they don’t want to take too much money.  
 
 
 Input
 The first line contains the number of test cases.
 Each test case starts with three integers: n, m and k. n (3 <= n <=500) stands for the number of survived cities, m (0 <= m <= 25000) stands for the number of roads you can choose to connect the cities and k (0 <= k <= 100) stands for the number of still connected cities.
 To make it easy, the cities are signed from 1 to n.
 Then follow m lines, each contains three integers p, q and c (0 <= c <= 1000), means it takes c to connect p and q.
 Then follow k lines, each line starts with an integer t (2 <= t <= n) stands for the number of this connected cities. Then t integers follow stands for the id of these cities.
 
 
 Output
 For each case, output the least money you need to take, if it’s impossible, just output -1.
 
 
 Sample Input
 1
 6 4 3
 1 4 2
 2 6 1
 2 3 5
 3 4 33
 2 1 2
 2 1 3
 3 4 5 6
 
 
 Sample Output
 1
*/