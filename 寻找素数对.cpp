#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i,j,n,a[10010];
    memset(a, 1, sizeof(a));
    for (i=2; i<=10000; i++)
        if (a[i])
            for (j=i; j*i<=10000; j++)
                a[j*i]=0;
    while (cin >> n) {
        int min,x;
        for (i=n,min=999999; i>=2; i--)
            if (a[i]&&a[n-i]&&abs(i+i-n)<min) {
                min=i+i-n;
                x=i;
            }
        cout << n-x << ' ' << x << '\n';
    }
    return 0;
}
/*
 Problem Description
 哥德巴赫猜想大家都知道一点吧.我们现在不是想证明这个结论,而是想在程序语言内部能够表示的数集中,任意取出一个偶数,来寻找两个素数,使得其和等于该偶数.
 做好了这件实事,就能说明这个猜想是成立的.
 由于可以有不同的素数对来表示同一个偶数,所以专门要求所寻找的素数对是两个值最相近的.
 
 
 Input
 输入中是一些偶整数M(5<M<=10000).
 
 
 Output
 对于每个偶数,输出两个彼此最接近的素数,其和等于该偶数.
 
 
 Sample Input
 20 30 40
 
 
 Sample Output
 7 13
 13 17
 17 23
*/