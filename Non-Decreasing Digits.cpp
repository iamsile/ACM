#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long i,j,n,d,a[1001],b[1001];
        long long sum=0;
        cin >> n >> d;
        for (i=1; i<=10; i++) {
            a[i]=0;
            b[i]=1;
        }
        d--;
        while (d--) {
            for (i=1; i<=10; i++)
                for (j=1; j<=i; j++) 
                    a[i]+=b[j];
            for (i=1; i<=10; i++) {
                b[i]=a[i];
                a[i]=0;
            }
        }
        for (i=1; i<=10; i++)
            sum+=b[i];
        cout << n << ' ' << sum << '\n';
    }
    return 0;
}
//f(a,b)表示长度为b的数字，最左边的是a的递增数的个数
//方程就是f(a,b)=f(a+1,b)+f(a,b-1)
/*
 Problem description
 A number is said to be made up of non-decreasing digits if all the digits to the left of any digit is less than or equal to that digit. For example, the four-digit number 1234 is composed of digits that are non-decreasing. Some other four-digit numbers that are composed of non-decreasing digits are 0011, 1111, 1112, 1122, 2223. As it turns out, there are exactly 715 four-digit numbers composed of non-decreasing digits.
 Notice that leading zeroes are required: 0000, 0001, 0002 are all valid four-digit numbers with nondecreasing digits.
 For this problem, you will write a program that determines how many such numbers there are with a specified number of digits.
 
 
 Input
 The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number of digits N, (1 ≤ N ≤ 64).
 
 Output
 For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of N digit values that are composed entirely of non-decreasing digits.
 
 Sample Input
 3
 1 2
 2 3
 3 4
 Sample Output
 1 55
 2 220
 3 715
*/