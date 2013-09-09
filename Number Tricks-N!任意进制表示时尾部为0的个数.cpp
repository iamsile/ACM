#include <iostream>
using namespace std;
int a[10001],num[10001];
int main()
{
    int t,lab=1;
    scanf("%d",&t);
    while (t--) {
        int i,j,k,b,n,maxn,ans;
        memset(a, 0, sizeof(a));
        memset(num, 0, sizeof(num));
        scanf("%d%d",&b,&n);
        for (i=2,j=0; i*i<=b; i++) {
            while (b%i==0) {
                a[j]=i;
                num[j]++;
                b/=i;
            }
            j++;
        }
        a[j]=b;
        num[j]++;
        maxn=99999999;
        for (i=0; i<=j; i++)
            if (a[i]!=1&&a[i]!=0) {
                ans=0;
                for (k=a[i]; k<=n; k*=a[i])
                    ans+=n/k;
                ans/=num[i];
                if (ans<maxn)
                    maxn=ans;
            }
        printf("Case #%d: %d\n",lab++,maxn);
    }
    return 0;
}
/*
 此题自己做的时候一直Wrong Answer,后来改了一点点后终于Accepted,但还是不知错在哪里。改之后与改之前思路基本一样，就是实现形式不同而已，怪哉。
 该题思路与HOJ 1039很类似，在这题上我感受到了举一反三的重大作用。HOJ1039一题为N!在10进制数尾部0的个数，而此题为在任意进制表示的数的尾部0的个数。
 本质一样。10进制数时主要看其在N!中有多少个5*2，即将进制数分解为质因数的乘积。再看N!中有多少个质因数的乘积。如N!在45进制数时尾部为0的个数求法。
 45=3*3*5，找出在小于等于N的数中有a个3，有b个5，将3的个数除2得a/2与b比较，取小值即得0的个数。
 先将进制数分解质因数，在找出每个因子在N!的个数,将每个因子的个数除以每个因子的指数得到一组数，再取这组数中的最小值即为题中所求值。
 */
/*
#include<stdio.h>
int a[1010],q[205],len,num[1010];
int n,b;
void prime()//打质数表
{
    int i,j;
    for(i=3;i<=1000;i=i+2) a[i]=1;
    for(i=3;i<=1000;i=i+2)
        if(a[i])
            for(j=i*i;j<=1000;j=j+2*i)
                a[j]=0;
    q[1]=2;
    len=1;
    for(i=3;i<=1000;i=i+2)
        if(a[i]) q[++len]=i;//离散化
    return ;
}
int main()
{
    int i,j,t,k;
    int cases,ca=0;
    int ans;
    prime();
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&b,&n);
        for(i=0;i<=1000;i++)
            num[i]=0;
        for(i=1;i<=len;i++)//质因数分解
            while(b%q[i]==0)
            {
                num[q[i]]++;
                b=b/q[i];
            }
        ans=9999999;//再一次因为初始化问题让我WA了。。。。
        for(i=1;i<=len;i++)//
            if(num[q[i]])
            {
                t=q[i];
                k=0;
                while(n/t)
                {
                    k=k+n/t;
                    t=t*q[i];
                }
                if(k/num[q[i]]<ans) ans=k/num[q[i]];
            }
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}
 首先看n!后面的0的个数。当时我的想法是：10=5*2。在所有的数中出现质因数5的次数明显比2少。所以只需要
 寻找5的个数，然后又因为25,75,。。225。。这些数可以被5^2，或者5的更高次方整除的。他们含有质因子5的
 数目多余一个。。
 或者说给出n!,我们需要寻找在这1-n个数中寻找总共有多少个2的因子（4=2*2,4就含有两个2因子了）,
 寻找总共有多少个5的因子，然后因为是n!，1-n的n个数想成，所以我们可以看看可以凑成多少个（2*5）
 。。这样就是末尾0的个数了。。
 当时做这一题的时候没有想过还需要质因子分解等知识，自己也没有想太多。现在终于知道是怎么回事了。
 而这一题的意思是：给你两个数b,n 求出n!用b进制表示末尾有多少0
 看末尾有多少个0，就是看他能够被b的多少次方整除。b^x=n
 所以，这一题先把b质因数分解。假设为（a1^n1 * a2^n2 * ...an^nn a1,a2,...都是质数，任何一个合数
 都可以表示成质数相乘的形式！）
 所以我们可以把问题转化为求( a1^n1 * a2^n2 * ...an^nn )^x。
 这样的话，我们可以先求出每个质因子出现的次数。然后看出现了多少个 a1^n1 ， a2^n2 ， ...an^nn。
 取多少个中的最小值就是答案了。
 怎样看出现了多少个，其实就是只要用n这个最大的数去看就OK了。比如a1。我们可以用n/a1,结果就是在>=1&&<=n的数里，
 出现了n/a1个可以被a1整除的数；接着n/a1^2，结果就是在>=1&&<=n的数里，出现了n/a1^2个可以被a1^2整除的数，也就是说
 他们这些数因式分解后是含有>=2个的质因子a1的。。。。。总之找出a1在各个数因式分解后中出现的次数的总数。。
*/
/*
 Description
 Dora loves impressing her friends with number tricks. One of her favorite tricks is to let them name a number n. Dora will then tell them, how many zeroes there are at the end of n!. Usually, Dora’s friends are very impressed because n! is such a large number. For example, if n is 100, even though n! is bigger than the estimated number of atoms in the universe (not counting parallel universes, though), Dora can quickly tell that n! ends with exactly 24 zeroes. However, some of Dora’s newest friends are aliens with more or less than 10 fingers (or however you call the corresponding parts of their bodies). Like all life forms she has met so far, they count in a number system that has as many digits as they have fingers (even the centipedes from planet Millennium!). Dora wants to impress them as well, but she is not sure how to adapt her trick. Can you help her? Problem Given a base b and a number n, you should compute how many zeroes there are at the end of n! when written in base b. For example, consider b = 2 and n = 5. Since 5! = 120 = (1111000)2, the answer is three.
 Input
 The first line contains the number of scenarios. For each scenario, the input will consist of one line containing the two numbers b (2 <= b <= 1 000) and n (1 <= n <= 1 000 000), both given in base ten.
 Output
 The output for every scenario begins with a line containing “Case #i: ”, where i is the number of the scenario starting at 1. Then print a single line containing (in base ten) k, the number of zeroes at the end of n! when written in base b.
 Sample Input
 3
 2 5
 10 100
 45 10000
 Sample Output
 Case #1: 3
 Case #2: 24
 Case #3: 2498
*/