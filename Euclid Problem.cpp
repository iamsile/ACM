#include <iostream>
using namespace std;
long x,y,q;

void Eulid(long a,long b)
{
    if (b==0) {
        x=1;
        y=0;
        q=a;
    }
    else {
        Eulid(b, a%b);
        long temp=x;
        x=y;
        y=temp-a/b*y;
    }
}

int main()
{
    long a,b;
    while (cin >> a >> b) {
        Eulid(a, b);
        cout << x << ' ' << y << ' ' << q << '\n';
    }
    return 0;
}
/*
From Euclid, it is known that for any positive integers A and B there exist such integers X and Y that AX + BY = D, where D is the greatest common divisor of A and B. The problem is to find the corresponding X, Y, and D for a given A and B.

Input

The input will consist of a set of lines with the integer numbers A and B, separated with space ( A, B < 1, 000, 000, 001).

Output

For each input line the output line should consist of three integers X, Y, and D, separated with space. If there are several such X and Y, you should output that pair for which XY and | X| + | Y| is minimal.

Sample Input

4 6
17 17
Sample Output

-1 1 2
0 1 17
*/