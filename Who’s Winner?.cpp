#include <iostream>
using namespace std;

int main()
{
    long long n;
    while (cin >> n) {
        while (n>=19) {
            if (n%18!=0)
                n=n/18+1;
            else n=n/18;
        }
        if (n>=10&&n<=18)
            cout << "Susan wins.\n";
        else cout << "Nic wins.\n";
    }
    return 0;
}
/*解题思路：像是贪心算法，要想先到达p，就要先到达p/18;要想到达p/18
 
 就要先到达p/(18*18);以此类推就可以了。这是因为，倒数第二次报数，如果
 
 相赢的话，就要保证小于p/9,但这还不够，因为对方乘以最小数是2；所以你报的
 
 数应该保证对方乘以9，不能到达p，又要使对方乘以2之后，你又能到达p；
 
 这个最小的数就是p/18*/
/*
 Problem description
 
 Nic and Susan play the game of multiplication by multiplying an integer p by one of the number 2 to 9. Nic always starts with p=1, does his multiplication. Then Susan multiplies the number, then Nic and so on. Before a game starts, they draw an integer 1<=n<4294967295 and the winner is who first reaches p>=n. 
 
 Input
 
 Each line of input contains one integer number n.
 
 Output
 
 For each line of input output one line either
 Nic wins.
 
 Or
 
 Susan wins.
 
 Assume that both of them play perfectly. 
 
 
 Sample Input
 162
 17
 34012226
 Sample Output
 Nic wins.
 Susan wins.
 Nic wins.
*/