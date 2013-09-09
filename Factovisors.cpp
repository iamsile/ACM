#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
#define N 65000
int len,p[65000];

void prime()
{
    int i,j,k=(int)sqrt(N);
    for (i=2; i<=N; i++)
        p[i]=1;
    for (i=2; i<=k; i++)
        if (p[i])
            for (j=i*i; j<=N; j+=i)
                p[j]=0;
}

int main()
{
    unsigned n,m;
    prime();
    while (scanf("%u%u",&n,&m)!=EOF) {
        int i,flag,lab,count,sum,a[6000],num[6000];
        if (!m)
            flag=0;
        else if (n>=m)
            flag=1;
        else {
            flag=1;lab=m;count=0;sum=0;
            memset(num, 0, sizeof(num));
            for (i=2; i<=N; i++) {
                if (p[i]==0)
                    continue;
                if (lab%i==0) {
                    a[count]=i;
                    while (lab%i==0) {
                        num[count]++;
                        lab/=i;
                    }
                    count++;
                }
                if (lab==1)
                    break;
            }
            if (lab>=47000) {
                a[count]=lab;
                num[count++]++;
            }
            for (i=count-1; i>=0; i--) {
                if (a[i]>n) {
                    flag=0;
                    break;
                }
                lab=n;
                while (lab) {
                    sum+=lab/a[i];
                    lab/=a[i];
                }
                if (sum<num[i]) {
                    flag=0;
                    break;
                }
            }
        }
        if (flag)
            cout << m << " divides " << n << "!\n";
        else
            cout << m << " does not divide " << n << "!\n";
    }
    return 0;
}
/*
 The factorial function, n! is defined as follows for all non-negative integers n: 
 0!	=	1	  
 n!	=	n x (n - 1)!        (n > 0)	  
 
 We say that a divides b if there exists an integer k such that
 
 k x a = b
 Input
 
 The input to your program consists of several lines, each containing two non-negative integers, n and m, both less than 231.
 Output
 
 For each input line, output a line stating whether or not m divides n!, in the format shown below.
 Sample Input
 
 6 9
 6 27
 20 10000
 20 100000
 1000 1009
 Sample Output
 
 9 divides 6!
 27 does not divide 6!
 10000 divides 20!
 100000 does not divide 20!
 1009 does not divide 1000!
*/