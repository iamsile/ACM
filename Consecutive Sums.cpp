#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
	int n,m,i,j,x,y,sum,lab;
	cin >> m;
	while(m--)
	{
		cin >> n;
		lab=0;
		for(i=sqrt(n*2);i>=2;i--)
		{
			if((n*2)%i==0)
			{
				sum=0;
				x=(n*2/i-i+1)/2;
				y=(n*2/i+i-1)/2;
				for(j=x;j<=y;j++)
					sum+=j;
				if(sum!=n)
					continue;
				for(j=x;j<=y;j++)
				{
					if(j>x)
						cout << ' ';
					cout << j;
					lab++;
				}
				cout << '\n';
			}
		}
		if(i==1&&lab==0)
		{
			cout << "NONE\n";
			continue;
		}
	}
	return 0;
}
/*
 解题思路：
 (x+y)*(y-x+1)=n*2;假如分解出的结果是n*2=a*b;即x=(a-b+1)/2;y=(a+b-1)/2;
*/
/*
 Problem description
 A positive integer can be obtained by adding n (n>=2) consecutive positive integers, take 15 as an example, 15 can be decomposed to 1+2+3+4+5 or 4+5+6 or 7+8 and 10 can only be decomposed to 1+2+3+4 . As an excellent programmer in Hunan University, you are request to write a program that will compute all possible cases and output them all. 
 
 Input
 The input contains several test cases. The first line is the test case number N. For each test case, there is only one positive integer M(M<=65535) in a single line. 
 
 Output
 For each test case, you should output all possible answers containing the numbers that add up to M. You should output them in the order like this: if one answer has more numbers the other, it should be first output. So for the input 15, you should output 1 2 3 4 5 4 5 6 7 8 If there is no answer, just output NONE in a line. 
 
 Sample Input
 3
 15
 10
 16
 Sample Output
 1 2 3 4 5
 4 5 6
 7 8
 1 2 3 4
 NONE
*/