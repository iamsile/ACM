#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n,m,lab=1;
    while (cin >> n >> m) {
        if (!n&&!m)
            break;
        cout << "Test #" << lab++ << ":\n";
        if (m>n) {
            cout << "0\n";
            continue;
        }
        int i,j,k=1,d=0,len=m+n,sum=0,a[10000]={1,0};
        for (i=1; i<=len; i++) {
            for (j=0; j<=k; j++)
                a[j]*=i;
            for (j=0; j<=k; j++)
                if (a[j]>9) {
                    a[j+1]+=a[j]/10;
                    a[j]=a[j]%10;
                    if (j+1==k)
                        k++;
                }
        }
        for (i=0; i<=k; i++)
            a[i]*=(n-m+1);
        for (i=0; i<=k; i++)
            if (a[i]>9) {
                a[i+1]+=a[i]/10;
                a[i]=a[i]%10;
                if (i+1==k) {
                    k++;
                }
            }
        for (i=k; i>=0; i--)
            if (a[i])
                break;
        for (; i>=0; i--) {//divide
            d=d*10+a[i];
            a[i]=d/(n+1);
            d%=(n+1);
        }
        for (i=k; i>=0; i--)
            if (a[i])
                break;
        for (; i>=0; i--) 
            cout << a[i];
        cout << '\n';
    }
    return 0;
}
/*
 ( C(m+n, n) - C(m+n, m+1) ) * m! * n! 化简即 (m+n)! * (m-n+1) / (m+1)
 
 推导过程如下 :
 
 m个人拿50，n个人拿100 
 
 1:    所以如果 n > m，那么排序方法数为 0 这一点很容易想清楚 
 
 2:    现在我们假设 拿50的人用 ‘0’表示， 拿100的人用 1 表示。
 
 如果有这么一个序列 0101101001001111. 
 
 当第K个位置出现1的个数多余0的个数时就是一个不合法序列了
 
 假设m=4 n=3的一个序列是：0110100 显然，它不合法， 现在我们把它稍微变化一下： 
 
 把第二个1（这个1前面的都是合法的）后面的所有位0变成1，1变成0 
 
 就得到 0111011 这个序列1的数量多于0的数量， 显然不合法， 但现在的关键不是看这个序列是不是合法的 
 
 关键是：它和我们的不合法序列 0110100 成一一对应的关系 
 
 也就是说任意一个不合法序列(m个0，n个1)， 都可以由另外一个序列(n-1个0和m+1个1)得到 
 
 另外我们知道，一个序列要么是合法的，要么是不合法的 
 
 所以，合法序列数量 = 序列总数量 - 不合法序列的总量 
 
 序列总数可以这样计算m+n 个位置中， 选择 n 个位置出来填上 1， 所以是 C(m+n, n) 
 
 不合法序列的数量就是： m+n 个位置中， 选择 m+1 个位置出来填上 1 所以是 C(m+n, m+1) 
 
 然后每个人都是不一样的，所以需要全排列 m! * n! 
 
 所以最后的公式为 :  ( C(m+n, n) - C(m+n, m+1) ) * m! * n! 化简即 (m+n)! * (m-n+1) / (m+1)
 
 推广:
 如果原来有p张50元的话,那么不合法的序列的数量应该是:任意一个不合法序列(m个0，n个1)，
 
 都可以由另外一个序列(n-1个0和m+1+p个1)得到,所以是m+n 个位置中， 选择 m+1+p 个位置
 
 出来填上 1 所以是 C(m+n, m+1+p) 接下来的化简就不推了.
 Problem Description
 The "Harry Potter and the Goblet of Fire" will be on show in the next few days. As a crazy fan of Harry Potter, you will go to the cinema and have the first sight, won’t you?
 
 Suppose the cinema only has one ticket-office and the price for per-ticket is 50 dollars. The queue for buying the tickets is consisted of m + n persons (m persons each only has the 50-dollar bill and n persons each only has the 100-dollar bill).
 
 Now the problem for you is to calculate the number of different ways of the queue that the buying process won't be stopped from the first person till the last person. 
 Note: initially the ticket-office has no money. 
 
 The buying process will be stopped on the occasion that the ticket-office has no 50-dollar bill but the first person of the queue only has the 100-dollar bill.
 
 
 Input
 The input file contains several test cases. Each test case is made up of two integer numbers: m and n. It is terminated by m = n = 0. Otherwise, m, n <=100.
 
 
 Output
 For each test case, first print the test number (counting from 1) in one line, then output the number of different ways in another line.
 
 
 Sample Input
 3 0
 3 1
 3 3
 0 0
 
 
 Sample Output
 Test #1:
 6
 Test #2:
 18
 Test #3:
 180
*/