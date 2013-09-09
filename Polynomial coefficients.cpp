#include <iostream>
using namespace std;

int main()
{
    int i,n,m,l;
    unsigned a[14]={1,1,2,6,24,120,720,5040,40320,362880,
        3628800,39916800,479001600};
    while (cin >> n >> m) {
        unsigned k=a[n];
        for (i=0; i<m; i++) {
            cin >> l;
            k/=a[l];
        }
        cout << k << '\n';
    }
    return 0;
}
/*The coefficient of x1n1x2n2...xknk is 
 (n, n1)(n-n1, n2)...(n-n1-n2-...-nk-1, nk) = n!/n1!n2!...nk!.
 */
/*
 This problem seeks the coefficients resulting from the expansion of the polynomial
 
 P = (x1 + x2 + ... + xk)^n
 Input
 
 The input will consist of a set of pairs of lines. The first line of the pair consists of two integers n and k separated with space ( 0 < k, n < 13). These integers define the power of the polynomial and the number of variables. The second line in each pair consists of k non-negative integers n1,..., nk, where n1 + ... + nk = n.
 
 Output
 
 For each input pair of lines the output line should consist of one integer, the coefficient of the monomial x1n1x2n2...xknk in expansion of the polynomial (x1 + x2 + ... + xk)n.
 
 Sample Input
 
 2 2
 1 1
 2 12
 1 0 0 0 0 0 0 0 0 0 1 0
 Sample Output
 
 2
 2
*/