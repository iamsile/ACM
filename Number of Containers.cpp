#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        long long n,k,i,ans=0;
        scanf("%lld",&n);
        k=(long long)sqrt(n);
        for (i=1; i<=k; i++)
            ans+=n/i;
        ans=ans*2-k*k-n;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
 欧拉在1734年得到条公式：1+1/2+1/3+...+1/n = ln(n+1)+r (其中欧拉常数r = 0.577218) 这条取的都是连续的值。
 
 由于这个n非常大，故有两种思考方向，第一种是找该函数的递推或者公式，貌似很难而且每有头绪
 还有种思考的方式就是我们按段来统计，就是统计区间上有多少个数含有这个约数，我们是可以O(1)时间计算的
 接下来就是如何分这个段，其实这个问题反映到坐标系中就是对于x*y<=n，我们要找在这个图形中所有的正整数点
 我们用直线x=y把这个图形分成两部分,显然这两部分是对称的，于是我们可以令i=[1,sqrt(n)] 累加n/i （其实就是我之前说的段）
 这个再*2,但是注意到对角线上的元素我们计算了两次，故要减去k*k(k=sqrt(n))
 为什么是这个我们把整点看成基点，就是说面积通过数基点得到，我们对应到坐标上是双曲线，发现每次重算的部分叠加起来正好是一个正方形
 内所有的整点，故是k*k
 For two integers m and k, k is said to be a container of m if k is divisible by m. Given 2 positive integers n and m (m < n), the function f(n, m) is defined to be the number of containers of m which are also no greater than n. For example, f(5, 1)=4, f(8, 2)=3, f(7, 3)=1, f(5, 4)=0...
 
 Let us define another function F(n) by the following equation:
 
 Now given a positive integer n, you are supposed to calculate the value of F(n).
 Input
 
 There are multiple test cases. The first line of input contains an integer T(T<=200) indicating the number of test cases. Then T test cases follow.
 
 Each test case contains a positive integer n (0 < n <= 2000000000) in a single line.
 
 Output
 
 For each test case, output the result F(n) in a single line.
 
 Sample Input
 
 2
 1
 4
 Sample Output
 
 0
 4
*/