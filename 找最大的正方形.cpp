#include <iostream>    
using namespace std;  

int main()
{   
	int i,j,k,n,t,lab;
	int x[501],y[501],s[501];
	char a[501][501];
	memset(a,0,sizeof(a));   
	cin >> n>> t;   
	for(k=0;k<t;k++)
	{   
		cin >> i >> j;   
		a[i][j]=1;   
	}   
	for(i=0;i<=n;i++)   
	{   
		x[i]=0;   
		y[i]=0;   
	}   
	lab=0;   
	for(i=1;i<=n;i++)
	{   
		for(j=1;j<=n;j++)   
			if(a[i][j])//以输入的点为起始点进行深度搜索
			{   
				x[j]=0;   
				y[j]=0;   
			}
			else
			{   
				x[j]++;   
				y[j]=y[j-1]+1;   
			}   
		for(j=n;j>=1;j--)
		{   
			s[j]=s[j-1]+1;   
			if(x[j]<s[j]) //如果x[j]>s[j]则代表这个点已经搜索过了
				s[j]=x[j];   
			if(y[j]<s[j]) //
				s[j]=y[j];   
			if(s[j]>lab)//搜索的最大深度
				lab=s[j];   
		}   
	}   
	cout<< lab <<'\n'; 
	return 0;
}
/*
 Problem description
 在平面N*N(N<=500)的格子上有一些障碍物。要求找到一个最大的正方形，它的内部不包含障碍物。
 
 Input
 第一行个正整数，以空格隔开，第一个数n(n<=500)表示格子的大小N，第二个数表示在n*n里障碍物的个数。 下面的n行分别描述每个障碍物位置，每一行两个数i,j，(1<=i,j<=500)以空格隔开，分别表示障碍物位于第i行，第j列。 
 
 Output
 输出最大正方形的边长。
 
 Sample Input
 5 4
 1 2
 3 4
 5 2
 4 5
 Sample Output
 3
*/