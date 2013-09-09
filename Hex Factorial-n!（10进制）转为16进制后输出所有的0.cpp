#include <iostream>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)&&n>=0) {
        int i,j,k=1,sum=0,a[1001]={1,0};
        for (i=1; i<=n; i++) {
            for (j=0; j<=k; j++)
                a[j]*=i;
            for (j=0; j<=k; j++) {
                if (a[j]>15) {
                    a[j+1]+=a[j]/16;
                    a[j]%=16;
                    if (j+1==k)
                        k++;
                }
            }
        }
        for (i=k; i>=0; i--)
            if (a[i])
                break;
        for (j=i; j>=0; j--)
            if (a[j]==0)
                sum++;
        printf("%d\n",sum);
    }
    return 0;
}
/*
 Problem description
 The expression N!,reads as the factorial of N,denoting the product of the first N positive integers. If the factorial of N is written in hexadecimal without leading zeros,can you tell us how many zeros are there in it?Take 15! As an example,you should answer “3” because(15)10! = (13077775800)16,and there are 3 zeros in it.
 
 Input
 The input contains several cases.Each case has one line containing a non-negative decimal integer N (N<=100).You need to count the zeros in N! in hexadecimal.A negative number terminates the input.
 
 Output
 For each non-negative integer N,output one line containing exactly one integer indicating the number of zeros in N!.
 
 Sample Input
 1
 15
 -1
 Sample Output
 0
 3
*/