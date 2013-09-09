#include <iostream>
using namespace::std;

int main()
{
	int n,i;
	long int sum;
	while(cin >> n&&n)
	{
		sum=1;
		for(i=2;i<=n;i++)
		{
			sum*=i;
			while(sum%10==0)
				sum/=10;
			sum%=10000;//对10000取余是下限了，保证数的末尾不会被冲掉
		}
		cout << sum%10 << '\n';
	}
	return 0;
}
/*
 Problem description
 The factorial of an integer N, written N!, is the product of all the integers from 1 through N inclusive. The factorial quickly becomes very large: 13! is too large to store in a 32-bit integer on most computers, and 70! is too large for most floating-point variables. Your task is to find the rightmost non-zero digit of n!. For example, 5! = 1 * 2 * 3 * 4 * 5 = 120, so the rightmost non-zero digit of 5! is 2. Likewise, 7! = 1 * 2 * 3 * 4 * 5 * 6 * 7 = 5040, so the rightmost non-zero digit of 7! is 4.
 
 Input
 There are multiple test cases. Each contains A single positive integer N no larger than 10,000 in a single line.
 
 Input ends with a zero and this line should not be processed.
 
 Output
 A single line containing but a single digit: the right most non-zero digit of N! .
 
 Sample Input
 7
 0
 Sample Output
 4
*/