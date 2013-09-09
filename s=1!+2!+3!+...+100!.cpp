#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int i,j,len=1,a[1000]={1},sum[1000];
        for (i=1; i<=n; i++) {
            for (j=0; j<=len; j++)
                a[j]=a[j]*i;
            for (j=0; j<=len; j++)
                if (a[j]>9) {
                    if (j+1==len)
                        len++;
                    a[j+1]+=a[j]/10;
                    a[j]%=10;
                }
            for (j=0; j<len; j++) {
                sum[j]+=a[j];
                if (sum[j]>9) {
                    if (j+1==len)
                        len++;
                    sum[j+1]+=sum[j]/10;
                    sum[j]%=10;
                }
            }
        }
        for (j=len; j>=0; j--)
            if (a[j])
                break;
        for (i=j; i>=0; i--)
            cout << sum[i];
        cout << '\n';
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
    }
    return 0;
}