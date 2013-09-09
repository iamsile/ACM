#include <iostream>
#include <stdio.h>
using namespace std;
#define N 1200005
#define inf ~0U>>1
#define LL __int64

int a[6000000],p[N];

LL cal(LL n,LL k)
{
    LL sum=0;
    while(n>=1) {
        n/=k;
        sum+=n;
    }
    return sum;
}

int main()
{
    int i,j,t,cnt=0;
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    for(i=2;i<=N;i++) {
        if(!a[i])
            p[++cnt]=i;
        for(j=i+i;j<N;j+=i)
            a[j]=1;
    }
    scanf("%d",&t);
    while(t--) {
        LL n,k,ans=inf;
        scanf("%I64d%I64d",&n,&k);
        ans*=inf;
        int num=1;
        for(i=1;k>1&&k>p[i]&&i<=cnt;i++)
            if(k%p[i]==0) {
                num=1;
                for(k/=p[i];k%p[i]==0;k/=p[i])
                    num++;
                ans=min(ans,cal(n,p[i])/num);
            }
        if(k>1)
            ans=min(ans,cal(n,k));
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
 任何一个合数都可以表示成几个质数的乘积，质数的乘积是本身。
 任何一个数都可以表示成几个素数的和，素数是他本身
 比如要算 10！可以最大整除除以2 的多少次方 
 a：10  9 8 7 6 5 4 3 2  1
 a列的数除以2 变为（取整）
 b：5 4 3 2 1
 同理得
 c：2 1
 那么ans=10/2+5/2+2/2
 
 
 
 题意是说给出n , k 求出最大的 i 使得 n! % k^i == 0 ...
 假设最简单的情况...k是质数...要求 n! = 1*2*3...*n ...易看出在k的倍数里..有1个k..在k的平方的有2个k..在k的立方中有3个k... 那么 n!  中k的个数为  n/k+n/(k^2)+n/(n^3)....及为最大的 i ...
 拓展一步..若k非质数..但只有一个质因子..如8，9，125 之类的...可以先求出在 n! 中有多少个其质因子,设为x...那么有多少个k..就是 i = x/p...p是指k为起质因数的多少次方..
 最终拓展出题目所要求的任意数的情况..k=a1^k1 * a2^k2 * a3^k3...an^kn  其中a1,a2...an为质数..可以算出n!中有多少a1,a2,a3...an...而组成一个k需要k1个a1..k2个a2..kn个an..那么也就是说n(a1)/k1 , n(a2)/k2 .... n(an)/kn...中最小的就是答案...
 Problem description
 Fred Faculty and Paul Power love big numbers. Day after day Fred chooses a random integer n and he computes n!. His friend Paul amuses himself by computing several powers of his randomly chosen integer k like k2, k3 and so on. On a hot summer day, Fred and Paul got really, really bored, so they decided to play a joke on their buddy Dave Divider. Fred chooses a random integer n while Paul chooses a random integer k. They want Dave to find the biggest integer i such that ki divides n! without a remainder, otherwise they will throw a cake in Dave's face. Because Dave does not like cakes in his face, he wants you to help him finding that integer i.
 
 Input
 The first line contains the number of test cases t (1 ≤ t ≤ 100). Each of the following t lines contains the two numbers n,k (2 ≤ n ≤ 1018, 2 ≤ k ≤ 1012) separated by one space.
 
 Output
 For each test case, print the maximum integer i on a separate line.
 
 Sample Input
 2
 5 2
 10 10
 Sample Output
 3
 2
*/