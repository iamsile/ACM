#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    __int64 n;
    while (scanf("%I64d",&n),n) {
        __int64 i,m=n,ans=n;
        for (i=2; i<=sqrt((double)n); i++) {
            if (n%i==0)
                ans=ans/i*(i-1);
            while (n%i==0)
                n/=i;
        }
        if (n!=1)
            ans=ans/n*(n-1);
        printf("%I64d\n",m-1-ans);
    }
    return 0;
}
/*
 Problem Description
 Do you have spent some time to think and try to solve those unsolved problem after one ACM contest?
 No? Oh, you must do this when you want to become a "Big Cattle".
 Now you will find that this problem is so familiar:
 The greatest common divisor GCD (a, b) of two positive integers a and b, sometimes written (a, b), is the largest divisor common to a and b. For example, (1, 2) =1, (12, 18) =6. (a, b) can be easily found by the Euclidean algorithm. Now I am considering a little more difficult problem:
 Given an integer N, please count the number of the integers M (0<M<N) which satisfies (N,M)>1.
 This is a simple version of problem “GCD” which you have done in a contest recently,so I name this problem “GCD Again”.If you cannot solve it still,please take a good think about your method of study.
 Good Luck!
 
 
 Input
 Input contains multiple test cases. Each test case contains an integers N (1<N<100000000). A test case containing 0 terminates the input and this test case is not to be processed.
 
 
 Output
 For each integers N you should output the number of integers M in one line, and with one line of output for each line in input.
 
 
 Sample Input
 2
 4
 0
 
 
 Sample Output
 0
 1
*/