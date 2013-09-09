#include <iostream>
using namespace std;
typedef long long int64;
int64 num[10005],up[10005],down[10005],f[10005];

int main()
{
    int t,m,a,b,sum0,sum1,ans;
    cin>>t;
    while(t--)
	{
        cin >> m >> a >> b;
        for (int i=1;i<=m;i++) 
			cin>>num[i];
        sum0=num[1];
		sum1=0;
		up[1]=0;
        for(int i=2;i<=m;i++)
		{
            up[i]=up[i-1]+b*sum0+sum1;
            sum1+=sum0; 
			sum0+=num[i];
        }
        sum0=num[m];
		sum1=0; 
		down[m]=0;
        for (int i=m-1;i>=1;i--)
		{
            down[i]=down[i+1]+a*sum0+sum1;
            sum1+=sum0; 
			sum0+=num[i];
        }
        ans=1;
        for (int i=1;i<=m;i++)
		{
            num[i]=up[i]+down[i];
            if (num[ans]>up[i]+down[i]) 
				ans=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
 思路：设up[i]为在第i层停，向下走的乘客的总不满意度，down[i]为在第i层停，向上走的乘客的总不满意度。
 则有up[i] = sum(num[i - k] * (a * k + (k - 1) * k / 2)) k => 1..i - 1
 经过推导：up[i] = up[i - 1] + b * sum0[i] + sum1[i]，其中sum0[i] = sum(num[1..i])；
 sum1[i] = sum(sum0[1..i-1])
 同理有：down[i] = donw[i + 1] + b * sum0[i] + sum1[i]，其中sum0[i] = sum(num[i..m])；
 sum1[i] = sum(sum0[1..i-1])
*/
/*
 Problem description
 There's a building with M floors. The amounts of tenants of every floor are K1, K2, K3, ..., Km. One day all the tenants went home together and they took the same lift (suppose the lift was large enough). Because of some reason the lift could only stop on one floor and the tenants must go upstairs or downstairs to their houses. Every tenant went up N floors would make the dissatisfied degree rise N * a + 0.5 * N * (N - 1) degrees, and every tenant went down N floors would make the dissatisfied degree rise N * b + 0.5 * N * (N - 1) degrees. Your task is to tell which floor the lift should stop, in order to make the dissatisfied degree as low as possible.
 
 Input
 The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. The first line of each test contains M (1 <= M <= 10000), a and b (0 <= a, b <= 100). The second line contains K1, K2, K3, ..., Km(0 <= Ki <= 20, i = 1..M).
 
 Output
 For each test case, print a line containing a single integer, indicating which floor the lift should stop.
 
 Sample Input
 1
 5 3 2
 1 1 1 1 1
 Sample Output
 3
*/