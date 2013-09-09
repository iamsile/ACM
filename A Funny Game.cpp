#include <iostream>
using namespace::std;

int main() 
{
    int n;  
	string a;
    while(cin >> n)
    {
		if(n==0)
			break;
		cin >> a;
        if(n>2)
        {
			if(a=="Bird")
				cout << "Pomelo\n";
			else 
				cout << "Bird\n";
        }
        else
            cout << a << '\n';
    }
    return 0;
}
/*这是一个博弈游戏。事实上，当硬币的数目大于等于3的时候，Bob都有必胜的策略。如果硬币总数是偶数，那么每轮Bob只要拿与Alice相同数目的硬币，并且是中心对称的硬币。如果硬币总数是奇数，那么Bob只要在第一轮拿走（3-Alice拿走的数目）的硬币就可以了。

比如下图

     1       2

3                  4

         5
／／／／／／／／／／／／／／／／／／／／／／／
／／／／／poj上的解题报告！！！！／／／／／／
／／／／／／／／／／／／／／／／／／／／／／／
如果Alice第一轮拿走5，那么Bob就拿走1、2。留下3与4对称就行了。

如果Alice拿走1、3，那么Bob就拿走4就行了。*/
/*
 Problem description
 Bird和Pomelo打算玩一个有趣的游戏。在游戏开始之前，他们收集到了n枚硬币，并排成一个环，如Figure 1所示。游戏时，两人轮流拿走硬币。每一轮一个人可以移走一枚或相邻的两枚硬币，但是至少要拿走一枚。谁拿走了最后一枚硬币谁便获胜。
 
 Bird和Pomelo丢硬币决定谁先拿。最后输了的人将请获胜的人吃巴比馒头和吉祥馄饨！
 
 
 注意：对于n>3， 我们令c1, c2, ..., cn 表示按顺时针排列的硬币。如果Bird拿走了c2, 那么c1和 c3 就不相邻了！（因为c1和c3之间有一个空位）
 
 假设Bird和Pomelo在游戏中都使出了各自最优的拿币策略，现在你需要决定谁将赢得这个游戏。 
 
 Input
 有多组测试数据。 每组数据独占一行，包括 n（1 <= n <= 106） 和字符串 name，分别表示硬币的个数和 先开始游戏的人的名字（即Bird或Pomelo）。
 
 数据以一个单独的0结束，对这个0无须作任何处理。 
 
 Output
 对每个数据，输出赢得比赛的人的名字。
 
 Sample Input
 1 Bird
 2 Pomelo
 3 Bird
 0
 Sample Output
 Bird
 Pomelo
 Pomelo
*/