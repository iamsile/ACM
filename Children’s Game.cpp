#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
char nums[55][100];
int cmp(const void *e1,const void *e2)
{
	char *p1=((char *)e1);
	char *p2=((char *)e2);
	char b1[200],b2[200];
	strcpy(b1,p1);
	strcat(b1,p2);
	strcpy(b2,p2);
	strcat(b2,p1);
	if(strcmp(b1,b2)<=0)
        return 1;
    else
        return -1;
}
int main()
{
	int n,i;
	while(cin >> n&&n)
	{
		memset(nums,0,sizeof(nums));
		for(i=0;i<n;i++)
			cin >> nums[i];
        qsort(nums,n,sizeof(nums[0]),cmp);
		for(i=0;i<n;i++)
			cout << nums[i];
		cout << '\n';
	}
	return 0;
}
/*
 Problem description
 There are lots of number games for children. These games are pretty easy to play but not so easy to make. We will discuss about an interesting game here. Each player will be given N positive integers. (S)He can make a big integer by appending those integers after one another. Such as if there are 4 integers as 123, 124, 56, 90 then the following integers can be made: 1231245690, 1241235690, 5612312490, 9012312456, 9056124123 etc. In fact 24 such integers can be made. But one thing is sure that 9056124123 is the largest possible integer which can be made.
 You may think that it’s very easy to find out the answer but will it be easy for a child who has just got the idea of number? 
 
 Input
 Each input starts with a positive integer N (≤ 50). In next lines there are N positive integers. Input is terminated by N = 0, which should not be processed. The largest integer that the program should accept is 32767. 
 
 Output
 For each input set, you have to print the largest possible integer which can be made by appending all the N integers. 
 
 Sample Input
 4
 123 124 56 90
 5
 123 124 56 90 9
 5
 9 9 9 9 9
 0
 Sample Output
 9056124123
 99056124123
 99999
*/