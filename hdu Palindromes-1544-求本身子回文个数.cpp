#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[10000];
    while (scanf("%s",a)!=EOF) {
        int i,j,k=(int)strlen(a),sum=0;
        for (i=0; i<k; i++) {
            if (i>0)
                for (j=0; j<i&&j+i<k; j++) {
                    if (a[i-j-1]!=a[i+j])
                        break;
                    sum++;
                }
            for (j=0; j<=i&&j+i<k; j++) {
                if (a[i-j]!=a[i+j])
                    break;
                sum++;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem Description
 A regular palindrome is a string of numbers or letters that is the same forward as backward. For example, the string "ABCDEDCBA" is a palindrome because it is the same when the string is read from left to right as when the string is read from right to left.
 
 Now give you a string S, you should count how many palindromes in any consecutive substring of S.
 
 
 Input
 There are several test cases in the input. Each case contains a non-empty string which has no more than 5000 characters.
 
 Proceed to the end of file.
 
 
 Output
 A single line with the number of palindrome substrings for each case. 
 
 
 Sample Input
 aba
 aa
 
 
 Sample Output
 4
 3
*/