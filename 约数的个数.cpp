#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    while (~scanf("%d",&t)) {
        while (t--) {
            int n,i,k=0,m=0;
            scanf("%d",&n);
            if (n==1) {
                puts("1");
                continue;
            }
            k=sqrt(n);
            for (i=1; i<=k;i++)
                if (n%i==0)
                    m++;
            m+=m;
            if (k*k==n)
                m--;
            printf("%d\n",m);
        }
    }
    return 0;
}
/*
 题目描述：
 输入n个整数,依次输出每个数的约数的个数
 输入：
 输入的第一行为N，即数组的个数(N<=1000)
 接下来的1行包括N个整数，其中每个数的范围为(1<=Num<=1000000000)
 当N=0时输入结束。
 输出：
 可能有多组输入数据，对于每组输入数据，
 输出N行，其中每一行对应上面的一个数的约数的个数。
 样例输入：
 5
 1 3 4 6 12
 样例输出：
 1
 2
 3
 4
 6
*/