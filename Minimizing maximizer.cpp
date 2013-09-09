#include <iostream>
#include <stdlib.h>
int n, m, N;
int min[70000];

int find(int a)
{
	int x=min[a],i;
	for(i=1;i < N;i<<=1)
	{
		if((a&i)&&!(a&(i<<1)))
		{
			a&=~i; 
			a|=(i<<1);
			if(min[a]<x) 
				x=min[a];
		}
		a&=~i;
	}
	return x;
}

void put(int a,int x)
{
	int i;
	for(i=1;a!=0;i<<=1)
	{
		if(min[a]>x) 
			min[a]=x;
		a&=~i;
	}
}

int main()
{
	int a,b,i=1,j;
	scanf("%d%d",&n,&m);
	while(i<n)
	{ 
		i<<=1;
	}
	N=i;
	for(i=0;i<=N;i++) 
		min[i]=9999999;
	min[0]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		a--;
		b--;
		j=find(a);
		if(j>=9999999)
			continue;
		put(b,j+1);
	}
	printf("%d\n",find(n-1));
	return 0;
}
/*
 Problem description
 The company Chris Ltd. is preparing a new sorting hardware called Maximizer. Maximizer has n inputs numbered from 1 to n. Each input represents one integer. Maximizer has one output which represents the maximum value present on Maximizer's inputs. 
 
 Maximizer is implemented as a pipeline of sorters Sorter(i1, j1), ... , Sorter(ik, jk). Each sorter has n inputs and n outputs. Sorter(i, j) sorts values on inputs i, i+1,... , j in non-decreasing order and lets the other inputs pass through unchanged. The n-th output of the last sorter is the output of the Maximizer. 
 
 An intern (a former ACM contestant) observed that some sorters could be excluded from the pipeline and Maximizer would still produce the correct result. What is the length of the shortest subsequence of the given sequence of sorters in the pipeline still producing correct results for all possible combinations of input values? 
 
 Task 
 Write a program that: 
 
 reads a description of a Maximizer, i.e. the initial sequence of sorters in the pipeline, 
 computes the length of the shortest subsequence of the initial sequence of sorters still producing correct results for all possible input data, writes the result. 
 
 
 Input
 The first line of the input contains two integers n and m (2 <= n <= 50000, 1 <= m <= 500000) separated by a single space. Integer n is the number of inputs and integer m is the number of sorters in the pipeline. The initial sequence of sorters is described in the next m lines. The k-th of these lines contains the parameters of the k-th sorter: two integers ik and jk (1 <= ik < jk <= n) separated by a single space. 
 
 Output
 The output consists of only one line containing an integer equal to the length of the shortest subsequence of the initial sequence of sorters still producing correct results for all possible data. 
 
 Sample Input
 40 6
 20 30
 1 10
 10 20
 20 30
 15 25
 30 40
 Sample Output
 4
*/