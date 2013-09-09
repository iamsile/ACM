#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	unsigned int m;
	cin >> m;
	for(unsigned int i=0;i<m;i++)
	{
		unsigned int n,h;
		cin >> n;
		h=(int)sqrt(2*(n-1))+1;
		if((h*(h-1)/2+1)==n)
		{
			if(i+1==m)
				cout << "1";
		    else
				cout << "1 ";
		}
		else 
		{
			if(i+1==m)
				cout << "0";
			else 
				cout << "0 ";
		}
	}
	return 0;
}
/*
 Problem description
 Let's consider an infinite sequence of digits constructed of ascending powers of 10 written one after another. Here is the beginning of the sequence: 110100100010000... You are to find out what digit is located at the definite position of the sequence.
 
 Input
 There is the only positive integer number N in the first line, N < 65536. The i-th of N left lines contains the positive integer Ki - the number of position in the sequence. It's given that Ki < 231..
 
 Output
 You are to output N digits 0 or 1 separated with a space. More precisely, the i-th digit of output is to be equal to the Ki-th digit of described above sequence.
 
 Sample Input
 4
 3
 14
 7
 6
 Sample Output
 0 0 1 0
*/