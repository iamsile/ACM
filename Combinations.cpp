#include <stdio.h>

int main()
{
    __int64 i,n,m,l,sum,lab;
    while (scanf("%I64d%I64d",&n,&m))
    {
        if (n==0&&m==0)
            return 0;
        sum=1;
        for (i=1; i<=m; i++) 
            sum=sum*(n-m+i)/i;
        printf("%I64d things taken %I64d at a time is %I64d exactly.\n",n,m,sum);
    }
    return 0;
}
/*
 Problem description
 Computing the exact number of ways that N things can be taken M at a time can be a great challenge when N and/or M become very large. Challenges are the stuff of contests. Therefore, you are to make just such a computation given the following: 
 GIVEN: 5 <= N <= 100; 5 <= M <= 100; M <= N 
 Compute the EXACT value of: C = N! / (N-M)!M! 
 You may assume that the final value of C will fit in a 64-bit Pascal LongInt or a C long long. For the record, the exact value of 100! is: 
 93,326,215,443,944,152,681,699,238,856,266,700,490,715,968,264,381,621, 468,592,963,895,217,599,993,229,915,608,941,463,976,156,518,286,253, 697,920,827,223,758,251,185,210,916,864,000,000,000,000,000,000,000,000 
 
 
 Input
 The input to this program will be one or more lines each containing zero or more leading spaces, a value for N, one or more spaces, and a value for M. The last line of the input file will contain a dummy N, M pair with both values equal to zero. Your program should terminate when this line is read.
 
 Output
 The output from this program should be in the form: N things taken M at a time is C exactly. 
 
 Sample Input
 100  6
 20  5
 18  6
 0  0
 Sample Output
 100 things taken 6 at a time is 1192052400 exactly.
 20 things taken 5 at a time is 15504 exactly.
 18 things taken 6 at a time is 18564 exactly.
 Problem Source
*/