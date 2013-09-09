#include <iostream>
#include <stdio.h>
using namespace std;
#define maxn 1000001
int a[1000009];

void prime()
{
    int i,j;
    for (i=2; i<=maxn; i++)
        a[i]=0;
    a[1]=1;
    for (i=2; i<=maxn; i++)
        if (!a[i])
            for (j=i; j<=maxn; j+=i) {
                if (!a[j])
                    a[j]=j;
                a[j]=a[j]/i*(i-1);
            }
}

int main()
{
    int n;
    prime();
    while (scanf("%d",&n)!=EOF) {
        cout << a[a[n]-1] << '\n';
    }
    return 0;
}
/*
 Description
 
 We say that integer x, 0 < x < p, is a primitive root modulo odd prime p if and only if the set { (xi mod p) | 1 <= i <= p-1 } is equal to { 1, ..., p-1 }. For example, the consecutive powers of 3 modulo 7 are 3, 2, 6, 4, 5, 1, and thus 3 is a primitive root modulo 7. 
 Write a program which given any odd prime 3 <= p < 65536 outputs the number of primitive roots modulo p. 
 Input
 
 Each line of the input contains an odd prime numbers p. Input is terminated by the end-of-file seperator.
 Output
 
 For each p, print a single number that gives the number of primitive roots in a single line.
 Sample Input
 
 23
 31
 79
 Sample Output
 
 10
 8
 24
*/