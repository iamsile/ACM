#include <iostream>
#include <string.h>
using namespace std;
int n,m,a[1000001],b[100001],c[100001];

void next()
{
    int j=1,k=0;
    c[1]=0;
    while (j<m) {
        if (k==0||b[k]==b[j]) {
            j++;
            k++;
            c[j]=k;
        }
        else k=c[k];
    }
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for (i=1; i<=m; i++)
            scanf("%d",&b[i]);
        next();
        i=1;
        j=1;
        while (i<=n&&j<=m) {
            if (j==0||a[i]==b[j]) {
                i++;
                j++;
            }
            else j=c[j];
        }
        if (j>m)
            cout << i-m << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
/*
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int i,j,x,c,n,m,a[100],b[100],dfa[260][260];
        cin >> n >> m;
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=0; i<m; i++)
            cin >> b[i];
        dfa[b[0]][0]=1;
        for (x=0,j=1; j<m; j++) {
            for (c=0; c<260; c++)
                dfa[c][j]=dfa[c][x];
            dfa[b[j]][j]=j+1;
            x=dfa[b[j]][x];
        }
        for (i=0,j=0; i<n&&j<m; i++)
            j=dfa[a[i]][j];
        if (j==m)
            cout << i-m+1 << '\n';
        else cout << "-1\n";
    }
    return 0;
}
*/
/*
 Problem Description
 Given two sequences of numbers : a[1], a[2], ...... , a[N], and b[1], b[2], ...... , b[M] (1 <= M <= 10000, 1 <= N <= 1000000). Your task is to find a number K which make a[K] = b[1], a[K + 1] = b[2], ...... , a[K + M - 1] = b[M]. If there are more than one K exist, output the smallest one.
 
 
 Input
 The first line of input is a number T which indicate the number of cases. Each case contains three lines. The first line is two numbers N and M (1 <= M <= 10000, 1 <= N <= 1000000). The second line contains N integers which indicate a[1], a[2], ...... , a[N]. The third line contains M integers which indicate b[1], b[2], ...... , b[M]. All integers are in the range of [-1000000, 1000000].
 
 
 Output
 For each test case, you should output one line which only contain K described above. If no such K exists, output -1 instead.
 
 
 Sample Input
 2
 13 5
 1 2 1 2 3 1 2 3 1 3 2 1 2
 1 2 3 1 3
 13 5
 1 2 1 2 3 1 2 3 1 3 2 1 2
 1 2 3 2 1
 
 
 Sample Output
 6
 -1
*/