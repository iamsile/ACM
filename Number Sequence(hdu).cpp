#include <iostream>
using namespace std;

long long cal(long long a,long long b,long long k)
{
    if (k==1||k==2)
        return 1;
    else 
        return (a*cal(a, b, k-1)+b*cal(a, b, k-2))%7;
}

int main()
{
    long long n,m,k;
    while (cin >> n >> m >> k) {
        if (!n&&!m&&!k)
            return 0;
        if (k>48)
            k%=48;
        long long num=cal(n,m,k);
        cout << num << '\n';
    }
    return 0;
}
/*
 Problem Description
 A number sequence is defined as follows:
 
 f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
 
 Given A, B, and n, you are to calculate the value of f(n).
 Input
 The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
 Output
 For each test case, print the value of f(n) on a single line.
 Sample Input
 1 1 3
 1 2 10
 0 0 0
 Sample Output
 2
 5
*/