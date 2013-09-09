#include <iostream>
using namespace std;

int mins(char s[],int len)
{
    int i=0,j=1,k=0,t;
    while (i<len&&j<len&&k<len) {
        t=s[(i+k)%len]-s[(j+k)%len];
        if (!t)
            k++;
        else {
            if (t>0)
                i=i+k+1;
            else j=j+k+1;
            if (i==j) j++;
            k=0;
        }
    }
    return min(i, j);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        char a[100010];
        scanf("%d%s",&n,a);
        m=mins(a,n);
        printf("%d\n",m);
    }
    return 0;
}
/*
 Description 
 
 Some time the programmers have very strange ways to hide their passwords. See for example
 how Billy “Hacker” Geits hide his password. Billy chooses a string S composed of small Latin letters with length L. Then he makes all L-1 one-letter left cyclic shifts of the string and takes as a password one prefix of the lexicographically first of the obtained strings (including S). For example let consider the string alabala. The cyclic one-letter left shifts (including the initial string) are:
 alabala
 labalaa
 abalaal
 balaala
 alaalab
 laalaba
 aalabal
 and lexicographically first of them is the string aalabal. The first letter of this string is in position 6 in the initial string (the positions in the string are counted from 0).
 Write a program that for given string S finds the start position of the smallest lexicographically one-letter left cyclic shift of this string. If the smallest lexicographically left shift appears more than once then the program have to output the smallest initial position.
 Input 
 
 Your program has to be ready to solve more than one test case. The first line of the input file will contains only the number T of the test cases. Each of the following T lines will describe one test case – first the length L of the string (5≤L≤100000) and then, separated by one space, the string S itself.
 
 Output 
 
 The output file have to contain exactly T lines with a single number each – the initial position found by your program.
 
 Sample Input 
 
 2
 6 baabaa
 7 alabala
 Sample Output 
 
 1
 6
*/