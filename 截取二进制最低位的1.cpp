#include <iostream>
using namespace::std;

int main()
{
	int m,r;
	while(cin >>m&&m)
	{
		r=1;
		while(m){
			r=1;
			if((m&1)==1) break;
			m>>=1;
			r<<=1;
		}
		cout << r << '\n';
	}
	return 0;
}
/*
 given an positive integer A(1<=A<=100000000),
 output the lowest bit of A.for example,given
 A=26,we can write A in binary form as 11010,so
 the lowest bit of A is 10,so the output should be
 2.Another example goes like this:given A=88,we can
 write A in binary form as 1011000,so the lowest
 bit of A is 1000,so the output should be 8.
*/
