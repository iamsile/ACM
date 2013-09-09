#include<iostream>
using namespace std;

int min1;
int a[8][8];
int n;
int max(int a[])
{
	int m=-999999999;
	for(int i=0;i<n;i++)
		if(a[i]>m)
			m=a[i];
	return m;
}

void dfs(int k,int a1[])
{
	int i,j,temp[8];
	if(k==n)
	{
		int mm=max(a1);
		if(mm<min1)
			min1=mm;
		return ;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			temp[j]=a1[j];
		for(j=0;j<n;j++)
			temp[j]+=a[k][(j+i)%n];
		dfs(k+1,temp);
	}
}

int main()
{
	while(cin >> n&&n!=-1)
	{
		min1=INT_MAX/2;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> a[i][j];
		dfs(1,a[0]);
		cout << min1 <<'\n';
	}
	return 0;
}
/*
这题在于枚举的一个小技巧。每次把一行的数都叠加到下一行要转换的然后再转这样可以减少最后取和的运算
*/
/*
 Problem description
 Given an n*n matrix A, whose entries Ai,j are integer numbers ( 0 <= i < n, 0 <= j < n ). An operation SHIFT at row i ( 0 <= i < n ) will move the integers in the row one position right, and the rightmost integer will wrap around to the leftmost column. 
 　
 
 
 You can do the SHIFT operation at arbitrary row, and as many times as you like. Your task is to minimize 
 　
 max0<=j< n{Cj|Cj=Σ0<=i< nAi,j}
 
 
 Input
 The input consists of several test cases. The first line of each test case contains an integer n. Each of the following n lines contains n integers, indicating the matrix A. The input is terminated by a single line with an integer −1. You may assume that 1 <= n <= 7 and |Ai,j| < 104.
 
 Output
 For each test case, print a line containing the minimum value of the maximum of column sums.
 
 Sample Input
 2
 4 6
 3 7
 3
 1 2 3
 4 5 6
 7 8 9
 -1
 Sample Output
 11
 15
*/