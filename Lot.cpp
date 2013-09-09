#include <iostream>
using namespace::std;
long cal(long n)
{
	long sum;
	if(n==1||n==2||n==4)
		sum=0;
	else if(n==3)
		sum=1;
	else if(n%2==0)
		sum=2*cal(n/2);
	else 
		sum=cal(n/2)+cal(n-n/2);
	return sum;
}
int main()
{
	long n;
	while(cin >> n&&n)
	{
		cout << cal(n) << '\n';
	}
	return 0;
}
/*
 Problem description
 Out of N soldiers, standing in one line, it is required to choose several to send them scouting. In order to do that, the following operation is performed several times: if the line consists of more than three soldiers, then all soldiers, standing on even positions, or all soldiers, standing on odd positions, are taken away. The above is done until three or less soldiers are left in the line. They are sent scouting. Find, how many different groups of three scouts may be created this way.
 
 Note: Groups with less than three number of soldiers are not taken into consideration.
 
 0 < N <= 10 000 000
 
 
 Input
 The input file contains the number N.
 
 Process to the end of file.
 
 
 Output
 The output file must contain the solution - the amount of variants.
 
 
 Sample Input
 10
 4
 Sample Output
 2
 0
*/