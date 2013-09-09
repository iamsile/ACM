#include<iostream>
#include<math.h>
using namespace::std;

int main()
{
    int a,b,n,s,t;
    double sum,ans,ant;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> s >> t;
        ant=acos(t/(float)a);
        ans=acos(s/(float)a);
        sum=a*b*((sin(2*ant)-sin(2*ans))/2-(ant-ans));
        printf("%.3f\n",sum);
    }
    return 0;   
}
/*
 Math is important!! Many students failed in 2+2’s mathematical test, so let's AC this problem to mourn for our lost youth..
 Look this sample picture:
 
 
 
 
 A ellipses in the plane and center in point O. the L,R lines will be vertical through the X-axis. The problem is calculating the blue intersection area. But calculating the intersection area is dull, so I have turn to you, a talent of programmer. Your task is tell me the result of calculations.(defined PI=3.14159265 , The area of an ellipse A=PI*a*b )
 
 
 Input
 Input may contain multiple test cases. The first line is a positive integer N, denoting the number of test cases below. One case One line. The line will consist of a pair of integers a and b, denoting the ellipse equation , A pair of integers l and r, mean the L is (l, 0) and R is (r, 0). (-a <= l <= r <= a).
 
 
 Output
 For each case, output one line containing a float, the area of the intersection, accurate to three decimals after the decimal point.
 
 
 Sample Input
 2
 2 1 -2 2
 2 1 0 2
 
 
 Sample Output
 6.283
 3.142
*/