#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--) {
        char a[1100];
        int i;
        gets(a);
        for (i=strlen(a)-1; i>=0; i--)
            cout << a[i];
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 In most languages, text is written from left to right. However, there are other languages where text is read and written from right to left. As a first step towards a program that automatically translates from a left-to-right language into a right-to-left language and back, you are to write a program that changes the direction of a given text. 
 
 
 Input
 The input contains several test cases. The first line contains an integer specifying the number of test cases. Each test case consists of a single line of text which contains at most 70 characters. However, the newline character at the end of each line is not considered to be part of the line.
 
 
 Output
 For each test case, print a line containing the characters of the input line in reverse order.
 
 
 Sample Input
 3
 Frankly, I don't think we'll make much
 money out of this scheme.
 madam I'm adam
 
 
 Sample Output
 hcum ekam ll'ew kniht t'nod I ,ylknarF
 .emehcs siht fo tuo yenom
 mada m'I madam
*/