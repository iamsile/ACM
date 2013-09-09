#include <iostream>
using namespace::std;

int main()
{
	float n;
	while (cin >> n && n) {
		printf("%.2f\n",(float)(n*n/2/3.1415926));
	}
	return 0;
}
/*
 Problem description
 There is a wall in your backyard. It is so long that you can’t see its endpoints. You want to build a fence of length L such that the area enclosed between the wall and the fence is maximized. The fence can be of arbitrary shape, but only its two endpoints may touch the wall. 
 
 Input
 The input consists of several test cases. For every test case, there is only one integer L (1 ≤ L ≤ 100), indicating the length of the fence. The input ends with L=0.
 
 Output
 For each test case, output one line containing the largest area. Your answer should be rounded to 2 digits after the decimal point.
 
 Sample Input
 1
 100
 0
 Sample Output
 0.16
 1591.55
*/