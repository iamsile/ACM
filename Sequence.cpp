#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int i,sum=0;
        int a[110],b[110],c[3];
        for (i=0; i<n; i++)
            cin >> a[i];
        b[0]=a[0];
        b[n-1]=a[n-1];
        for (i=1; i<n-1; i++) {
            c[0]=b[i-1];
            c[1]=a[i];
            c[2]=a[i+1];
            sort(c,c+3);
            b[i]=c[1];
        }
        for (i=0; i<n; i++)
            sum+=abs(a[i]-b[i]);
        for (i=0; i<n-1; i++)
            sum+=abs(b[i]-b[i+1]);
        cout << sum << '\n';
    }
    return 0;
}
/*
题目意思很简单，将公式简单变形就可以推出b[0]=a[0]和b[n-1]为区间[a[n-1],b[n-2](不知道a[n-1]与b[n-2]大小关系)内的任意一个数或者b[n-1]=a[n-1]和b[0]为区间[a[0],b[1]]区间内的任意一个数,而考虑b[i],即要使 |b[i]-a[i]|+|b[i]-b[i+1]|+|b[i-1]-b[i]|的值最小,即在数轴上找一点满足到点a[i],b[i+1],b[i-1]的距离之和最小，显然该点(即b[i])为这在数轴上三个点中间的一个点(即三个数的中位数),由上面的叙述b[0]已知，现在求b[1],我们可以将a[2]后面的数字暂时去掉，可知这时b[2]=a[2],由b[0],b[2],a[1]这时可以求出b[1],同理求b[2]时采用同样的方法处理。
*/
/*
 Problem description
 Given a sequence with N integers A(1), A(2), ..., A(N), your task is to find out a sequence B(1), B(2), ..., B(N), such that 
 V = (|A(1) - B(1)| + |A(2) - B(2)| + ... + |A(N) - B(N)|) + (|B(1) - B(2)| + |B(2) - B(3)| + ... +|B(N-1) - B(N)|)
 
 is minimum. 
 
 Input
 The first line in the input contains an integer N (1 <= N <= 100). Then follow N lines, the i-th of which contains an integer A(i) (-10000 <= A(i) <= 10000). 
 
 Output
 The output only contains an integer, which is the minimum value of V.
 
 Sample Input
 3
 3
 5
 8
 Sample Output
 5
*/