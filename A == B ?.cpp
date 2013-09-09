#include <iostream>
#include <string.h>
using namespace std;
char a[30000],b[30000],c[30000],d[30000];

int main()
{
    while (cin >> a >> b) {
        int i,j,x,lab=0,k1=strlen(a),k2=strlen(b);
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        for (i=0; i<k1; i++)
            if (a[i]=='.') {
                lab=1;
                break;
            }
        if (lab)
            while (a[k1-1]=='0') {
                k1--;
            }
        if (a[k1-1]=='.')
            k1--;
        for (i=0; i<k1; i++) {
            if (a[i]=='0')
                continue;
            else break;
        }
        x=i;
        for (i=x,j=0; i<k1; i++)
            c[j++]=a[i];
        
        lab=0;
        for (i=0; i<k2; i++)
            if (b[i]=='.') {
                lab=1;
                break;
            }
        if (lab)
            while (b[k2-1]=='0') {
                k2--;
            }
        if (b[k2-1]=='.')
            k2--;
        for (i=0; i<k2; i++) {
            if (b[i]=='0')
                continue;
            else break;
        }
        x=i;
        for (i=x,j=0; i<k2; i++)
            d[j++]=b[i];
        if (strcmp(c, d)==0)
            puts("YES");
        else puts("NO");
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void del_0_after_point(char *s)
{
    int len = strlen(s); 
    char *p = s+len-1;
    if(strchr(s,'.'))
        while(*p =='0')
            *p-- = '\0';
    if(*p == '.')
        *p = '\0';     
}
int main()
{
    char a[100024],b[100024];
    char *a_x,*b_x;
    while(scanf("%s%s",a,b) != EOF)
    {
        a_x = a;
        b_x = b;
        while(*a_x == '0')
            a_x ++;
        while(*b_x == '0')
            b_x ++;
        del_0_after_point(a);
        del_0_after_point(b);
        puts(strcmp(a_x,b_x)==0?"YES":"NO");
    }
    return 0;
}
*/
/*
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[1000],b[1000];
	while(cin>>a>>b)
	{
		int max1,min1,max2,min2,dian1,dian2,i,j,d1,d2;
		d1=strlen(a);
		d2=strlen(b);
		for(i=0;i<d1;i++)
		{
			if(a[i]=='-')
				continue;
			if(a[i]!='0')
				break;
		}
		if(i==d1||a[i]=='.')
			i--;
		min1=i;
		for(i=0;i<d2;i++)
		{
			if(b[i]=='-')
				continue;
			if(b[i]!='0')
				break;
		}
		if(i==d2||b[i]=='.')
			i--;
		min2=i;
		for(i=0;i<d1;i++)
			if(a[i]=='.')
				break;
		dian1=i;
		if(dian1!=d1)
		{
			for(i=d1-1;i>=dian1;i--)
                if(a[i]!='0'&&a[i]!='.')
                    break;
		}
		else
			i=d1-1;
		max1=i;
	    for(i=0;i<d2;i++)
			if(b[i]=='.')
				break;
		dian2=i;
		if(dian2!=d2)
		{
			for(i=d2-1;i>=dian2;i--)
                if(b[i]!='0'&&b[i]!='.')
                    break;
		}
		else
			i=d2-1;
		max2=i;
		if((max1-min1==max2-min2)&&((a[0]=='-'&&b[0]=='-')||(a[0]!='-'&&b[0]!='-')))
		{
			for(i=0;i<=max1-min1;i++)
				if(a[min1+i]!=b[min2+i])
					break;
			if(i>max1-min1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
*/
/*
 Problem Description
 Give you two numbers A and B, if A is equal to B, you should print "YES", or print "NO".
 
 
 Input
 each test case contains two numbers A and B.
 
 
 Output
 for each case, if A is equal to B, you should print "YES", or print "NO".
 
 
 Sample Input
 1 2
 2 2
 3 3
 4 3
 
 
 Sample Output
 NO
 YES
 YES
 NO
*/