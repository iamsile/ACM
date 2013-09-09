#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,x,y;
        cin >> n;
        while (n%10==0)
            n/=10;
        if (n%5==0) {
            x=(n/10)*10;
            y=(n/10+1)*10;
        }
        else {
            x=(n/5)*5;
            y=(n/5+1)*5;
        }
        if (x*20>=n*19||y*20<=n*21)
            cout << "absurd\n";
        else cout << "not absurd\n";
    }
    return 0;
}
/*
 这题 分情况讨论一下
 假设输入的数是a1,a2,a3,^^^an
 末尾第一个不为0的如果是5
 我假设的ai表示数的每一位
 比如 1850000
 这个末尾第一个不为0的是5
 也就是说 找absurdity比它小的e ，那么e的长度只能是
 原来输入的那个数的长度-1
 那么这里的话 就这能是不为0的长度为2 
 也就是把原来的数 5 改为0 
 然后 再枚举 5的前一个位置 8 （+1） 或者 （-1）然后得到的数 是否在那个区间内
 是（+1） 和 （+0）
 如果有一个在那就是absurd 
 那么对于5的情况已经讨论玩了
 如果末尾不是5 
 那么根据题意 要找的e 有几种情况 
 第一是 把输入的那一位不是5的改为5
 第二就是不为0的长度（-1） 也就是把 那个数改为0 长度 然后回到第一种情况
 比如是 输入 189000
 那么测试 185000 和 190000 和 180000 是否在区间内就行了
 假设末尾不是5 就如189000 那么要求一个e 的absurdity  小于输入的c
 那么只能是把 9 换成 5 或者 0
 换成5的话 absurdity值肯定变小了 
 换成5 可以理解吗？
 换成0 的话
 首先知道absurdity值肯定变小了
 然后 将枚举满足比输入的C 大得最小的数 以及比输入的C小的最大的数
 看看是否在里面 
 对于上面的输入 也就是枚举180000 以及190000
 也就是 上一位(+1) 或者不变
 Problem description
 Surely you know that supermarkets, shopping centres, and indeed all kind of vendors seem to have fallen in love with the digit 9, for that digit occurs most often in the price of a product, preferably at the least signicant positions. Your favourite chocolate bar might cost 99 cents, just right to be able to advertise that it costs less than 1 euro. Your new bicycle might cost 499:98 euros, which, of course, is less than 500 euros.
 While such comparisons are mathematically sound, they seem to impose a certain amount of stupidity on the customer. Moreover, who wants to carry home those annoying small coins you get back as change?
 Fortunately, the FIFA has not adopted this weird pricing scheme: a ticket for the nal in the rst category for example costs 900 dollar, in the second category 600 dollar and in the third category 400 dollar. These prices may only be regarded weird for other reasons.
 We want to distinguish between absurd prices like 99 cents, 499:98 euros, etc. and normal prices. To measure the absurdity of a positive integer, do the following:
  Eliminate all trailing zeros, i.e., those in the least signicant positions, from the number. You now have a positive integer, say x, with a non-zero digit d at its end.
  Count the number of digits, say a, of the number x.
  if d = 5 the absurdity of the number is 2 * a - 1
  otherwise, the absurdity of the number is 2 * a
 For example, the absurdity of 350 is 3 and the absurdity of 900900 is 8. Using the measure of absurdity, we can dene what we call an absurd price: A price c is absurd if and only if the closed interval [0:95  c; 1:05  c] contains an integer e such that the absurdity of e is less than the absurdity of c.
 Given a price in cents, go ahead and tell whether it is absurd!
 
 
 Input
 The rst line of the input consists of the number t of test cases to follow. Each test case is specied by one line containing an integer c. You may assume that 1 <= c <= 109.
 
 Output
 For each test case output if c is \absurd" or not. Adhere to the format shown in the sample output.
 
 Sample Input
 4
 99
 49998
 90000
 970000000
 Sample Output
 absurd
 absurd
 not absurd
 absurd
*/