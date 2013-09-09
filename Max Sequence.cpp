#include<iostream>
using namespace::std;

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int i,sum=0,max=-100000,lab=-0x7fffffff,*a=new int[100000],*b=new int[100000];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(sum>0) 
                sum+=a[i];
            else 
                sum=a[i];
            if(sum>max) 
                max=sum;
            b[i]=max;
        }
        for(max=-100000,sum=0,i=n-1;i>=1;i--)
        {
            if(sum>0)
                sum+=a[i];
            else 
                sum=a[i];
            if(sum>max)
                max=sum;
            if(max+b[i-1]>lab) 
                lab=max+b[i-1];
        }
        printf("%d\n",lab);
		delete a;
		delete b;
    }
    return 0;
}
/*
#include <stdio.h>
#include <limits.h>
int a[100002],b[100002],c[100002];
int main(){
    int i,n,t,sum;
    while(scanf("%d",&n) && n){
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(t=0,sum=INT_MIN,i=0; i<n; i++){
            if(t>0)
                t+=a[i];
            else 
                t=a[i];
            if(t>sum)
                sum=b[i]=t;
            else
                b[i] = sum;
        }
        for(t=0,sum=INT_MIN,i=n-1; i>=1; i--){
            if(t>0)
                t+=a[i];
            else 
                t=a[i];
            if(t>sum)
                sum=c[i]=t;
            else
                c[i] = sum;
        }
        for(sum=b[0]+c[1],i=2; i<n-2; i++){
            if(b[i]+c[i+1]>sum)
                sum=b[i]+c[i+1];
        }
        printf("%d\n",sum);
    }
    return 0;
}
*/
//0x7fffffff=2^31;
/*
 Problem description
 Give you N integers a1, a2 ... aN (|ai| <=1000, 1 <= i <= N). 
 
 S=max(1<=i<=j<=p<=q<=N){求和(i<=t<=j)at+求和(p<=t<=q)at};
 
 You should output S. 
 
 
 Input
 The input will consist of several test cases. For each test case, one integer N (2 <= N <= 100000) is given in the first line. Second line contains N integers. The input is terminated by a single line with N = 0.
 
 Output
 For each test of the input, print a line containing S. 
 
 Sample Input
 5
 -5 9 -5 11 20
 0
 
 Sample Output
 40
*/