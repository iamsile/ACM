#include<iostream>
using namespace::std;

int MaxSum(int *a,int n)
{
    int i,sum,b;
    sum=a[0];
    b=0;
    for(i=0;i<n;i++)
    {
        if(b>0)
            b+=a[i];
        else
            b=a[i];
        if(b>sum)
            sum=b;
    }
    return sum;
}

int main()
{
    int n;
    int a[100][100];
    int max,lab,sum[102],o,i,j,k;
    while(cin >> n&&n)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
				cin >> a[i][j];
        max=0;
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
            {
                memset(sum,0,sizeof(sum));
                for(o=0;o<n;o++)
                    for(k=i; k<=j; k++)
                        sum[o]+=a[k][o];
                lab=MaxSum(sum,n);
                if(lab>max)
					max=lab;
            }
        cout << max << '\n';
    }
}
/*
 Problem description
 Given a 2-dimensional array of positive and negative integers, find the sub-rectangle with the largest sum. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. A sub-rectangle is any contiguous sub-array of size 1 × 1 or greater located within the whole array. As an example, the maximal sub-rectangle of the array:
 
 0 -2 -7 0
 9 2 -6 2
 -4 1 -4 1
 -1 8 0 -2
 is in the lower-left-hand corner:
 9 2
 -4 1
 -1 8
 
 and has the sum of 15.
 
 Input
 The input consists of an array of N × N integers. The input begins with a single positive integer N on a line by itself indicating the size of the square two dimensional array. This is followed by N2 integers separated by white-space (newlines and spaces). These N2 integers make up the array in row-major order (i.e., all numbers on the first row, left-to-right, then all numbers on the second row, left-to-right, etc.). N may be as large as 100. The numbers in the array will be in the range [-127, 127].
 
 Output
 The output is the sum of the maximal sub-rectangle.
 
 Sample Input
 4
 0 -2 -7 0 9 2 -6 2
 -4 1 -4 1 -1
 8 0 -2
 Sample Output
 15
*/