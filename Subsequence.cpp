#include <iostream>
using namespace std;

int main()
{
    unsigned int t;
    scanf("%u",&t);
    while (t--) {
        unsigned int i,j,k=0,n,m,len,lab=0,sum=0,max=100000000,a[100000]={0};
        scanf("%u%u",&n,&m);
        for (i=0; i<n; i++) {
            scanf("%u",&a[i]);
            sum+=a[i];
            if (sum>=m)
            {
                lab=1;
                for (j=k; j<n; j++) {
                    sum-=a[j];
                    if (sum<=m) {
                        k=j;
                        break;
                    }
                }
                len=i-k+1;
                if (max>len)
                    max=len;
                k++;
            }
        }
        if (lab)
            printf("%u\n",max);
        else 
            printf("0\n");
    }
    return 0;
}
/*
 Problem description
 A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.
 
 Input
 The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.
 
 Output
 For each the case the program has to print the result on separate line of the output file.if no answer, print 0.
 
 Sample Input
 2
 10 15
 5 1 3 5 10 7 4 9 2 8
 5 11
 1 2 3 4 5
 Sample Output
 2
 3
*/