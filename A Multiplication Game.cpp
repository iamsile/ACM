#include <iostream>
using namespace std;

int main()
{
    unsigned n;
    while (cin >> n) {
        while (n>18)
            n=(n-1)/18+1;
        if (n>9)
            cout << "Ollie wins.\n";
        else
            cout << "Stan wins.\n";
    }
    return 0;
}
/*若先手方先超越n，则赢。为了保证超越n，当上轮后手时必须将对手限制在[x/18,x/9)范围内。所以上轮先手时若能达到(x/18/2,x/18)
则此逼迫一定会成功。*/
/*
 Stan and Ollie play the game of multiplication by multiplying an integer p by one of the numbers 2 to 9. Stan always starts with p = 1, does his multiplication, then Ollie multiplies the number, then Stan, and so on. Before a game starts, they draw an integer 1 < n < 4, 294, 967, 295 and the winner is whoever reaches pn first.
 
 Input
 
 Each input line contains a single integer n.
 Output
 
 For each line of input, output one line - either
 Stan wins.
 or
 Ollie wins.
 assuming that both of them play perfectly.
 Sample Input
 
 162
 17
 34012226
 Sample Output
 
 Stan wins.
 Ollie wins.
 Stan wins.
*/