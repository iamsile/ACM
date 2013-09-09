#include <iostream>
#include <algorithm>
using namespace std;

int a[51][1001];
int compute(const int b, const int f)
{
	if(b==1) 
		return f;
	if(f==0) 
		return 0;
	if(f==1) 
		return 1;
	if(a[b][f]>=0)
		return a[b][f];
	int m=f;
	for (int n=1;n<=f;++n)
	{
		const int x=compute(b-1, n-1);
		const int y=compute(b, f-n);
		const int z=1+(x>y?x:y);
		m=(z<m?z:m);
	}
	a[b][f]=m;
	return m;
}

int main()
{
	int b,prob;
	for (int f=1;f<=1000;++f)
		a[1][f]=f;
	for(b=2;b<=50;++b)
	{
		a[b][1]=1;
		a[b][0]=0;
	}
	for(b=2;b<=50;++b)
		for(int f=2;f<=1000;++f)
			a[b][f]=-1;
	int num;
	cin >> num;
	for(int i=1;i<=num;++i)
	{
		int b,f;
		cin >> prob;
		cin >> b >> f;
		cout << prob << " " << compute(b,f) << endl;
	}
	return 0;
}
/*
 Problem description
 The classic Two Glass Balls brain-teaser is often posed as:
 "Given two identical glass spheres, you would like to determine the lowest floor in a 100-story building from which they will break when dropped. Assume the spheres are undamaged when dropped below this point. What is the strategy that will minimize the worst-case scenario for number of drops?"
 Suppose that we had only one ball. We'd have to drop from each floor from 1 to 100 in sequence, requiring 100 drops in the worst case.
 Now consider the case where we have two balls. Suppose we drop the first ball from floor n. If it breaks we're in the case where we have one ball remaining and we need to drop from floors 1 to n-1 in sequence, yielding n drops in the worst case (the first ball is dropped once, the second at most n-1 times). However, if it does not break when dropped from floor n, we have reduced the problem to dropping from floors n+1 to 100. In either case we must keep in mind that we've already used one drop. So the minimum number of drops, in the worst case, is the minimum over all n.
 You will write a program to determine the minimum number of drops required, in the worst case, given B balls and an M-story building.
 
 
 Input
 The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set consists of a single line containing three (3) decimal integer values: the problem number, followed by a space, followed by the number of balls B, (1 ≤ B ≤ 50), followed by a space and the number of floors in the building M, (1 ≤ M ≤ 1000). 
 
 Output
 For each data set, generate one line of output with the following values: The data set number as a decimal integer, a space, and the minimum number of drops needed for the corresponding values of B and M. 
 
 Sample Input
 4 
 1 2 10 
 2 2 100 
 3 2 300 
 4 25 900
 Sample Output
 1 4 
 2 14 
 3 24 
 4 10
*/