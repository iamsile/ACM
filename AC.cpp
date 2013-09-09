#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        char c;
        int i,n,m,sum=1;
        cin >> c >> n >> m;
        if (c=='A') {
            m=n-m;
            if (m==0)
                m=1;
            for (; n>m; n--)
                sum*=n;
        }
        else {
            for (i=1; i<=m; i++)
                sum=sum*(n-m+i)/i;
        }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem Description
 Are you excited when you see the title "AC" ? If the answer is YES , AC it ;
 
 You must learn these two combination formulas in the school . If you have forgotten it , see the picture.
 
 
 
 
 Now I will give you n and m , and your task is to calculate the answer .
 
 
 Input
 In the first line , there is a integer T indicates the number of test cases.
 Then T cases follows in the T lines.
 Each case contains a character 'A' or 'C', two integers represent n and m. (1<=n,m<=10)
 
 
 Output
 For each case , if the character is 'A' , calculate A(m,n),and if the character is 'C' , calculate C(m,n).
 And print the answer in a single line.
 
 
 Sample Input
 2
 A 10 10
 C 4 2
 
 
 Sample Output
 3628800
 6
*/