#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int i,j,k,c1[10001],c2[10001];
        for (i=0; i<=n; i++) {
            c1[i]=1;
            c2[i]=0;
        }
        for (i=2; i<=n; i++) {
            for (j=0; j<=n; j++)
                for (k=0; j+k<=n; k+=i)
                    c2[j+k]+=c1[j];
            for (j=0; j<=n; j++) {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout << c1[n] << '\n';
    }
}
/*
#include<stdio.h>
int record[150][150];
int N;
int n=120,m=120;
int main()
{
    int i,j;
    for(i=1;i<150;i++)
        record[1][i]=1;
    for(i=1;i<150;i++)
        record[i][1]=1;
    for(i=1;i<150;i++)
        for(j=1;j<150;j++)
        {
            if(i==j)
                record[i][j]=1+record[i][j-1];
            else if(i<j)
                record[i][j]=record[i][i];
            else if(i>j)
                record[i][j]=record[i][j-1]+record[i-j][j];
            
        }
    while(scanf("%d",&N)!=EOF)
    {
        printf("%d\n",record[N][N]);
    }
    return 0;
}
/*
/*
 Problem Description
 "Well, it seems the first problem is too easy. I will let you know how foolish you are later." feng5166 says.
 
 "The second problem is, given an positive integer N, we define an equation like this:
 N=a[1]+a[2]+a[3]+...+a[m];
 a[i]>0,1<=m<=N;
 My question is how many different equations you can find for a given N.
 For example, assume N is 4, we can find:
 4 = 4;
 4 = 3 + 1;
 4 = 2 + 2;
 4 = 2 + 1 + 1;
 4 = 1 + 1 + 1 + 1;
 so the result is 5 when N is 4. Note that "4 = 3 + 1" and "4 = 1 + 3" is the same in this problem. Now, you do it!"
 Input
 The input contains several test cases. Each test case contains a positive integer N(1<=N<=120) which is mentioned above. The input is terminated by the end of file.
 Output
 For each test case, you have to output a line contains an integer P which indicate the different equations you have found.
 Sample Input
 4
 10
 20
 Sample Output
 5
 42
 627
*/