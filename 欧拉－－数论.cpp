#include<iostream>
#include<stdio.h>
using namespace std;
int a[100001];
int sum[100001];
int main()
{
    sum[1]=a[1]=1;
    int i;
    for(i=2;i<100000;i++)
    {
        a[i]=(1+sum[i/2])%10007;
        sum[i]=(a[i]+sum[i-1])%10007;
    }
    int n;
    while(~scanf("%d",&n))
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
/*
 Description

 定义函数ans(n)为整数n写成若干个2的整数幂的和的方法数，例如

 7=1+1+1+1+1+1+1

 =1+1+1+1+1+2

 =1+1+1+2+2

 =1+1+1+4

 =1+2+2+2

 =1+2+4。

 即ans(7)=6，由于结果很大，请将结果对10007取余。

 Input

 多组数据，每行有1个整数n(0,10^5)
 Output

 每组数据一行，ans(n)%10007。
 Sample Input
 
 7
 Sample Output
 
 6
*/