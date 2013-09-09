#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n&&n) {
        int i,flag=1;
        double a[50],sum=0.0;
        for (i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        if (n==1) {
            cout << "NO\n";
            continue;
        }
        if (n==2) {
            if (a[0]==a[1])
                cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        sum=a[0]+a[1];
        for (i=2; i<n&&flag; i++) {
            if (a[i]<=sum) {
                flag=0;
                break;
            }
            sum+=a[i];
        }
        if (!flag)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
 分析：
 如果有个子集S能构成多边形且不含最短的一段ai，则可以把ai加入S，依然是一个多边形。故S一定含有最短边ai。
 将这些半圆排序。设从小到大为b1, b2, b3, …… , bn。如果存在某一子集S'能构成多边形，S' = {bi1, bi2, …… , bik} (bi1≤bi2≤……≤bik)，即
 bik ≤ bi1 + …… + bi(k-1).
 则b1, b2, …… , bik 必能构成多边形。因为，（设S = {b1, b2, …… , bik}, S' = {bi1, bi2, …… , bik}, S'' = S - S'）
 bik ≤ bi1 + …… + bi(k-1) ≤ bi1 + …… + bi(k-1) + sum(S'').
 （函数sum(A)对集合A的所有元素求和）
 注意：排序的原因是避免加入过大的段，从而破坏多边形。
 
 由上所诉，算法为
 sorts input array w;
 sum = w1 + w2;
 for i = 2 to n
 if wi ≤ sum then
 print "They can be made a closed shape."
 else sum = sum + wi;

 Problem description
 George has K ≤ 20 steel wires shaped in the form of half-circles, with radii a1, a2, . . . , aK. They can be soldered (connected) at the ends, in any angle. Is it possible for George to make a closed shape out of these wires? He does not have to use all the wires. 
 The wires can be combined at any angle, but may not intersect. Beware of floating point errors.
 
 Input
 Each data set consists of a number 0 < K ≤ 20 on a line by itself, followed by a line of K space-separated numbers ai. Each number is in the range 0 < ai < 107, and has at most 3 digits after the decimal point. 
 The input will be terminated by a zero on a line by itself.
 
 Output
 For each test case, there should be one word on a line by itself; "YES" if it is possible to make a simple connected figure out of the given arcs, and "NO" if it isn’t. 
 
 Sample Input
 1
 4.000
 2
 1.000 1.000
 3
 1.455 2.958 4.424
 7
 1.230 2.577 3.411 2.968 5.301 4.398 6.777
 0
 Sample Output
 NO
 YES
 NO
 YES
*/