#include<iostream>
using namespace std;
long long sum;
int a[500010],b[500010];

void mergesort(int l,int r)
{
	int mid,i,j,ans;
	if(r<=l+1)
		return;
	mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid,r);
	ans=l;
	for(i=l,j=mid;i<mid&&j<r;) {
		if(a[i]>a[j]) {
			b[ans++]=a[j++];
			sum+=mid-i;
		}
		else
			b[ans++]=a[i++];
	}
	if(j<r)
		while(j<r)
			b[ans++]=a[j++];
	else
		while(i<mid)
			b[ans++]=a[i++];
	for(i=l;i<r;i++)
		a[i]=b[i];
	return;
}
int main()
{
	int i,n;
	while(scanf("%d",&n)&&n)
	{
		sum=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(0,n);
		cout << sum << '\n';
	}
	return 0;
}
/*
 Problem description
 In this problem, you have to analyze the a Bubble-Sorting algorithm. The algorithm processes a sequence of n distinct integers by swapping two adjacent sequence elements until the sequence is sorted in ascending order. For the input sequence 5 4 2 9 1 , Bubble-Sorting produces the output 1 2 4 5 9. Your task is to determine how many swap operations Bubble-Sorting needs to perform in order to sort a given input sequence. 
 
 Input
 The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. followed by n integers, a[n], 0 ≤ a[i] ≤ 10^9, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.
 
 Output
 For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.
 
 Sample Input
 3
 1 2 3
 5
 9 1 0 5 4
 20
 20 2 1 18 12 13 9 8 11 10 19 17 6 14 15 16 7 5 4 3 
 0
 Sample Output
 0
 6
 113
*/