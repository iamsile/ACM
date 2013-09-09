#include <iostream>
using namespace::std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d", &n);
		if(!(240%n))
			puts("YES");
		else 
			puts("NO");
	}
	return 0;
}
/*
 
 Problem description
 A Kitty Number N is a positive integer satisfies that given two positive integers A and B, and among A, B and N, we have 
 N | ((A2)*B+1)
 
 Then 
 N | (A2+B)
 
 Now, you are asked to judge a given positive number is Kitty Number or not.
 
 
 Input
 The first line there is a number T (0 < T < 5000), denoting the test case number.
 The following T lines for each line there is a positive number N (0 < N < 5000) you need to judge.
 
 
 Output
 For each case, output “YES” if the given number is Kitty Number, “NO” if it is not.
 
 
 Sample Input
 2
 3
 7
 Sample Output
 YES
 NO
 */
