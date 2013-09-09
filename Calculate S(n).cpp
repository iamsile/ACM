#include <iostream>
using namespace std;

int main()
{
    __int64 n;
    while (scanf("%I64d",&n)!=EOF) {
        __int64 m=((n*(n+1)/2)%10000)*((n*(n+1)/2)%10000)%10000;
        printf("%04I64d\n",m);
    }
    return 0;
}
/*
 Problem Description
 Calculate S(n).
 
 S(n)=13+23 +33 +......+n3 .
 
 
 Input
 Each line will contain one integer N(1 < n < 1000000000). Process to end of file.
 
 
 Output
 For each case, output the last four dights of S(N) in one line.
 
 
 Sample Input
 1
 2
 
 
 Sample Output
 0001
 0009
*/