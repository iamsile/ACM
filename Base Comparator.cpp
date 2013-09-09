#include <iostream>

int main()
{
	int b,d;
	char a[1001],c[1001];
	while(scanf("%s%d%s%d",a,&b,c,&d)!=EOF)
	{
		int i,base,sum=0,sum1=0,k=strlen(a),k1=strlen(c);
		if(b==1)
			sum+=k-1;
		else 
		{
			base=1;
			for(i=k-1;i>=0;i--)
			{
				sum+=(a[i]-'0')*base;
				base*=b;
			}
		}
		if(d==1)
			sum1+=k1-1;
		else
		{
			base=1;
			for(i=k1-1;i>=0;i--)
			{
				sum1+=(c[i]-'0')*base;
				base*=d;
			}
		}
		if(sum==sum1)
			printf("=\n");
		else if(sum>sum1)
			printf(">\n");
		else 
			printf("<\n");
	}
	return  0;
}
/*
 Problem description
 DigiCircuits Inc. is a software company that develops software simulators for digital circuits. A very frequently used component of its software, named the comparator, is a simulated circuit that compares numbers expressed in different numerical bases. More exactly, this component receives two numbers, each one in a possible different base, and decides if the first number is less than, equal to or greater than the second number.
 
 The numerical bases that may appear vary from 1 to 9. Remember that a number expressed in base b uses only digits less than b.
 Your task is to develop a program that simulates the function of the comparator component.
 
 Input
 The input file contains several test cases, each one of them in a separate line. Each test case has four numerical strings, each two of them separated by a blank character, say
 
 s b t c
 Strings b and c are one-character strings. They represent the bases for the first and third strings s and t, respectively.
 The end of the input is denoted by the end of the input file. 
 
 Output
 Output text for each input case is presented in the same order that input is read. For each test case the answer must be a left aligned answer-character corresponding to the input. This character must be < , = or > , accordingly to the fact that the first string represents a numerical value less than, equal to or greater that the represented by the third string.
 The output must be written to standard output.
 
 Sample Input
 54 6 71 8
 110 2 6 7
 3 4 3 9
 14 7 1000 2
 Sample Output
 <
 =
 =
 >
*/