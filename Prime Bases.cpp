#include<iostream>
using namespace::std;

int main()
{
	int a[10]={1,2,6,30,210,2310,30030,510510,9699690,223092870},n;
	char b[10][25]={"1","2","2*3","2*3*5","2*3*5*7","2*3*5*7*11","2*3*5*7*11*13",
        "2*3*5*7*11*13*17","2*3*5*7*11*13*17*19","2*3*5*7*11*13*17*19*23"};
	while(cin >> n&&n)
	{
		printf("%d = ",n);
		int i=9,num=0,d[15]={0};
		while(n)
		{
			while(a[i]>n) 
				i--;
			d[i]=n/a[i];
			n%=a[i];
			num++;
		} 
		for(i=0;i<15;i++)
			if(d[i])
			{
				if(i==0) 
					cout << "1";
				else 
					printf("%d*%s",d[i],b[i]);
				if(num!=1) 
					cout << " + ";
				num--;
			}
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 Given any integer base b ≥ 2, it is well known that every positive integer n can be uniquely represented in base b. That is, we can write 
 n = a0 + a1*b + a2*b*b + a3*b*b*b + ... 
 
 where the coefficients a0, a1, a2, a3, ... are between 0 and b-1 (inclusive).
 What is less well known is that if p0, p1, p2, ... are the first primes (starting from 2, 3, 5, ...), every positive integer n can be represented uniquely in the "mixed" bases as:
 n = a0 + a1*p0 + a2*p0*p1 + a3*p0*p1*p2 + ...
 where each coefficient ai is between 0 and pi-1 (inclusive). Notice that, for example, a3 is between 0 and p3-1, even though p3 may not be needed explicitly to represent the integer n.
 Given a positive integer n, you are asked to write n in the representation above. Do not use more primes than it is needed to represent n, and omit all terms in which the coefficient is 0. 
 
 Input
 Each line of input consists of a single positive 32-bit signed integer. The end of input is indicated by a line containing the integer 0.
 
 Output
 For each integer, print the integer, followed by a space, an equal sign, and a space, followed by the mixed base representation of the integer in the format shown below. The terms should be separated by a space, a plus sign, and a space. The output for each integer should appear on its own line.
 
 Sample Input
 123
 456
 123456
 0
 Sample Output
 123 = 1 + 1*2 + 4*2*3*5
 456 = 1*2*3 + 1*2*3*5 + 2*2*3*5*7
 123456 = 1*2*3 + 6*2*3*5 + 4*2*3*5*7 + 1*2*3*5*7*11 + 4*2*3*5*7*11*13
*/