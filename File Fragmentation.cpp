#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;

void cal(char a[][1000],int n,char c[])
{
    int i,j,b[1000][2],d[1000],len=0;
    memset(b, 0, sizeof(b));
    memset(d, 0, sizeof(d));
    for (i=0; i<n; i++)
        for (j=0; a[i][j]!='\0'; j++) {
            ++b[j][a[i][j]-'0'];
            ++d[i];
            ++len;
        }
    len=len*2/n;
    for (i=0; i<n; i++)
        for (j=0; a[i][j]!='\0'; j++)
            ++b[len-d[i]+j][a[i][j]-'0'];
    for (i=0; i<len; i++)
        c[i]=b[i][0]>b[i][1]?'0':'1';
}

int main()
{
    int t;
    cin >> t;
    getchar();
    getchar();
    while (t--) 
    {
        int i=0;
        char a[1000][1000]={0},c[1000]={0};
        while (cin.getline(a[i], 1000)&&a[i][0]!='\0') {
            i++;
        }
        cal(a,i,c);
        cout << c << '\n';
        if (t>0)
            cout << '\n';
    }
    return 0;
}
/*
 Your friend, a biochemistry major, tripped while carrying a tray of computer files through the lab. All of the files fell to the ground and broke. Your friend picked up all the file fragments and called you to ask for help putting them back together again.
 
 Fortunately, all of the files on the tray were identical, all of them broke into exactly two fragments, and all of the file fragments were found. Unfortunately, the files didn't all break in the same place, and the fragments were completely mixed up by their fall to the floor.
 
 The original binary fragments have been translated into strings of ASCII 1's and 0's. Your job is to write a program that determines the bit pattern the files contained.
 
 Input
 
 The input begins with a single positive integer on its own line indicating the number of test cases, followed by a blank line. There will also be a blank line between each two consecutive cases.
 
 Each case will consist of a sequence of ``file fragments,'' one per line, terminated by the end-of-file marker or a blank line. Each fragment consists of a string of ASCII 1's and 0's.
 
 Output
 
 For each test case, the output is a single line of ASCII 1's and 0's giving the bit pattern of the original files. If there are 2N fragments in the input, it should be possible to concatenate these fragments together in pairs to make N copies of the output string. If there is no unique solution, any of the possible solutions may be output.
 
 Your friend is certain that there were no more than 144 files on the tray, and that the files were all less than 256 bytes in size.
 
 The output from two consecutive test cases will be separated by a blank line.
 
 Sample Input
 
 1
 
 011
 0111
 01110
 111
 0111
 10111
 Sample Output
 
 01110111
*/