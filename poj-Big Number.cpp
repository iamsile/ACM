#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.1415926
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int len=(n*log(n)-n+0.5*(log(2*n*pi)))/log(10);
        cout << len+1 << '\n';
    }
}
//lnN!=NlnN－N+0.5ln(2N*pi),一个数M的位数是等于log10(M)取整后加1
/*
 Description
 
 In many applications very large integers numbers are required. Some of these applications are using keys for secure transmission of data, encryption, etc. In this problem you are given a number, you have to determine the number of digits in the factorial of the number.
 Input
 
 Input consists of several lines of integer numbers. The first line contains an integer n, which is the number of cases to be tested, followed by n lines, one integer 1 <= m <= 10^7 on each line.
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