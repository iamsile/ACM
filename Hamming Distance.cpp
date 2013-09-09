#include <stdio.h>

int main()
{
	__int64 unsigned x,y;
	while(scanf("%I64u%I64u",&x,&y)&&x&&y)
	{
		x=x^y;
		__int64 unsigned num=0;
		while(x>0)
		{
			if(x%2==0)
				x>>=1;
			else
			{
				num++;
				x>>=1;
			}
		}
		printf("%I64u\n",num);
	}
	return 0;
}
/*
 Problem description
 Given a positive integer A,we can write A in binary form,and the binary form of A is called code word of A. The Hamming Distance between two code words i and j is the number of components at which the two code words differ, and is denoted by h(i,j).
 
 Example: i=98 and j=70
 i: 01100010(code word)
 j: 01000110(code word)
 
 It is clear to see that these two words differ at the 3rd and 6th positions. We can then say that they have a Hamming Distance of 2.
 Your task is to calculate Hamming distance of two given integers.
 
 Input
 The input contains multiple test cases,one per line.
 Each line of input contains two integers i and j (0< i , j <264). A line containing "0 0" indicates the end of input, and must not be processed. 
 
 
 Output
 For each test case, output a line containing Hamming distance h(i,j).
 
 Sample Input
 98 70
 100 100
 0 0
 Sample Output
 2
 0
*/