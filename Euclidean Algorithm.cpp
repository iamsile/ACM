#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define ll long long
#define max 51000
ll n,n_gcd,n_lcm,mod,mod2,c,prime[max];
int num[max],np;

ll mult_mod(ll x,ll y,ll n)
{
    ll t,T,a,b,c,d,e,f,g,h,v,ans;
    T=(ll)sqrt(double(n)+0.5);
    t=T*T-n;
    a=x/T;
    b=x%T;
    c=y/T;
    d=y%T;
    e=a*c/T;
    f=a*c%T;
    v=((a*d+b*c)%n+e*t)%n;
    g=v/T;
    h=v%T;
    ans=(((f+g)*t%n+b*d)%n+h*T)%n;
    while (ans<0) {
        ans+=n;
    }
    return ans;
}

ll cal(ll m,ll n)
{
    ll a,ans=1;
    rand();
    a=rand();
    a*=rand()%(n-1);
    a*=rand()%(n-1);
    a=a%(n-1)+1;
    while (m) {
        if (m&1)
            ans=mult_mod(ans, a, n);
        m>>=1;
        a=mult_mod(a, a, n);
    }
    return ans;
}

int miller_rabin(ll n)
{
    if (n==2)
        return 1;
    if (n<2||(n&1)==0)
        return 0;
    ll m=n-1,s=0,a,i,j;
    while (!(m&1)) {
        m>>=1;
        s++;
    }
    for (i=1; i<=10; i++) {
        a=cal(m,n);
        if (a==1)
            continue;
        for (j=1; j<=s; j++) {
            if (a==n-1)
                break;
            a=mult_mod(a, a, n);
        }
        if (j>s)
            return 0;
    }
    return 1;
}

ll gcd(ll a,ll b)
{
    if (b==0)
        return a;
    else return gcd(b, a%b);
}

ll f(ll x,ll n)
{
    return (mult_mod(x, x, n)+1)%n;
}

ll pollard_rho(ll n)
{
    if (n<2)
        return 0;
    if (!(n&1))
        return 2;
    ll x,y,i,d;
    for (i=1; i<=10; i++) {
        rand();
        x=rand()%n;
        y=f(x,n);
        d=gcd((y-x+n)%n, n);
        while (d==1) {
            x=f(x,n);
            y=f(f(y, n), n);
            d=gcd((y-x+n)%n, n)%n;
        }
        if (d)
            return d;
    }
    return 0;
}

int use[max];
void calc(int e,ll d)
{
    int i;
    ll now=n/d,ol=n/d;
    for (i=0; i<=e; i++)
        if (use[i]!=num[i])
            ol=ol-ol/prime[i];
    for (i=e+1; i<np; i++)
        ol=ol-ol/prime[i];
    n_gcd+=((d%mod)*(ol%mod))%mod;
    n_gcd%=mod;
    n_lcm+=(((n/d)%mod2)*ol)%mod2;
    n_lcm%=mod2;
}

void dfs(int s,int t,ll last)
{
    if (s>=np||t>=num[s])
        return;
    int i;
    use[s]=0;
    dfs(s+1, 0, last);
    for (i=t; i<num[s]; i++) {
        use[s]++;
        last*=prime[s];
        calc(s, last);
        dfs(s+1, 0, last);
    }
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while (T--) {
        scanf("%I64d%I64d",&n,&c);
        mod=c;
        np=0;
        mod2=2*c;
        ll temp=n;
        while (!miller_rabin(temp)&&temp!=1) {
            num[np]=0;
            ll now=pollard_rho(temp);
            prime[np]=now;
            while (temp%now==0) {
                temp/=now;
                num[np]++;
            }
            np++;
        }
        if (temp!=1) {
            prime[np]=temp;
            num[np]=1;
            np++;
        }
        n_gcd=n_lcm=0;
        calc(-1, 1);
        dfs(0, 0, 1);
        n_lcm = (n_lcm*(n%mod2))%mod2;
        n_lcm = (n_lcm+(n%mod2))%mod2;
        n_lcm = (n_lcm/2)%mod;
        if (n_lcm==n_gcd)
            puts("yes");
        else puts("no");
    }
    return 0;
}
/*
 从1到n（闭区间）所有数与n的gcd 与 lcm的和：
 穷举 n的所有约数 d 对于 每个gcd(I,n)=d 它的个数等价于 gcd(I/d,n/d)=1即phi(n/d)即n/d 的欧拉函数  
 可以将lcm(I,n)用  公式展开，这样可以推出 
 这样gcd和lcm都可以理论求出来了
 
 至于枚举每个数的质因子 可以用随机素数测试法
 复杂度大概为 这个算法就是个模板具体见代码。
 枚举约数d只需要根据质因子以及其个数 dfs一次就可以了，可能估计一下这个因子数不会很大。
 */
/*
 Problem Description
 wr recently learned the Euclidean algorithm to solve the greatest common divisor,then he realized that the algorithm can also be able to solve the least common multiple.In order to train the skill of code,he find a number p(1<=p<=2^25)and a number q(1<=q<=2^25) then he got n=p*q,he calculated a1=∑gcd(i, n) 1<=i <=n and a2= ∑lcm(i, n) 1<=i <=n,he wants to know if a2-a1 is the multiple of c(1<=c<=10^9)
 
 
 Input
 The first line contains the number of scenarios.
 Every scenario consists of a single line containing two integers n and c separated by a space.
 
 
 Output
 for every scenario print a single line contain "yes" or "no"
 if the difference is the multiple of c print "yes",otherwise print "no"
 
 
 Sample Input
 2
 6 100
 4 2
 
 
 Sample Output
 no
 yes
*/