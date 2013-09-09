#include <iostream>
using namespace std;

int main()
{
    char a[1001];
    while (cin >> a&&a[0]!='#') {
        int i,k=strlen(a),flag=1;
        for (i=0; i<k; i++) {
            if (a[i]!='b'&&a[i]!='d'&&a[i]!='p'&&a[i]!='q'
                &&a[i]!='i'&&a[i]!='o'&&a[i]!='v'&&a[i]!='w'
                &&a[i]!='x') {
                flag=0;
                break;
            }
            if (a[i]=='b')
                a[i]='d';
            else if (a[i]=='d')
                a[i]='b';
            else if (a[i]=='p')
                a[i]='q';
            else if (a[i]=='q')
                a[i]='p';
        }
        if (flag) {
            for (i=k-1; i>=0; i--)
                cout << a[i];
            cout << '\n';
        }
        else cout << "INVALID\n";
    }
    return 0;
}
/*
 Problem description
 For most fonts, the lowercase letters b and d are mirror images of each other, as are the letters p and q. Furthermore, letters i, o, v, w, and x are naturally mirror images of themselves. Although other symmetries exists for certain fonts, we consider only those specifically mentioned thus far for the remainder of this problem. 
 
 Because of these symmetries, it is possible to encode certain words based upon how those words would appear in the mirror. For example the word boxwood would appear as boowxod, and the word ibid as bidi. Given a particular sequence of letters, you are to determine its mirror image or to note that it is invalid.
 
 Input
 The input contains a series of letter sequences, one per line, followed by a single line with the # character. Each letter sequence consists entirely of lowercase letters.
 
 Output
 For each letter sequence in the input, if its mirror image is a legitimate letter sequence based upon the given symmetries, then output that mirror image. If the mirror image does not form a legitimate sequence of characters, then output the word INVALID.
 
 Sample Input
 boowxod
 bidi
 bed
 bbb
 #
 Sample Output
 boxwood
 ibid
 INVALID
 ddd
*/