#include <iostream>
using namespace::std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		char *a=new char[1001];
		scanf("%d %s",&n,a);
		if(next_permutation(a, a+strlen(a)))
			cout << n << ' ' <<  a << '\n';
		else 
			cout << n << ' ' << "BIGGEST\n";
		delete a;//这个可有可无
	}
	return 0;
}
/*
 Problem description
 For this problem, you will write a program that takes a (possibly long) string of decimal digits, and outputs the permutation of those decimal digits that has the next larger value (as a decimal number)
 than the input number. For example:
 123 -> 132
 279134399742 -> 279134423799
 It is possible that no permutation of the input digits has a larger value. For example, 987. 
 
 Input
 The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by up to 80 decimal digits which is the input value.
 
 
 Output
 For each data set there is one line of output. If there is no larger permutation of the input digits, the output should be the data set number followed by a single space, followed by the string BIGGEST. Ifthere is a solution, the output should be the data set number, a single space and the next larger
 permutation of the input digits.
 
 
 Sample Input
 3
 1 123
 2 279134399742
 3 987
 Sample Output
 1 132
 2 279134423799
 3 BIGGEST
*/