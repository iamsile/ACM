#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int p[1000010];
int a[1000010];

int main()
{
    int i,j,len;
    memset(p, 0, sizeof(p));
    memset(a, 0, sizeof(a));
    len=0;
    for (i=2; i<1001; i++) {
        if (!p[i])
            for (j=2; j<=1000000/i; j++)
                p[i*j]=1;
    }
    for (i=2; i<1000000; i++)
        if (!p[i]) {
            len++;
            a[i]=len;
        }
    int n,k,prime;
    while (scanf("%d",&n)!=EOF) {
        if (1==n) {
            cout << "0\n";
            continue;
        }
        if (!p[n]) {
            cout << a[n] << '\n';
            continue;
        }
        k=(int)sqrt(n);
        prime=2;
        for (i=2; i<=k; i++) {
            if (n%i==0) {
                j=n/i;
                if (!p[i])
                    prime=i;
                if (!p[j]) {
                    prime=j;
                    break;
                }
            }
        }
        cout << a[prime] << '\n';
    }
    return 0;
}
/*
 Problem Description
 Everybody knows any number can be combined by the prime number.
 Now, your task is telling me what position of the largest prime factor.
 The position of prime 2 is 1, prime 3 is 2, and prime 5 is 3, etc.
 Specially, LPF(1) = 0.
 
 
 Input
 Each line will contain one integer n(0 < n < 1000000).
 
 
 Output
 Output the LPF(n).
 
 
 Sample Input
 1
 2
 3
 4
 5
 
 
 Sample Output
 0
 1
 2
 1
 3
*/