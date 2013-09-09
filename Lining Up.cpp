#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int x,y;
}dic;
dic d[1001];

double cal(double x1,double y1,double x2,double y2)
{
    return (y2-y1)/(x2-x1);
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n==0)
            return 0;
        int i,j,sum,max,lab,flag=0,a[1001];
        double k[1001];
        for (i=0; i<n; i++)
            scanf("%d%d",&d[i].x,&d[i].y);
        for (i=0; i<n-1; i++) {
            sum=0;
            for (j=i+1; j<n; j++)
                k[sum++]=cal(d[i].x,d[i].y,d[j].x,d[j].y);
            sort(k, k+sum);
            lab=0;a[0]=1;
            for (j=1; j<sum; j++) {
                if (k[j]==k[j-1]) {
                    a[lab]++;
                }
                else {
                    lab++;
                    a[lab]=1;
                }
            }
            max=0;
            for (j=0; j<=lab; j++)
                if (a[j]>max)
                    max=a[j];
            if (flag<max)
                flag=max;
        }
        printf("%d\n",flag+1);
    }
    return 0;
}
/*
 Problem description
 "How am I ever going to solve this problem?" said the pilot. 
 
 Indeed, the pilot was not facing an easy task. She had to drop packages at specific points scattered in a dangerous area. Furthermore, the pilot could only y over the area once in a straight line, and she had to y over as many points as possible. All points were given by means of integer coordinates in a two-dimensional space. The pilot wanted to know the largest number of points from the given set that all lie on one line. Can you write a program that calculates this number? Your program has to be efficient! 
 
 Input
 Input consist several case,First line of the each case is an integer N ( 1 < N < 700 ),then follow N pairs of integers. Each pair of integers is separated by one blank and ended by a new-line character. The input ended by N=0.
 
 Output
 output one integer for each input case ,representing the largest number of points that all lie on one line.
 
 Sample Input
 5
 1 1
 2 2
 3 3
 9 10
 10 11
 Sample Output
 3
*/