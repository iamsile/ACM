#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,m;
    while (cin >> n >> m) {
        int k,nr,nl,mr,ml,d1=sqrt(n),d2=sqrt(m);
        if (d1*d1!=n)
            d1++;
        if (d2*d2!=m)
            d2++;
        nr=(d1*d1-n)/2+1;
        nl=(n-(d1-1)*(d1-1)+1)/2;
        mr=(d2*d2-m)/2+1;
        ml=(m-(d2-1)*(d2-1)+1)/2;
        k=abs(nr-mr)+abs(nl-ml)+abs(d1-d2);
        cout << k << '\n';
    }
    return 0;
}
/*
 每个点都可以用三向坐标来表示
 最短路径=两点各坐标差的绝对值之和决定的。用三向坐标表示后，你会发现最短路径总是穿过3种线段，步数=各线段和=坐标差之和.有时侯把图转过几个角度或把元素分分类或掠取几条线都可能有新发现。
 
 #include<iostream>
 #include<cmath>
 using namespace std;
 int main()
 { 
 int n1,n2; 
 int i,alevel,aright,aleft,blevel,bright,bleft,steps; 
 
 while(cin>>n1>>n2)
 {
 alevel=1;
 blevel=1; 
 for(i=1;;i=i+2)
 { 
 if(n1-i<=0)
 {
 aright=(i-n1)/2+1;
 aleft=(n1+1)/2; 
 break;
 }
 alevel++;
 n1=n1-i;
 } 
 for(i=1;;i=i+2)
 { 
 if(n2-i<=0)
 {
 bright=(i-n2)/2+1;
 bleft=(n2+1)/2; 
 break;
 }
 blevel++;
 n2=n2-i;
 }
 steps=abs(alevel-blevel)+abs(aleft-bleft)+abs(aright-bright);
 cout<<steps<<endl;
 } 
 return 0;
 }
 Problem Description
 A triangle field is numbered with successive integers in the way shown on the picture below. 
 
 
 
 
 The traveller needs to go from the cell with number M to the cell with number N. The traveller is able to enter the cell through cell edges only, he can not travel from cell to cell through vertices. The number of edges the traveller passes makes the length of the traveller's route. 
 
 Write the program to determine the length of the shortest route connecting cells with numbers N and M. 
 
 
 Input
 Input contains two integer numbers M and N in the range from 1 to 1000000000 separated with space(s).
 
 
 Output
 Output should contain the length of the shortest route.
 
 
 Sample Input
 6 12 
 
 
 Sample Output
 3

*/