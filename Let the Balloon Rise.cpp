#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n&&n) {
        char a[1010][40];
        int i,j,lab,flag,max;
        for (i=0; i<n; i++)
            cin >> a[i];
        max=1,flag=0;
        for (i=0; i<n; i++) {
            lab=1;
            if (a[i][0]=='\0')
                continue;
            for (j=i+1; j<n; j++) {
                if (a[j][0]=='\0')
                    continue;
                if (strcmp(a[i], a[j])==0) {
                    lab++;
                    a[j][0]='\0';
                }
            }
            if (lab>max) {
                max=lab;
                flag=i;
            }
        }
        cout << a[flag] << '\n';
    }
    return 0;
}
/*
 Problem Description
 Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.
 
 This year, they decide to leave this lovely job to you. 
 
 
 Input
 Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.
 
 A test case with N = 0 terminates the input and this test case is not to be processed.
 
 
 Output
 For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
 
 
 Sample Input
 5
 green
 red
 blue
 red
 red
 3
 pink
 orange
 pink
 0
 
 
 Sample Output
 red
 pink
*/