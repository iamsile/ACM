#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[110][110],mark[110][110],loc[110],cnt;
char a[110][40],b[110][40];

void print(int i, int j)
{
    if (i==0||j==0)
        return;
    else if (mark[i][j]==1) {
        print(i-1, j-1);
        loc[cnt++]=i-1;
    }
    else if (mark[i][j]==2)
        print(i-1, j);
    else if (mark[i][j]==3)
        print(i, j-1);
}

int main()
{
    char s[40];
    while (scanf("%s",s)!=EOF) {
        strcpy(a[0], s);
        int i,j,len1=1,len2=0;
        while (1) {
            cin >> a[len1++];
            if (a[len1-1][0]=='#')
                break;
        }
        while (1) {
            cin >> b[len2++];
            if (b[len2-1][0]=='#')
                break;
        }
        len1--;
        len2--;
        memset(dp, 0, sizeof(dp));
        for (i=1; i<=len1; i++)
            for (j=1; j<=len2; j++) {
                if (strcmp(a[i-1], b[j-1])==0) {
                    dp[i][j]=dp[i-1][j-1]+1;
                    mark[i][j]=1;
                }
                else {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                    if (dp[i-1][j]>dp[i][j-1])
                        mark[i][j]=2;
                    else 
                        mark[i][j]=3;
                }
            }
        memset(loc, 0, sizeof(loc));
        cnt=0;
        print(len1,len2);
        for (i=0; i<cnt; i++) {
            if (i)
                cout << ' ';
            cout << a[loc[i]];
        }
        cout << '\n';
    }
   
    return 0;
}
/*
 Description
 
 In a few months the European Currency Union will become a reality. However, to join the club, the Maastricht criteria must be fulfilled, and this is not a trivial task for the countries (maybe except for Luxembourg). To enforce that Germany will fulfill the criteria, our government has so many wonderful options (raise taxes, sell stocks, revalue the gold reserves,...) that it is really hard to choose what to do. 
 
 Therefore the German government requires a program for the following task: 
 Two politicians each enter their proposal of what to do. The computer then outputs the longest common subsequence of words that occurs in both proposals. As you can see, this is a totally fair compromise (after all, a common sequence of words is something what both people have in mind). 
 
 Your country needs this program, so your job is to write it for us.
 Input
 
 The input will contain several test cases. 
 Each test case consists of two texts. Each text is given as a sequence of lower-case words, separated by whitespace, but with no punctuation. Words will be less than 30 characters long. Both texts will contain less than 100 words and will be terminated by a line containing a single '#'. 
 Input is terminated by end of file.
 Output
 
 For each test case, print the longest common subsequence of words occuring in the two texts. If there is more than one such sequence, any one is acceptable. Separate the words by one blank. After the last word, output a newline character.
 Sample Input
 
 die einkommen der landwirte
 sind fuer die abgeordneten ein buch mit sieben siegeln
 um dem abzuhelfen
 muessen dringend alle subventionsgesetze verbessert werden
 #
 die steuern auf vermoegen und einkommen
 sollten nach meinung der abgeordneten
 nachdruecklich erhoben werden
 dazu muessen die kontrollbefugnisse der finanzbehoerden
 dringend verbessert werden
 #
 Sample Output
 
 die einkommen der abgeordneten muessen dringend verbessert werden
*/