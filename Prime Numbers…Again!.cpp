#include <iostream>
using namespace std;
#define max 10000

int main()
{
    int i,j,k,c,t,n,cnt,sum,len=1,p[max/2],pri[max];
    c=max>>1;
    for (i=0; i<c; i++)
        p[i]=1;
    for (i=0; i<50; i++)
        if (p[i])
            for (k=(i<<1)+3,j=k*i+i+k; j<c; j+=k)
                p[j]=0;
    pri[0]=2;
    for (i=0; i<c; i++)
        if (p[i])
            pri[len++]=(i<<1)+3;
    cin >> t;
    while (t--) {
        cin >> n;
        cnt=0;
        for (i=0; i<n; i++) {
            sum=0;
            for (j=i; j<len; j++) {
                if (pri[j]>n) 
                    break;
                sum+=pri[j];
                if (sum==n)
                    cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
/*
 Problem description
 We can write some of the numbers as the sum of some distinct consecutive prime numbers. For instance, number 15 can be represented as 3+5+7=15 
 You are given a postive integer number 1≤n≤10000 and you should find the number of different ways that number can be represented as the sum of some distinct consecutive prime numbers. 
 
 Input
 The number of test cases comes in the first line. For each test case you are given a positive integer (1≤n≤10000 ).
 
 Output
 For each test case, print the number of the different ways that can be represented as a sum of some consecutive prime numbers.
 
 Sample Input
 2
 3
 17
 Sample Output
 1
 2
*/