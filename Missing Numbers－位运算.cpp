#include <stdio.h> 
#include <math.h> 
#include <string.h> 
int main() 
{ 
    __int64 i,n,num,n1,n2,j,s1,s2,max; 
    char ch; 
    while(1) 
    { 
        scanf("%I64d",&n); 
        if(n==0) break; 
        s1=0; 
        s2=0; 
        max=10*n*n; 
        for(i=0,j=n;i<n-2;i++) 
        { 
            if(s2<=max) 
            { 
                s2+=j*j; 
                j--; 
            } 
            while(ch=getchar()) if(ch >='0'&&ch<='9') break;  
            num=ch-'0';  
            while(ch=getchar(),ch>='0'&&ch<='9')  
            {  
                num=num*10+ch-'0';  
            } 
            s1+=num; 
            s2-=num*num; 
        } 
        for(i=j;i>=1;i--) 
            s2+=i*i;//算出除了输入的数之外剩下的两个数的平方
        s1=n*(n+1)/2-s1; //算出剩下两个数的和
        n1=(s1-sqrt(2*s2-s1*s1))/2; 
        n2=(s1+sqrt(2*s2-s1*s1))/2; 
        printf("%I64d %I64d\n",n1,n2); 
    } 
    return 0; 
} 
/*
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)&&n) {
        int i,m,flag=0;
        bitset< 2000001> a;
        a.set(0);
        for (i=0; i<n-2; i++) {
            scanf("%d",&m);
            a[m]=1;
        }
        for (i=1; i<=n; i++)
            if (!a[i]) {
                if (flag)
                    printf(" ");
                printf("%d",i);
                flag=1;
            }
        printf("\n");
    }
    return 0;
}
*/
/*
 Problem description
 Leo loves collecting numbers, he consumed half of his spare time and made a collection of all the numbers from 1 to n, one day, he decided to take out all the numbers he gathered and count them(a fantastic idea... -______-b). when the counting was finished, he found that there are only n - 2 numbers left, he can't memorize those numbers he already got, but still wonders which two numbers are missing.
 
 Input
 The input file consists of several test cases. Each case starts with a line containing one integer n, 2 < n <= 10000000, Then followed n - 2 lines, each line contains one exclusive integer k, 0 < k <= n. The last line of 0 indicates the end of input which should not be processed.
 
 Output
 For each test case, output a single line contains the two missing numbers in ascending order.
 
 Sample Input
 3
 2
 5
 1
 5
 3
 0
 Sample Output
 1 3
 2 4
 Judge Tips
 Huge input file, 'scanf'&'printf' recommended to avoid TLE.
 MLE expected...
*/