#include <iostream>
using namespace::std;

int main()
{
    int n,i,j=1,sum=0,a[10000]={0};
    cin >> n;
    for(i=1;i<=n;i++)
    {
        a[i]=j++;
        sum+=a[i];
        if(sum>=n&&(sum-n)%2==0)
        {
            cout << i <<'\n';
            break;
        }
    }
    return 0;
}
/*
解法
 一：sum一定要大于或等于输入的S.（等于时就已经找到了答案）
 小于的话就算全做加法运算也不能达到S。
 
 二：在满足第一条的情况下，注意一定要满足第一条后
 第一次碰到（sum　-　S　）　％　２　＝＝　０ 
 　这里（ sum = 1 + 2  + ....　+　i ）这时的i就是答案。
 证明如下：
 1：若res是奇数，就说明res = （ 1 + 2 + ... + i ）- S 是奇数
 也就是说无论你怎么改变sum（ sum = 1 + 2  + ....　+　i ）的表达式
 （当然是通过改变其中的加号为减号）也无法让res为0
 举个例子吧:S = 5, sum = 1+2+3 = 6, res = 6 - 5 = 1;
 无论改变（1+2+3）中的加号也没用，这是因为你在sum中改变一个加号为减号
 时它的值就一定减少了一个偶数值（这是显然的）sum-S仍然为奇数
 2：令res = sum - S，则res一定是0，2， 4， 6....中的一个
 下面说明总可以通过改变sum表达式中的某几个加号为减号使得res为0
 当k = 0的情况就不用说明了吧， 假设2k表示res 显然k = 1 2 3 4...
 当k = 1 时可以通过把sum（ sum = 1 + 2 + ... + i )
 改成（ sum = -1 + 2 + ... + i )
 当k = 2 时可以通过把sum （ sum = 1 + 2 + ... + i )
 改成( sum = 1 - 2 + ... + i ) 
 一次类推res总可以变为0
 */
/*
 Problem description
 Consider the natural numbers from 1 to N. By associating to each number a sign (+ or -) and calculating the value of this expression we obtain a sum S. The problem is to determine for a given sum S the minimum number N for which we can obtain S by associating signs for all numbers between 1 to N. 
 
 For a given S, find out the minimum value N in order to obtain S according to the conditions of the problem.
 
 Input
 The only line contains in the first line a positive integer S (0< S <= 100000) which represents the sum to be obtained.
 
 Output
 The output will contain the minimum number N for which the sum S can be obtained. 
 
 Sample Input
 12
 Sample Output
 7
 Judge Tips
 The sum 12 can be obtained from at least 7 terms in the following way: 12 = -1+2+3+4+5+6-7.
*/