#include <iostream>
using namespace std;

int main()
{
    int n,m,k,l=1;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
        int i,a[1020],j=n*m;
        for (i=0; i<j; i++)
            cin >> a[i];
        sort(a, a+j);
        cout << "Scenario #" << l++ << '\n';
        cout << a[j-k] << "\n";
    }
    return 0;
}
/*
 Problem description
 There are n classes in Mr Li's grade.And each class have m students.The last examination's ranked results have been finished.Now Mr Li wants to know the score of the student who got the kth place.
 
 Input
 Each test case have three integers n,m,k(1≤n≤10, 1≤m≤100,1≤k≤n*m) in the first line.Then,there are n lines,one line indicating the scores of one class.Each line contains m positive integers.
 Process to the end of file.
 
 Output
 For each test case, first print a line saying "Scenario #k", where k is the number of the test case.Then,output one integer the score of student who are placed kth,in one line.Print a blank line after each test case, even after the last one.
 
 Sample Input
 2 4 4
 90 87 98 59
 78 67 88 99
 Sample Output
 Scenario #1
 88
*/