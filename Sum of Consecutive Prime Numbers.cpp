#include <iostream>
using namespace std;
int a[20009] = {0};

void prime()
{
	int i,k;
	for(i=2;i<=10000;i++)
		if(a[i]==0)
			for(k=2;k*i<=10000;k++)
			{
				a[k*i]=1;
				if (k*i>10000)
					break;
			}
}

int search(int num)
{
	int i,k,counter=0,sum;
	for(k=2;k<=num;k++)
	{
		sum=0;
		for(i=k;i<=num;i++)
		{
			if(a[i]==0)
				sum=sum+i;
			if(sum==num)
			{
				counter++;
				break;
			}
			if(sum>num)
				break;
		}
		for(i=k+1;i<=num;i++)
			if(a[i]==0)
			{
				k=i-1;
				break;
			}
	}
	return counter;
}

int main()
{
	prime();
	int n;
	while(cin>>n&&n)
	{
		cout << search(n) <<endl;
	}
	return 0;
}
/*
 Problem description
 Some positive integers can be represented by a sum of one or more consecutive prime numbers. How many such representations does a given positive integer have? For example, the integer 53 has two representations 5 + 7 + 11 + 13 + 17 and 53. The integer 41 has three representations 2+3+5+7+11+13, 11+13+17, and 41. The integer 3 has only one representation, which is 3. The integer 20 has no such representations. Note that summands must be consecutive prime 
 numbers, so neither 7 + 13 nor 3 + 5 + 5 + 7 is a valid representation for the integer 20. 
 Your mission is to write a program that reports the number of representations for the given positive integer.
 
 Input
 The input is a sequence of positive integers each in a separate line. The integers are between 2 and 10 000, inclusive. The end of the input is indicated by a zero.
 
 Output
 The output should be composed of lines each corresponding to an input line except the last zero. An output line includes the number of representations for the input integer as the sum of one or more consecutive prime numbers. No other characters should be inserted in the output.
 
 Sample Input
 2
 3
 17
 41
 20
 666
 12
 53
 0
 Sample Output
 1
 1
 2
 3
 0
 0
 1
 2
*/