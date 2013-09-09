#include <stdio.h>
#include <math.h>
const long max=65001;
bool a[max];

void primes()
{
    int i,j,k=(int)sqrt(max);
    for (i=2; i<=max; i++)
        a[i]=true;
    for (i=2; i<=k; i++)
        if (a[i])
            for (j=i*i; j<=65000; j+=i)
                a[j]=false;
}

long mod(long x,long n,long p)
{
    if (n==1)
        return x%p;
    long ans=mod(x, n/2, p);
    ans=(ans*ans)%p;
    if (n%2==1)
        return ans*x%p;
    return ans;
}

int main()
{
    long n;
    primes();
    while (scanf("%ld",&n)!=EOF) {
        if (n==0)
            break;
        int i,flag=1;
        if (!a[n])
            for (i=2; i<n; i++)
                if (mod(i, n, n)!=i) {
                    flag=0;
                    break;
                }
        if (flag&&!a[n])
            printf("The number %ld is a Carmichael number.\n",n);
        else
            printf("%ld is normal.\n",n);
    }
    return 0;
}
/*
 
 
 
 Carmichael Numbers
 
 
 
 
 Certain cryptographic algorithms make use of big prime numbers. However, checking whether a big number is prime is not so easy.
 
 Randomized primality tests exist that offer a high degree of confidence of accurate determination at low cost, such as the Fermat test. Let a be a random number between 2 and n - 1, where n is the number whose primality we are testing. Then, n is probably prime if the following equation holds:
 
 an mod n = a
 If a number passes the Fermat test several times, then it is prime with a high probability.
 Unfortunately, there is bad news. Certain composite numbers (non-primes) still pass the Fermat test with every number smaller than themselves. These numbers are called Carmichael numbers.
 
 Write a program to test whether a given integer is a Carmichael number.
 
 Input
 
 The input will consist of a series of lines, each containing a small positive number n ( 2 < n < 65, 000). A number n = 0 will mark the end of the input, and must not be processed.
 Output
 
 For each number in the input, print whether it is a Carmichael number or not as shown in the sample output.
 Sample Input
 
 1729
 17
 561
 1109
 431
 0
 Sample Output
 
 The number 1729 is a Carmichael number.
 17 is normal.
 The number 561 is a Carmichael number.
 1109 is normal.
 431 is normal.
*/