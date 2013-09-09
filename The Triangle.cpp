#include <iostream>
using namespace::std;

int main()
{
	int m,n,i,j,a[100][100]={0};
	cin >> m;
	cout << '\n';
	while(m--)
	{
		cin >> n;
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				cin >> a[i][j];
		for(i=n-1;i>=0;i--)
			for(j=0;j<=i;j++)
			{	
				if(a[i+1][j]>a[i+1][j+1])
					a[i][j]=a[i][j]+a[i+1][j];
				else 
					a[i][j]=a[i][j]+a[i+1][j+1];
			}
		cout << a[0][0] << '\n';
	}
	return 0;
}
/*
 Problem description
 7
 
 3   8
 
 8   1   0
 
 2   7   4   4
 
 4   5   2   6   5
 
 
 
 (Figure 1)
 
 Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right.
 
 
 Input
 Your program is to read from standard input. The first line contains one integer T, the number of test cases, for each test case: the first line contain a integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99. 
 
 Output
 Your program is to write to standard output. The highest sum is written as an integer for each test case one line.
 
 Sample Input
 1
 
 5
 7
 3 8
 8 1 0 
 2 7 4 4
 4 5 2 6 5
 Sample Output
 30
*/