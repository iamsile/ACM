#include <iostream>
using namespace::std;

int cmp(const void *a,const void *b)
{
	return *(int*)a -*(int*)b;
}

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int i,j,n,a[30001]={0},sum=0;
		cin >> n;
		for(i=0;i<n;i++)
			cin >> a[i];
		qsort(a, n, sizeof(a[0]), cmp);
		j=a[n/2];
		for(i=0;i<n;i++)
			sum+=abs(j-a[i]);
		cout << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 The world-known gangster Vito Deadstone is moving to New York. He has a very big family there, all of them living in Lamafia Avenue. Since he will visit all his relatives very often, he is trying to find a house close to them.
 Vito wants to minimize the total distance to all of them and has blackmailed you to write a program that solves his problem. 
 
 
 Input
 The input consists of several test cases. The first line contains the number of test cases.
 For each test case you will be given the integer number of relatives r ( 0 < r < 500) and the street numbers (also integers)  where they live ( 0 < si < 30000 ). Note that several relatives could live in the same street number. 
 
 
 Output
 For each test case your program must write the minimal sum of distances from the optimal Vito's house to each one of his relatives. The distance between two street numbers si and sj is dij= |si-sj|. 
 
 Sample Input
 2
 2 2 4 
 3 2 4 6
 
 Sample Output
 2
 4
*/