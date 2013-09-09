#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int fi(int n)
{
    if (n==0)
        return 0;
    else if (n==1) return 1;
    else return fi(n-1)+fi(n-2);
}

int main()
{
    int n;
    double f;
    while (scanf("%d",&n)!=EOF) {
        if (n<21)
            cout << fi(n) << '\n';
        else {
            f=(-0.5)*log10(5.0)+((double)n)*log10((sqrt(5.0)+1.0)/2);
            f-=(int)f;
            f=pow(10.0, f);
            while (f<1000)
                f*=10.0;
            cout << (int)f << '\n';
        }
    }
    return 0;
}
/*
 Problem Description
 2007年到来了。经过2006年一年的修炼，数学神童zouyu终于把0到100000000的Fibonacci数列
 (f[0]=0,f[1]=1;f[i] = f[i-1]+f[i-2](i>=2))的值全部给背了下来。
 接下来，CodeStar决定要考考他，于是每问他一个数字，他就要把答案说出来，不过有的数字太长了。所以规定超过4位的只要说出前4位就可以了，可是CodeStar自己又记不住。于是他决定编写一个程序来测验zouyu说的是否正确。
 
 
 Input
 输入若干数字n(0 <= n <= 100000000)，每个数字一行。读到文件尾。
 
 
 Output
 
 输出f[n]的前4个数字（若不足4个数字，就全部输出）。
 
 
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
 
 
 Sample Output
 0
 1
 1
 2
 3
 5
 9227
 1493
 2415
 3908
 6324
 1023
 */