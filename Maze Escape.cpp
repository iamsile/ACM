#include <iostream>
using namespace::std;

int main()
{
	int n,m;
	while (cin >> n >> m) {
		int i,num,sum=0;
		if (n==0&&m==0) 
			return 0;
		for (i=1; i<=n; i++) {
			cin >> num;
			sum+=num;
			if (i==m)
				sum+=num;
		}
		printf("%.2f\n",(float)sum/2);
	}
}
/*
 Problem description
 John is a very crazy and clever boy, one of his very crazy game is maze. Finally one day, he is stranded in a complex maze which contains a large number of channels. We assume that the place of John currently stays is spot START, in front of John there are N channels, but just one of them can lead to exit, and others are circularity, and it will lead back to the spot START in a certain minutes. But John is a very clever boy, he never repeats the same channel, every time he will randomly select one channel from which he has never chosen, until he gets away.
 
 We assume, John accomplished the 1st channel with T1 minutes, accomplished the 2nd channel with T2 minutes, …... , accomplished the Nth channel with TN minutes, and the Mth channel leads to exit. Now can you tell me how many minutes will be consumed in average that John needs to get away? In other words, you will calculate the value of time expectation E(T) that John needs to get away? 
 
 Input
 The input test file consists of several test cases. Each case of the input contains two lines, the first line contains two integer numbers N, M (1 <= N <= 50, 1 <= M <=N), the second line contains N integer numbers, T1, T2, …… , TN (0 <= Ti < 100). The end-of-file is denoted by a single line containing both 0, which should not be processed.
 
 Output
 For each test case, print one line containing the value of time expectation E(T), round to two decimal places.
 
 Sample Input
 1 1
 26
 2 2
 7 5
 3 1
 5 0 0
 7 5
 45 26 35 21 1 35 68
 0 0
 Sample Output
 26.00
 8.50
 5.00
 116.00
*/