#include <iostream>
#include <string.h>
using namespace::std;

int main()
{
    int t,flag=1;
    cin >> t;
    while (t--) {
        char a[1100],b[1100];
        int i,j,k,x,y,c[1100];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        cin >> a;
        cin >> b;
        if (strlen(a)>strlen(b)) {
            for (i=0; i<strlen(b); i++) {
                x=a[(int)strlen(a)-i-1]-'0';
                y=b[(int)strlen(b)-i-1]-'0';
                c[i]+=x+y;
                if (c[i]>9) {
                    c[i+1]=c[i]/10;
                    c[i]%=10;
                }
            }
            for (j=i,k=strlen(a)-i-1; k>=0; j++,k--) {
                c[j]+=a[k]-'0';
                if (c[j]>9) {
                    c[j+1]=c[j]/10;
                    c[j]%=10;
                }
            }
        }
        else {
            for (i=0; i<strlen(a); i++) {
                x=a[(int)strlen(a)-i-1]-'0';
                y=b[(int)strlen(b)-i-1]-'0';
                c[i]+=x+y;
                if (c[i]>9) {
                    c[i+1]=c[i]/10;
                    c[i]%=10;
                }
            }
            for (j=i,k=strlen(b)-i-1; k>=0; j++,k--) {
                c[j]+=b[k]-'0';
                if (c[j]>9) {
                    c[j+1]=c[j]/10;
                    c[j]%=10;
                }
            }
        }
        cout << "Case " << flag++ << ":\n";
        for (i=1009; i>=0; i--)
            if (c[i]!=0)
                break;
        cout << a << " + " << b << " = ";
        if (i+1==0)
            cout << "0\n";
        else {
            for (j=i; j>=0; j--)
                cout << c[j];
            cout << '\n';
        }
        if (t)
            cout << '\n';
    }
    return 0;
}
/*
 I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
 
 
 Input
 The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
 
 
 Output
 For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.
 
 
 Sample Input
 2
 1 2
 112233445566778899 998877665544332211
 
 
 Sample Output
 Case 1:
 1 + 2 = 3
 
 Case 2:
 112233445566778899 + 998877665544332211 = 1111111111111111110
*/