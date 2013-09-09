#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) {
        unsigned n;
        scanf("%d",&n);
        int k=(int)sqrt(n)+(int)sqrt(n/2);
        printf("%d\n",k%2);
    }
    return 0;
}
/*
 【题意】
 
 给定数N，求S(N)%2，其中S(N)=T(1)+T(2)+……+T(N)，其中T(N)表示数N的因子和。
 
 【前话】
 
 队友推荐的这一题，当时想的是可以寻规律，打了个长度为N的表，压根没发现什么规律，不过却发现T(N)的一个特点，N=1，2，4，8，9，16，18，25，32，36，49，50，64……时T(N)%2==1，其余的都是0，结果见下表。
 
 T(N)%2……
 
 S(N) 1 0 0 1 1 1 1 0 1 1 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0……
 
 即S(N)= S(N-1)^(T(N)%2)。
 
 【分析】
 
 我后来列了N=10；
 
 1
 
 1 2
 
 1 3
 
 1 2 4
 
 1 5
 
 1 2 3 6
 
 1 7
 
 1 2 4 8
 
 1 3 9
 
 1 2 5 10
 
 注意到不要单行相加，按列来加，有10个1，5个2，3个3，2个4和5，1个6，7，8，9，10，看到这里，我立刻就醒过省来了，和fzu1988求个数如出一辙（见我的上一篇文章）。
 
 10/1=10，10/10=1，s+= 10;
 
 10/2=5，10/5=2,
 
 10/3=3，10/3=3，s+= 3*3;
 
 10/4=2，10/2=5，s+= (4+5)*2; //按区间算；
 
 10/6=1，10/10=1，s+= (6+7+8+9+10)*1;//按区间算；
 
 【后话】
 
 交完125MS，只有百度看那些0MS的怎么写，结果是吓一跳，别人打表到50就出了规律，话说我的打到10000我也没怎么看出，Orz！
 
 “凡是“能够被完全开方”或者“被2整除后能够完全被开方”的数，它的(T(N) % 2)都是1。”
 
 对于T(n)，设n=2^k * p1^s1 * p2^s2 * ... * pm^sm，则T(n)=(2^0+2^1+...+2^k)*(p1^0+p1^1+...+p1^s1)*...*(ps^0+ps^1+...+ps^sm)；
 因为(2^0+2^1+...+2^k)%2==1始终成立，则T(n)%2的结果取决于(pi^0+pi^1+...+pi^si)%2，只要其中一个为0，则T(n)%2==0。所以只要有一个si为奇数时，
 T(n)%2==0。即n为2^k*m^2时，T(n)为1。显然n也即m^2或2*m^2时，T(n)为1。而对于S(n)，只需算出i<=n中有几个T(i)为1即可。所以有以下AC代码：
 */
/*
 Problem Description
 Solving problem is a interesting thing. Yifenfei like to slove different problem,because he think it is a way let him more intelligent. But as we know,yifenfei is weak in math. When he come up against a difficult math problem, he always try to get a hand. Now the problem is coming! Let we
 define T(n) as the sum of all numbers which are positive integers can divied n. and S(n) = T(1) + T(2) + T(3)…..+T(n). 
 
 
 Input
 The first line of the input contains an integer T which means the number of test cases. Then T lines follow, each line consists of only one positive integers n. You may assume the integer will not exceed 2^31.
 
 
 Output
 For each test case, you should output one lines of one integer S(n) %2. So you may see the answer is always 0 or 1 .
 
 
 Sample Input
 3
 1
 2
 3 
 
 
 Sample Output
 1
 0
 0
 */