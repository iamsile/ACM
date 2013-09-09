#include <iostream>
using namespace::std;

int solve(char a[])
{
	int i=0,f1=0,f2=0,len=strlen(a);
	if(a[i]=='+'||a[i]=='-')
		i++;
	while(a[i]>='0'&&a[i]<='9')
	{
		f1=1;
		i++;
	}
	if(a[i]=='.')
	{
		if(i==0&&a[i+1]=='\0') 
			return 0;
    	i++;    
    }
	while(a[i]>='0'&&a[i]<='9')
	{
		f1=1;
		i++;
	}
	if(f1&&(a[i]=='e'||a[i]=='E'))
	{
		i++;
		if(a[i]=='+'||a[i]=='-')
			i++;
		while(a[i]>='0'&&a[i]<='9')
		{
			f2=1;
			i++;
		}
		if(!f2) 
			return 0;
	}
	if(i<len)
		return 0;
	return 1;
}

int main()
{
	int t;
	char a[1005];	
	cin >> t;
	while (t --)
	{
		cin >> a;
		printf("%s\n",solve(a)?"YES":"NO");	
	}
	return 0;
}
/*
Problem description
In scientific notation, real numbers are written like this:
a×10 b
Here we call a the coefficient and b the exponent. But the representation of real numbers in programming language has a little different; we use the character e or E to indicate the start of the exponent. For example, 2×103 in the programming language is written as 2e3. And the exponent part of the real number is not all necessary so that the numbers as "6", "6.5" without an exponent are also valid real number.
Real numbers may have a decimal point in the coefficient (and must have numbers on at least one side of the decimal point, e.g. "0.1", ".1", "1.0", "1. ", are all valid real numbers, but "." is not.). 
The exponent of the real number is an integer and starts with the character e or E. Before the character e or E, there must have a valid coefficient.
There may be a plus or minus sign in front of the coefficient or exponent, or both (without any blank characters after the sign). e.g. "- 0.1", "1.1e-1" are valid but "-.", "1.1e-", "1.e 3" are not.
Note that there is no bound on the range of the numbers in the input, but for the sake of simplicity, you may assume the input strings are not longer than 1000 characters. There are no blanks in the input data.


Input
The first line of the input contains a single integer T which is the number of test cases, followed by T lines each containing the input line for a test case.


Output
The output contains T lines, each having a string which is “YES” or “NO”.


Sample Input
4
1.5e+2
3.
2.e
-.35

Sample Output
YES
YES
NO
YES
*/