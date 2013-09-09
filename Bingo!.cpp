#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,m;
    while (cin >> n >> m) {
        if (!n&&!m)
            break;
        int i,j,lab,sum=0,a[200],b[200];
        memset(b, 0, sizeof(b));
        for (i=0; i<m; i++) {
            cin >> a[i];
            for (j=0; j<i; j++) {
                lab=abs(a[i]-a[j]);
                if (!b[lab]) {
                    b[lab]=1;
                    sum++;
                }
            }
        }
        if (sum>=n)
            cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
/*
 Problem description
 Albert, Charles and Mary invented a new version of the classical game Bingo. In traditional Bingo the game is presided over by a non-player known as the caller. At the beginning of the game each player is given a card containing a unique combination of numbers from 0 to N arranged in columns and rows. The caller has a bag containing N + 1 balls, numbered from 0 to N. On each turn, the caller randomly selects a ball from the bag, announces the number of the drawn ball to the players, and sets the ball aside so that it cannot be selected again. Each player searches his card for the called number and marks it if he finds it. The first player who marks a complete pre-announced pattern on the card (for example, a full horizontal line) wins a prize.
 In the Albert-Charles-Mary version, on each turn, the caller draws a first ball, returns it to the bag, draws a second ball, returns it to the bag, and then calls out the absolute difference between the two ball numbers. To generate even more excitement, before the game started a possibly empty subset of balls is removed from the bag, in such a way that at least two balls remain there. They would like to know if every number from 0 to N may still be called out with the new drawing method considering the balls that were left in the bag. 
 
 
 Input
 Each test case is given using exactly two lines. The first line contains two integers N and B. The meaning of N was described above (1 ≤ N ≤ 90), while B represents the number of balls which remained in the bag (2 ≤ B ≤ N + 1). The second line contains B distinct integers bi, indicating the balls which remained in the bag (0 ≤ bi ≤ N). The last test case is followed by a line containing two zeros. 
 
 
 Output
 For each test case output a single line containing a single uppercase ‘Y’ if is possible to call out every number from 0 to N, inclusive, or a single uppercase ‘N’ otherwise. 
 
 
 Sample Input
 6 7
 2 1 3 4 0 6 5
 5 4
 5 3 0 1
 5 3
 1 5 0
 0 0
 Sample Output
 Y
 Y
 N
*/