#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;

int main()
{
    int n,lab=1;
    while (cin >> n&&n)
    {
        char a[110][500]={0},b[110][500]={0},c[1000],d[1000];
        int i,j,m,l=0,flag=0;
        getchar();
        for (i=0; i<n; i++) 
            gets(a[i]);            
        cin >> m;
        getchar();
        for (i=0; i<m; i++)
            gets(b[i]);
        if (m==n) 
        {
            for (i=0; i<n; i++) 
                if (strcmp(a[i], b[i])!=0) 
                {
                    flag=1;
                    break;
                }
            if (flag==0)
                cout << "Run #" << lab++ << ": Accepted\n";
        }
        if (flag||m!=n)
        {
            for (i=0; i<n; i++)
                for (j=0; j<strlen(a[i]); j++)
                    if (a[i][j]>='0'&&a[i][j]<='9')
                        c[l++]=a[i][j];
            c[l]='\0';
            l=0;
            for (i=0; i<m; i++)
                for (j=0; j<strlen(b[i]); j++)
                    if (b[i][j]>='0'&&b[i][j]<='9')
                        d[l++]=b[i][j];
            d[l]='\0';
            if (strcmp(d, c)==0)
                cout << "Run #" << lab++ << ": Presentation Error\n";
            else 
                cout << "Run #" << lab++ << ": Wrong Answer\n";
        }
    }
    return 0;
}
/*
 注意：1. n与m不一定相等。2.这一点是最重要的，不管数字是怎么出现的的，只要所有的数字组成的字符串相等就可能满足Ac或者PE。
 
 基于上面一点，首先将能够接受的比较出来，剩下的就是PE和WA了，然后比较所有数字组成的串，相等就PE，否者就WA...*/
/*
 Human programming contest judges are known to be very picky. To eliminate the need for them, write an automated judge script to judge submitted solution runs.
 
 Your program should take a file containing the correct output as well as the output of submitted program and answer either Accepted, Presentation Error, or Wrong Answer, defined as follows:
 
 Accepted:
 You are to report ``Accepted'' if the team's output matches the standard solution exactly. All characters must match and must occur in the same order.
 Presentation Error:
 Give a ``Presentation Error'' if all numeric characters match in the same order, but there is at least one non-matching non-numeric character. For example, ``15 0'' and ``150'' would receive ``Presentation Error'', whereas ``15 0'' and ``1 0'' would receive ``Wrong Answer,'' described below.
 Wrong Answer:
 If the team output cannot be classified as above, then you have no alternative but to score the program a `Wrong Answer'.
 Input
 
 The input will consist of an arbitrary number of input sets. Each input set begins with a line containing a positive integer n < 100, which describes the number of lines of the correct solution. The next n lines contain the correct solution. Then comes a positive integer m < 100, alone on its line, which describes the number of lines of the team's submitted output. The next m lines contain this output. The input is terminated by a value of n = 0, which should not be processed.
 
 No line will have more than 100 characters.
 
 Output
 
 For each set, output one of the following:
 
 
 Run #x: Accepted
 
 Run #x: Presentation Error
 
 Run #x: Wrong Answer
 
 
 where x stands for the number of the input set (starting from 1).
 
 Sample Input
 
 2
 The answer is: 10
 The answer is: 5
 2
 The answer is: 10
 The answer is: 5
 2
 The answer is: 10
 The answer is: 5
 2
 The answer is: 10
 The answer is: 15
 2
 The answer is: 10
 The answer is:  5
 2
 The answer is: 10
 The answer is: 5
 3
 Input Set #1: YES
 Input Set #2: NO
 Input Set #3: NO
 3
 Input Set #0: YES
 Input Set #1: NO
 Input Set #2: NO
 1
 1 0 1 0
 1
 1010
 1
 The judges are mean!
 1
 The judges are good!
 0
*/