#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i,n,f[50]={1,2};
    for (i=2; i<40; i++)
        f[i]=f[i-1]+f[i-2];
    while (~scanf("%d",&n)) {
        int cnt=0,m=0x7fffffff;
        for (i=39; i>=0; i--)
            if (n>=f[i]) {
                n-=f[i];
                cnt++;
                if (m>=f[i])
                    m=f[i];
            }
        if (cnt==1)
            printf("lose\n");
        else printf("%d\n",m);
    }
    return 0;
}
/*
 第一个人，可以任意拿，但必须至少拿一个
 
 这个题目不同于常规的游戏题目，首先石子的个数非常的巨大，不可能计算必胜态必败态。而且两个游戏着之间有某种操作上的联系，所以这个题目必须另外来找规律
 
 首先根据规则石子个数是1的时候，必败。
 通过枚举前100个石子的必胜必败态，可以搞清楚必败态的规律来。
 其实必败态满足fibonaci数列。
 也就是说石子数位1 2 3 5 8 13 21 34 ..这些石子的时候，不论怎么拿，都会失败
 那么剩下的那些石子个数都是必胜态。
 这个规律刚好能够满足题目所说的游戏规则。至于这个规律怎么来得暂时我也不是很清楚。
 
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
 Fib                              1 1 1 0 1 0 0 1 0 0  0  0  1  0  0  0  0  0  0  0  1  0  0  0
 必胜态所能取的最小值                   1   1 2   1 2  3  1     1  2  3  1  5  1  2     1  2  3
 必胜态所能取的最大值(理论上届)         1   1 2   2 3  3  3     4  4  5  5  5  6  6     7  7  7
 
 按照必胜态的最小值选择初始值，就必然能够从必胜态转化为必败态
 Two players(A and B) take turns to take stones form a heap of N stones.
 
 There are some rules:
 1.A always takes first. He can take arbitrary number of stones but not all of them.
 2.The number of the one who will take should less than or equal the twice of the other one taken last time. But must more than one or one.
 3.The one who take take the last one stone is the winner.
 4.The two players are clever enough, they can make the best choice.
 Input
 
 Every test case has only one line with one integer N(2 <= N <= 100000000), the numbers of the stones.
 
 Output
 
 If A will lose output "lose"
 
 If A can win,output the numbers A should take at the first time. If there are more ways to make A win, output the smallest one.
 
 Sample Input
 
 4
 
 Sample Output
 
 1
 */