#include <iostream>
using namespace std;
double a[100001];

int main()
{
    long n;
    while (cin >> n) {
        if(!n) {
            cout << "0\n";
            continue;
        }
        long sum=1,i;
        double left;
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=1,left=a[0]+1; i<n; i++)
            if (left<=a[i]) {
                left=a[i]+1;
                sum++;
            }
        cout << sum << '\n';
    }
    return 0;
}
/*
 Problem description
 Joe is a skilled programmer. The management of the highway police division wants to control the traffic on the highway, and hired him to solve the following problem. There are some fixed control points on the highway. The highway police division wants to place specialized devices to record information from all the control points. Such a device is very expensive and unfortunately can cover an interval of only one meter (including the left endpoint and excluding the right endpoint). The management wants to place the minimum number of devices to cover all the control points. Joe must find an efficient solution. 
 
 
 Input
 The program input is from a text file. Each data set in the file stands for a particular configuration of control points. A data set starts with the number n (n ≤ 100000) ? the number of control points, followed by the real values in ascending order describing the coordinates of the control points (the highway is considered a real line). The coordinates are expressed in meters. White spaces can occur freely in the input. The input data terminate with an end of file. 
 
 
 Output
 For each set of data the program has to print the minimum number of devices needed to cover all the control points to the standard output. 
 
 
 Sample Input
 2 
 3.56 4 
 3 
 1 2 2.9
 Sample Output
 1 
 2
*/