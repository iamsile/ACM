#include <iostream>
using namespace::std;

int main()
{
	char a[101]={0};
	while(gets(a)!=NULL)
	{
		int i,j=0,sum=0,flag=0,k=strlen(a);
		for(i=0;i<k;i++)
		{
			if(a[i]=='A')
			{
				sum+=4;
				j++;
			}
			else if(a[i]=='B')
			{
				sum+=3;
				j++;
			}
			else if(a[i]=='C')
			{
				sum+=2;
				j++;
			}
			else if(a[i]=='D')
			{
				sum+=1;
				j++;
			}	
			else if(a[i]=='F')
				j++;
			else if(a[i]=='E'||a[i]>'F'&&a[i]<='Z')
				flag=1;
		}
		if(flag)
			cout << "Unknown letter grade in input\n";
		else 
			printf("%.2f\n",(double)sum/j);
		memset(a, 0, sizeof(a));
	}
	return 0;
}
/*
 Problem description
 Each course grade is one of the following five letters: A, B, C, D, and F. (Note that there is no grade E.) The grade A indicates superior achievement, whereas F stands for failure. In order to calculate the GPA, the letter grades A, B, C, D, and F are assigned the following grade points, respectively: 4, 3, 2, 1, and 0. 
 
 Input
 The input file will contain data for one or more test cases, one test case per line. On each line there will be one or more upper case letters, separated by blank spaces.
 
 Output
 Each line of input will result in exactly one line of output. If all upper case letters on a particular line of input came from the set {A, B, C, D, F} then the output will consist of the GPA, displayed with a precision of two decimal places. Otherwise, the message "Unknown letter grade in input" will be printed. 
 
 Sample Input
 A B C D F
 B F F C C A
 D C E F
 
 Sample Output
 2.00
 1.83
 Unknown letter grade in input
*/