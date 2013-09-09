#include <iostream>
using namespace std;

int main()
{
    int n,lab=0;
    char s,a,b,map[101][101];
    while (cin >> n >> a >> b) {
        int i,j,k=n/2;
        lab++;
        if (lab!=1)
            cout << '\n';
        if (n==1) {
            cout << a << '\n';
            continue;
        }
        if (k%2)
            k=n+1;
        else k=n;
        for (i=0; i<=n/2; i++) {
            if (k%2)
                s=a;
            else s=b;
            for (j=i; j<n-i; j++,k++) {
                map[i][j]=s;
                map[j][i]=s;
            }
            for (j=n-1-i; j>=i; j--) {
                map[n-1-i][j]=s;
                map[j][n-1-i]=s;
            }
        }
        map[0][0]=' ';
        map[0][n-1]=' ';
        map[n-1][0]=' ';
        map[n-1][n-1]=' ';
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++)
                cout << map[i][j];
            cout << '\n';
        }
    }
    return 0;
}
/*
 
 Problem Description
 需要的时候，就把一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错。这个工作现在要让计算机来完成，得看你的了。
 
 
 Input
 输入是一个个的三元组，分别是，外筐尺寸n（n为满足0<n<80的奇整数），中心花色字符，外筐花色字符，后二者都为ASCII可见字符；
 
 
 Output
 输出叠在一起的筐图案，中心花色与外筐花色字符从内层起交错相叠，多筐相叠时，最外筐的角总是被打磨掉。叠筐与叠筐之间应有一行间隔。
 
 
 Sample Input
 11 B A
 5 @ W
 
 
 Sample Output
 AAAAAAAAA 
 ABBBBBBBBBA
 ABAAAAAAABA
 ABABBBBBABA
 ABABAAABABA
 ABABABABABA
 ABABAAABABA
 ABABBBBBABA
 ABAAAAAAABA
 ABBBBBBBBBA
 AAAAAAAAA 
 
 @@@ 
 @WWW@
 @W@W@
 @WWW@
 @@@ 
*/