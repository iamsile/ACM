#include <iostream>
#include <map>
using namespace std;
int a[100010],b[100010],c[100010],r[100010];
int main()
{
    int n,s,w,q;
    while (scanf("%d%d%d%d",&n,&s,&w,&q)!=EOF) {
        if (!n&&!s&&!w&&!q)
            break;
        int i,num,g=s,sum=0;
        for (i=0; i<n; i++) {
            a[i]=(g/7)%10;
            if (g%2==0)
                g=g/2;
            else g=(g/2)^w;
        }
        if (q==2||q==5) {
            for (i=0,num=0; i<n; i++) {
                if (a[i])
                    num++;
                if (a[i]%q==0)
                    sum+=num;
            }
            printf("%d\n",sum);
        }
        else {
            map<int, int> dic;
            b[0]=1;
            for (i=1; i<=n; i++)
                b[i]=(b[i-1]*10)%q;
            a[n]=0;
            r[n]=0;
            for (i=n-1; i>=0; i--)
                r[i]=(r[i+1]+(a[i]%q)*b[n-i-1])%q;
            dic[0]=1;
            for (i=n-1; i>=0; i--) {
                if (a[i])
                    sum+=dic[r[i]];
                dic[r[i]]++;
            }
            printf("%d\n",sum);
            dic.clear();
        }
    }
    return 0;
}
/*第一次自己写的超时算法
#include <iostream>
#include <math.h>
using namespace std;
int a[100010],b[100010],c[100010],r[100010];
int main()
{
    int n,s,w,q;
    while (scanf("%d%d%d%d",&n,&s,&w,&q)!=EOF) {
        if (!n&&!s&&!w&&!q)
            break;
        int i,j,k,lab,g=s,sum=0;
        for (i=0; i<n; i++) {
            a[i]=(g/7)%10;
            if (g%2==0)
                g=g/2;
            else g=(g/2)^w;
        }
        if (q==2||q==5) {
            c[0]=0;
            for (i=0; i<n-1; i++)
                if (a[i])
                    c[i+1]=c[i]+1;
                else c[i+1]=c[i];
            for (i=n-1; i>=0; i--)
                if (a[i]%q==0) {
                    if (a[i]/q)
                        sum++;
                    sum+=c[i];
                }
            printf("%d\n",sum);
        }
        else {
            for (k=i,i=0,lab=0; i<k; i++) {
                if (a[k-i-1]) {
                    b[i]=a[k-i-1]*pow(10,i)+lab;
                    lab=b[i];
                }
                else b[i]=0;
                if (b[i]) {
                    r[i]=b[i]%q;
                    if (r[i]==0)
                        sum++;
                }
                else r[i]=-1;
            }
            for (i=0; i<k; i++) {
                for (j=i+1; j<k; j++)
                    if ((r[i]-r[j])%q==0&&r[i]!=-1&&r[j]!=-1)
                        sum++;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
*/
/*
 > 刚开始要产生一个a序列这个应该简单的（那个“^”是异或运算符，我还以为是幂运算呢，在这里卡了N久啊，悲剧），
 > 接下来呢，先把原序列倒一下，这样对每位的权好计算，比如a[0]直接就乘心10的0次方，a[i]直接乘以10的i次方然后将前面i项相加就得到了以a[i]结尾的对q取余的结果了。
 > 记为res[i],然后就是要找一个j，使得(res[i]-res[j])/(10^j)%q==0 (注意这里的“^”是次方的意思，即j个10相乘)
 > 下面部分可以用费马小定理解决，因为q是素数，当q不是2和5时1/(10^j)%q是不可能为0的，所以只要res[i]-res[j]为0就行了，那现在问题就转化为i前面有多少个对q取余是和i一样的了。这样问题就解决了一大半了，那如果当q是2时，我们知道，一个数对2取余为0时，他的末位应该是偶数（0，2，4，6，8）的，当q是5时，他的末位应该是0或5，这样问题就解决了。
 [野鸡大学]hl(195724606) 11:27:01
 你想， 假设子串(i,j)模Q是0，  那么后缀a[i]-后缀a[j]模Q也是0
 [野鸡大学]hl(195724606) 11:27:14
 哦 除了Q=2 Q=5我需要想想。。。。
 [野鸡大学]hl(195724606) 11:27:29
 a[i]-a[j-1]
 [野鸡大学]hl(195724606) 11:28:51
 2和5特判掉就行了。
 [野鸡大学]hl(195724606) 11:30:23
 按照同余类把后缀分类，  假设同余类里面有n个数， 就把答案加上 n*(n-1)/2
 */
