#include <iostream>
using namespace std;
unsigned long long f[104],g[104];
void init()
{
    f[1]=1,f[2]=2;
    g[1]=1,g[2]=1;
    for (int i=3; i<93; i++) {
        f[i]=f[i-1]+f[i-2];
        g[i]=g[i-1]+g[i-2];
    }
}

unsigned long long cal(unsigned long long a,int k)
{
    unsigned long long tmp;
    if (a==0)
        return 0;
    if (a==f[k])
        return g[k];
    if (a<=f[k]) 
        return cal(a,k-1);
    else
    {
        tmp=cal(a-f[k],k-2);
        return g[k]+tmp;
    }
}

int main()
{
    unsigned long long x,y,n,m;
    init();
    cin >> n;
    while (n--) {
        cin >> x >> y;
        const int l=92;
        m=cal(y,l)-cal(x-1,l);
        cout << m << '\n';
    }
    return 0;
}
/*
 我们先看看序列变化规律，S1 = "1", S2 = "10", S3 = "101", S4 = "10110", S5 = "10110101", 等等. Si 是 S（i+1）的前缀。
 序列Si 是由序列 S（i-1） 和 S（i-2）, 连接而成的。
 即Si = Si-1 + Si-2 (实际上是Fibonacci数列)。
 设F[i]表示第i个序列的（长度）位数，G[i]表示第i个序列中“1”的个数。 如果要求的区间端点恰好是某个F[i]，则可以直接返回此时的G[i]。例如，当a=1,b=13时，F[6]=13，则序列中G[6]=8个“1”。如果区间的端点不是某个F[i],mj 需要发现的规律是:如果a=F[i]+F[j]+F[k]，则区间[1，a]中“1”的个数为G[i]+G[j]+G[k]。
 例如，a=31时，a=F[7]+F[5]+F[2]=21+8+2，则区间中“1”的个数为：
 13 + 5 + 1 = 19
 找到规律以后，我们可以用递归的方法求出任意长度的序列中“1”的个数。在计算闭区间[a, b]中“1”的个数时，是用区间[1,b]的结果减去区间[1,a-1]的结果。这是一个常用的技巧，希望能记着用。
 
 此题需要先找出数学规律，再进用递归实现。主要考查选手的数学思维能力和递归程序的实现。
 Problem Description
 1、 开始时序列是： "1" ；
 2、 每一次变化把序列中的 "1" 变成 "10" ，"0" 变成 "1"。 经过无限次变化，我们得到序列"1011010110110101101..."。
 总共有 Q 个询问，每次询问为：在区间A和B之间有多少个1。
 任务 写一个程序回答Q个询问
 Input
 第一行为一个整数Q，后面有Q行，每行两个数用空格隔开的整数a, b。
 1 <= Q <= 5000
 1 <= a <= b < 263
 Output
 共Q行，每行一个回答.
 Sample Input
 1
 2 8
 Sample Output
 4
*/