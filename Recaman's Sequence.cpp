#include <iostream>
#include <memory.h>
#include <string.h>
using namespace::std;

int main()
{
	int m,i;
	unsigned int a[500001]={0};
	char b[800000];
    while(cin >> m&&m!=-1)
    {
		
        for(i=1;i<=m;i++)
		{
            if(a[i-1]>i&&b[a[i-1]-i])
                a[i]=a[i-1]-i;
            else 
                a[i]=a[i-1]+i;
			b[a[i]]=false;
		}
        cout << a[i-1] << '\n';
		memset(a, 0, sizeof(a));
		memset(b, true, sizeof(b));
    }
    return 0;
}//下标会越界
/*#include<cstdio>
#include<cstring>
bool f[10000000];
int r[500001];
int main()
{
    int n,i;
    memset(f,true,sizeof(f));
    r[0]=0;
    for(i=1;i<=500000;i++)
    {
        if(r[i-1]>i&&f[r[i-1]-i])r[i]=r[i-1]-i;
        else r[i]=r[i-1]+i;
        f[r[i]]=false;
    }
    while(scanf("%d",&n)&&n!=-1)
        printf("%d\n",r[n]);
    return 0;
}*/
/*
 Problem description
 The Recaman's sequence is defined by a0 = 0 ; for m > 0, am = am−1 − m if the rsulting am is positive and not already in the sequence, otherwise am = am−1 + m. 
 The first few numbers in the Recaman's Sequence is 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9 ... 
 Given k, your task is to calculate ak.
 
 Input
 The input consists of several test cases. Each line of the input contains an integer k where 0 <= k <= 500000. The last line contains an integer −1, which should not be processed.
 
 Output
 For each k given in the input, print one line containing ak to the output.
 
 Sample Input
 7
 10000
 -1
 Sample Output
 20
 18658
*/