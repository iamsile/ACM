#include<iostream>
using namespace std;

int main()
{
	int a[50];
	int A,B;
	long n;
	a[0]=a[1]=1;
	while(cin >> A >> B >> n)
	{
		for(int i=2;i<50;i++)
		{
			a[i]=(A*a[i-1]+B*a[i-2])%7;
		}
		if(A==0&&B==0&&n==0)
			break;
		cout <<a[n%48-1] << '\n';
	}
	return 0;
}
/*
 Problem Description
 A number sequence is defined as follows:
 
 f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
 
 Given A, B, and n, you are to calculate the value of f(n).
 
 
 Input
 The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
 
 
 Output
 For each test case, print the value of f(n) on a single line.
 
 
 Sample Input
 1 1 3
 1 2 10
 0 0 0
 
 
 Sample Output
 2
 5
*/