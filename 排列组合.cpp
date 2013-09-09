#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string.h>
using namespace std;

double cal(int k)
{
    double ans=1.0;
    for (int i=1; i<=k; i++)
        ans*=i;
    return ans;
}

int main()
{
    int n,m;
    while (cin >> n >> m) {
        int i,j,k,a[100];
        double c1[110],c2[110];
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=0; i<=n; i++)
            c1[i]=c2[i]=0.0;
        for (i=0; i<=a[0]; i++)
            c1[i]=1.0/cal(i);
        for (i=1; i<n; i++) {
            for (j=0; j<=n; j++)
                for (k=0; k<=a[i]&&k+j<=n; k++)
                    c2[j+k]+=c1[j]/cal(k);
            for (j=0; j<=n; j++) {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout << fixed << setprecision(0) << c1[m]*cal(m) << '\n';
    }
    return 0;
}
/*
 Problem Description
 有n种物品，并且知道每种物品的数量。要求从中选出m件物品的排列数。例如有两种物品A,B，并且数量都是1，从中选2件物品，则排列有"AB","BA"两种。
 
 
 Input
 每组输入数据有两行，第一行是二个数n,m(1<=m,n<=10)，表示物品数，第二行有n个数，分别表示这n件物品的数量。
 
 
 Output
 对应每组数据输出排列数。(任何运算不会超出2^31的范围)
 
 
 Sample Input
 2 2
 1 1
 
 
 Sample Output
 2
*/