#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

struct teams {
    int num;
    int solved[12];
    int penalty[12];
    bool submit;
} a[105];

void calculateAll()
{
    int i,j;
    for (i=1;i<105;i++)
        for (j=1;j<=9;j++) 
            if(a[i].solved[j])
            {
                a[i].solved[10]++;
                a[i].penalty[10]+=a[i].penalty[j];
            }
}

bool cmp(teams x, teams y)
{
    if (x.solved[10]>y.solved[10]) 
        return true;
    if (x.solved[10]==y.solved[10]&&x.penalty[10]<y.penalty[10])
        return true;
    if (x.solved[10]==y.solved[10]&&x.penalty[10]==y.penalty[10]&&x.num<y.num) 
        return true;
    return false;
}

int main() 
{
    int t,i,j;
    bool blank=false;
    char input[1000];
    cin >> t;
    getchar();
    gets(input);
    while (t--) 
    {
        for (i=0;i<105;i++)
        {
            a[i].num=i;
            memset(a[i].solved, 0, sizeof(a[i].solved));
            memset(a[i].penalty, 0, sizeof(a[i].penalty));
            a[i].submit=false;
        }
        while (gets(input)&&strlen(input)) 
        {
            int c,p,t;
            char l;
            sscanf(input, "%d %d %d %c",&c,&p,&t,&l);
            a[c].submit=true;
            if (l=='R'||l=='U'||l=='E') 
                continue;
            if (l=='C') 
            {
                if (!a[c].solved[p]) 
                {
                    a[c].solved[p]=1;
                    a[c].penalty[p]+=t;
                }
            }
            else
                if (!a[c].solved[p])
                    a [c].penalty[p]+=20;
        }
        calculateAll();
        sort(a, a + 105, cmp);
        if (blank)
            cout << '\n';
        blank = true;
        for (i=0;i<=105;i++)
            if(a[i].submit)
                printf("%d %d %d\n",a[i].num,a[i].solved[10],a[i].penalty[10]);
    }
    return 0;
}
/*
 Want to compete in the ACM ICPC? Then you had better know how to keep score! Contestants are ranked first by the number of problems solved (the more the better), then by decreasing amounts of penalty time. If two or more contestants are tied in both problems solved and penalty time, they are displayed in order of increasing team numbers.
 
 A problem is considered solved by a contestant if any of the submissions for that problem was judged correct. Penalty time is computed as the number of minutes it took until the first correct submission for a problem was received, plus 20 minutes for each incorrect submission prior to the correct solution. Unsolved problems incur no time penalties.
 
 Input
 
 The input begins with a single positive integer on a line by itself indicating the number of cases, each described as below. This line is followed by a blank line. There is also a blank line between two consecutive inputs.
 
 The input consists of a snapshot of the judging queue, containing entries from some or all of contestants 1 through 100 solving problems 1 through 9. Each line of input consists of three numbers and a letter in the format contestant problem time L, where L can be C, I, R, U, or E. These stand for Correct, Incorrect, clarification Request, Unjudged, and Erroneous submission. The last three cases do not affect scoring.
 
 The lines of input appear in the order in which the submissions were received.
 
 Output
 
 The output for each test case will consist of a scoreboard, sorted by the criteria described above. Each line of output will contain a contestant number, the number of problems solved by the contestant and the total time penalty accumulated by the contestant. Since not all contestants are actually participating, only display those contestants who have made a submission.
 
 The output of two consecutive cases will be separated by a blank line.
 
 Sample Input
 
 1
 
 1 2 10 I
 3 1 11 C
 1 2 19 R
 1 2 21 C
 1 1 25 C
 Sample Output
 
 1 2 66
 3 1 11
*/