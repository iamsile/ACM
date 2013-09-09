#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool prime(unsigned k)
{
    if (k==2)
        return true;
    if (k%2==0)
        return false;
    for (long l=3; l<=(long)sqrt(k)+1; l+=2)
        if (k%l==0)
            return false;
    return true;
}

unsigned gcd(unsigned n)
{
    if (n==4)
        return 2;
    else {
        unsigned i,j=n/2;
        for (i=3; i<=j; i+=2)
            if (prime(i)&&prime(n-i))
                return i;
    }
}
    
int main()
{
    unsigned n;
    while (scanf("%u",&n)!=EOF) {
        unsigned k;
        if (n<=7)
            cout << "Impossible.\n";
        else if(n%2) {
            k=gcd(n-5);
            cout << "2 3 " << k << ' ' << n-5-k << '\n';
        }
        else {
            k=gcd(n-4);
            cout << "2 2 " << k << ' ' << n-4-k << '\n';
        }
    }
    return 0;
}
/*
 Waring's prime number conjecture states that every odd integer is either prime or the sum of three primes. Goldbach's conjecture is that every even integer is the sum of two primes. Both problems have been open for over 200 years.
 
 In this problem you have a slightly less demanding task. Find a way to express a given integer as the sum of exactly four primes.
 
 Input
 
 Each input case consists of one integer n ( n10000000) on its own line. Input is terminated by end of file.
 
 Output
 
 For each input case n, print one line of output containing four prime numbers which sum up to n. If the number cannot be expressed as a summation of four prime numbers print the line ``Impossible." in a single line. There can be multiple solutions. Any good solution will be accepted.
 
 Sample Input
 
 24
 36
 46
 Sample Output
 
 3 11 3 7
 3 7 13 13
 11 11 17 7
*/