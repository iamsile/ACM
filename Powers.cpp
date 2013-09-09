#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	long int n,m;
	while (cin >> n >> m) {
		double l,num;
		double k,a;
		if (n==0&&m==0) {
			return 0;
		}
		k=m*log10(n);
		l=(int)k;
		a=k-l;
		num=(int)pow(10, a);
		cout << num << '\n';
		
	}
	return 0;
}
/*
 Compute the first digit of BN, given 1 ≤B < 10, 1 ≤ N ≤1000000. 
 
 Input
 The input consists of multiple data set. Each data set is a line containing two integers, B and N, separated by a single space. The data set are followed by a line `0 0'. There will be no more than 10 data set of input. 
 
 Output
 You must output one line for each line of input (other than the terminating line). The line consist of a single digit, which is the leading digit of BN for the corresponding line of input. 
 
 Sample Input
 1 1
 2 4
 7 8
 9 13
 0 0
 
 Sample Output
 1
 1
 5
 2
*/