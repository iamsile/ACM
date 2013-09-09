#include <iostream>
using namespace std;

int main()
{
    int i,n,j,a[32]={1,0},b[1001];
    for (i=1; i<=30; i++)
        a[i]=2*a[i-1]+1;//每位的权都存入a[]
    while (scanf("%d",&n)&&n!=-1) {
        if (!n)
            cout << "0 []\n";
        else {
            i=30;j=0;
            cout << n << " [";
            while (n) {
                while (n>=a[i]) {
                    b[j++]=i;//找到符合条件的权存入数组b[]
                    n-=a[i];
                }
                i--;
            }
            sort(b, b+j);
            for (i=0; i<j; i++) {
                if (i)
                    cout << ',';
                cout << b[i];
            }
            cout << "]\n";
        }
    }
    return 0;
}
/*
 Problem description
 Number representations are made up of a list of digits. Call the lowest order digit the rank 0 digit, the next, rank 1, etc. For example, in decimal representation, digits are 0-9, the rank 0 digit has weight 1, the rank 1 digit has weight 10, and the rank i digit has weight 10i. In binary representation, the digits are 0 and 1, and the rank i digit has weight 2i. In skew binary representation, the digits are 0, 1, and 2, and the rank i digit has weight 2(i+1) -1. 
 Rank       Weight
 
 0           1
 1           3
 2           7
 3           15
 4           31
 5           63
 6           127
 7           255
 
 :           :
 Allowing the digit 2 in the skew binary means there may be several ways to represent a given number. However the convention is that the digit 2 may only appear as the lowest rank non-zero digit. This makes the representation unique. 
 
 In this problem, you should use a special way to write skew binary numbers as a list of ranks of non-zero digits in the number. The digit 2 is represented by the rank of the digit appearing twice in the list. Note that this means that only the first two ranks in the list may be equal. 
 
 Each rank is a decimal integer, and is separated from the next rank by a comma (','). A list is started by a '[' and ended by a ']'. For example, the decimal number 5, which has the skew representation 12, should be written as [0,0,1]. Decimal 0 is an empty list: []. 
 
 
 Input
 Input consists of decimal numbers, one per line, Each line of input contains a single integer n, (0<=n<=100000000). The end-of-file is denoted by a single line containing the number -1. 
 
 Output
 There should be one line per test case containing the input decimal number, with no leading zeros or spaces, a single space, and the skew binary equivalent in list format with no leading or trailing spaces.And they must be arranged in increasing order. Within the list each rank should have no extra leading zeros or leading or trailing spaces. 
 
 Sample Input
 0
 1
 2
 3
 4
 -1
 Sample Output
 0 []
 1 [0]
 2 [0,0]
 3 [1]
 4 [0,1]
*/