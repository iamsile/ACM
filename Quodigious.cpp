#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned n,l=1;
    while (cin >> n&&n) {
        unsigned i,j,k,lab,sum,flag;
        if(l++>1)
            cout << '\n';
        for (i=(unsigned)pow(10, n-1); i<=(unsigned)pow(10, n)-1; i++) {
            j=i;sum=0;flag=1;lab=1;
            if (i==1)
                continue;
            while (j) {
                k=j%10;
                if (k<=1) {
                    flag=0;
                    break;
                }
                if (i%k) {
                    flag=0;
                    break;
                }
                sum+=k;
                lab*=k;
                j/=10;
            }
            if (flag&&i%lab==0)
                if (i%sum==0)
                    cout << i << '\n';
        }
    }
    return 0;
}
/*
 Problem description
 According to Dr. Rich, a quodigious number is a positive decimal number whose digits are each greater than 1, and which is evenly divisible by both the sum and product of its digits. For example, 735 is a quodigious number since its digits 7, 3 and 5 are each greater than 1, and 735 is evenly divisible (with zero remainder) by 7 · 3 · 5 = 105 and 7 + 3 + 5 = 15. In this program, we will find and print quodigious numbers.
 
 Input
 The input consists of one or more positive integers, each representing a number of decimal digits n < 10.
 
 Output
 For each number n in the input, output all n-digit quodigious numbers on successive lines, followed by an empty line.
 
 Sample Input
 1 2 3 4
 Sample Output
 2
 3
 4
 5
 6
 7
 8
 9
 
 24
 36
 
 224
 432
 624
 735
 
 2232
 3276
 4224
 6624
*/