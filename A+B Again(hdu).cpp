#include <stdio.h>

int main()
{
    __int64 a,b;
    while (scanf("%I64x%I64x",&a,&b)!=EOF) {
        if (a+b<0)
            printf("-%I64X\n",-a-b);
        else
            printf("%I64X\n",a+b);
    }
    return 0;
}
/*
 Problem Description
 There must be many A + B problems in our HDOJ , now a new one is coming.
 Give you two hexadecimal integers , your task is to calculate the sum of them,and print it in hexadecimal too.
 Easy ? AC it !
 Input
 The input contains several test cases, please process to the end of the file.
 Each case consists of two hexadecimal integers A and B in a line seperated by a blank.
 The length of A and B is less than 15.
 Output
 For each test case,print the sum of A and B in hexadecimal in one line.
 Sample Input
 +A -A
 +1A 12
 1A -9
 -1A -12
 1A -AA
 Sample Output
 0
 2C
 11
 -2C
 -90
*/