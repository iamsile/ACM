#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--) {
        char a[1100]={0},b[1100]={0};
        int i,lab=0;
        gets(a);
        for (i=0; i<=strlen(a);i++) {
            if (a[i]==' ') {
                reverse(b+lab, b+i);
                lab=i+1;
                b[i]=' ';
            }
            else if (a[i]=='\0')
            {
                reverse(b+lab, b+i);
            }
            else b[i]=a[i];
        }
        for (i=0; i<strlen(b); i++)
            cout << b[i];
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 Ignatius likes to write words in reverse way. Given a single line of text which is written by Ignatius, you should reverse all the words and then output them.
 
 
 Input
 The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
 Each test case contains a single line with several words. There will be at most 1000 characters in a line.
 
 
 Output
 For each test case, you should output the text which is processed.
 
 
 Sample Input
 3
 olleh !dlrow
 m'I morf .udh
 I ekil .mca
 
 
 Sample Output
 hello world!
 I'm from hdu.
 I like acm.
 
 Hint
 
 Remember to use getchar() to read '\n' after the interger T, then you may use gets() to read a line and process it.
*/