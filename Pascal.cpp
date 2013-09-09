#include <stdio.h>
#include <math.h>

__int64 mod(__int64 x,__int64 n,__int64 p)
{
    if(n==0)
        return 1;
    __int64 temp=mod((x*x)%p,n/2,p);
    if((n&1)!=0)
        temp=(temp*x)%p;
    return temp;
}

int main()
{
    int t,lab=1;
    scanf("%d",&t);
    while(t--)
    {
        __int64 n,sum1,sum2,sum;
        scanf("%I64d",&n);
        if(n==1)
            printf("%d. Sum = 1\n",lab++);
        else 
        {
            sum1=((2*n)%1234567-3)%1234567;
            sum2=mod(2,n-1,1234567);
            sum=(sum1+sum2)%1234567;
            printf("%d. Sum = %I64d\n",lab++,sum);
        }
    }
    return 0;
}
/*
 Problem description
 Pascal's triangle is a triangle of numbers. The triangle starts with one on its first row and each number in subsequent lines is equal to the sum of the two numbers above it (top left and top right). If one of the two numbers doesn't exist, it is substituted with zero. The picture to the right shows the first six rows in Pascal's triangle.
 
 Pascal's triangle is amazingly interesting. It is one thing that have an infinite number of patterns and properties; for example the number at row r and column c is the binomial coefficient (in Combinatorics n choose r). This triangle can also be connected to Fibonacci numbers, powers of 11, Fourier transform, Sierpinski triangle and much more!
 
 In this problem, we are interested in one simple property of the triangle which is the sum of the numbers on the border of a triangle with N rows. Since the sum may be quite large, print it mod 1234567.
 
 Input
 The first line contains T ≤ 1000 the number of triangles, T lines follow, each with an integer 1 ≤ N ≤ 109 representing the number of rows of the triangle.
 
 Output
 For each triangle print one line in the format: "t. Sum = S" without double quotes, where t is the triangle number starting from 1 and S is the sum as described above.
 
 Sample Input
 2
 2
 6
 Sample Output
 1. Sum = 3
 2. Sum = 41
*/