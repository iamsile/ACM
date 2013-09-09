#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int dp[1101][1101];
int main()
{
    char a[1100],b[1100];
    while (~scanf("%s%s",a,b)) {
        int i,j,len1=strlen(a),len2=strlen(b);
        memset(dp, 0, sizeof(dp));
        for (i=1; i<=len1; i++)
            for (j=1; j<=len2; j++)
                if (a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        cout << dp[len1][len2] << '\n';
    }
    return 0;
}
/*
 Description
 
 A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = < x1, x2, ..., xm > another sequence Z = < z1, z2, ..., zk > is a subsequence of X if there exists a strictly increasing sequence < i1, i2, ..., ik > of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = < a, b, f, c > is a subsequence of X = < a, b, c, f, b, c > with index sequence < 1, 2, 4, 6 >. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
 Input
 
 The program input is from the std input. Each data set in the input contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct.
 Output
 
 For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.
 Sample Input
 
 abcfbc         abfcab
 programming    contest 
 abcd           mnp
 Sample Output
 
 4
 2
 0
*/