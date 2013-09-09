#include <iostream>
#include <iomanip>
using namespace::std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		double a;
		cin >> a;
		double d=a*3.14159265358/180.0;
		printf("%.3f\n",d);
	}
	return 0;
}
/*
 Problem description
 Jack is a beginner at C programming. One day he met a problem in programming, he used the function sin() and found that the result was not the one he expected. for example, he used sin(30), and expected the result to be 0.5, but that was't true. Can you help him to find the mistake?
 
 Input
 The first line contains one integer T, the following T lines each contains only one integer, which is the degree of the angle in the function sin().
 
 Output
 There are T lines in the output. which is the right value that should be written in the function sin().
 (The results should be with precision of three decimal places in each line.)
 
 Sample Input
 3
 0
 180
 90
 Sample Output
 0.000
 3.142
 1.571
 Judge Tips
 注意PI的精度
*/