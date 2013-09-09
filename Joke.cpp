#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long double a,b;
    while (cin >> a >> b) {
       cout << (long long)((a+1e-10)/b) << '\n';
    }
    return 0;
}
/*
 Problem description
 The problem is to cut the largest possible number of circles with diameter y out of a stripe of length x and width y.
 
 Input
 The only line of input consists of two positive real numbers x and y with 9-digit precision separated by spaces. The integers may be written without decimal point.
 
 Output
 Output a single integer — the maximum number of circles one can cut out of the stripe.
 
 Sample Input
 6.3 0.9
 0.63 0.09
 1 1
 Sample Output
 7
 7
 1
*/