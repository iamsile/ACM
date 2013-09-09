#include <iostream>

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        __int64 i,j,a[100010],sum1[21],ans=0;
        memset(a, 0, sizeof(a));
        memset(sum1, 0, sizeof(sum1));
        for (i=0; i<n; i++) {
            scanf("%I64d",&a[i]);
            for (j=0; a[i]; j++,a[i]/=2)
                if (a[i]%2)
                    sum1[j]++;
        }
        for (i=0; i<20; i++)
            ans+=sum1[i]*(n-sum1[i])*(2<<i);//(2<<i)==2*pow(2,i);
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
虽然题意很简单，但是数据可不简单，n达到了100000。如果直接求的话，最多需要100000^2次运算，
 无论如何都不能在规定的时限内出解，所以我们就要想想别的方法。考虑到位运算是针对每一个二进制位来的，
 那么，我们就将每一个二进制位单独处理。首先将所有的数转化成二进制数，
 然后将每一个二进制位上的0和1个数统计出来。由于只有当0 xor 1时能得出1。
 那么假设2^i这一位上有a个0和b个1，那么一共会有a*b*2次运算这一位为1，
 也就是最后的答案包含a*b*2个2^i。如此一来我们最多只要用20次计算就可以得出最后的答案。
 而一开始的预处理需要nlogn的复杂度。所以总的时间复杂度是O（nlogn）。
*/
/*
 Problem description
 We all know that huicpc302 is good at maths, now he does a job below.
 
 At first he got a n numbers.
 
 Then he got a function below:
 long long Cal(int a[], int n)
 {
 int i, j;
 long long ret = 0;
 for(i = 0; i < n; i ++)
 {
 for(j = 0; j < n; j ++)
 {
 ret += a[i]^a[j];
 }
 }
 return ret;
 }
 Now he wants to know what he will get, when using the function to the calculate the n numbers.
 Note that when n is too large, this function works slowly, but huicpc302 wants to get the answer as soon as possible.
 
 
 Input
 There are several test cases in the input, the first line of each test case is an integer n, the second line contains n(1 <= n <= 100000) integers, a0, a1, a2... an-1. (1 <= ai < 219). The input ends by EOF.
 
 Output
 For each test case, output one line, the result.
 
 Sample Input
 5
 41 18467 6334 26500 19169
 5
 15724 11478 29358 26962 24464
 Sample Output
 338484
 352232
*/