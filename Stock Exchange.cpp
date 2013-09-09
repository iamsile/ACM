#include<iostream>
using namespace::std;

int main() 
{
	long n,i,len,L,M,H,a[100000];
	while(cin >> n&&n!=-1)
	{
		len=0;
		for(i=1;i<=n;i++) 
			cin >> a[i];
		a[0]=-1; 
		len++; 
		for(i=2;i<=n;i++) 
		{
			L=0;H=len;
			while(L<=H) 
			{
				M=(L+H)/2; 
				if(a[i]>a[M]) 
					L=M+1; 
				else 
					H=M-1; 
			} 
			a[L]=a[i]; 
			if(L>len) 
				len++; 
		} 
		ct << len << '\n';
	}
 return 0; 
} 
//主要的思想还是动态规划，但是中间插入了二分查找
/*
 Problem description
 The world financial crisis is quite a subject. Some people are more relaxed while others are quite anxious. John is one of them. He is very concerned about the evolution of the stock exchange. He follows stock prices every day looking for rising trends. Given a sequence of numbers p1, p2,...,pn representing stock prices, a rising trend is a subsequence pi1 < pi2 < · · · < pik, with i1 < i2 < · · · < ik. John’s problem is to find very quickly the longest rising trend.
 
 Input
 The program input is from a text file. Each data set in the file stands for a particular set of stock prices. A data set starts with the length L (L ≤ 100000) of the sequence of numbers, followed by the numbers (a number fits a long integer). The program prints the length of the longest rising trend.
 White spaces can occur freely in the input. The input data are correct and terminate with an end of file.
 
 Output
 For each set of data the program prints the result to the standard output from the beginning of a line. An input/output sample is in the table bellow. There are three data sets. In the first case, the length L of the sequence is 6. The sequence is 5, 2, 1, 4, 5, 3. The result for the data set is the length of the longest rising trend: 3.
 
 Sample Input
 6
 5 2 1 4 5 3
 3
 1 1 1
 4
 4 3 2 1
 Sample Output
 3
 1
 1
 */
