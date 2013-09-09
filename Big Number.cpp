#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned int t;
    cin >> t;
    while (t--) {
        double i,n,sum=0;
        cin >> n;
        for (i=1; i<=n; i++)
            sum+=log10(i);
        cout << (int)sum+1 << '\n';
    }
}
/*
推导以下公式：
n!=n*(n-1)*(n-2)*…..*1
N的位数=[lg(N)]+1;
所以：n!的位数=[lg(n*(n-1)*(n-2)*…..*1)]+1=[lgn+lg(n-1)+lg[n-2]+….+lg1]+1;
*/
/*
 Problem Description
 In many applications very large integers numbers are required. Some of these applications are using keys for secure transmission of data, encryption, etc. In this problem you are given a number, you have to determine the number of digits in the factorial of the number.
 
 
 Input
 Input consists of several lines of integer numbers. The first line contains an integer n, which is the number of cases to be tested, followed by n lines, one integer 1 ≤ n ≤ 107 on each line.
 
 
 Output
 The output contains the number of digits in the factorial of the integers appearing in the input.
 
 
 Sample Input
 2
 10
 20
 
 
 Sample Output
 7
 19
*/