#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    int tmp;
    while (b) {
        tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        unsigned i,j,n,sum=0,ans,a[10010],b[10010],c[10010];
        cin >> n;
        for (i=1; i<=n; i++) {
            cin >> a[i];
            b[i]=c[i]=0;
        }
        for (i=1; i<=n; i++) {
            for (j=1; j<i; j++) {
                if (gcd(a[i],a[j])==1)
                    b[i]++;
                else c[i]++;
            }
            for (j=i+1; j<=n; j++) {
                if (gcd(a[i],a[j])==1)
                    b[i]++;
                else c[i]++;
            }
            sum+=b[i]*c[i];
        }
        ans=n*(n-1)*(n-2)/6-sum/2;
        cout << ans << '\n';
    }
    return 0;
}
/*
 题目描述：
 给你n个数，问满足条件1或者条件2的a，b，c组合有多少个。
 条件1：任意两个互质
 条件2：任意两个不互质
 解题报告：
 只要统计a[i]:和第i个数互质的有多少个。
 和b[i]：和第i个数不互质的有多少个。
 那么a[i] * b[i]是包含i的不合法的组合的一个子集。
 不难发现，对每个i进行这样的操作，能够覆盖到所有的不满足条件的abc，而且是算了两次。
 所以，最后就是C(n,3)- sum/2即可。
 
 */
/*
#include<stdio.h>
#define MAXN 10010
int a[MAXN],b[MAXN],num[MAXN];
int gcd(int da,int xiao)//求最大公约数的循环形式 
{
    int temp;
    while(xiao!=0)
    {
        temp=da%xiao;
        da=xiao;
        xiao=temp;
    }    
    return da;
} 
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int T,n,i,j;
    int sum;//不符合的总数 
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            a[i]=0;//a[i]表示与num[i]互质的数的个数 
            b[i]=0;//a[i]表示与num[i]不互质的数的个数
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if(gcd(num[i],num[j])==1)  a[i]++;
                else  b[i]++;
            } 
            for(j=i+1;j<=n;j++)
            {
                if(gcd(num[i],num[j])==1)  a[i]++;
                else  b[i]++;
            }
            sum+=a[i]*b[i];       
        }
        int cnt=n*(n-1)*(n-2)/6-sum/2;
        printf("%d\n",cnt);       
    } 
    return 0;   
}    
*/
/*
 Problem Description
 Given many different integers, find out the number of triples (a, b, c) which satisfy a, b, c are co-primed each other or are not co-primed each other. In a triple, (a, b, c) and (b, a, c) are considered as same triple.
 
 
 Input
 The first line contains a single integer T (T <= 15), indicating the number of test cases.
 In each case, the first line contains one integer n (3 <= n <= 800), second line contains n different integers d (2 <= d < 105) separated with space.
 
 
 Output
 For each test case, output an integer in one line, indicating the number of triples.
 
 
 Sample Input
 1
 6
 2 3 5 7 11 13
 
 
 Sample Output
 20
*/