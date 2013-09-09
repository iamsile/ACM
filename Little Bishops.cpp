#include <iostream>
#include <stdio.h>
using namespace std;
const long table[9][65]={{0},{1,1},{1,4,4},{1,9,26,26,8},{1,16,92,232,260,112,16},
{1,25,240,1124,2728,3368,1960,440,32},{1,36,520,3896,16428,39680,53744,38368,12944,1600,64},
{1,49,994,10894,70792,282248,692320,1022320,867328,389312,81184,5792,128},{1,64,1736,26192,
242856,1444928,5599888,14082528,22522960,22057472,12448832,3672448,489536,20224,256}};

int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)){
        if (!n&&!m)
            return 0;
        printf("%ld\n", table[n][m]);
    }
    return 0;
}
/*
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;
int n,m,num;

void construct_candidates(int a[],int k,int c[],int *ncandidates)
{
	*ncandidates=0;
	int i,j,ans,bns,t,temp;
	ans=k;
	bns=0;
	if(k>n) ans=2*n-k;
	for(i=0; i<=ans; i++)
	{
		temp=1;
		for(j=1; j<k&&i!=0; j++)
		{
			if(k%2!=j%2) continue;
			if(a[j]==0) continue;
			if(j>n) bns=2*n-j;
			else bns=j;
			if(k>n&&j>n)
			{
				t=(abs(j-k)/2);
				if(t+i==a[j])
                    temp=0;
			}
			else if(k>n&&j<=n)
			{
				t=(abs(2*n-k-j)/2);
				if(2*n-k<j)
				{
					if(i+t==a[j])
                        temp=0;
				}
				else
				{
					if(i==t+a[j])
						temp=0;
				}
			}
			else if(k<=n&&j<=n)
			{
                t=(abs(k-j)/2);
                if(t+a[j]==i)
                    temp=0;
			}
		}
		if(temp)
		{
			c[*ncandidates]=i;
			*ncandidates=*ncandidates+1;
		}
	}
}

int is_a_solution(int k,int a[],int count)
{
	if(count==m)
	{
		num++;
	    return 1;
	}
	else if(k==2*n-1)
		return 1;
	else return 0;    
}

void backtrack( int a[], int k, int count)
{
	int c[500],temp;
	int ncandidates;
	int i;
	if(is_a_solution(k,a,count)==0)
	{
		k++;
		construct_candidates(a,k,c,&ncandidates);
        temp=1;
		for(i=0; i<ncandidates; i++)
		{
			a[k]=c[i];
			if(c[i]!=0&&temp)
			{
				count++;
				temp=0;
			}
			if(count+2*n-1-k>=m)
                backtrack(a,k,count);
		}
	}
}

int main()
{
	int a[1000];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		num=0;
		backtrack(a,0,0);
		printf("%d\n",num);
	}
	return 0;
}*/
/*#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,m,map[10][10];
unsigned num;

void dfs(int x,int y,int k)
{
    if (y==n) {
        ++x;
        y=0;
    }
    if (k==m) {
        ++num;
        return;
    }
    if (x==n)
        return;
    if (!map[x][y]) {
        int i,j,loc=0,pos[1001][2];
        for (i=x,j=y; i<n&&j<n; i++,j++)
            if (!map[i][j]) {
                map[i][j]=1;
                pos[loc][0]=i;
                pos[loc][1]=j;
                loc++;
            }
        for (i=x-1,j=y-1; i>=0&&j>=0; i--,j--)
            if (!map[i][j]) {
                map[i][j]=1;
                pos[loc][0]=i;
                pos[loc][1]=j;
                loc++;
            }
        for (i=x,j=y; i>=0&&j<n; i--,j++)
            if (!map[i][j]) {
                map[i][j]=1;
                pos[loc][0]=i;
                pos[loc][1]=j;
                loc++;
            }
        for (i=x,j=y; i<n&&j>=0; i++,j--)
            if (!map[i][j]) {
                map[i][j]=1;
                pos[loc][0]=i;
                pos[loc][1]=j;
                loc++;
            }
        map[x][y]=1;
        dfs(x, y+1, k+1);
        map[x][y]=0;
        for (i=0; i<loc; i++)
            map[pos[i][0]][pos[i][1]]=0;
    }
    dfs(x, y+1, k);
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF) {
        if (!n&&!m)
            return 0;
        num=0;
        memset(map, 0, sizeof(map));
        dfs(0,0,0);
        printf("%u\n",num);
    }
    return 0;
}*/
/*
 A bishop is a piece used in the game of chess which can only move diagonally from its current position. Two bishops attack each other if one is on the path of the other. In the figure below, the dark squares represent the reachable locations for bishop B1 from its current position. Bishops B1 and B2 are in attacking position, while B1 and B3 are not. Bishops B2 and B3 are also in non-attacking position.
 
 
 
 Given two numbers n and k, determine the number of ways one can put k bishops on an n x n chessboard so that no two of them are in attacking positions.
 
 Input
 
 The input file may contain multiple test cases. Each test case occupies a single line in the input file and contains two integers n(1  n  8) and k(0  k  n2).
 
 A test case containing two zeros terminates the input.
 
 Output
 
 For each test case, print a line containing the total number of ways one can put the given number of bishops on a chessboard of the given size so that no two of them lie in attacking positions. You may safely assume that this number will be less than 1015.
 
 Sample Input
 
 8 6
 4 4
 0 0
 Sample Output
 
 5599888
 260
*/