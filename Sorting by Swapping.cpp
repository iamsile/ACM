#include <iostream>
using namespace::std;

int main()
{
	int m,n,i,lab,a[10000]={0},b[10000]={0};
	cin >> m;
	while(m--)
	{
		cin >> n;
		for(i=1;i<=n;i++)
		{
			cin >> a[i];
			b[a[i]]=i;
		}
		lab=0;
		for(i=1;i<=n;i++)
		{
			if(b[i]!=i)
			{
				lab++;
				a[b[i]]=a[i];
				b[a[i]]=b[i];
			}
		}
		cout << lab << '\n';
	}
	return 0;
}
/*
 #include <iostream>
 using namespace::std;
 
 int main()
 {
	int m;
	cin >> m;
	while(m--)
	{
		int n,i,sum=0,flag=0,a[10001]={0};
		cin >> n;
		for(i=1;i<=n;i++)
			cin >> a[i];
		for(i=1;i<=n;i++)
		{
			if(i!=a[i])
			{
				swap(a[i], a[a[i]]);
				sum++;
				flag=1;
			}
			if(flag&&i>n/2)
			{
				i=1;
				flag=0;
			}
		}
		cout << sum << '\n';
		}
	return 0;//这个更短
 }*/
/*
 思路就是首先找出数字1然后将它换到第1位，
 然后找数字2...为了能更快的找到数字的位置，
 另开了一个数组保存每个数字所在的位置，
 在交换的过程中同时更新两个数组
*/
/*
 Problem description
 Given a permutation of numbers from 1 to n, we can always get the sequence 1, 2, 3, ..., n by swapping pairs of numbers. For example, if the initial sequence is 2, 3, 5, 4, 1, we can sort them in the following way: 
 
 2 3 5 4 1 
 1 3 5 4 2 
 1 3 2 4 5 
 1 2 3 4 5 
 
 Here three swaps have been used. The problem is, given a specific permutation, how many swaps we needs to take at least. 
 
 Input
 The first line contains a single integer t (1 <= t <= 20) that indicates the number of test cases. Then follow the t cases. Each case contains two lines. The first line contains the integer n (1 <= n <= 10000), and the second line gives the initial permutation.
 
 Output
 For each test case, the output will be only one integer, which is the least number of swaps needed to get the sequence 1, 2, 3, ..., n from the initial permutation. 
 
 Sample Input
 2
 3
 1 2 3
 5
 2 3 5 4 1
 Sample Output
 0
 3
 */