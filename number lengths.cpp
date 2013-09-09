#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	double sum,i;
	int n;
	while(cin >> n)
	{
		sum=0;
		for(i=1;i<=n;i++)
			sum+=log10(i);
		cout << (int)sum+1 << '\n';
	}
	return 0;
}
/*Problem description
 N! (N factorial) can be quite irritating and difficult to compute for large values of N. So instead of calculating N!, I want to know how many digits are in it. (Remember that N! = N * (N - 1) * (N - 2) * ... * 2 * 1) 
 
 Input
 Each line of the input will have a single integer N on it 0 < N < 1000000 (1 million). Input is terminated by end of file. 
 
 Output
 For each value of N, print out how many digits are in N!. 
 
 Sample Input
 1
 3
 32000
 1000000
 Sample Output
 1 
 1
 130271
 5565709
 */