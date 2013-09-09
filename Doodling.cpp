#include <iostream>
using namespace std;

long cal(long a,long b)
{
    if (b==0)
        return a;
    else return cal(b, a%b);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long n,m;
        cin >> n >> m;
        long l=(n-1)*(m-1)/cal(n-1,m-1);
        cout << (long)(l+1-(l/(n-1)-1)*(l/(m-1)-1)/2) << '\n';
    }
    return 0;
}
/*Repeatedly mirroring the grid on its lower row and rightmost
column, reveals that the number of squares you fill out before
you fill out a new corner is the LCM of h − 1 and w − 1 (let
this be L), plus 1 for the new corner. The pattern will run
between top and bottom	L/(h-1)	times, and between left and h−1
right L/w−1 times.
Some squares will be counted twice in this way. Each sequence
from the left to the right edge intersects each sequence from
the upper to the lower edge exactly once, except when these
sequences are overlapping. This is is case for each of the edge
points, of which there are	L/(h-1)	+ L/(w-1)− 1. Also, everything is
counted twice in this way, as the two kinds of sequences are made up of the same squares.
The final result is L+1− 1/2(L/(h-1)-1)*(L/(w-1)-1))
 Problem description
 When thinking about a hard problem a lot of people like to doodle, to create \an unfocused drawing that can help the memory and improve abstract thinking". The most basic form of doodle is a repetitive pattern covering the whole page. One way to create such a pattern is to take a graphing paper and start in the top-left corner (0; 0) and fill out the square, then move down and right one square (1; 1), fill it out, and so on. Every time you hit the edge of the paper you reverse direction, until you are back at the starting point. This will create a very soothing pattern.
 However, to ensure you don't spend the whole competition doodling you need to figure out how how many squares you will have to fill in the paper to complete the doodle before you even start doodling. 
 
 
 Input
 1 ≤ n ≤ 4000 The number of testcases For each n: 2 ≤ x; y ≤ 20000 The height and width (in squares) of the graphing paper.
 
 
 Output
 The number of unique squares you will have filled in before you are done with your doodle.
 
 
 Sample Input
 3
 11 3
 5 7
 5 8
 Sample Output
 11
 12
 20
*/