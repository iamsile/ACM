#include <iostream>
#include <string.h>
using namespace::std;
int C[3500][7], sum[3500][7];

char s[7]={'I','V','X','L','C','D','M'};
int t[10][3]={{0,0,0},{1,0,0},{2,0,0},{3,0,0},{1,1,0},
{0,1,0},{1,1,0},{2,1,0},{3,1,0},{1,0,1}};

void solve(int a,int b,int c,int i,int n,int k)
{
    int p,j;
    while(i<=n)
	{
        for(j=0;j<7;j++)
            C[i][j]=C[i%k][j];
        p=i/k;
        C[i][a]+=t[p][0];
        if(p>3) 
		{
            C[i][b]+=t[p][1];
            C[i][c]+=t[p][2];
        }
        for(j=0;j<7;j++) 
            sum[i][j]=sum[i-1][j]+C[i][j];
        i++;
    }
}

int main()
{    
    int i,N;
    memset(C, 0, sizeof(C));
    memset(sum, 0, sizeof(sum));
    cin >> N;
    if(N>=9) 
		solve(0,1,2,1,9,1);
    else 
		solve(0,1,2,1,N,1);
    if(N>=99) 
		solve(2,3,4,10,99,10);
    else
		solve(2,3,4,10,N,10);
    if(N>=999) 
		solve(4,5,6,100,999,100);
    else 
		solve(4,5,6,100,N,100);
    solve(6,0,0,1000,N,1000);
    for(i=0;i<7;i++)
        if(sum[N][i]>0) 
            cout << s[i] << ' ' << sum[N][i] << '\n';
    return 0;
}
/*
 题意：构造罗马数字。
 思路：可以找到规律；
     I  V  X
 1   1  0  0
 2   2  0  0
 3   3  0  0
 4   1  1  0
 5   0  1  0
 6   1  1  0
 7   2  1  0
 8   3  1  0
 9   1  0  1
 */
/*
 Problem description
 A certain book's prefaces are numbered in upper case Roman numerals. Traditional Roman numeral values use a single letter to represent a certain subset of decimal numbers. Here is the standard set:
 I   1     L   50    M  1000
 V   5     C  100
 X  10     D  500
 As many as three of the same marks that represent 10n may be placed consecutively to form other numbers:
 
 III is 3
 CCC is 300
 Marks that have the value 5x10n are never used consecutively.
 
 Generally (with the exception of the next rule), marks are connected together and written in descending order to form even more numbers:
 
 CCLXVIII = 100+100+50+10+5+1+1+1 = 268
 Sometimes, a mark that represents 10^n is placed before a mark of one of the two next higher values (I before V or X; X before L or C; etc.). In this case, the value of the smaller mark is SUBTRACTED from the mark it precedes:
 
 IV = 4
 IX = 9
 XL = 40
 Compound marks like XD, IC, and XM are not legal, since the smaller mark is too much smaller than the larger one. For XD (wrong for 490), one would use CDXC; for IC (wrong for 99), one would use XCIX; for XM (wrong for 990), one would use CMXC.
 
 Given N (1 <= N < 3,500), the number of pages in the preface of a book, calculate and print the number of I's, V's, etc. (in order from lowest to highest) required to typeset all the page numbers (in Roman numerals) from 1 through N. Do not print letters that do not appear in the page numbers specified.
 
 If N = 5, then the page numbers are: I, II, III, IV, V. The total number of I's is 7 and the total number of V's is 2. 
 
 
 Input
 A single line containing the integer N.
 
 Output
 The output lines specify, in ascending order of Roman numeral letters, the letter, a single space, and the number of times that letter appears on preface page numbers. Stop printing letter totals after printing the highest value letter used to form preface numbers in the specified set.
 
 Sample Input
 5
 Sample Output
 I 7
 V 2
*/