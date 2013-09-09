#include <iostream>
using namespace std;

struct Time {
    int h,m;
}a,b,c,l;

int cal(Time d,Time e)
{
    int k=0;
    while (d.h!=e.h||d.m!=e.m) {
        d.m++;
        if (d.m==60) {
            d.m=0;
            d.h++;
            if (d.h==13)
                d.h=1;
        }
        k++;
    }
    return k;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int n=0;
        scanf("%d:%d",&a.h,&a.m);
        scanf("%d:%d",&b.h,&b.m);
        scanf("%d:%d",&c.h,&c.m);
        if (cal(a,b)==cal(b,c)) {
            n++;
            l=b;
        }
        if (cal(a, c)==cal(c, b)) {
            n++;
            l=c;
        }
        if (cal(c, a)==cal(a, b)) {
            n++;
            l=a;
        }
        if (n!=1)
            printf("Look at the sun\n");
        else {
            printf("The correct time is %d:",l.h);
            if (l.m<10)
                printf("0");
            printf("%d\n",l.m);
        }
    }
    return 0;
}
/*
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
		while(t--)
		{
			int a[5],c[5];
			int h[5],m[5];
			char d;
			int n=3;
			while(n--)
			{
				scanf("%d%c%d",&h[n],&d,&m[n]);
				a[n]=h[n]*60+m[n];
			}
			a[3]=a[0];
			a[4]=a[1];
			int i;
			for(i=0;i<3;i++)
			{
				c[i]=abs(a[i+1]-a[i+2]);
				if(c[i]>360)
					c[i]=720-c[i];
			}
			c[3]=c[0];
			c[4]=c[1];
			int k=0;
			for(i=0;i<3;i++)
			{
				if(c[i+1]==c[i+2])
				{
					if(c[i+1]!=240)
						k=1;
					break;
				}
			}
			if(k)
			{
				cout<<"The correct time is "<<h[i]<<':';
				if(m[i]<0)
					cout<<0;
				cout<<m[i]<<endl;
			}
			else
				cout<<"Look at the sun"<<endl;
		}
	return 0;
}
*/
/*
 Problem description
 Percy likes to be punctual. So much so that he always keeps three watches with him,so that he can be sure exactly what the time is. However, Percy's having a bad day. He found out that one of his watches was giving the wrong time. What's worse, when he went to correct the watch, he corrected the wrong one! That is, one watch was running x minutes behind (where x <= 480) and he wound one of the other watches x minutes forward. He now has three watches reading three different times, and hence is in serious danger of being tardy. Can you help Percy by writing a program that takes in the three times displayed on the watches and returns the correct time?
 
 Input
 The input begins with an integer T indicating the number of cases that follow (0 < T < 100). Each of the following T lines contains one test case, made up of three readings,separated by single space characters: H1:M1 H2:M2 H3:M3 In each reading H1,H2,H3 represent the hours displayed (0 < H1,H2,H3 < 13), and M1,M2,M3 represent the minutes displayed (0 < M1,M2,M3 < 60). If the number of minutes is less than 10, a leading 0 is added.
 
 Output
 For each test case, one line should be produced, formatted exactly as follows: "The correct time is Hi:Mi". If the number of minutes is less than 10, a leading 0 should be added. If the number of hours is less than 10, a leading 0 should NOT be added. If it is impossible to tell the time from the three readings, print the string: "Look at the sun".
 
 Sample Input
 3
 5:00 12:00 10:00
 11:59 12:30 1:01
 12:00 4:00 8:00
 Sample Output
 The correct time is 5:00
 The correct time is 12:30
 Look at the sun
*/