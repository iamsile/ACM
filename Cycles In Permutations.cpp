#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,n,a[100],cnt,f,l,maxn=-1;
        cin >> n;
        for (i=1; i<=n; i++)
            cin >> a[i];
        for (i=1; i<=n; i++) {
            cnt=1;
            f=l=a[i];
            while (l!=a[f]) {
                f=a[f];
                cnt++;
            }
            if (cnt>maxn)
                maxn=cnt;
        }
        cout << maxn << '\n';
    }
    return 0;
}
/*
 Problem description
 The permutations game is a simple solitaire game played on a rectangular board. The board is divided into N squares, arranged in a row. Each square of the board has a distinct number between 1 and N, inclusive, printed on it. Each square also has a position. The leftmost square has position 1, the rightmost square has position N, and positions are numbered consecutively from left to right. 
 
 
 In this example for N=6 you can see the board with the numbers printed on it. Below each square is its position.
 
 This game is played in the following way: First, the player chooses any square as his starting square and steps on it. At each step, he will look at the number printed on the square on which he is standing, and then move to the square at that position. He repeats this until he returns to his starting square.
 
 In the board shown above, the player might start at position 3. He would see the 4 printed on that square and move to position 4. Then, he would see a 1 and move to the position 1. Finally, he would see a 3 and return to his starting square, and the game would end there. If he started at position 2, he would see the 2 printed on that square, move to position 2 (where he was already standing), and stop there. Depending on where he started, he would visit a different number of squares (3 in the first example, and 1 in the second example). The goal of the game is to select the starting square that allows you to visit the greatest number of squares possible.
 
 
 
 
 Input
 The first line of input contains a single integer T, (1 ≤ T ≤ 200), which is the number of data sets that follow. Each data set consists of 2 lines. The first line contains an integer N. The second line contains the board.
 The board will be given as an integer array, where the ith element is the value printed on the square at position i (i is a 1-based index).
 
 The board will contain between 1 and 50 elements, inclusive.
 
 The board will contain exactly one occurrence of each integer between 1 and the number of elements in board, inclusive. 
 
 
 
 Output
 For each data set,output the maximum number of squares the player can visit if he selects his starting square optimally.
 
 
 Sample Input
 3
 6
 3 2 4 1 6 5
 6
 1 2 3 4 5 6
 5
 5 1 2 3 4
 Sample Output
 3
 1
 5
*/