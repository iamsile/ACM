#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        double a,b,c,k,lab;
        cin >> a >> b >> c;
        lab=b*b-4*a*c;
        if (lab<0)
            cout << "NO\n";
        else if (lab==0)
        {
            k=0-(b/(2*a));
            printf("%.2f\n",k);
        }
        if (lab>0)
        {
            double x1=((0-b)+sqrt(lab))/(2*a);
            double x2=((0-b)-sqrt(lab))/(2*a);
            if (x1>x2)
                printf("%.2f %.2f\n",x2,x1);
            else printf("%.2f %.2f\n",x1,x2);
            
        }
    }
    return 0;
}
/*
 Problem Description
 Wei wei is a pupil. He is tired of calculating the quadratic equation. He wants you to help him to get the result of the quadratic equation. The quadratic equation’ format is as follows: ax^2+bx+c=0.
 Input
 The first line contains a single positive integer N, indicating the number of datasets. The next N lines are n datasets. Every line contains three integers indicating integer numbers a,b,c (a≠0).
 Output
 For every dataset you should output the result in a single line. If there are two same results, you should just output once. If there are two different results, you should output them separated by a space. Be sure the later is larger than the former. Output the result to 2 decimal places. If there is no solution, output “NO”.
 Sample Input
 3
 1 2 1
 1 2 3
 1 -9 6
 Sample Output
 -1.00
 NO
 0.73 8.27
*/