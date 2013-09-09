#include <iostream>
using namespace::std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		unsigned k=n*2;
		unsigned sum=(k*k-k+2)/2;
		cout << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 yiyi loves pancakes, every time he orders a pancake, he cuts it into smaller pieces, and swallows them all.
 One straight cut makes a whole pancake sepearated into two pieces at most, another cut makes 4, another makes 7, etc.. 
 One day, an idea occurs to him, he wonders how many pieces at most can he make by "zig" cuts, thus each cut looks like "<".Two "zig" cuts can make 7 pieces, see the picture down below for clarification.
 
 Note that a single "zig" cut cannot be placed with its vertex on or out of the edge of the pancake, which would be considered as two straight cuts.
 
 
 Input
 The first line contains an integer t (0 < t < 1000) which indicates the number of testcases, then followed t lines, each line contains a single integer n(n < 10000) 
 
 Output
 For each testcase, print the number - how many pieces can be seperated by n "zig" cuts, in separate lines. 
 
 Sample Input
 2
 1
 2
 Sample Output
 2
 7
*/