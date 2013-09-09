#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int k,m;
	while(scanf("%d%d",&k,&m)!=EOF)
	{
		printf("%d %d ",k,m);
		if(k==m)
		{
			printf("12:00\n");
			continue;
		}
		int lastsecond=43200%(abs(k-m));
		double add=lastsecond*1.0*86400/(1.0*abs(k-m));
		double lostk=43200*1.0*k/(1.0*abs(k-m));
		add-=lostk;
		int h,m;
		double total=43200.0+add;
		while(total<=60*60) 
			total+=43200.0;
		while(total>12*60*60+59) 
			total-=43200.0;
		int min=(int)((total*1.0/60.0)+0.5);
		m=min%60;
		h=min/60;
		if(h>12)
			h-=12;
		else if(h<1) 
			h+=12;
		if(h<10) 
			printf("0%d:",h);
		else 
			printf("%d:",h);
		if(m<10) 
			printf("0%d\n",m);
		else
			printf("%d\n",m);
	}
	return 0;
}
/*
 Problem description
 It has been said that a watch that is stopped keeps better time than one that loses 1 second per day. The one that is stopped reads the correct time twice a day while the one that loses 1 second per day is correct only once every 43,200 days. This maxim applies to old fashioned 12-hour analog watches, whose hands move continuously (most digital watches would display nothing at all if stopped). 
 
 Given two such analog watches, both synchronized to midnight, that keep time at a constant rate but run slow by k and m seconds per day respectively, what time will the watches show when next they have exactly the same time? 
 
 Input
 Input consists of a number of lines, each with two distinct non-negative integers k and m between 0 and 256, indicating the number of seconds per day that each watch loses. 
 
 Output
 For each line of input, print k, m, and the time displayed on each watch, rounded to the nearest minute. Valid times range from 01:00 to 12:59 
 
 Sample Input
 1 2
 0 7
 2 13
 Sample Output
 1 2 12:00
 0 7 10:17
 2 13 04:22
*/