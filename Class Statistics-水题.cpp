#include <iostream>
using namespace std;

int main()
{
    int t,lab=1;
    scanf("%d",&t);
    while (t--) {
        int i,n,sum=-1,maxn=-1,minn=999999,a[100]={0};
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            scanf("%d",&a[i]);
            if (a[i]>maxn)
                maxn=a[i];
            if (a[i]<minn)
                minn=a[i];
        }
        sort(a, a+n);
        for (i=1; i<n; i++)
            if (a[i]-a[i-1]>sum)
                sum=a[i]-a[i-1];
        printf("Class %d\n",lab++);
        printf("Max %d, Min %d, Largest gap %d\n",maxn,minn,sum);
    }
    return 0;
}
/*
 Problem description
 The new principal of Woop Woop Public plans to meet the teaching team to discuss the performance of the classes/teachers and, being a bean counting fundamentalist, he wants to arm himself with some statistics for the meetings.
 Your task is to write a program that reads the pupils' marks in each class and generates performance reports for the principal prior to the meetings.
 
 Input
 The input starts with an integer K (1 <= K <= 100) indicating the number of classes on a line by itself. Each of the following K lines gives a class's data, which starts with an integer N (2 <= N <= 50) indicating the number of pupils in the class. The number of pupils is followed by their marks, given as integers, in the range of zero to one hundred, separated by single spaces.
 
 Output
 The report for each class consists of two lines. The first line consists of the sentence: "Class X", where X indicates the class number starting with the value of one. The second line reports the maximum class mark, minimum class mark and the largest difference between consecutive marks (when sorted in non-decreasing order) in the class using the formats shown in the sample below.
 
 Sample Input
 2
 5 30 25 76 23 78
 6 25 50 70 99 70 90
 Sample Output
 Class 1
 Max 78, Min 23, Largest gap 46
 Class 2
 Max 99, Min 25, Largest gap 25
*/