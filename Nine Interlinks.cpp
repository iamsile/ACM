#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t,i,n,a[40]={0};
	a[1]=1;a[2]=2;
	for(i=3;i<=30;i++)
		a[i]=a[i-1]+2*a[i-2]+1;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
/*
 "What are you doing now?"
 
 "Playing Nine Interlinks!"
 
 "What is that?"
 
 "Oh it is an ancient game played over China. The task is to get the nine rings off the stick according to some rules. Now, I have got them off, would you like to have a try to get them on?"
 
 Input
 
 The first line of the input contains an integer T (T <= 30), indicating the number of cases.
 
 Each case consists of a simple integer n (1 < n < 30), which is the number of the total rings you need to get on the stick.
 
 At the beginning, all rings are off the stick.
 
 In each step, you can only get one ring on or off by the following rules:
 
 1. You can get the first ring on or off freely at each step.
 
 2. If the ith ring is on the stick, and the 1st, 2nd... (i-1)st rings are off the stick, you can get the (i+1)st ring on or off freely at each step.
 
 Output
 
 For each case, print in a single line the minimum number of steps you need to get n rings on the stick.
 
 Sample Input
 
 2
 2
 3
 Sample Output
 
 2
 5
 Hint
 The first sample: 1 on, 2 on.
 The second sample: 1 on, 2 on, 1 off, 3 on, 1 on.
*/