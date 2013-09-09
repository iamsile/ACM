#include <iostream>
#include <string.h>
using namespace std;

int f(int i1[],int i2[],int i3[],int i4[],int t4,int i5[])
{
    int t5,i,k;
    for (i=0; i<t4; i++)
        i5[i]=i4[i]+i3[i]+i2[i]+i1[i];
    for (i=0; i<t4||i5[i]; i++) {
        k=i5[i]/10;
        if (k) {
            i5[i+1]+=k;
            i5[i]%=10;
            if (i==t4-1)
                t4++;
        }
    }
    t5=t4;
    return t5;
}

int main()
{
    int n,i,j;
    int i1[2600],i2[2600],i3[2600],i4[2600],i5[2600],t4,t5;
    while (scanf("%d",&n)!=EOF) {
        if (n<5) {
            cout << "1\n";
            continue;
        }
        memset(i1, 0, sizeof(i1));
        memset(i2, 0, sizeof(i2));
        memset(i3, 0, sizeof(i3));
        memset(i4, 0, sizeof(i4));
        memset(i5, 0, sizeof(i5));
        i1[0]=i2[0]=i3[0]=i4[0]=1;
        t4=1;
        for (i=4; i<n; i++) {
            t5=f(i1,i2,i3,i4,t4,i5);
            if (i==n)
                break;
            for (j=0; j<t4; j++)
                i1[j]=i2[j];
            for (j=0; j<t4; j++)
                i2[j]=i3[j];
            for (j=0; j<t4; j++)
                i3[j]=i4[j];
            for (j=0; j<t5; j++)
                i4[j]=i5[j];
            t4=t5;
        }
        for (i=t5-1; i>=0; i--)
            cout << i5[i];
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 A Fibonacci sequence is calculated by adding the previous two members the sequence, with the first two members being both 1.
 F(1) = 1, F(2) = 1, F(3) = 1,F(4) = 1, F(n>4) = F(n - 1) + F(n-2) + F(n-3) + F(n-4)
 Your task is to take a number as input, and print that Fibonacci number.
 
 
 Input
 Each line will contain an integers. Process to end of file.
 
 
 Output
 For each case, output the result in a line.
 
 
 Sample Input
 100
 
 
 Sample Output
 4203968145672990846840663646
*/