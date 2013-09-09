#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long n,sum=0;
        cin >> n;
        if (n>9) {
        here: while (n) {
                sum+=n%10;
                n/=10;
            }
        if (sum>9) {
            n=sum;
            sum=0;
            goto here;
        }
            else cout << sum << '\n';
        }
        else cout << n << '\n';
    }
    return 0;
}
/*
 Problem description
 Let Compression of an integer a be the sum of all digits of a and yields another positive integer. It is obvious that if we compress a number for certain finite steps, we will reach a one digit number. You are given a positive integer a and you are asked to output a one digit number which is created by compression of .
 For instance, if you are given a number 86, after one step of compression, we will reach number 8+6=14 , and after another step of compression, we reach 1+4=5. So, you should write 5 to the output.
 
 
 Input
 The number of test cases comes in the first line. For each test case you are given a positive integer a.
 
 Output
 For each test case, write one digit number that you will reach after some steps of compression.
 
 Sample Input
 3
 43
 111
 57871
 Sample Output
 7
 3
 1
*/