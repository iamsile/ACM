#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long double n;
    while (cin >> n) {
        long double m1=log2l(n),m2=log2l(n+1),m=ceill(log10l(n+0.5))+1;
        for (; ceill(m1+m*log2l(10))!=floorl(m2+m*log2l(10)); m+=1) {}
        cout << ceill(m1+m*log2l(10)) << '\n';
    }
    return 0;
}//ceill取最小整数，floorl取最大整数
/*
 digits. We are searching for N, 
 that the prefix of 2^N is P. 
 We have an inequlity of
 P*10^T <= 2^N < (P+1)*10^T
 thus
 log2(P*10^T) <= log2(2^N) < log2((P+1)*10^T),
 which is
 log2(P)+T*log2(10) <= N < log2(P+1)+T*log2(10).
 Also, we know that
 P < 10^(T-1),
 that is
 T > log10(P)+1.
 Then, we can brute force on T and find the minmum N.*/
/*
 An archaeologist, seeking proof of the presence of extraterrestrials in the Earth's past, has stumbled upon a partially destroyed wall containing strange chains of numbers. The left-hand part of these lines of digits is always intact, but unfortunately the right-hand one is often lost because of erosion of the stone. However, she notices that all the numbers with all its digits intact are powers of 2, so that the hypothesis that all of them are powers of 2 is obvious. To reinforce her belief, she selects a list of numbers on which it is apparent that the number of legible digits is strictly smaller than the number of lost ones, and asks you to find the smallest power of 2 (if any) whose first digits coincide with those of the list.
 
 Thus you must write a program that, given an integer, determines the smallest exponent E (if it exists) such that the first digits of 2E coincide with the integer (remember that more than half of the digits are missing).
 
 Input
 
 Each line contains a positive integer N not bigger than 2,147,483,648.
 
 Output
 
 For every one of these integers, print a line containing the smallest positive integer E such that the first digits of 2E are precisely the digits of N, or, if there isn't one, the sentence ``no power of 2".
 
 Sample Input
 
 1
 2
 10
 Sample Output
 
 7
 8
 20
*/