#include <iostream>
using namespace std;

int cal(int c[],int s)
{
    int i,num=0;
    for (i=s; i>=0; i--) {
        num+=c[i];
        c[i]=0;
    }
    return num;
}

int main()
{
    int n,m;
    while (scanf("%d",&n),n) {
        int i,j,x,y,sum=0,a[10010],b[10010];
        for (i=0; i<n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for (i=0; i<m; i++)
            scanf("%d",&b[i]);
        for (i=0,j=0; i<n; ) {
            if (a[i]>b[j])
                j++;
            else if (a[i]<b[j])
                i++;
            else if (a[i]==b[j]) {
                x=cal(a, i);
                y=cal(b, j);
                i++;j++;
                sum+=x>y?x:y;
            }
        }
        x=cal(a, n-1);
        y=cal(b, m-1);
        sum+=x>y?x:y;
        printf("%d\n",sum);
    }
    return 0;
}
/*
 Problem description
 Two finite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are printed in bold:
 First =	3 5 7 9 20 25 30 40 55 56 57 60 62
 Second =	1 4 7 11 14 25 44 47 55 57 100
 
 
 You can ``walk" over these two sequences in the following way:
 
 You may start at the beginning of any of the two sequences. Now start moving forward.
 At each intersection point, you have the choice of either continuing with the same sequence you're currently on, or switching to the other sequence.
 
 The objective is finding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450 which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62.
 
 
 Input
 Your program will be tested on a number of test cases. Each test case will be specified on two separate lines. Each line denotes a sequence and is specified using the following format:
 n v1 v2 ... vn
 
 Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are b etween -10,000 and 10,000 (inclusive).
 
 The last line of the input includes a single zero, which is not part of the test cases.
 
 
 Output
 For each test case, write on a separate line, the largest possible sum that can be produced.
 
 Sample Input
 13 3 5 7 9 20 25 30 40 55 56 57 60 62
 11 1 4 7 11 14 25 44 47 55 57 100
 4 -5 100 1000 1005
 3 -12 1000 1001
 0
 
 Sample Output
 450 
 2100
*/