#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string a;
    while (getline(cin, a)) {
        map<string, int> dic;
        const char *s=a.c_str();
        int i,j,k=a.size(),f=0,r=1;
        string b[100];
        for (i=0; i<k; i++)
            for (j=i; j<k; j++) {
                string c(s+i,s+j+1);
                dic[c]=1;
            }
        b[0]="";
        while (f<r) {
            string t=b[f];
            string la=t+"a";
            if (dic[la]==0) {
                cout << la;
                break;
            }
            b[r++]=la;
            string lb=t+"b";
            if (dic[lb]==0) {
                cout << lb;
                break;
            }
            b[r++]=lb;
            string lc=t+"c";
            if (dic[lc]==0) {
                cout << lc;
                break;
            }
            b[r++]=lc;
            f++;
        }
        cout << " is absent from " << a << '\n';
    }
    return 0;
}
/*
 Problem description
 Given a string of symbols, it’s natural to look it over and see what substrings are present. In this problem, you are given a string and asked to consider what substrings are absent. Of course, a given string has finite length and therefore only finitely many substrings, so there are always infinitely many strings that don’t appear as substrings of a given string. We’ll seek to find the lexicographically least string that is absent from the given string.
 
 Input
 Each line of input contains a string x over the alphabet {a, b, c}. x may be the empty string, as shown in the second line of the input sample below, or a nonempty string.
 
 Output
 For each input string x, find and output the lexicographically least string s over the alphabet {a, b, c} such that s is not a substring of x; i.e. s is absent from x. Since the empty string is a substring of every string, your output s is necessarily nonempty. Recall that a string is lexicographically less than another string if it is shorter or is the same length and alphabetically less; e.g. b< aa, abc< acb. Format each line of output to show s and x, as shown in the output sample below.
 
 Sample Input
 bcabacbaa
 
 aaabacbbcacc
 Sample Output
 bb is absent from bcabacbaa
 a is absent from 
 aac is absent from aaabacbbcacc
*/