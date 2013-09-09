#include <iostream>
using namespace std;
bool ok[202][202];
char a[202],b[202],c[422];

int main()
{
    int t,n=1;
    cin >> t;
    while (t--) {
        int i,j,len1,len2;
        scanf("%s%s%s",a,b,c);
        memset(ok, false, sizeof(ok));
        len1=(int)strlen(a);
        len2=(int)strlen(b);
        ok[0][0]=true;
        for (i=1; i<=len1; i++)
            if (a[i-1]==c[i-1]&&ok[i-1][0])
                ok[i][0]=true;
            else break;
        for (i=1; i<=len2; i++)
            if (b[i-1]==c[i-1]&&ok[0][i-1])
                ok[0][i]=true;
            else break;
        for (i=1; i<=len1; i++)
            for (j=1; j<=len2; j++)
                if ((ok[i-1][j]&&a[i-1]==c[i+j-1])||(ok[i][j-1]&&b[j-1]==c[i+j-1]))
                        ok[i][j]=true;
                else ok[i][j]=false;
        if (ok[len1][len2])
            cout << "Data set " << n++ << ": yes\n";
        else cout << "Data set " << n++ << ": no\n";
    }
    return 0;
}
/*
 Problem description
 Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but each must stay in its original order. 
 
 For example, consider forming "tcraete" from "cat" and "tree": 
 
 String A: cat 
 String B: tree 
 String C: tcraete 
 
 As you can see, we can form the third string by alternating characters from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree": 
 
 String A: cat 
 String B: tree 
 String C: catrtee 
 
 Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
 
 Input
 The first line of input contains a single positive integer from 1 through 1000. It represents the number of data sets to follow. The processing for each data set is identical. The data sets appear on the following lines, one data set per line. 
 
 For each data set, the line of input consists of three strings, separated by a single space. All strings are composed of upper and lower case letters only. The length of the third string is always the sum of the lengths of the first two strings. The first two strings will have lengths between 1 and 200 characters, inclusive. 
 
 
 Output
 For each data set, print: 
 
 Data set n: yes 
 
 if the third string can be formed from the first two, or 
 
 Data set n: no 
 
 if it cannot. Of course n should be replaced by the data set number. See the sample output below for an example.
 
 Sample Input
 3
 cat tree tcraete
 cat tree catrtee
 cat tree cttaree
 Sample Output
 Data set 1: yes
 Data set 2: yes
 Data set 3: no
*/