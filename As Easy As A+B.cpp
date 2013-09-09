#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i,t,n;
    cin >> t;
    while (t--) {
        unsigned int a[1100]={0};
        cin >> n;
        for (i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        for (i=0; i<n; i++) {
            if (i>0)
                cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem Description
 These days, I am thinking about a question, how can I get a problem as easy as A+B? It is fairly difficulty to do such a thing. Of course, I got it after many waking nights.
 Give you some integers, your task is to sort these number ascending (升序).
 You should know how easy the problem is now!
 Good luck!
 
 
 Input
 Input contains multiple test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow. Each test case contains an integer N (1<=N<=1000 the number of integers to be sorted) and then N integers follow in the same line. 
 It is guarantied that all integers are in the range of 32-int.
 
 
 Output
 For each case, print the sorting result, and one line one case.
 
 
 Sample Input
 2
 3 2 1 3
 9 1 4 7 2 5 8 3 6 9
 
 
 Sample Output
 1 2 3
 1 2 3 4 5 6 7 8 9
*/