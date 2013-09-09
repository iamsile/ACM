#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (n==1) {
            cout << "YES\n";
            continue;
        }
        if (n==2||n==3||n==4) {
            cout << "NO\n";
            continue;
        }
        int i,k=sqrt(n),flag=1;
        for (i=2; i<=k; i++)
            if (n%i==0) {
                flag=0;
                break;
            }
        if (!flag)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
 Problem description
 Kolya is still trying to pass a test on Numbers Theory. The lecturer is so desperate about Kolya’s knowledge that she gives him the same task every time.
 The problem is to check if N! is divisible by N2.
 
 Input
 The first line of input contains the only integer N (1 ≤ N ≤ 109).
 
 Output
 Please, print to output “YES” provided that N! is divisible by N2, otherwise print “NO”.
 
 Sample Input
 3
 9
 Sample Output
 NO
 YES
*/