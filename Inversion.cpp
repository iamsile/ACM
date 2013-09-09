#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int a[500002];
bool b[500002];
int main()
{
    int n;
    long m;
    int i;
    while(scanf("%d%ld",&n,&m)&&!(n==-1&&m==-1))
    {
        memset(b,false,sizeof(bool)*(n+1));
        for(i=0;i<n;++i)
            a[i]=i+1;
        int j=ceil((-3.0+sqrt(9.0+8.0*m))/2.0);
        int k=m-((j+1)%2==0?(j+1)/2*j:j/2*(j+1));
        int d=n-j-1;
        int lab=n-2-j;
        a[lab]=k+d;
        for(i=0;i<=lab;++i)
            b[a[i]-1]=true;
        int temp=n-1;
        for(i=lab+1;i<n;++i)
        {
            while(b[temp])
                --temp;
            a[i]=temp+1;
            b[temp]=true;
        }
        for(i=0;i<n;i++)
        {
            if(i>0)
                printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
 Problem description
 The inversion number of an integer sequence a1, a2, . . . , an is the number of pairs (ai, aj) that satisfy i < j and ai > aj . Given n and the inversion number m, your task is to find the smallest permutation of the set { 1, 2, . . . , n }, whose inversion number is exactly m. 
 A permutation a1, a2, . . . , an is smaller than b1, b2, . . . , bn if and only if there exists an integer k such that aj = bj for 1 <= j < k but ak < bk.
 
 Input
 The input consists of several test cases. Each line of the input contains two integers n and m. Both of the integers at the last line of the input is −1, which should not be processed. You may assume that 1 <= n <= 50000 and 0 <= m <= n(n − 1)/2.
 
 Output
 For each test case, print a line containing the smallest permutation as described above, separates the numbers by single spaces.
 
 Sample Input
 5 9
 7 3
 -1 -1
 Sample Output
 4 5 3 2 1
 1 2 3 4 7 6 5
*/