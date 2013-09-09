#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char b[1000010];
    while (scanf("%s",b)!=EOF) {
        if (b[0]=='0')
            break;
        string a=b,b1="b",b2="a",dd;
        int i,flag=0,k=(int)a.size();
        if (k<3) {
            if (a=="b"||a=="ab"||a=="a")
                flag=1;
        }
        else {
            for (i=0; ; i++) {
                dd=b2+b1;
                if (a==dd) {
                    flag=1;
                    break;
                }else {
                    b1=b2;
                    b2=dd;
                }
                if (dd.size()>a.size()) {
                    flag=0;
                    break;
                }
            }
        }
        if (flag)
            cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}
/*
 Problem description
 The Fibnacci string is as follows:
 S1=b
 S2=a
 Sk=Sk-1Sk-2 k>2
 We are given a string, is there a Fibnacci string? 
 
 Input
 The input will consist of a series of string, one string per line, followed by a line containing only the char ‘0’ that signals the end of the input file and need not to be processed.
 You may assume that the length of each string is no more than 1,000,000.
 
 
 Output
 For each string you should output the ‘true’ if the string is a Fibnacci string, or ‘false’ if the string is not a Fibnacci string and with one line of output for each line in input. 
 
 Sample Input
 abaab
 abaababa
 abaababaababa
 0
 Sample Output
 true
 true
 false
*/