#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[1001];
    while (cin >> a&&a[0]!='#') {
        int i,k=strlen(a),sum1=0,sum2=0,sum3=0,sum4=0;
        for (i=0; i<k; i++) {
            if (a[i]=='Y')
                sum1++;
            else if (a[i]=='N')
                sum2++;
            else if (a[i]=='P')
                sum3++;
            else if (a[i]=='A')
                sum4++;
        }
        if (sum4>=k/2&&k%2==0)
            cout << "need quorum\n";
        else if ((sum4>=(k/2+1))&&k%2==1)
            cout << "need quorum\n";
        else if (sum1>sum2)
            cout << "yes\n";
        else if (sum2>sum1)
            cout << "no\n";
        else if (sum1==sum2)
            cout << "tie\n";
    }
    return 0;
}
/*
Problem description
A committee clerk is good at recording votes, but not so good at counting and figuring the outcome correctly.  As a roll call vote proceeds, the clerk records votes as a sequence of letters, with one letter for every member of the committee:
Y means a yes vote
N means a no vote
P means present, but choosing not to vote
A indicates a member who was absent from the meeting
Your job is to take this recorded list of votes and determine the outcome.

Rules:   
There must be a quorum.  If at least half of the members were absent, respond "need quorum".  Otherwise votes are counted.   If there are more yes than no votes, respond "yes".   If there are more no than yes votes, respond "no".   If there are the same number of yes and no votes, respond "tie". 


Input
The input contains of a series of votes, one per line, followed by a single line with the # character. Each vote consists entirely of the uppercase letters discussed above.  Each vote will contain at least two letters and no more than 70 letters.



Output
For each vote, the output is one line with the correct choice "need quorum", "yes", "no" or "tie".


Sample Input
YNNAPYYNY
YAYAYAYA
PYPPNNYA
YNNAA
NYAAA
#
Sample Output
yes
need quorum
tie
no
need quorum
*/