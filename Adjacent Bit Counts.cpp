#include<iostream>
using namespace std;

int a[105][105][3];
int main()
{
	memset(a,0,sizeof(a));
	a[1][0][0]=1;a[1][0][1]=1;
	int i,j;
	for(i=2;i<=101;i++)
	{ 
		for(j=0;j<i-1;j++)
		{
			a[i][j][0]=a[i-1][j][1]+a[i-1][j][0];
			a[i][j][1]=a[i-1][j][0]+a[i-1][j-1][1];               
		}
		a[i][j][1]=1;                   
	}
	int t;
	cin >> t;
	while(t--)
	{
		int lab,m,n,k;
		cin >> lab >> m >> n; 
		k=a[m][n][0]+a[m][n][1];
		cout << lab << " " << k <<'\n';                                        
	}                 	
	return 0;              
}
/*
 a[i][j][0]=a[i-1][j][1]+a[i-1][j][0];
 也就是说，当有i 位 得值为j最后一位为 0时，相当于，
 在 “共有i-1 位得数为j 的最后一位为1 的后面再加一个 0 和
 “最后一位为0的后面加一个0得到的”，” 
 a[i][j][1]=a[i-1][j][0]+a[i-1][j-1][1];
 思路一样；   
 a[1][0][0]=1;a[1][0][1]=1;这是特殊情况，要提出 ；
*/
/*
 Problem description
 For a string of n bits x1, x2, x3, …, xn, the adjacent bit count of the string (AdjBC(x)) is given by
 
 x1*x2 + x2*x3 + x3*x4 + … + xn-1*xn
 
 which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
 
 AdjBC(011101101) = 3
 AdjBC(111101101) = 4
 AdjBC(010101010) = 0
 
 Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2n) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting
 AdjBC(x) = 2:
 
 11100, 01110, 00111, 10111, 11101, 11011 
 
 Input
 The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100 and the parameters n and k will be chosen so that the result will fit in a signed 32-bit integer. 
 
 Output
 For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of n-bit strings with adjacent bit count equal to k. 
 
 Sample Input
 10
 1 5 2
 2 20 8
 3 30 17
 4 40 24
 5 50 37
 6 60 52
 7 70 59
 8 80 73
 9 90 84
 10 100 90
 Sample Output
 1 6
 2 63426
 3 1861225
 4 168212501
 5 44874764
 6 160916
 7 22937308
 8 99167
 9 15476
 10 23076518
*/