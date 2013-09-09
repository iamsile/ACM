#include <iostream>
using namespace std;

int main()
{
    int i,n;
    while (~scanf("%d",&n)) {
        double a,b,c,m=(double)n,sum1,sum2;
        scanf("%lf%lf",&a,&b);
        sum1=m*a+b;
        sum2=0;
        for (i=1; i<=n; i++) {
            scanf("%lf",&c);
            sum2=sum2+m*c;
            m--;
        }
        printf("%.2f\n",(sum1-2*sum2)/(n+1));
    }
    return 0;
}
/*
 Problem Description
 有如下方程：Ai = (Ai-1 + Ai+1)/2 - Ci (i = 1, 2, 3, .... n).
 若给出A0, An+1, 和 C1, C2, .....Cn.
 请编程计算A1 = ?
 
 
 Input
 输入包括多个测试实例。
 对于每个实例，首先是一个正整数n,(n <= 3000); 然后是2个数a0, an+1.接下来的n行每行有一个数ci(i = 1, ....n);输入以文件结束符结束。
 
 
 Output
 对于每个测试实例，用一行输出所求得的a1(保留2位小数).
 
 
 Sample Input
 1
 50.00
 25.00
 10.00
 2
 50.00
 25.00
 10.00
 20.00
 
 
 Sample Output
 27.50
 15.00
*/