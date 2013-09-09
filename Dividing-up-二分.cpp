#include <stdio.h>
#include <string.h>
int value[60010];
#define MAX(a, b) (a > b ? a : b)

void calmax(int cost,int w,int m)
{
    for (int i=cost; i<=m; i++)
        value[i]=MAX(value[i], value[i-cost]+w);
}

void calmin(int cost,int w,int m)
{
    for (int i=m; i>=cost; i--)
        value[i]=MAX(value[i], value[i-cost]+w);
}

int main()
{
    int t=1;
    while (1) {
        int i,k,lab,sum=0,a[10]={0};
        for (i=1; i<=6; i++) {
            scanf("%d",&a[i]);
            sum+=i*a[i];
        }
        if (!sum)
            break;
        printf("Collection #%d:\n",t++);
        if (sum&1) {
            puts("Can't be divided.\n");
            continue;
        }
        memset(value, 0, sizeof(value));
        sum>>=1;
        for (i=1; i<=6; i++) {
            k=i*a[i];
            if (k>sum)
                calmax(i,i,sum);
            else {
                lab=1;
                while (lab<a[i]) {
                    calmin(lab*i, lab*i, sum);
                    a[i]-=lab;
                    lab<<=1;
                }
                calmin(a[i]*i, a[i]*i, sum);
            }
        }
        if (value[sum]==sum)
            puts("Can be divided.\n");
        else puts("Can't be divided.\n");
    }
    return 0;
}
/*
 Problem Description
 Marsha and Bill own a collection of marbles. They want to split the collection among themselves so that both receive an equal share of the marbles. This would be easy if all the marbles had the same value, because then they could just split the collection in half. But unfortunately, some of the marbles are larger, or more beautiful than others. So, Marsha and Bill start by assigning a value, a natural number between one and six, to each marble. Now they want to divide the marbles so that each of them gets the same total value. 
 Unfortunately, they realize that it might be impossible to divide the marbles in this way (even if the total value of all marbles is even). For example, if there are one marble of value 1, one of value 3 and two of value 4, then they cannot be split into sets of equal value. So, they ask you to write a program that checks whether there is a fair partition of the marbles.
 
 
 Input
 Each line in the input describes one collection of marbles to be divided. The lines consist of six non-negative integers n1, n2, ..., n6, where ni is the number of marbles of value i. So, the example from above would be described by the input-line ``1 0 1 2 0 0''. The maximum total number of marbles will be 20000. 
 
 The last line of the input file will be ``0 0 0 0 0 0''; do not process this line.
 
 
 Output
 For each colletcion, output ``Collection #k:'', where k is the number of the test case, and then either ``Can be divided.'' or ``Can't be divided.''. 
 
 Output a blank line after each test case.
 
 
 Sample Input
 1 0 1 2 0 0
 1 0 0 0 1 1
 0 0 0 0 0 0
 
 
 Sample Output
 Collection #1:
 Can't be divided.
 
 Collection #2:
 Can be divided.
*/