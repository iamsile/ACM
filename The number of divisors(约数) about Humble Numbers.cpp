#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

__int64 cal(__int64 n,__int64 m)
{
    __int64 k=0;
    while (n!=1) {
        if (n%m==0) {
            k++;
            n/=m;
        }
        else break;
    }
    return k;
}

int main()
{
    __int64 n;
    while (scanf("%I64d",&n)&&n) {
        __int64 a=1,b=1,c=1,d=1,num=0;
        a+=cal(n,2);
        b+=cal(n,3);
        c+=cal(n,5);
        d+=cal(n,7);
        num=a*b*c*d;
        printf("%I64d\n",num);
    }
    return 0;
}
/*
 Problem Description
 A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers. 
 
 Now given a humble number, please write a program to calculate the number of divisors about this humble number.For examle, 4 is a humble,and it have 3 divisors(1,2,4);12 have 6 divisors.
 
 
 
 Input
 The input consists of multiple test cases. Each test case consists of one humble number n,and n is in the range of 64-bits signed integer. Input is terminated by a value of zero for n.
 
 
 Output
 For each test case, output its divisor number, one line per case.
 
 
 Sample Input
 4
 12
 0
 
 
 Sample Output
 3
 6
*/