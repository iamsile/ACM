#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i,n,a[20000]={0,1},f[50]={0,1};
    for (i=2; i<=15000; i++)
        a[i]=(a[i-1]+a[i-2])%10000;
    for (i=2; i<40; i++)
        f[i]=f[i-1]+f[i-2];
    while (~scanf("%d",&n)) {
        if (n<40)
            cout << f[n] << '\n';
        else {
            double k=0.5*(1.0+sqrt(5.0)),m;
            m=-0.5*log10(5.0)+n*log10(k);
            m-=(int)m;
            m=pow(10.0, m);
            while (m<1000)
                m*=10;
            printf("%d...%04d\n",(int)m,a[n%15000]);
        }
    }
    return 0;
}
/*
 题目大意:给定一个K（K很大很大），请你输出第K个Fibonacci数的前四位和后四位。
 
 解题思路：这道题一开始后四位我直接就是想着去打表，我只是猜测说后四位的数字可能会形成一个周期，所以我就写了个测试代码，来测试是否存在周期，结果发现果然存在周期15000，所以就打表打出了后四位的值。前四位的求法也是参考了别人的思路后才了解的。
 
 我们要搬出Fibonacci的通项公式——
 f(n)=1/sqrt(5)(((1+sqrt(5))/2)^n+((1-sqrt(5))/2)^n)
 
 假设F[n]可以表示成 t * 10^k（t是一个小数），那么对于F[n]取对数log10，答案就为log10 t + K，此时很明显log10 t<1，于是我们去除整数部分，就得到了log10 t ，再用pow（10，log10 t)我们就还原回了t。将t×1000就得到了F[n]的前四位。
 
 具体实现的时候Log10 F[n]约等于((1+sqrt(5))/2)^n/sqrt(5)，这里我们把((1-sqrt(5))/2)^n这一项忽略了，因为当N>=40时，这个数已经小的可以忽略。于是log10 F[n]就可以化简成log10 1/sqrt(5) + n*log10 (1+sqrt(5))/2
 Problem description
 The Fibonacci sequence is the sequence of numbers such that every element is equal to the sum of the two previous elements, except for the first two elements f0 and f1 which are respectively zero and one.
 
 What is the numerical value of the nth Fibonacci number?
 
 Input
 For each test case, a line will contain an integer i between 0 and 108 inclusively, for which you must compute the ith Fibonacci number fi.
 There is no special way to denote the end of the of the input, simply stop when the standard input terminates (after the EOF).
 
 Output
 Fibonacci numbers get large pretty quickly, so whenever the answer has more than 8 digits, output only the first and last 4 digits of the answer, separating the two parts with an ellipsis (“...”).
 
 Sample Input
 0
 1
 2
 3
 4
 5
 35
 36
 37
 38
 39
 40
 64
 65
 Sample Output
 0
 1
 1
 2
 3
 5
 9227465
 14930352
 24157817
 39088169
 63245986
 1023...4155
 1061...7723
 1716...7565
*/