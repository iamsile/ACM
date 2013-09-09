#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    char a[100],b[100];
    while (cin >> a >> b >> n) {
        int i,j,f[60][26];
        memset(f, 0, sizeof(f));
        for (i=0; a[i]; i++)
            f[0][a[i]-97]++;
        for (i=0; b[i]; i++)
            f[1][b[i]-97]++;
        for (i=2; i<=n; i++)
            for (j=0; j<26; j++)
                f[i][j]=f[i-1][j]+f[i-2][j];
        for (i=0; i<26; i++)
            cout << (char)(i+'a') << ':' << f[n][i] << '\n';
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 After little Jim learned Fibonacci Number in the class , he was very interest in it.
 Now he is thinking about a new thing -- Fibonacci String .
 
 He defines : str[n] = str[n-1] + str[n-2] ( n > 1 ) 
 
 He is so crazying that if someone gives him two strings str[0] and str[1], he will calculate the str[2],str[3],str[4] , str[5].... 
 
 For example :
 If str[0] = "ab"; str[1] = "bc";
 he will get the result , str[2]="abbc", str[3]="bcabbc" , str[4]="abbcbcabbc" …………;
 
 As the string is too long ,Jim can't write down all the strings in paper. So he just want to know how many times each letter appears in Kth Fibonacci String . Can you help him ?
 
 
 Input
 The first line contains a integer N which indicates the number of test cases.
 Then N cases follow.
 In each case,there are two strings str[0], str[1] and a integer K (0 <= K < 50) which are separated by a blank.
 The string in the input will only contains less than 30 low-case letters.
 
 
 Output
 For each case,you should count how many times each letter appears in the Kth Fibonacci String and print out them in the format "X:N". 
 If you still have some questions, look the sample output carefully.
 Please output a blank line after each test case.
 
 To make the problem easier, you can assume the result will in the range of int. 
 
 
 Sample Input
 1
 ab bc 3
 
 
 Sample Output
 a:1
 b:3
 c:2
 d:0
 e:0
 f:0
 g:0
 h:0
 i:0
 j:0
 k:0
 l:0
 m:0
 n:0
 o:0
 p:0
 q:0
 r:0
 s:0
 t:0
 u:0
 v:0
 w:0
 x:0
 y:0
 z:0
*/