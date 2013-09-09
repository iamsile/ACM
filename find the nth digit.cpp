#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t,j;
    scanf("%d",&t);
    while (t--) {
        unsigned n,k;
        scanf("%u",&n);
        double s,m=sqrt(n*2);
        j=(int)m;
        m=m-(m-j);
        s=m*(m+1)/2;
        if (s<n)
            m+=1;
        s=m*(m-1)/2;
        k=(int)(n-s)%9;
        if (k==0)
            k=9;
        printf("%u\n",k);
    }
    return 0;
}
/*
 Problem Description
 假设：
 S1 = 1
 S2 = 12
 S3 = 123
 S4 = 1234
 .........
 S9 = 123456789
 S10 = 1234567891
 S11 = 12345678912
 ............
 S18 = 123456789123456789
 ..................
 现在我们把所有的串连接起来
 S = 1121231234.......123456789123456789112345678912.........
 那么你能告诉我在S串中的第N个数字是多少吗？
 
 
 Input
 输入首先是一个数字K，代表有K次询问。
 接下来的K行每行有一个整数N(1 <= N < 2^31)。
 
 
 Output
 对于每个N，输出S中第N个对应的数字.
 
 
 Sample Input
 6
 1
 2
 3
 4
 5
 10
 
 
 Sample Output
 1
 1
 2
 1
 2
 4
 
 
 Author
 8600
*/