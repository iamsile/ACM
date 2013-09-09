#include<iostream>
using namespace::std;

int main()
{
    bool a[1000000];
    int i,j,n;
    memset(a, 1, sizeof(a));
    for(i=2;i<1000000;i++)
        if(a[i])
            for(j=2;j<1000000/i;j++)
                a[i+i*j]=0;
    while(cin >> n&&n)
    {
        for(i=3;i<=n;i+=2)
            if(a[i]&&a[n-i])
                break;
        printf("%d = %d + %d\n",n,i,n-i);
    }
    return 0;
}
/*
 Problem description
 In 1742, Christian Goldbach, a German amateur mathematician, sent a letter to Leonhard Euler in which he made the following conjecture:
 
 Every even number greater than 4 can be written as the sum of two odd prime numbers. 
 
 For example: 
 
 8 = 3 + 5. Both 3 and 5 are odd prime numbers. 
 20 = 3 + 17 = 7 + 13. 
 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23. 
 Today it is still unproven whether the conjecture is right. (Oh wait, I have the proof of course, but it is too long to write it on the margin of this page.) 
 Anyway, your task is now to verify Goldbach's conjecture for all even numbers less than a million.
 
 
 Input
 The input will contain one or more test cases. Each test case consists of one even integer n with 6 <= n < 1000000. Input will be terminated by a value of 0 for n. 
 
 
 Output
 For each test case, print one line of the form n = a + b, where a and b are odd primes. Numbers and operators should be separated by exactly one blank like in the sample output below. If there is more than one pair of odd primes adding up to n, choose the pair where the difference b - a is maximized. If there is no such pair, print a line saying "Goldbach's conjecture is wrong."
 
 
 Sample Input
 8
 20
 42
 0
 Sample Output
 8 = 3 + 5
 20 = 3 + 17
 42 = 5 + 37
*/