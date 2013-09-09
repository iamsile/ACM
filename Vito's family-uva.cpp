#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace::std;

int main()
{
	int m;
	cin >> m;
	while(m--)
	{
		int n,a[30000],sum=0;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a+0, a+n);
		for(int i=0;i<n;i++)
			sum+=abs(a[n/2]-a[i]);
		cout << sum << '\n';
	}
	return 0;
}
/*
 The famous gangster Vito Deadstone is moving to New York. He has a very big family there, all of them living on Lamafia Avenue. Since he will visit all his relatives very often, he wants to find a house close to them.
 
 Indeed, Vito wants to minimize the total distance to all of his relatives and has blackmailed you to write a program that solves his problem.
 
 Input
 
 The input consists of several test cases. The first line contains the number of test cases.
 For each test case you will be given the integer number of relatives r (0 < r < 500) and the street numbers (also integers) s1, s2,..., si,..., sr where they live (0 < si < 30, 000). Note that several relatives might live at the same street number.
 
 Output
 
 For each test case, your program must write the minimal sum of distances from the optimal Vito's house to each one of his relatives. The distance between two street numbers si and sj is dij = | si - sj|.
 Sample Input
 
 2
 2 2 4 
 3 2 4 6
 Sample Output
 
 2
 4
*/