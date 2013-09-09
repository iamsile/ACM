#include <iostream>
#include <string.h>
using namespace std;
int c[110][110];

int lcs(char a[],char b[],int n,int m)
{
    if (a[n]==b[m]&&n>1&&m>1)
        c[n][m]=lcs(a, b, n-1, m-1)+1;
    if (a[n]!=b[m]&&n>1&&m>1)
        c[n][m]=max(lcs(a, b, n-1, m), lcs(a, b, n, m-1));
    return c[n][m];
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        char a[100],b[100];
        cin >> a >> b;
        int i=strlen(a),j=strlen(b);
        memset(c, 0, sizeof(c));
        lcs(a,b,i,j);
        cout << c[i][j] << '\n';
        for (int k1=0; k1<=i; k1++) {
            for (int k2=0; k2<=j; k2++) {
                cout << c[k1][k2] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}