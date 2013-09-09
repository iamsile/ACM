#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int n,i,a[3000]={0},b[3000]={0};
	while (cin >> n&&n) {
		for(i=0;i<n;++i)
		{
			cin >> a[i];
			b[i]=abs(a[i]-a[i-1]);
		}
		sort(b+1,b+n);
		i=1;
		for(j=1;j<n;++j)
			if(j!=b[i++])
			{
				j=0;
				break;
			}
		if(j==0)
			cout << "Not jolly" << '\n';
		else 	
			cout << "Jolly" << '\n';
		
	}
	return 0;
}
/*
 Problem description
 A sequence of n > 0 integers is called a jolly jumper if the absolute values of the difference between successive elements take on all the values 1 through n-1. For instance, 
 
 1 4 2 3 
 
 is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether or not each of a number of sequences is a jolly jumper. 
 
 Input
 Each line of input contains an integer n < 3000 followed by n integers representing the sequence.
 
 Output
 For each line of input, generate a line of output saying "Jolly" or "Not jolly". 
 
 Sample Input
 4 1 4 2 3
 5 1 4 2 -1 6
 Sample Output
 Jolly
 Not jolly
*/