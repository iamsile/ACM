#include <iostream>
#include <math.h>
using namespace::std;

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
		unsigned int n,i,j,k,x,y,sum,lab;
        cin >> k >> n;
        lab=0;
        for(i=sqrt(n*2);i>=2;i--)
		{
			if(n*2%i==0)
			{
				sum=0;
				x=(n*2/i-i+1)/2;
				y=(n*2/i+i-1)/2;
				for(j=x;j<=y;j++)
					sum+=j;
				if(sum==n)
					lab++;
			}
		}
		cout << k << ' ' << lab << '\n';
    }
    return 0;
}
/*解题思路：
(x+y)*(y-x+1)=n*2;假如分解出的结果是n*2=a*b;即x=(a-b+1)/2;y=(a+b-1)/2;*/
/*
 
 Problem description
 Most positive integers may be written as a sum of a sequence of at least two consecutive positive integers. For instance, 
 6 = 1 + 2 + 3
 9 = 5 + 4 = 2 + 3 + 4
 but 8 cannot be so written. Write a program which will compute how many different ways an input number may be written as a sum of a sequence of at least two consecutive positive integers. 
 
 Input
 The first line of input will contain the number of problem instances N on a line by itself, (1 ≤ N ≤ 1000). This will be followed by N lines, one for each problem instance. Each problem line will have the problem number, a single space and the number to be written as a sequence of consecutive positive integers. The second number will be less than 231 (so will fit in a 32-bit integer). 
 
 Output
 The output for each problem instance will be a single line containing the problem number, a single space and the number of ways the input number can be written as a sequence of consecutive positive integers. 
 
 Sample Input
 7
 1 6
 2 9
 3 8
 4 1800
 5 987654321
 6 987654323
 7 987654325
 
 Sample Output
 1 1
 2 2
 3 0
 4 8
 5 17
 6 1
 7 23
*/