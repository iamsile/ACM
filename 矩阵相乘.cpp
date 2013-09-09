#include <iostream>
using namespace std;
int a[101][101],b[101][101],c[101][101];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,k,x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (i=0; i<x1; i++)
            for (j=0; j<y1; j++)
                cin >> a[i][j];
        for (i=0; i<x2; i++)
            for (j=0; j<y2; j++)
                cin >> b[i][j];
        if (x1!=y2||y1!=x2) {
            cout << "error\n";
            continue;
        }
        memset(c, 0, sizeof(c));
        for (i=0; i<x1; i++)
            for (j=0; j<y2; j++)
                for (k=0; k<y1; k++)
                    c[i][j]+=a[i][k]*b[k][j];
        for (i=0; i<x1; i++) {
            for (j=0; j<y2; j++) {
                if (j)
                    cout << ' ';
                cout << c[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
/*
 Problem description
 
 
 求两个矩阵相乘后得到的新矩阵。
 
 Input
 
 第一行一个整数T（T<=10），表示有T组测试数据，每组测试数据的第一行四个整数，分别表示相乘的两个矩阵的行和列数，接下来分别按照行与列的格式给出两个矩阵，同行数字之间用空格隔开。
 
 Output
 
 每组测试数据按照行与列的格式输出相乘后的得到的新矩阵，如果两个矩阵不能相乘，则输出一行为error。
 
 Sample Input
 2
 1 2 2 1
 3 4
 5
 6
 2 3 2 2
 2 3 4
 8 1 3
 10 5
 20 93
 Sample Output
 39
 error
*/