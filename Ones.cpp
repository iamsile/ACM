#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int m=1,i;
        for(i=1;m%n!=0;i++){
            m=(m*10+1)%n;
        }
        cout << i << '\n';
    }
    return 0;
}
/*
 Given any integer 0n10, 000 not divisible by 2 or 5, some multiple of n is a number which in decimal notation is a sequence of 1's. How many digits are in the smallest such multiple of n?
 
 Input
 
 A file of integers at one integer per line.
 Output
 
 Each output line gives the smallest integer x > 0 such that p = 1 x 10i, where a is the corresponding input integer, p = a x b, and b is an integer greater than zero.
 Sample Input
 
 3
 7
 9901
 Sample Output
 
 3
 6
 12
*/