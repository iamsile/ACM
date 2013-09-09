#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        double n;
        cin >> n;
        double r=-n*log10(2)-1;
        double k=(double)pow(10, -n*log10(2)-(int)r);
        printf("2^-%d = %.3fE%d\n",(int)n,k,(int)r);
    }
    return 0;
}
//2^-n=10^(-nlg2)，所以指数部分就是r=-nlg2-1,实数部分就是10^(-nlg2-r); 
/*
 Problem description
 The probability of n heads in a row tossing a fair coin is 2-n 
 
 Input
 The first line of the input contains an integer r. Then r lines containing each one an integer number n. The value of n is as follows: 0 < n ≤ 9000. 
 
 Output
 Print r lines each with the value of 2-n for the given values of n, using the format:
 
 2^-n = x.xxxE-y
 
 
 where each x is a decimal digit and each y is a decimal integer with no leading zeroes or spaces. 
 
 
 Sample Input
 3
 8271
 6000
 1
 
 Sample Output
 2^-8271 = 1.517E-2490
 2^-6000 = 6.607E-1807
 2^-1 = 5.000E-1
*/