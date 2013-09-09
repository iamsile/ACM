#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,n,m,len=1,num=0,a[1001];
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        a[0]=1;
        for (i=1; i<=n; i++) {
            for (j=0; j<len; j++)
                a[j]*=i;
            for (j=0; j<len; j++)
                if (a[j]>9) {
                    a[j+1]+=a[j]/10;
                    a[j]%=10;
                    if (j+1==len)
                        len++;
                }
        }
        for (i=0; i<len; i++)
            if (a[i]==m)
                num++;
        cout << num << '\n';
    }
    return 0;
}
/*
 Problem description
 There is just one basic rule in the Idiot of the Year Contest (IYC)! The contestant picks a random digit between 0 and 9, computes the factorial of the day of the year he/she is born, and counts the how many times the digit picked appears in the factorial. The contestant with highest count is the Idiot of the Year! For example, if you are born on 5th of Mordad which is the 129th day of the year, and you pick the digit 6, your score will be the number of times the digit 6 appears in 129! (that is 1 × 2 × 3 × ... × 129).
 The chief judge of IYC wants you to write a program to get an integer which is the day of the year a contestant is born on and a digit and report the number of times the digit appears in the factorial of the first number.
 
 
 Input
 The first line of the input contains a single integer T which is the number of test cases, followed by T lines each containing the data for a test case having two numbers. The first number is the day of the year a contestant is born and the second one is the digit he/she has picked.
 
 Output
 The output contains T lines, each having one integer which is the number of times the digit appears in the factorial of the first number.
 
 Sample Input
 2
 5 2
 7 0
 Sample Output
 1
 2
*/