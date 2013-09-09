#include <iostream>
using namespace::std;
unsigned int a[4194304]={1,1,0};

int main()
{
	unsigned int x,y;
	while(cin >> x >> y&&x&&y)
	{
		int num=0;
		for(int i=2;i<=y;i++)
		{
			while(a[i]==1)
				i++;
			for(int j=i+i;j<=y;j+=i)
				a[j]=1;
		}
		for(int i=x;i<=y;i++)
			if(a[i]==0)
				num++;
		cout << num << '\n';	
	}
	return 0;
}
/*
 Problem description
 The "Hacks Memo", usually called HAKMEM, is a collection of interesting mathematical and programming items discovered/written up by people who had been at the famous MIT AI lab. HAKMEM is available at 
 http://www.inwap.com/pdp10/hbaker/hakmem/hakmem.html 
 One little tidbit, from Bill Gosper, is that "algebra is run on a machine (the universe) that is two's-complement", (item 154). Another tidbit is from Gene Salamin, who says that "There are exactly 23,000 primes less than 2^(18)". 
 
 You are to write a program to count how many primes are in a given range. 
 
 Input
 Each line of input will consist of two integers, a and b, both > 0, with a < b. They will be separated by a space. b will not exceed 4194304 (2^22). 
 
 Output
 A single integer saying how many prime numbers are between a and b, inclusive. 
 
 Sample Input
 2 10 
 10 20
 2 262144
 Sample Output
 4
 4
 23000
 */