/*
#include <iostream>
#include <map>
using namespace std;

map <int, int> mp;
int a[100010];
typedef long long ll;
int main()
{
    int n, s, w, p;
    while (cin >> n >> s >> w >> p)
    {
        if (n == 0) break;
        int g = s, ans = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = (g / 7) % 10;
            if (g % 2 == 0) g = g >> 1;
            else g = (g >> 1) ^ w;
        }
        if (p == 2 || p == 5)
        {
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                if (a[i]) ++cnt;
                if (a[i] % p == 0) ans += cnt;
            }
        }
        else
        {
            mp.clear();
            int v = 0, q = 1;
            mp[0] = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                v = (v + a[i] * q) % p;
                if (mp.find(v) == mp.end()) mp[v] = 0;
                if (a[i]) ans += mp[v];
                ++mp[v];
                q = q * 10 % p;
            }
        }
        cout << ans << endl;
    }
}
*/
/*
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;
#define N 100010
int b[N];
int a[N];
int res[N];
int f[N];
map <int ,int > mp;
void geta(int n,int s,int w)
{
    int g = s;
    for (int i = 0; i < n; i++)
    {
        
        a[i] = (g/7) % 10;
        if( g%2 == 0 )   { g = (g/2); }
        else             { g = (g/2) ^ w;}
    }
}
int main()
{
    int n,s,w,q;
    int i,j;
    int ans;
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    while (scanf("%d %d %d %d",&n,&s,&w,&q)!=EOF&&(n||s||w||q))
    {
        geta(n,s,w);
        b[0]=1;
        if (q==2||q==5)
        {
            ans=0;
            f[0]=0;
            for (i=0;i<n-1;i++)
                if (a[i]) f[i+1]=f[i]+1;
                else  f[i+1]=f[i];
            for (i=n-1;i>=0;i--)
                if (a[i]%q==0)
                {
                    if (a[i]/q) ans++;
                    ans+=f[i];
                }
            printf("%d\n",ans);
        }
        
        else
        {
            for (i=1;i<=n;i++)
                b[i]=(b[i-1]*10)%q;
            mp.clear();
            a[n]=0;
            res[n]=0;
            ans=0;
            for (i=n-1;i>=0;i--)
                res[i]=(res[i+1]+(a[i]%q)*b[n-1-i])%q;
            //memset(count,0,sizeof(count));
            mp[0]=1;
            for (i=n-1;i>=0;i--)
            {
                if (a[i]) ans+=mp[res[i]];
                mp[res[i]]++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
*/
/*
 Problem description
 You are given a sequence a0a1 · · · aN-1 of digits and a prime number Q. For each i ≤ j with ai ≠ 0, the subsequence aiai+1 · · · aj can be read as a decimal representation of a positive integer. Subsequences with leading zeros are not considered. Your task is to count the number of pairs (i, j) such that the corresponding subsequence is a multiple of Q. 
 
 Input
 The input consists of at most 50 datasets. Each dataset is represented by a line containing four integers N, S, W, and Q, separated by spaces, where 1 ≤ N ≤ 105, 1 ≤ S ≤ 109, 1 ≤ W ≤ 109, and Q is a prime number less than 108. The sequence a0 · · · aN-1 of length N is generated by the following code, in which ai is written as a[i].
 int g = S;
 for(int i = 0; i < N; i++) {
 a[i] = (g/7) % 10;
 if( g%2 == 0 )   { g = (g/2); }
 else             { g = (g/2) ^ W; }
 }
 
 Note: the operators /, %, and ^ are the integer division, the modulo, and the bitwise exclusiveor, respectively. The above code is meant to be a random number generator. The intended solution does not rely on the way how the sequence is generated. 
 The end of the input is indicated by a line containing four zeros separated by spaces.
 
 
 Output
 For each dataset, output the answer in a line. You may assume that the answer is less than 230. 
 
 
 Sample Input
 3 32 64 7
 4 35 89 5
 5 555 442 3
 5 777 465 11
 100000 666 701622763 65537
 0 0 0 0
 Sample Output
 2
 4
 6
 3
 68530
 Judge Tips
 In the first dataset, the sequence is 421. We can find two multiples of Q = 7, namely, 42 and 21.
 In the second dataset, the sequence is 5052, from which we can find 5, 50, 505, and 5 being the multiples of Q = 5. Notice that we don’t count 0 or 05 since they are not a valid representation of positive integers. Also notice that we count 5 twice, because it occurs twice in different positions.
 In the third and fourth datasets, the sequences are 95073 and 12221, respectively.
*/