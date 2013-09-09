#include <stdio.h>
using namespace::std;

int main()
{
	__int64 a,b;
	while(scanf("%I64d%I64d",&a,&b)!=EOF)
	{
		printf("%I64d\n",2*a*b);
	}
	return 0;
}
/*
 Problem description
 There is a inscribed rectangle in the ellipse(x*x/a*a+y*y/b*b=1)。The edges of inscribed rectangle and axes of ellipse are parallel.Please calculate the maximal area of the inscribed rectangle.
 
 Input
 The input consists of several test cases.Each line contains two positive integers: a, b.
 
 Output
 The output should be one integer per line, which means the maximal area of the inscribed rectangle.
 
 Sample Input
 5 6
 100 200
 Sample Output
 60
 40000
*/