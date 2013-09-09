#include <iostream>
using namespace std;

int main()
{
    int n,k,t,lab=1;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << "Case " << lab++ << ": ";
        if (k==1) {
            if (n%2)
                cout << "first\n";
            else cout << "second\n";
        }
        else if (n<=k)
            cout << "first\n";
        else cout << "second\n";
    }
    return 0;
}
/*
 假设我们有10枚硬币,K=2,第一个玩家拿走一枚之后,第二个玩家在圆的对称点拿走相应的,保持剩下的两边硬币相等,这样不管第一个玩家怎么取,第二个玩家只要在另一边一样的取法就能保证自己是最后一个取硬币的.也可以根据SG定理知道,SG值一样的两个游戏为必败状态.
 
 推广到更大的情况也一样,所以第一个玩家胜利的情况只可能是N为奇数且K为1,或者K>=N,
 
 其他情况均第二个玩家胜.
 
 当然你也可以用sg定理去推出初始状态的必胜必败情况,从而得到规律.不过比较费时间且没有上述推论直观.
 Problem Description
 After hh has learned how to play Nim game, he begins to try another coin game which seems much easier.
 
 
 The game goes like this: 
 Two players start the game with a circle of n coins. 
 They take coins from the circle in turn and every time they could take 1~K continuous coins. 
 (imagining that ten coins numbered from 1 to 10 and K equal to 3, since 1 and 10 are continuous, you could take away the continuous 10 , 1 , 2 , but if 2 was taken away, you couldn't take 1, 3, 4, because 1 and 3 aren't continuous)
 The player who takes the last coin wins the game. 
 Suppose that those two players always take the best moves and never make mistakes. 
 Your job is to find out who will definitely win the game.
 
 
 Input
 The first line is a number T(1<=T<=100), represents the number of case. The next T blocks follow each indicates a case.
 Each case contains two integers N(3<=N<=109,1<=K<=10).
 
 
 Output
 For each case, output the number of case and the winner "first" or "second".(as shown in the sample output)
 
 
 Sample Input
 2
 3 1
 3 2
 
 
 Sample Output
 Case 1: first
 Case 2: second
*/