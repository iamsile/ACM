#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;
char a[80][80],b[100];
int n,m;
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
int position(char *p,char *q)
{
    int i,lenth1=strlen(p);
    for (i=0; i<lenth1; i++)
        if (p[i]!=q[i]&&(p[i]+32)!=q[i]&&p[i]!=(q[i]+32))
            return 0;
    return 1;
}

int findpath(int x,int y)
{
    char q[100];
    int i,num=0,x1,y1;
    int lenth=strlen(b);
    for (i=0; i<8; i++)
    {
        num=1;
        x1=x;
        y1=y;
        q[0]=a[x1][y1];
        while (num<lenth) 
        {
            x1+=dx[i];
            y1+=dy[i];
            if (x1>=0&&x1<n&&y1>=0&&y1<m)
                q[num++]=a[x1][y1];
            else 
                break;
        }
        if (num!=lenth)
            continue;
        q[num]='\0';
        if (position(q,b))
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,k,len;
        cin >> n >> m;
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                cin >> a[i][j];
        cin >> len;
        for (k=0; k<len; k++) 
        {
            cin >> b;
            int x=0,y=0,flag=0;
            for (i=0; i<n; i++) 
            {
                for (j=0; j<m; j++)
                {
                    if (a[i][j]==b[0]||(a[i][j]+32)==b[0]||a[i][j]==(b[0]+32))
                    {
                        x=i;
                        y=j;
                        if (findpath(x,y))
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                if (flag)
                    break;
            }
            cout << x+1 << ' ' << y+1 << '\n';
            memset(b, 0, sizeof(b));
        }
        if (t!=0)
            cout << '\n';
    }
}
/*
 Given an m by n grid of letters and a list of words, find the location in the grid at which the word can be found.
 
 A word matches a straight, uninterrupted line of letters in the grid. A word can match the letters in the grid regardless of case (i.e., upper- and lowercase letters are to be treated as the same). The matching can be done in any of the eight horizontal, vertical, or diagonal directions through the grid.
 
 Input
 
 The input begins with a single positive integer on a line by itself indicating the number of cases, followed by a blank line. There is also a blank line between each two consecutive cases.
 
 Each case begins with a pair of integers m followed by n on a single line, where 1  m, n  50 in decimal notation. The next m lines contain n letters each, representing the grid of letters where the words must be found. The letters in the grid may be in upper- or lowercase. Following the grid of letters, another integer k appears on a line by itself ( 1  k  20). The next k lines of input contain the list of words to search for, one word per line. These words may contain upper- and lowercase letters only - no spaces, hyphens, or other non-alphabetic characters.
 
 Output
 
 For each word in each test case, output a pair of integers representing its location in the corresponding grid. The integers must be separated by a single space. The first integer is the line in the grid where the first letter of the given word can be found (1 represents the topmost line in the grid, and m represents the bottommost line). The second integer is the column in the grid where the first letter of the given word can be found (1 represents the leftmost column in the grid, and n represents the rightmost column in the grid). If a word can be found more than once in the grid, then output the location of the uppermost occurrence of the word (i.e., the occurrence which places the first letter of the word closest to the top of the grid). If two or more words are uppermost, output the leftmost of these occurrences. All words can be found at least once in the grid.
 
 The output of two consecutive cases must be separated by a blank line.
 
 Sample Input
 
 1
 
 8 11
 abcDEFGhigg
 hEbkWalDork
 FtyAwaldORm
 FtsimrLqsrc
 byoArBeDeyv
 Klcbqwikomk
 strEBGadhrb
 yUiqlxcnBjf
 4
 Waldorf
 Bambi
 Betty
 Dagbert
 Sample Output
 
 2 5
 2 3
 1 2
 7 8
*/