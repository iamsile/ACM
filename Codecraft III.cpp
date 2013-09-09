#include <iostream>
using namespace::std;
char m[12][10]={"January","February","March","April","May","June","July","August","September",
	"October","November","December"};

int main()
{
	char a[10];
	int n,lab,k;
	while(scanf("%s%d",a,&n)!=EOF)
	{
		if(a[0]=='J'&&strlen(a)>4)
			lab=1;
		else if(a[0]=='F')
			lab=2;
		else if(a[0]=='M'&&strlen(a)>3)
			lab=3;
		else if(a[0]=='A'&&strlen(a)==5)
			lab=4;
		else if(a[0]=='M')
			lab=5;
		else if(a[0]=='J'&&a[3]=='e')
			lab=6;
		else if(a[0]=='J'&&a[3]=='y')
			lab=7;
		else if(a[0]=='A'&&strlen(a)==6)
			lab=8;
		else if(a[0]=='S')
			lab=9;
		else if(a[0]=='O')
			lab=10;
		else if(a[0]=='N')
			lab=11;
		else if(a[0]=='D')
			lab=12;
		k=(lab+n)%12;
		if(k)
			puts(m[k-1]);
		else 
			puts(m[11]);
	}
	return 0;
}
/*
 Problem description
 Today Vasya visited a widely known site and learned that the continuation of his favourite game Codecraft II will appear after exactly k months. He looked at the calendar and learned that at the moment is the month number s. Vasya immediately got interested in what month Codecraft III will appear. Help him understand that.
 All the twelve months in Vasya's calendar are named using their usual English names: January, February, March, April, May, June, July, August, September, October, November, December.
 
 
 Input
 There are several test cases in the input file.Each test case contains the name of the current month. It is guaranteed that it is a proper English name of one of twelve months. The first letter is uppercase, the rest are lowercase. The second line contains integer k (0 ≤ k ≤ 100) — the number of months left till the appearance of Codecraft III.
 
 Output
 Print starting from an uppercase letter the name of the month in which the continuation of Codeforces II will appear. The printed name must be contained in the list January, February, March, April, May, June, July, August, September, October, November, December.
 
 Sample Input
 November
 3
 May
 24
 Sample Output
 February
 May
*/