#include <iostream>
#include <stdio.h>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int judge(int y)
{
	if(y%400==0||(y%4==0&&y%100!=0))
		return 1;
	else return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
		int i,j,k,n,m,flag,sum=0;
		scanf("%d%d",&n,&m);
		for(i=n;i<=m;i++) {
			flag=judge(i);
			for(j=1;j<=12;j++)
				for(k=1;k<=month[j]+flag;k++)
					if((j*j==k*k&&j*j==i%100)||(j*j==k*k&&j*j==i%1000))
						sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
/*
 Square Root Day is an unofficial holiday celebrated on days when both the day of the month and the month are the square root of either the last two or three digits of the year. For example, the last Square Root Day was March 3, 2009 (3/3/09), and the next Square Root Day will be April 4, 2016 (4/4/16).
 
 Input
 
 The first line of the input contains an integer T (T <= 10), indicating the number of cases.
 
 Then T lines follows, each has two integers x and y (1 <= x <= y <= 2009).
 
 Output
 
 Output the number of Square Root Days from year x to year y, both inclusive.
 
 Sample Input
 
 2
 2009 2009
 81 100
 Sample Output
 
 1
 2
*/