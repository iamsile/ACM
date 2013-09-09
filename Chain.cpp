#include <iostream>
#include <stdio.h>
using namespace std;
__int64 a[100005],b[100005];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        __int64 sum=0,i,max=0,lab=-1;
        for (i=1; i<=n; i++) {
            scanf("%I64d",&a[i]);
            sum+=a[i];
            if (a[i]>max) {
                max=a[i];
                lab=i;
            }
        }
        for (i=1; i<=n; i++)
            scanf("%I64d",&b[i]);
        sum-=a[lab];
        if (max>(sum+1)*b[lab])
            sum+=(sum+1)*b[lab];
        else
            sum+=a[lab];
        printf("%I64d\n",sum);
    }
    return 0;
}
/*
 Problem Description
 Li Lei has many pearls of N different color. The number of each color is limited. Han Mei is Li Lei’s girl friend.
 Since Han Mei’s birthday is coming, Li Lei wants to give Han Mei his present for her birthday. Finally, Li Lei decides to make a chain for his lovely girl friend with his beautiful pearls. He wants to make the chain more beautiful, so the number of the continuous pearls with same color is limited.
 Now, Li Lei wants to know how long his chain will be. He will always make the chain as long as possible. Pay attention that the shape of a chain is a line but not a circle here.
 Input
 The first line is an integer N. It means that Li Lei has many pearls of N different color.
 The next line contains N integers A(0),A(1)……A(N-1). It means that Li Lei has A(i) pearls of the i-th color.
 The third line contains N integers B(0),B(1)……B(N-1). It means that in the chain, there will be no more than B(i) continuous pearls of the i-th color.
 You can assume that A(i) is not smaller than B(i).
 All integers in the input is positive and no larger than 100000.
 Output
 There is one integer in a line for each test case, representing the length of the chain.
 Sample Input
 3
 1 1 100
 1 1 1
 3
 1 1 100
 1 1 2
 Sample Output
 5
 8
*/