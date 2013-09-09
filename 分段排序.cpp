#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--) {
        char a[1001];
        gets(a);
        int i,j,m,l,k=strlen(a),sum=0,b[1001],c[1001],d[1001];
        for (i=0,j=0; i<k; i++) {
            if (a[i]!=' ')
                sum=sum*10+a[i]-'0';
            else if (a[i]==' ') {
                b[j++]=sum;
                sum=0;
            }
        }
        b[j++]=sum;
        for (i=0,l=0,m=0; i<j; i++)
            if (i%2==0)
                c[l++]=b[i];
            else d[m++]=b[i];
        sort(c, c+l);
        sort(d, d+m);
        for (i=0,l=0,m--; i<j; i++) {
            if (i)
                cout << ' ';
            if (i%2==0)
                cout << c[l++];
            else cout << d[m--];
        }
        cout << '\n';
    }
    return 0;
}
/*
 Problem description
 
 
 对于一个整数列进行排序，其中位置为偶数的按照从大到小排列，奇数位置的数按照从小到大排列，第一个数的位置为1，依此类推。
 
 Input
 
 输入的第一行为一个整数N表示有N行数列，接下来N行输入，每一行输入个数列，数用空格隔开。
 
 Output
 
 对于输入的每一行数列对应输出一行排好序的数列，数之间用空格隔开。
 
 Sample Input
 2
 3 7 4 3 1 9 7
 9 0 3 7 4 8 12 43
 Sample Output
 1 9 3 7 4 3 7
 3 43 4 8 9 7 12 0
*/