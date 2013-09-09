#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        char a[1001];
        int i;
        cin >> a;
        for (i=0; i<strlen(a); i++) {
            if (a[i]=='a'||a[i]=='e'||a[i]=='i'||
                a[i]=='o'||a[i]=='u')
                cout << (char)(a[i]-32);
            else if ((a[i]!='A'&&a[i]!='E'&&a[i]!='I'&&
                     a[i]!='O'&&a[i]!='U')&&(a[i]>='A'&&a[i]<='Z'))
                cout << char(a[i]+32);
            else cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 The "Vowel-Counting-Word"(VCW), complies with the following conditions.
 Each vowel in the word must be uppercase. 
 Each consonant (the letters except the vowels) must be lowercase.
 For example, "ApplE" is the VCW of "aPPle", "jUhUA" is the VCW of "Juhua".
 Give you some words; your task is to get the "Vowel-Counting-Word" of each word.
 
 
 Input
 The first line of the input contains an integer T (T<=20) which means the number of test cases.
 For each case, there is a line contains the word (only contains uppercase and lowercase). The length of the word is not greater than 50.
 
 
 Output
 For each case, output its Vowel-Counting-Word.
 
 
 Sample Input
 4
 XYz
 application
 qwcvb
 aeioOa 
 
 
 Sample Output
 xyz
 ApplIcAtIOn
 qwcvb
 AEIOOA
*/