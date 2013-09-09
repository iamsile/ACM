#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,k,l,n,c1[10001],c2[10001],m[10001],s[10001];
        cin >> n >> k;
        for (i=0; i<=n; i++) {
            c1[i]=0;
            c2[i]=0;
        }
        for (i=1; i<=k; i++)
            cin >> m[i] >> s[i];
        for (i=0; i<=s[1]; i++)
            c1[i*m[1]]=1;
        for (i=2; i<=k; i++) {
            for (j=0; j<=n; j++)
                for (l=0; l<=s[i]&&j+l*m[i]<=n; l++)
                    c2[j+l*m[i]]+=c1[j];
            for (j=0; j<=n; j++) {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout << c1[n] << '\n';
    }
    return 0;
}
/*
 Problem Description
 又到了选课的时间了，xhd看着选课表发呆，为了想让下一学期好过点，他想知道学n个学分共有多少组合。你来帮帮他吧。（xhd认为一样学分的课没区别）
 Input
 输入数据的第一行是一个数据T，表示有T组数据。
 每组数据的第一行是两个整数n(1 <= n <= 40)，k(1 <= k <= 8)。
 接着有k行，每行有两个整数a(1 <= a <= 8),b(1 <= b <= 10)，表示学分为a的课有b门。
 Output
 对于每组输入数据，输出一个整数，表示学n个学分的组合数。
 Sample Input
 2
 2 2
 1 2
 2 1
 40 8
 1 1
 2 2
 3 2
 4 2
 5 8
 6 9
 7 6
 8 8
 Sample Output
 2
 445
*/