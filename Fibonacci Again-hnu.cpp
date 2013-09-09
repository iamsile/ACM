#include <iostream>
using namespace std;

int main()
{
    unsigned int n;
    while (scanf("%u",&n)!=EOF) {
        if (n%8==6||n%8==2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
/*
 Problem Description
 There are another kind of Fibonacci numbers: F(0) = 7, F(1) = 11, F(n) = F(n-1) + F(n-2) (n>=2).
 
 
 Input
 Input consists of a sequence of lines, each containing an integer n. (n < 1,000,000).
 
 
 Output
 Print the word "yes" if 3 divide evenly into F(n).
 
 Print the word "no" if not.
 
 
 Sample Input
 0
 1
 2
 3
 4
 5
 
 
 Sample Output
 no
 no
 yes
 no
 no
 no
 */