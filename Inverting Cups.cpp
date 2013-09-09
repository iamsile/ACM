#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
__int64 a,b;

__int64 f(__int64 a, __int64 b)
{
    
    __int64 res=0;
    if (a%b==0)
        return a/b;
    if (a>=3*b) {
        res+=a/b-2;
        a=(a%b)+2*b;
    }
    if (a>=2*b) {
        if (a%2==b%2) 
            res+=3;
        else if (a%2==0) 
            res+=4;
        else res=-1;
    }
    else if (a%2==b%2) 
        res+=3;
    else if (a%2==0)
        return f(a, a-b);
    else res=-1;
    return res;
}

int main()
{
    while (scanf("%I64d%I64d",&a,&b)!=EOF)
    {
        __int64 res=f(a,b);
        if (res>0)
            printf("%I64d\n", res);
        else printf("No Solution!\n");
    }
    return 0;
}
/*
 题意是给出A个杯子，一开始都朝上，每次可以翻B个杯子，问最少需要翻转多少次可以让所有杯子都朝下。
 分类讨论：
 首先对于A%B==0一类情况，直接输出。
 对于A>=3B，让A减到[2B,3B)区间内，翻转次数累加上A/B-2。
 当A>=2B时，分奇偶讨论：A为奇数B为偶数显然无解；AB同奇偶时最多需要3次，A偶数B奇数最多需要4次。
 当A<2B时，分奇偶讨论：AB同奇偶时最多需要3次，A奇数B偶数无解，A偶数B奇数时，有F(A,B)=F(A,A-B)成立，可以转换成上面的情况求解即可。
 具体证明画画图就知道了，将两个B分别放到对称的位置上，想办法调整使得每次改变自己需要的杯子就行。对于A偶B奇的F(A,B)=F(A,A-B)，其实挺好想的，因为A是偶数，B是奇数，而每个杯子一共翻转了奇数次，而一共一定是要翻转偶数轮，因此每个杯子不翻转的次数也是奇数次，也就相当于对“翻转”操作“取反”，每次翻转A-B个，结果是一样的，因此F(A,B)=F(A,A-B)成立。
 另外：注意cin,cout超时。。。。。。
 n个杯子，一次翻转m个杯子。杯子初始状态都朝下。
 可以观察到在朝下的杯子和朝上的杯子足够多的时候，一次操作可以让朝上的杯子增加m,m-2,m-4.....-m+2,-m。比如：
 m=5的时候一次操作可以让朝上的杯子增加-5,-3,-1,1,3,5个。
 m=4时候是4,2,0,-2,-4。
 这个道理很简单，也很好想。
 当然在某种杯子数量不够多的时候，并不一定能做这几个操作。比如一开始就只能做增加m个朝上杯子的操作。
 当两种杯子都大于n的时候，任意一种操作都可以。（定理一）更详细的结论：
 (以下四个定理的k均大于0,整除下取整)
 偶数的情况：
 增加2k个朝上的杯子，需要m/2+k个朝下的杯子，m/2-k个朝上的杯子。（定理二）
 减少2k个朝上的杯子，需要m/2+k个朝上的杯子，m/2-k个朝上的杯子。（定理三）
 奇数的情况：
 增加2k+1朝上的杯子，需要m/2+k+1个朝下的杯子，需要m/2-k个朝上的杯子。（定理四）
 减少2k+1朝上的杯子，需要m/2+k+1个朝上的杯子，需要m/2-k个朝下的杯子。（定理五）
 接下来分几种情况来讨论：
 1
 n=奇数m等于偶数的情况：由于每次操作都是增加偶数个朝上杯子，所以无解。
 
 接下来的几种情况都有解，我的思路是在最前面的几次操作中让朝下的杯子变成m的整数倍，然后大家都懂的……
 当然，当n一开始就整除m的时候，答案就是n/m。
 
 2
 n=偶数m等于偶数的情况：
 先设n%m=2k。（余数必然为偶数）
 这又有两种情况：
 n>2*m:
 先增加m个朝上的杯子，然后由定理一，增加2k个杯子。这样剩下的杯子就已经是m的整数倍了，然后再把剩下的杯子全部翻转过来。
 这样的步数是n/m+1。这一定是最优解。
 因为n/m步最多最能翻转n-2k个杯子。所以一定还需要更多的步数。步数是整数，所以我的这种做法一定是最优解。
 n<2*m:
 先增加m个朝上的杯子，然后减少(m-2k)个朝上的杯子。由定理三，我们需要m-k朝上的杯子，k个朝下的杯子才能完成这个操作。这步操作一定可以完成。
 这样总的操作步数为n/m+2(因为减少花了一次，并且需要n/m+1次完整的增加m个杯子的操作才能达成目标态)
 另外由于m<n<2*m，所以n/m=1，所以总步数一定为3。
 这也一定是最优解，因为第一步只有增加m个杯子，然后可以证明第二步一定不能达成目标态*。所以三步就是最优解。
 
 *证明很简单，你剩下的朝下的杯子都不够m个，下次操作必然会翻转一些原来朝上的杯子，无法达到目标态
 3
 m=奇数
 n%m是一个偶数2k：
 增加m，减少一个数(=m-2k=2k'+1)使剩下的朝下的杯子是m的整数倍。这需要步数为n/m+2。这步需要m/2+(m-2k-1)/2+1个朝上的杯子(定理四)。由于m/2+m/2+1=m(除法下取整)，所以朝上的杯子够。需要m/2-(m-2k-1)/2朝下的杯子，由于2k+1/2<2k，所以朝下的杯子够。所以这步操作一定能实现。
 n/m步之后还会剩下2k个朝下的杯子，至少需要两步才能达到目标态（因为每次的增加或减少是奇数）。这一定是最优解。
 4
 m=奇数
 n%m是一个奇数k：
 n>2*m:
 还是先增加m个朝上的杯子，然后增加余数（定理一）。然后步数就是n/m+1。最优解证明同上。
 n<2*m:
 可以证明此时n为一个偶数(n=m+k)。由于每两次操作至少会有2*m-n个元素被重复操作了两次(n很小)。总操作次数为2*m。浪费了4*m-2*n次操作。实际操作次数为2*(n-m)。
 所以我们每两次操作可以等价为每次翻转n-m个两次操作。由于n是偶数，答案必然是偶数(每次增加奇数)。所以我们可以把m变为n-m，这样就有n>2*m(原来m>n/2，新的m'=n-m,必然n>2*m')，然后重新判断*。
 
 *证明
 假设如果等价前为m 等价后m'，最优解分别为a,a'
 如果a比a'小，那么我们可以由m的方案等价得到一个m'的方案，从而得到一个更优的m'的方案
 但是之前我们已经证明过我们的解是最优，所以a不能比a'小
 a也不可能比a‘大，因为我们可以由m’的最优解等价得到m的最优解。
 所以a=a'
*/
/*
 Problem Description
 When people drink some tea in the teahouse, they also play some casual games. Now, inverting cups is a popular game. The meaning of the question is, now there are some cups which are upturned, we can regard the total number of the cups as a positive integer number A , and we can invert some cups, the number is B and B is also a positive integer number. We define one retroflexion that if the original cup is upturned, one retroflexion makes it downward, and if the original cup is downward, one retroflexion makes it upturned. So the question is if the whole original cups are upturned , can we invert these cups to make all the cups downward? And if it is possible, how many is the least of times?
 
 
 Input
 The input contains multiple test cases(cases<=100000). Each case one line given two numbers , the first integer A (1<=A<=2^63) and the second integer B (1<=B<=A). The input is terminated by the end of file.
 
 
 Output
 For each test case, you should output how many the least of times if it is possible for us to invert all the cups, and if it is impossible please output “No Solution!”
 
 
 Sample Input
 5 3
 14 4
 8 5
 11 4
 
 
 Sample Output
 3
 4
 4
 No Solution!
*/