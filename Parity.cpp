#include <iostream>
using namespace::std;

int main()
{
    while (1) {
        char a[32];
        int i,num=0;
        memset(a, 0, sizeof(a));
        cin >> a;
        if (a[0]=='#')
            return 0;
        for (i=0; i<strlen(a)-1; i++) 
        {
            if (a[i]=='1')
                num++;
            printf("%c",a[i]);
        }
        if (a[i]=='e'&&num%2==0)
            cout << "0\n";
        else if (a[i]=='e'&&num%2)
            cout << "1\n";
        if (a[i]=='o'&&num%2==0)
            cout << "1\n";
        else if (a[i]=='o'&&num%2)
            cout << "0\n";
    }
}
/*
 Problem description
 A bit string has odd parity if the number of 1's is odd. A bit string has even parity if the number of 1's is even. Zero is considered to be an even number, so a bit string with no 1's has even parity. Note that the number of 0's does not affect the parity of a bit string.
 
 
 
 Input
 The input consists of one or more strings, each on a line by itself, followed by a line containing only "#" that signals the end of the input. Each string contains 1–31 bits followed by either a lowercase letter 'e' or a lowercase letter 'o'.
 
 Output
 Each line of output must look just like the corresponding line of input, except that the letter at the end is replaced by the correct bit so that the entire bit string has even parity (if the letter was 'e') or odd parity (if the letter was 'o').
 
 Sample Input
 101e
 010010o
 1e
 000e
 110100101o
 # 
 Sample Output
 1010
 0100101
 11
 0000
 1101001010
*/