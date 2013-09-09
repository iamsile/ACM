#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n&&n>=0) {
        if (n==0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
/*
 Problem description
 There is a line of coins with N(no more than 1000) coins. Two players I and II alternately takes away coins. In each turn one must take away one coin or two adjacent coins. The one who cannot make a move loses.
 You are to determine for a given N, whether I will win or II will win, i.e. N is a N-position（next-player-will-win） or P-position(previous-player-will-win). 
 
 Input
 Every test case is an N described above. Total test case is no more than 50. Process until the first negative number.
 
 Output
 If N is a N-position, output a string “Yes” in a line, else “No” in a line.
 
 Sample Input
 1
 2
 Sample Output
 Yes
 Yes
*/