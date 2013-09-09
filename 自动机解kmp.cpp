#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[100],b[100];
    while (cin >> a >> b) {
        int m=strlen(a),n=strlen(b);//a是输入的原始串，b是输入的要匹配的串
        int dfa[300][300]={0},i,j,x,c;
        dfa[a[0]][0]=1;
        for (x=0,j=1; j<n; j++) {//求要匹配的串的自动机
            for (c=0; c<300; c++)
                dfa[c][j]=dfa[c][x];
            dfa[b[j]][j]=j+1;
            x=dfa[b[j]][x];
        }
        for (i=0,j=0; i<m&&j<n; i++)
            j=dfa[a[i]][j];
        if (j==n)
            cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}