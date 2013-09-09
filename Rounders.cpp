#include <iostream>
using namespace::std;

int main()
{
	int m,i;
	cin >> m;
	while(m--)
	{
		unsigned int n,lab=0;
		cin >> n;
		while(n>10)
		{
			if(n%10>=5)
			{
				n/=10;
				n+=1;
				lab++;
			}
			else 
			{
				n/=10;
				lab++;
			}
		}
		cout << n;
		for(i=0;i<lab;i++)
			cout << '0';
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 For a given number, if greater than ten, round it to the nearest ten, then (if that result is greater than 100) take the result and round it to the nearest hundred, then (if that result is greater than 1000) take that number and round it to the nearest thousand, and so on ... 
 
 Input
 Input to this problem will begin with a line containing a single integer n indicating the number of integers to round. The next n lines each contain a single integer x (0 <= x <= 99999999).
 
 Output
 For each integer in the input, display the rounded integer on its own line. 
 
 Note: Round up on fives. 
 
 Sample Input
 9
 15
 14
 4
 5
 99
 12345678
 44444445
 1445
 446
 Sample Output
 20
 10
 4
 5
 100
 10000000
 50000000
 2000
 500
*/